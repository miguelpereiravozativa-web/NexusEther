#include "EtherAbility.h"
#include "NexusCharacter.h"

float UEtherAbility::CalculatePowerScore() const
{
    return Intensity * FMath::Max(Duration, 0.1f) * FMath::Max(Range, 0.1f) * ConditionMultiplier;
}

float UEtherAbility::CalculateEtherCost() const
{
    const float PowerScore = CalculatePowerScore();
    return BaseEtherCost + (PowerScore * 2.0f);
}

void UEtherAbility::ActivateAbility_Implementation(ANexusCharacter* User)
{
    if (!User)
    {
        return;
    }

    UE_LOG(
        LogTemp,
        Log,
        TEXT("%s ativou %s. Poder: %.2f | Custo: %.2f"),
        *User->GetName(),
        *AbilityName.ToString(),
        CalculatePowerScore(),
        CalculateEtherCost()
    );
}
