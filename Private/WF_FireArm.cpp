// Copyright 2023 Nightails Games. All Right Reserved.


#include "WF_FireArm.h"


AWF_FireArm::AWF_FireArm()
{
	// Initializing variables
	FireArmType = EFireArmType::Pistol;
	FireArmMode = EFireArmMode::Single;
	FiringRate = 5.f;
	SpreadMaxAngle = 5.f;

	// Initializing components
	FireArmSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	
	// Disable tick at the moment, due to no usage.
	PrimaryActorTick.bCanEverTick = false;
}

