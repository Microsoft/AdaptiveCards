// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"
#include "AdaptiveFontStyleDefinition.h"
#include "AdaptiveFontStylesDefinition.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

namespace AdaptiveNamespace
{
    HRESULT AdaptiveFontStylesDefinition::RuntimeClassInitialize() noexcept try
    {
        FontStylesDefinition stylesDefinition;
        return RuntimeClassInitialize(stylesDefinition);
    }
    CATCH_RETURN;

    HRESULT AdaptiveFontStylesDefinition::RuntimeClassInitialize(FontStylesDefinition stylesDefinition) noexcept
    {
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveFontStyleDefinition>(m_default.GetAddressOf(), stylesDefinition.defaultStyle));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveFontStyleDefinition>(m_monospace.GetAddressOf(), stylesDefinition.monospaceStyle));

        return S_OK;
    }

    HRESULT AdaptiveFontStylesDefinition::get_Default(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveFontStyleDefinition** value)
    {
        return m_default.CopyTo(value);
    }

    HRESULT AdaptiveFontStylesDefinition::put_Default(_In_ ABI::AdaptiveNamespace::IAdaptiveFontStyleDefinition* value)
    {
        m_default = value;
        return S_OK;
    }

    HRESULT AdaptiveFontStylesDefinition::get_Monospace(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveFontStyleDefinition** value)
    {
        return m_monospace.CopyTo(value);
    }

    HRESULT AdaptiveFontStylesDefinition::put_Monospace(_In_ ABI::AdaptiveNamespace::IAdaptiveFontStyleDefinition* value)
    {
        m_monospace = value;
        return S_OK;
    }
}
