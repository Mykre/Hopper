// © 2021, Matthew Barham. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/HopperAttackInterface.h"
#include "HopperGameMode.generated.h"

class AHopperBaseCharacter;
/**
 * 
 */
UCLASS()
class HOPPER_API AHopperGameMode : public AGameModeBase, public IHopperAttackInterface
{
	GENERATED_BODY()

public:
	/** IHopperAttackInferface Implementation */

	virtual void Attack(const FHopperAttack& Attack) override;

protected:
	static void DamageCharacter(TObjectPtr<AHopperBaseCharacter> CharacterToDamage, float Damage);
};
