#pragma once

#include "AdaptiveCards.Uwp.h"
#include "Enums.h"
#include "HostConfig.h"

namespace AdaptiveCards { namespace Uwp
{
    class AdaptiveActionsConfig :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        ABI::AdaptiveCards::Uwp::IAdaptiveActionsConfig>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Uwp_AdaptiveActionsConfig, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(AdaptiveCards::ActionsConfig actionsConfig) noexcept;

        IFACEMETHODIMP get_ShowCard(_Out_ ABI::AdaptiveCards::Uwp::IAdaptiveShowCardActionConfig** value);
        IFACEMETHODIMP put_ShowCard(_In_ ABI::AdaptiveCards::Uwp::IAdaptiveShowCardActionConfig* value);

        IFACEMETHODIMP get_ActionsOrientation(_Out_ ABI::AdaptiveCards::Uwp::ActionsOrientation* value);
        IFACEMETHODIMP put_ActionsOrientation(_In_ ABI::AdaptiveCards::Uwp::ActionsOrientation value);

        IFACEMETHODIMP get_ActionAlignment(_Out_ ABI::AdaptiveCards::Uwp::ActionAlignment* value);
        IFACEMETHODIMP put_ActionAlignment(_In_ ABI::AdaptiveCards::Uwp::ActionAlignment value);

        IFACEMETHODIMP get_ButtonSpacing(_Out_ UINT32* value);
        IFACEMETHODIMP put_ButtonSpacing(_In_ UINT32 value);

        IFACEMETHODIMP get_MaxActions(_Out_ UINT32* value);
        IFACEMETHODIMP put_MaxActions(_In_ UINT32 value);

        IFACEMETHODIMP get_Spacing(ABI::AdaptiveCards::Uwp::Spacing* value);
        IFACEMETHODIMP put_Spacing(ABI::AdaptiveCards::Uwp::Spacing value);

    private:
        ABI::AdaptiveCards::Uwp::ActionAlignment m_actionAlignment;
        ABI::AdaptiveCards::Uwp::ActionsOrientation m_actionsOrientation;
        UINT m_buttonSpacing;
        UINT m_maxActions;
        ABI::AdaptiveCards::Uwp::Spacing m_spacing;

        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Uwp::IAdaptiveShowCardActionConfig> m_showCardActionConfig;
    };

    ActivatableClass(AdaptiveActionsConfig);
}
}