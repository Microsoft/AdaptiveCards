#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "TextBlock.h"

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{

    class DECLSPEC_UUID("743555b2-f4fc-486f-9024-f77de55aef26") AdaptiveTextBlock :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveTextBlock,
            ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardElement,
            Microsoft::WRL::CloakedIid<ITypePeek>>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveTextBlock, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::TextBlock>& sharedTextBlock);

        // IAdaptiveTextBlock
        IFACEMETHODIMP get_Text(_Out_ HSTRING *text);
        IFACEMETHODIMP put_Text(_In_ HSTRING text);

        IFACEMETHODIMP get_Size(_Out_ ABI::AdaptiveCards::Rendering::Uwp::TextSize* textSize);
        IFACEMETHODIMP put_Size(_In_ ABI::AdaptiveCards::Rendering::Uwp::TextSize textSize);

        IFACEMETHODIMP get_Weight(_Out_ ABI::AdaptiveCards::Rendering::Uwp::TextWeight* textWeight);
        IFACEMETHODIMP put_Weight(_In_ ABI::AdaptiveCards::Rendering::Uwp::TextWeight textWeight);

        IFACEMETHODIMP get_Color(_Out_ ABI::AdaptiveCards::Rendering::Uwp::ForegroundColor* textColor);
        IFACEMETHODIMP put_Color(_In_ ABI::AdaptiveCards::Rendering::Uwp::ForegroundColor textColor);

        IFACEMETHODIMP get_Wrap(_Out_ boolean* wrap);
        IFACEMETHODIMP put_Wrap(_In_ boolean wrap);

        IFACEMETHODIMP get_IsSubtle(_Out_ boolean* isSubtle);
        IFACEMETHODIMP put_IsSubtle(_In_ boolean isSubtle);

        IFACEMETHODIMP get_MaxLines(_Out_ UINT32* value);
        IFACEMETHODIMP put_MaxLines(_In_ UINT32 value);

        IFACEMETHODIMP get_HorizontalAlignment(_Out_ ABI::AdaptiveCards::Rendering::Uwp::HAlignment* hAlignment);
        IFACEMETHODIMP put_HorizontalAlignment(_In_ ABI::AdaptiveCards::Rendering::Uwp::HAlignment hAlignment);

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveCards::Rendering::Uwp::ElementType* elementType);

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveCards::Rendering::Uwp::Spacing* spacing);
        IFACEMETHODIMP put_Spacing(_In_ ABI::AdaptiveCards::Rendering::Uwp::Spacing spacing);

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator);
        IFACEMETHODIMP put_Separator(_In_ boolean separator);

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id);
        IFACEMETHODIMP put_Id(_In_ HSTRING id);

        IFACEMETHODIMP get_ElementTypeString(_Out_ HSTRING* value);

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result);

        HRESULT GetSharedModel(_In_ std::shared_ptr<AdaptiveCards::TextBlock>& sharedModel);

        // ITypePeek method
        void *PeekAt(REFIID riid) override
        {
            return PeekHelper(riid, this);
        }

    private:
        std::shared_ptr<AdaptiveCards::TextBlock> m_sharedTextBlock;
    };

    ActivatableClass(AdaptiveTextBlock);
}}}