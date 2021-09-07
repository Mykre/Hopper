// © 2021, Matthew Barham. All rights reserved.

#pragma once

#include "HopperData.generated.h"

class UPaperFlipbook;

UENUM(BlueprintType)
enum class HopperAnimationDirection : uint8
{
	Down,
	Up,
	Right,
	Left,
	DownRight,
	DownLeft,
	UpRight,
	UpLeft
};

USTRUCT(BlueprintType)
struct FHopperFlipbooks
{
	GENERATED_BODY()

	// Idle

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleDownRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleDownLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleUpRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> IdleUpLeft;

	// Walking

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkDownRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkDownLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkUpRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> WalkUpLeft;
};
