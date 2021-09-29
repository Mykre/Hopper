// © 2021, Matthew Barham. All rights reserved.


#include "Actors/HopperEnemy.h"

AHopperEnemy::AHopperEnemy()
{
	SquashPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Squash Point"));
	SquashPoint->SetupAttachment(RootComponent);
	SquashPoint->SetRelativeLocation(FVector(0.f, 0.f, 70.f));
}

bool AHopperEnemy::IsSquashingHit(const FVector InImpactPoint, const float ErrorTolerance) const
{
	if (InImpactPoint.Equals(SquashPoint->GetComponentLocation(), ErrorTolerance))
		return true;
	else
		return false;
}
