#pragma once

#include "AdaptiveCards.Uwp.h"
#include "Enums.h"
#include "HostConfig.h"

namespace AdaptiveCards { namespace Uwp
{
    class AdaptiveImageSizesConfig :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::Uwp::IAdaptiveImageSizesConfig>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Uwp_AdaptiveImageSizesConfig, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(ImageSizesConfig imageSizesConfig) noexcept;

        IFACEMETHODIMP get_Small(_Out_ UINT32* value);
        IFACEMETHODIMP put_Small(_In_ UINT32 value);

        IFACEMETHODIMP get_Medium(_Out_ UINT32* value);
        IFACEMETHODIMP put_Medium(_In_ UINT32 value);

        IFACEMETHODIMP get_Large(_Out_ UINT32* value);
        IFACEMETHODIMP put_Large(_In_ UINT32 value);

    private:
        UINT32 m_small;
        UINT32 m_medium;
        UINT32 m_large;
    };

    ActivatableClass(AdaptiveImageSizesConfig);
}}