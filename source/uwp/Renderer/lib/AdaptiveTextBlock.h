// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "TextBlock.h"
#include "AdaptiveTextElement.h"

namespace AdaptiveNamespace
{
    class DECLSPEC_UUID("0c87566c-a58c-4332-8b3b-79c9714074f6") AdaptiveTextBlock
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveNamespace::IAdaptiveTextBlock,
                                              ABI::AdaptiveNamespace::IAdaptiveTextElement,
                                              ABI::AdaptiveNamespace::IAdaptiveCardElement,
                                              Microsoft::WRL::CloakedIid<ITypePeek>,
                                              Microsoft::WRL::CloakedIid<AdaptiveNamespace::AdaptiveCardElementBase>,
                                              Microsoft::WRL::CloakedIid<AdaptiveNamespace::AdaptiveTextElement>>
    {
        AdaptiveRuntime(AdaptiveTextBlock);

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(const std::shared_ptr<AdaptiveSharedNamespace::TextBlock>& sharedTextBlock);

        // IAdaptiveTextBlock
        IFACEMETHODIMP get_Wrap(_Out_ boolean* wrap) override;
        IFACEMETHODIMP put_Wrap(boolean wrap) override;

        IFACEMETHODIMP get_MaxLines(_Out_ UINT32* value) override;
        IFACEMETHODIMP put_MaxLines(UINT32 value) override;

        IFACEMETHODIMP get_HorizontalAlignment(_Out_ ABI::AdaptiveNamespace::HAlignment* HorizontalAlignment) override;
        IFACEMETHODIMP put_HorizontalAlignment(ABI::AdaptiveNamespace::HAlignment HorizontalAlignment) override;

        IFACEMETHODIMP get_Style(_Outptr_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextStyle>** value) override;
        IFACEMETHODIMP put_Style(_In_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextStyle>* value) override;

        // IAdaptiveTextElement
        IFACEMETHODIMP get_Text(_Outptr_ HSTRING* text) override { return AdaptiveTextElement::get_Text(text); }
        IFACEMETHODIMP put_Text(_In_ HSTRING text) override { return AdaptiveTextElement::put_Text(text); }

        IFACEMETHODIMP get_Size(_Outptr_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextSize>** textSize) override
        {
            return AdaptiveTextElement::get_Size(textSize);
        }
        IFACEMETHODIMP put_Size(_In_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextSize>* textSize) override
        {
            return AdaptiveTextElement::put_Size(textSize);
        }

        IFACEMETHODIMP get_Weight(_Outptr_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextWeight>** textWeight) override
        {
            return AdaptiveTextElement::get_Weight(textWeight);
        }
        IFACEMETHODIMP put_Weight(_In_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextWeight>* textWeight) override
        {
            return AdaptiveTextElement::put_Weight(textWeight);
        }

        IFACEMETHODIMP get_Color(_Outptr_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::ForegroundColor>** textColor) override
        {
            return AdaptiveTextElement::get_Color(textColor);
        }
        IFACEMETHODIMP put_Color(_In_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::ForegroundColor>* textColor) override
        {
            return AdaptiveTextElement::put_Color(textColor);
        }

        IFACEMETHODIMP get_IsSubtle(_Outptr_ ABI::Windows::Foundation::IReference<bool>** isSubtle) override
        {
            return AdaptiveTextElement::get_IsSubtle(isSubtle);
        }
        IFACEMETHODIMP put_IsSubtle(_In_ ABI::Windows::Foundation::IReference<bool>* isSubtle) override
        {
            return AdaptiveTextElement::put_IsSubtle(isSubtle);
        }

        IFACEMETHODIMP get_Language(_Outptr_ HSTRING* language) override
        {
            return AdaptiveTextElement::get_Language(language);
        }
        IFACEMETHODIMP put_Language(_In_ HSTRING language) override
        {
            return AdaptiveTextElement::put_Language(language);
        }

        IFACEMETHODIMP get_FontType(_Outptr_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::FontType>** type) override
        {
            return AdaptiveTextElement::get_FontType(type);
        }
        IFACEMETHODIMP put_FontType(_In_ ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::FontType>* type) override
        {
            return AdaptiveTextElement::put_FontType(type);
        }

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveNamespace::ElementType* elementType) override;

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveNamespace::Spacing* spacing) override
        {
            return AdaptiveCardElementBase::get_Spacing(spacing);
        }
        IFACEMETHODIMP put_Spacing(ABI::AdaptiveNamespace::Spacing spacing) override
        {
            return AdaptiveCardElementBase::put_Spacing(spacing);
        }

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator) override
        {
            return AdaptiveCardElementBase::get_Separator(separator);
        }
        IFACEMETHODIMP put_Separator(boolean separator) override
        {
            return AdaptiveCardElementBase::put_Separator(separator);
        }

        IFACEMETHODIMP get_IsVisible(_Out_ boolean* isVisible) override
        {
            return AdaptiveCardElementBase::get_IsVisible(isVisible);
        }
        IFACEMETHODIMP put_IsVisible(boolean isVisible) override
        {
            return AdaptiveCardElementBase::put_IsVisible(isVisible);
        }

        IFACEMETHODIMP get_Id(_Outptr_ HSTRING* id) override { return AdaptiveCardElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) override { return AdaptiveCardElementBase::put_Id(id); }

        IFACEMETHODIMP get_FallbackType(_Out_ ABI::AdaptiveNamespace::FallbackType* fallback) override
        {
            return AdaptiveCardElementBase::get_FallbackType(fallback);
        }
        IFACEMETHODIMP get_FallbackContent(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardElement** content) override
        {
            return AdaptiveCardElementBase::get_FallbackContent(content);
        }

        IFACEMETHODIMP put_FallbackType(ABI::AdaptiveNamespace::FallbackType fallback) override
        {
            return AdaptiveCardElementBase::put_FallbackType(fallback);
        }

        IFACEMETHODIMP put_FallbackContent(_In_ ABI::AdaptiveNamespace::IAdaptiveCardElement* content) override
        {
            return AdaptiveCardElementBase::put_FallbackContent(content);
        }

        IFACEMETHODIMP get_ElementTypeString(_Outptr_ HSTRING* value) override
        {
            return AdaptiveCardElementBase::get_ElementTypeString(value);
        }

        IFACEMETHODIMP get_AdditionalProperties(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result) override
        {
            return AdaptiveCardElementBase::get_AdditionalProperties(result);
        }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value) override
        {
            return AdaptiveCardElementBase::put_AdditionalProperties(value);
        }

        IFACEMETHODIMP get_Requirements(
            _COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveRequirement*>** requirements) override
        {
            return AdaptiveCardElementBase::get_Requirements(requirements);
        }

        IFACEMETHODIMP ToJson(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result) override
        {
            return AdaptiveCardElementBase::ToJson(result);
        }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseCardElement>& sharedModel) override;

        IFACEMETHODIMP get_Height(_Out_ ABI::AdaptiveNamespace::HeightType* height) override
        {
            return AdaptiveCardElementBase::get_Height(height);
        }
        IFACEMETHODIMP put_Height(ABI::AdaptiveNamespace::HeightType height) override
        {
            return AdaptiveCardElementBase::put_Height(height);
        }

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

    private:
        boolean m_wrap;
        UINT32 m_maxLines;
        ABI::AdaptiveNamespace::HAlignment m_horizontalAlignment;
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IReference<ABI::AdaptiveNamespace::TextStyle>> m_style;
    };

    ActivatableClass(AdaptiveTextBlock);
}
