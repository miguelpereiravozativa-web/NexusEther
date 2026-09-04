#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NexusCharacter.generated.h"

class UEtherComponent;
class UEtherAbility;

UCLASS()
class NEXUSETHER_API ANexusCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ANexusCharacter();

    virtual void SetupPlayerInputComponent(
        class UInputComponent* PlayerInputComponent
    ) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UEtherComponent* EtherComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Abilities")
    UEtherAbility* Ability1;

    UFUNCTION(BlueprintCallable, Category="Abilities")
    bool TryActivateAbility(UEtherAbility* Ability);

protected:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void UseAbility1();

private:
    TMap<UEtherAbility*, float> AbilityLastUseTime;

    bool IsAbilityOnCooldown(UEtherAbility* Ability) const;
};
