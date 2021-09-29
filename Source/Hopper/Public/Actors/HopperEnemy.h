// © 2021, Matthew Barham. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/HopperBaseCharacter.h"
#include "HopperEnemy.generated.h"

/**
 * 
 */
UCLASS()
class HOPPER_API AHopperEnemy : public AHopperBaseCharacter
{
	GENERATED_BODY()

public:
	AHopperEnemy();
protected:
	/**
	 * Detects whether the impacted point counts as a squashing hit on the enemy.
	 * i.e. A downward force counts as a squashing hit, whereas a bump to the side does not.
	 * @param InImpactPoint - The point of impact
	 * @param ErrorTolerance - The error tolerance for the detection, default = 50.f
	 * @return True if impact counts as a squash.
	 */
	UFUNCTION(BlueprintPure)
	bool IsSquashingHit(const FVector InImpactPoint, const float ErrorTolerance = 50.f) const;
	
	TObjectPtr<USceneComponent> SquashPoint;
};
