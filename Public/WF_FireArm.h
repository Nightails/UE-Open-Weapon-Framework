// Copyright 2023 Nightails Games. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WF_FireArm.generated.h"

/* Firearm Type
 * Currently only include trace firearm types.
 */
UENUM()
enum class EFireArmType : uint8
{
	Pistol,
	Revolver,
	Shotgun,
	Rifle,
	SniperRifle,
	SMG,
	LMG
};

/* Firearm Firing Mode */
UENUM()
enum class EFirArmMode : uint8
{
	Single,
	Automatic,
	Bust
};

/* Firearm Actor
 * A base firearm actor class that contains all the necessary components.
 */
UCLASS()
class WEAPONFRAMEWORK_API AWF_FireArm : public AActor
{
	GENERATED_BODY()

public:
	AWF_FireArm();

#pragma region // Attributes
	/* These attributes effect how a fire arm behave, from firing rate, accuracy, and damage per bullet. */

	// How fast this firearm can fire. (bullet per minute)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	float FiringRate;
	// The Max angle of spread to simulate inaccuracy. (degree)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	float SpreadMaxAngle;

#pragma endregion // Attributes

#pragma region // Components
public:
	USkeletalMeshComponent* GetFireArmSkeletalMesh() const { return FireArmSkeletalMesh; }
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<USkeletalMeshComponent> FireArmSkeletalMesh;
	
#pragma endregion // Components
};
