// Copyright 2024 by Nightails Games. All Right Reserved.


#include "WF_WeaponComponent.h"
#include "WF_WeaponConfigData.h"


// Sets default values for this component's properties
UWF_WeaponComponent::UWF_WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	MaxAvailableWeaponConfig = 3;
	ActiveWeaponIndex = 0;

	AttachSocketName = "";
	WeaponMeshComponent = nullptr;
}


// Called when the game starts
void UWF_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UWF_WeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWF_WeaponComponent::SetupWeaponForCharacter(USceneComponent* CharacterHandMesh)
{
	// Create a skeletal mesh component to display the weapon mesh, if none is created already.
	if (!WeaponMeshComponent)
	{
		const FTransform AttachTransform;
		WeaponMeshComponent = Cast<USkeletalMeshComponent>(GetOwner()->AddComponentByClass(USkeletalMeshComponent::StaticClass(), false, AttachTransform, false));
		WeaponMeshComponent->AttachToComponent(CharacterHandMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, AttachSocketName);
	}

	// Set the weapon skeletal mesh and animation instance.
	if (WeaponMeshComponent && AvailableWeaponConfigs.Num() > 0)
	{
		WeaponMeshComponent->SetSkeletalMesh(AvailableWeaponConfigs[ActiveWeaponIndex]->GetWeaponSkeletalMesh());
		WeaponMeshComponent->SetAnimInstanceClass(AvailableWeaponConfigs[ActiveWeaponIndex]->GetWeaponAnimInstanceClass());
	}
}

