#include "NexusCharacter.h"
#include "EtherComponent.h"
#include "EtherAbility.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

ANexusCharacter::ANexusCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    EtherComponent = CreateDefaultSubobject<UEtherComponent>(TEXT("EtherComponent"));
}

void ANexusCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ANexusCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ANexusCharacter::MoveRight);
    PlayerInputComponent->BindAction("Ability1", IE_Pressed, this, &ANexusCharacter::UseAbility1);
}

void ANexusCharacter::MoveForward(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void ANexusCharacter::MoveRight(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        AddMovementInput(GetActorRightVector(), Value);
    }
}

void ANexusCharacter::UseAbility1()
{
    TryActivateAbility(Ability1);
}

bool ANexusCharacter::TryActivateAbility(UEtherAbility* Ability)
{
    if (!Ability || !EtherComponent)
    {
        return false;
    }

    if (IsAbilityOnCooldown(Ability))
    {
        UE_LOG(LogTemp, Warning, TEXT("Habilidade em cooldown."));
        return false;
    }

    const float EtherCost = Ability->CalculateEtherCost();

    if (!EtherComponent->SpendEther(EtherCost))
    {
        UE_LOG(LogTemp, Warning, TEXT("Éter insuficiente."));
        return false;
    }

    Ability->ActivateAbility(this);

    if (UWorld* World = GetWorld())
    {
        AbilityLastUseTime.Add(Ability, World->GetTimeSeconds());
    }

    return true;
}

bool ANexusCharacter::IsAbilityOnCooldown(UEtherAbility* Ability) const
{
    if (!Ability)
    {
        return false;
    }

    const float* LastUse = AbilityLastUseTime.Find(Ability);

    if (!LastUse)
    {
        return false;
    }

    const UWorld* World = GetWorld();

    if (!World)
    {
        return false;
    }

    return (World->GetTimeSeconds() - *LastUse) < Ability->Cooldown;
}
