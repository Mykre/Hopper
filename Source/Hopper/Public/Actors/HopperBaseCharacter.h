// © 2021, Matthew Barham. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Core/HopperData.h"
#include "HopperBaseCharacter.generated.h"

/**
 * Base character class
 */
UCLASS()
class HOPPER_API AHopperBaseCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
	public:
	AHopperBaseCharacter();

	protected:
	/** Class Overrides */

	virtual void BeginPlay() override;
	virtual void OnJumped_Implementation() override;
	virtual void Landed(const FHitResult& Hit) override;

	/** Animation */

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Animate(float DeltaTime, FVector OldLocation, const FVector OldVelocity);
	virtual void SetCurrentAnimationDirection(const FVector& Velocity, TOptional<FMinimalViewInfo> ViewInfo);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	uint8 bIsMoving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	HopperAnimationDirection CurrentAnimationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	FHopperFlipbooks Flipbooks;
	
};
