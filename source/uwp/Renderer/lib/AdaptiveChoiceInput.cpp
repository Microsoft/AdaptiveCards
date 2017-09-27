#include "pch.h"
#include "AdaptiveChoiceInput.h"
#include "Util.h"
#include <windows.foundation.collections.h>
#include "XamlCardRendererComponent.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    HRESULT AdaptiveChoiceInput::RuntimeClassInitialize() noexcept try
    {
        m_sharedChoiceInput = std::make_shared<ChoiceInput>();
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::ChoiceInput>& sharedChoiceInput)
    {
        m_sharedChoiceInput = sharedChoiceInput;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::get_Title(HSTRING* title)
    {
        return UTF8ToHString(m_sharedChoiceInput->GetTitle(), title);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::put_Title(HSTRING title)
    {
        std::string out;
        RETURN_IF_FAILED(HStringToUTF8(title, out));
        m_sharedChoiceInput->SetTitle(out);
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::get_Value(HSTRING* value)
    {
        return UTF8ToHString(m_sharedChoiceInput->GetValue(), value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::put_Value(HSTRING value)
    {
        std::string out;
        RETURN_IF_FAILED(HStringToUTF8(value, out));
        m_sharedChoiceInput->SetValue(out);
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::get_IsSelected(boolean* isSelected)
    {
        *isSelected = m_sharedChoiceInput->GetIsSelected();
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::put_IsSelected(boolean isSelected)
    {
        m_sharedChoiceInput->SetIsSelected(isSelected);
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveChoiceInput::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::ChoiceInput;
        return S_OK;
    }
}}
