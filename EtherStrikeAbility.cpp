#include "EtherStrikeAbility.h"
#include "NexusCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UEtherStrikeAbility::UEtherStrikeAbility()
{
    AbilityName = "EtherStrike";
    AbilityType = EEtherAbilityType::Reinforcement;
    BaseEtherCost = 10.0f;
    Intensity = 1.5f;
    Duration = 0.2f;
    Range = 1.0f;
    Cooldown = 1.2f;
}

void UEtherStrikeAbility::ActivateAbility_Implementation(ANexusCharacter* User)
{
    Super::ActivateAbility_Implementation(User);

    if (!User || !User->GetWorld())
    {
        return;
    }

    const FVector Start = User->GetActorLocation();
    const FVector End = Start + User->GetActorForwardVector() * TraceDistance;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(User);

    const bool bHit = User->GetWorld()->LineTraceSingleByChannel(
        Hit,
        Start,
        End,
        ECC_Pawn,
        Params
    );

    if (bHit && Hit.GetActor())
    {
        const float FinalDamage = BaseDamage * Intensity * ConditionMultiplier;

        UGameplayStatics::ApplyDamage(
            Hit.GetActor(),
            FinalDamage,
            User->GetController(),
            User,
            nullptr
        );

        UE_LOG(
            LogTemp,
            Log,
            TEXT("EtherStrike acertou %s por %.2f de dano."),
            *Hit.GetActor()->GetName(),
            FinalDamage
        );
    }
}
