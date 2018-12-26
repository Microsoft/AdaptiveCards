#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "RenderedAdaptiveCard.h"
#include "AdaptiveActionInvoker.h"
#include "AdaptiveMediaEventInvoker.h"

namespace AdaptiveNamespace
{
    class DECLSPEC_UUID("F29649FF-C718-4F94-8F39-2415C86BE77E") AdaptiveRenderContext
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveNamespace::IAdaptiveRenderContext,
                                              Microsoft::WRL::CloakedIid<ITypePeek>>
    {
        AdaptiveRuntime(AdaptiveRenderContext);

    public:
        HRESULT RuntimeClassInitialize() noexcept;

        HRESULT RuntimeClassInitialize(ABI::AdaptiveNamespace::IAdaptiveHostConfig* hostConfig,
                                       ABI::AdaptiveNamespace::IAdaptiveElementRendererRegistration* elementRendererRegistration,
                                       ABI::AdaptiveNamespace::IAdaptiveCardResourceResolvers* resourceResolvers,
                                       ABI::Windows::UI::Xaml::IResourceDictionary* overrideStyles,
                                       ABI::Windows::UI::Xaml::IResourceDictionary* defaultActionSentimentStyles,
                                       AdaptiveNamespace::RenderedAdaptiveCard* renderResult) noexcept;

        IFACEMETHODIMP get_HostConfig(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveHostConfig** value);
        IFACEMETHODIMP get_ElementRenderers(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveElementRendererRegistration** value);
        IFACEMETHODIMP get_ActionInvoker(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveActionInvoker** value);
        IFACEMETHODIMP get_MediaEventInvoker(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveMediaEventInvoker** value);
        IFACEMETHODIMP AddInputValue(_In_ ABI::AdaptiveNamespace::IAdaptiveInputValue* inputValue);
        IFACEMETHODIMP get_ResourceResolvers(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardResourceResolvers** value);
        IFACEMETHODIMP get_OverrideStyles(_COM_Outptr_ ABI::Windows::UI::Xaml::IResourceDictionary** overrideDictionary);
        IFACEMETHODIMP AddError(_In_ ABI::AdaptiveNamespace::ErrorStatusCode statusCode, _In_ HSTRING message);
        IFACEMETHODIMP AddWarning(_In_ ABI::AdaptiveNamespace::WarningStatusCode statusCode, _In_ HSTRING message);
        IFACEMETHODIMP get_CardFrameworkElement(_COM_Outptr_ ABI::Windows::UI::Xaml::IFrameworkElement** value);

        HRESULT put_CardFrameworkElement(_In_ ABI::Windows::UI::Xaml::IFrameworkElement* value);

        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> GetDefaultActionSentimentDictionary();

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

    private:
        Microsoft::WRL::ComPtr<ABI::AdaptiveNamespace::IAdaptiveHostConfig> m_hostConfig;
        Microsoft::WRL::ComPtr<ABI::AdaptiveNamespace::IAdaptiveElementRendererRegistration> m_elementRendererRegistration;
        Microsoft::WRL::ComPtr<AdaptiveNamespace::RenderedAdaptiveCard> m_renderResult;
        Microsoft::WRL::ComPtr<AdaptiveNamespace::AdaptiveActionInvoker> m_actionInvoker;
        Microsoft::WRL::ComPtr<AdaptiveNamespace::AdaptiveMediaEventInvoker> m_mediaEventInvoker;
        Microsoft::WRL::ComPtr<ABI::AdaptiveNamespace::IAdaptiveCardResourceResolvers> m_resourceResolvers;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> m_overrideDictionary;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IFrameworkElement> m_cardFrameworkElement;

        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> m_actionSentimentDefaultDictionary;
    };

    ActivatableClass(AdaptiveRenderContext);
}
