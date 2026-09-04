#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EtherAbility.generated.h"

class ANexusCharacter;

UENUM(BlueprintType)
enum class EEtherAbilityType : uint8
{
    Reinforcement UMETA(DisplayName="Reforço"),
    Projectile    UMETA(DisplayName="Projétil"),
    Defense       UMETA(DisplayName="Defesa"),
    Weapon        UMETA(DisplayName="Arma"),
    Trap          UMETA(DisplayName="Armadilha"),
    Utility       UMETA(DisplayName="Utilidade")
};

UCLASS(Blueprintable, BlueprintType)
class NEXUSETHER_API UEtherAbility : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    FName AbilityName = "EtherAbility";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
    EEtherAbilityType AbilityType = EEtherAbilityType::Reinforcement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.0"))
    float BaseEtherCost = 15.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.0"))
    float Intensity = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.0"))
    float Duration = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.0"))
    float Range = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.1"))
    float ConditionMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(ClampMin="0.0"))
    float Cooldown = 2.0f;

    UFUNCTION(BlueprintPure, Category="Ability")
    float CalculatePowerScore() const;

    UFUNCTION(BlueprintPure, Category="Ability")
    float CalculateEtherCost() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Ability")
    void ActivateAbility(ANexusCharacter* User);
    virtual void ActivateAbility_Implementation(ANexusCharacter* User);
};
