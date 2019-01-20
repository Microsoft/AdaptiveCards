#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "ActionSet.h"

namespace AdaptiveCards
{
    namespace Rendering
    {
        namespace Uwp
        {
            class AdaptiveActionSetRenderer
                : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                                      ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveElementRenderer,
                                                      ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveElementParser>
            {
                InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveActionSetRenderer, BaseTrust)

                    public : HRESULT RuntimeClassInitialize() noexcept;

                IFACEMETHODIMP Render(_In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardElement* cardElement,
                                      _In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveRenderContext* renderContext,
                                      _In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveRenderArgs* renderArgs,
                                      _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result) noexcept;

                IFACEMETHODIMP FromJson(ABI::Windows::Data::Json::IJsonObject*,
                                        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveElementParserRegistration* elementParsers,
                                        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveActionParserRegistration* actionParsers,
                                        ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* adaptiveWarnings,
                                        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardElement** element) noexcept;
            };

            ActivatableClass(AdaptiveActionSetRenderer);
        }
    }
}
