#pragma once
#include "AdaptiveCards.XamlCardRenderer.h"
#include <wrl\async.h>
#include "XamlBuilder.h"
#include "XamlCardRendererComponent.h"
#include "XamlHelpers.h"

#define MakeAgileDispatcherCallback ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::ClassicCom>, ::ABI::Windows::UI::Core::IDispatchedHandler, ::Microsoft::WRL::FtmBase>>

/// A base class for IAsyncOperation<T> implementations for use with WRL
template<typename T>
class RenderAsyncBase :
    public Microsoft::WRL::RuntimeClass<
    Microsoft::WRL::AsyncBase<ABI::Windows::Foundation::IAsyncOperationCompletedHandler<T*>>,
    ABI::Windows::Foundation::IAsyncOperation<T*>,
    AdaptiveCards::XamlCardRenderer::IXamlBuilderListener>
{
    InspectableClass(L"Windows.Foundation.IAsyncInfo", BaseTrust)

public:
    typedef ABI::Windows::Foundation::IAsyncOperationCompletedHandler<T*> HandlerType;

    RenderAsyncBase(
        ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCard* card, AdaptiveCards::XamlCardRenderer::XamlCardRenderer* renderer)
        : m_card(card), 
          m_renderer(renderer)
    {
        // Get the dispatcher to we can run an async operation to build the xaml tree
        ComPtr<ABI::Windows::UI::Core::ICoreWindowStatic> coreWindowStatic;
        THROW_IF_FAILED(Windows::Foundation::GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Core_CoreWindow).Get(), &coreWindowStatic));
        ComPtr<ABI::Windows::UI::Core::ICoreWindow> coreWindow;
        THROW_IF_FAILED(coreWindowStatic->GetForCurrentThread(coreWindow.GetAddressOf()));
        THROW_IF_FAILED(coreWindow->get_Dispatcher(&m_dispatcher));

        m_builder = Microsoft::WRL::Make<AdaptiveCards::XamlCardRenderer::XamlBuilder>();
        m_builder->SetHostConfig(m_renderer->GetHostConfig());
    }

    // IAsyncOperation
    virtual auto STDMETHODCALLTYPE put_Completed(HandlerType* handler) -> HRESULT override
    {
        return AsyncBase::PutOnComplete(handler);
    }

    virtual auto STDMETHODCALLTYPE get_Completed(HandlerType** handler) -> HRESULT override
    {
        return AsyncBase::GetOnComplete(handler);
    }

    // IXamlBuilderListener
    IFACEMETHODIMP AllImagesLoaded()
    {
        return OnXamlImagesLoaded();
    }

    IFACEMETHODIMP ImagesLoadingHadError()
    {
        return OnXamlImagesHadError();
    }

    IFACEMETHODIMP XamlBuilderHadError()
    {
        return OnXamlBuilderHadError();
    }

protected:
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IUIElement> m_rootXamlElement;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> m_dispatcher;
    Microsoft::WRL::ComPtr<AdaptiveCards::XamlCardRenderer::XamlBuilder> m_builder;
    Microsoft::WRL::ComPtr<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCard> m_card;
    Microsoft::WRL::ComPtr<AdaptiveCards::XamlCardRenderer::XamlCardRenderer> m_renderer;

    HRESULT OnStart(void) override
    {
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncAction> dispatcherAsyncAction;
        m_dispatcher->RunAsync(ABI::Windows::UI::Core::CoreDispatcherPriority_Normal,
            MakeAgileDispatcherCallback([this]() -> HRESULT
        {
            m_builder->AddListener(this);
            try
            {
                m_builder->BuildXamlTreeFromAdaptiveCard(m_card.Get(), &m_rootXamlElement, m_renderer.Get());
            }
            catch (...)
            {
                //Catch all non-Image loading related problems.
                return XamlBuilderHadError();
            }
            return S_OK;
        }).Get(),
            &dispatcherAsyncAction);

        dispatcherAsyncAction->put_Completed(
            Microsoft::WRL::Callback<ABI::Windows::Foundation::IAsyncActionCompletedHandler>(
                [this](ABI::Windows::Foundation::IAsyncAction* action, ABI::Windows::Foundation::AsyncStatus status) -> HRESULT
        {
            return XamlRenderCompleted(action, status);
        }).Get());
        return S_OK;
    }

    void OnClose() override
    {
    }

    void OnCancel() override
    {
    }

    virtual HRESULT XamlRenderCompleted(ABI::Windows::Foundation::IAsyncAction* action, ABI::Windows::Foundation::AsyncStatus status) = 0;
    virtual HRESULT OnXamlImagesLoaded() = 0;
    virtual HRESULT OnXamlImagesHadError() = 0;

    HRESULT OnXamlBuilderHadError()
    {
        AsyncBase::TryTransitionToError(E_FAIL);
        return AsyncBase::FireCompletion();
    }

private:
    std::function<ABI::Windows::UI::Xaml::IUIElement*(ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCard*)> m_dispatchFunction;
};



class RenderCardAsXamlAsyncOperation : 
    public RenderAsyncBase<ABI::Windows::UI::Xaml::UIElement>
{
public:
    RenderCardAsXamlAsyncOperation(
        ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCard* card,
        AdaptiveCards::XamlCardRenderer::XamlCardRenderer* renderer)
        : RenderAsyncBase<ABI::Windows::UI::Xaml::UIElement>(card, renderer)
    {
        AsyncBase::Start();
    }

    STDMETHODIMP ABI::Windows::Foundation::IAsyncOperation_impl<TResult_complex>::GetResults(ABI::Windows::UI::Xaml::IUIElement** rootElement)
    {
        return m_rootXamlElement.CopyTo(rootElement);
    }

protected:
    HRESULT XamlRenderCompleted(ABI::Windows::Foundation::IAsyncAction* /*action*/, ABI::Windows::Foundation::AsyncStatus /*status*/) override
    {
        return S_OK;
    }

    HRESULT OnXamlImagesLoaded()
    {
        return AsyncBase::FireCompletion();
    }

    HRESULT OnXamlImagesHadError()
    {
        AsyncBase::TryTransitionToError(E_FAIL);
        return AsyncBase::FireCompletion();
    }

};