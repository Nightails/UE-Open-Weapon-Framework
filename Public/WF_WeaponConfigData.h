// Copyright 2024 by Nightails Games. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WF_WeaponConfigData.generated.h"

// Weapon Type.
UENUM()
enum class EWeaponType : uint8
{
	Melee,
	Firearm,
	Projectile,
	Throwable
};

// Firearm Type. Currently only include trace firearm types.
UENUM()
enum class EFirearmType : uint8
{
	Pistol,
	Revolver,
	Shotgun,
	Rifle,
	SniperRifle,
	SMG,
	LMG
};

// Firearm Firing Mode
UENUM()
enum class EFirearmMode : uint8
{
	Single,
	Automatic,
	Bust
};

/** UWF_WeaponConfigData
 * A data-asset that store a pre-config settings for a weapon.
 */
UCLASS()
class WEAPONFRAMEWORK_API UWF_WeaponConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	// Get the weapon-type of this weapon.
	UFUNCTION(BlueprintCallable, Category="WeaponFramework")
	EWeaponType GetWeaponType() const { return WeaponType; }

	// Get the firearm-type of this weapon.
	UFUNCTION(BlueprintCallable, Category="WeaponFramework|FireArm")
	EFirearmType GetFireArmType() const { return FirearmType; }
	// Get the firearm-mode of this weapon.
	UFUNCTION(BlueprintCallable, Category="WeaponFramework|FireArm")
	EFirearmMode GetFireArmMode() const { return FirearmMode; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Configuration")
	EWeaponType WeaponType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Configuration|Firearm", meta=(EditCondition = "WeaponType == EWeaponType::Firearm", EditConditionHides))
	EFirearmType FirearmType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Configuration|Firearm", meta=(EditCondition = "WeaponType == EWeaponType::Firearm", EditConditionHides))
	EFirearmMode FirearmMode;

	// All weapon expects to be rigged with a skeleton due to requirement for animation.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Visuals")
	TObjectPtr<USkeletalMesh> WeaponSkeletalMesh;
	// Can leave un-assign, if there is no animation for this weapon.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Visuals")
	TObjectPtr<UAnimInstance> WeaponAnimInstance;
	
	/** Attachments:
	 * - Scope
	 * - Magazine
	 * - Muzzle
	 * - Grip / Rail
	 */
	
	// Weapon visual effects & sounds
};
