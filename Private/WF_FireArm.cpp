// Copyright 2023 Nightails Games. All Right Reserved.


#include "WF_FireArm.h"


AWF_FireArm::AWF_FireArm()
{
	FiringRate = 5.f;
	SpreadMaxAngle = 5.f;
	
	// Disable tick at the moment, due to no usage.
	PrimaryActorTick.bCanEverTick = false;
}

