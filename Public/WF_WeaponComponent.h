// Copyright 2024 by Nightails Games. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WF_WeaponComponent.generated.h"

class UWF_WeaponConfigData;

/** UWF_WeaponComponent
 * An actor component that manage and control the behavior of attached weapon.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WEAPONFRAMEWORK_API UWF_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWF_WeaponComponent();
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Maximum number of available WeaponConfig that the character can have at once. View this as number of weapon slot.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Configurations")
	uint8 MaxAvailableWeaponConfig;
	// WeaponConfigs that are available to the character to use. View this as weapon slots. 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Configurations")
	TArray<TObjectPtr<UWF_WeaponConfigData>> AvailableWeaponConfigs;

private:
	// Keep track of which weapon config is being used/equipped.
	UPROPERTY(VisibleAnywhere, Category="Active Weapon")
	uint8 ActiveWeaponIndex;
};
