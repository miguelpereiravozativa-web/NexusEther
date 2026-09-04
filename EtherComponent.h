#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EtherComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FEtherChangedSignature,
    float, CurrentEther,
    float, MaxEther
);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NEXUSETHER_API UEtherComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEtherComponent();

    virtual void BeginPlay() override;
    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction
    ) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ether")
    float MaxEther = 100.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Ether")
    float CurrentEther = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ether")
    float RegenPerSecond = 6.0f;

    UPROPERTY(BlueprintAssignable, Category="Ether")
    FEtherChangedSignature OnEtherChanged;

    UFUNCTION(BlueprintCallable, Category="Ether")
    bool SpendEther(float Amount);

    UFUNCTION(BlueprintCallable, Category="Ether")
    void RestoreEther(float Amount);

    UFUNCTION(BlueprintPure, Category="Ether")
    float GetEtherPercent() const;

private:
    void ClampAndBroadcast();
};
