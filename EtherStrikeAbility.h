#pragma once

#include "CoreMinimal.h"
#include "EtherAbility.h"
#include "EtherStrikeAbility.generated.h"

UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class NEXUSETHER_API UEtherStrikeAbility : public UEtherAbility
{
    GENERATED_BODY()

public:
    UEtherStrikeAbility();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Strike")
    float BaseDamage = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Strike")
    float TraceDistance = 250.0f;

    virtual void ActivateAbility_Implementation(ANexusCharacter* User) override;
};
