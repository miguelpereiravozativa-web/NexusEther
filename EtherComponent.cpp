#include "EtherComponent.h"

UEtherComponent::UEtherComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UEtherComponent::BeginPlay()
{
    Super::BeginPlay();

    CurrentEther = MaxEther;
    ClampAndBroadcast();
}

void UEtherComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction
)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (CurrentEther < MaxEther)
    {
        CurrentEther += RegenPerSecond * DeltaTime;
        ClampAndBroadcast();
    }
}

bool UEtherComponent::SpendEther(float Amount)
{
    if (Amount <= 0.0f)
    {
        return true;
    }

    if (CurrentEther < Amount)
    {
        return false;
    }

    CurrentEther -= Amount;
    ClampAndBroadcast();
    return true;
}

void UEtherComponent::RestoreEther(float Amount)
{
    if (Amount <= 0.0f)
    {
        return;
    }

    CurrentEther += Amount;
    ClampAndBroadcast();
}

float UEtherComponent::GetEtherPercent() const
{
    if (MaxEther <= 0.0f)
    {
        return 0.0f;
    }

    return CurrentEther / MaxEther;
}

void UEtherComponent::ClampAndBroadcast()
{
    CurrentEther = FMath::Clamp(CurrentEther, 0.0f, MaxEther);
    OnEtherChanged.Broadcast(CurrentEther, MaxEther);
}
