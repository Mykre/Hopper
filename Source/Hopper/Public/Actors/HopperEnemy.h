// © 2021, Matthew Barham. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/HopperBaseCharacter.h"
#include "HopperEnemy.generated.h"

/**
 * Hopper Enemy class w/ Squash functions
 */
UCLASS()
class HOPPER_API AHopperEnemy : public AHopperBaseCharacter
{
	GENERATED_BODY()

public:
	AHopperEnemy();

	/**
	 * Called by the Squash function.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnSquashed();

protected:
	/**
	 * Detects whether the impacted point counts as a squashing hit on the enemy.
	 * i.e. A downward force counts as a squashing hit, whereas a bump to the side does not.
	 * @param InImpactPoint The point of impact
	 * @param ErrorTolerance The error tolerance for detection, default = 50.f
	 * @return True if impact counts as a squash.
	 */
	UFUNCTION(BlueprintPure)
	bool IsSquashingHit(const FVector InImpactPoint, const float ErrorTolerance = 50.f) const;

	/**
	 * Compresses the sprite and shifts it downward to make the character appear "squashed"
	 * then sets a timer and calls Event OnSquashed after the provided time runs out.
	 * @param TimeTillDestroy Time to hold the squashed state before destroying the actor.
	 */
	UFUNCTION(BlueprintCallable)
	void Squash(const float TimeTillDestroy = 1.f);
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USceneComponent> SquashPoint;
	
	FTimerHandle DeathHandle;
};
