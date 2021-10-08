// © 2021, Matthew Barham. All rights reserved.


#include "Core/HopperGameMode.h"

#include "Actors/HopperBaseCharacter.h"

void AHopperGameMode::Attack(const FHopperAttack& Attack)
{
	switch (Attack.AttackType)
	{
		float Damage;
	case HopperAttackType::Melee:
		Damage = Attack.Target->GetMaxHealth() / 3;
		DamageCharacter(Attack.Target, Damage);
		break;
	default:
		break;
	}
}

void AHopperGameMode::DamageCharacter(const TObjectPtr<AHopperBaseCharacter> CharacterToDamage, const float Damage)
{
	if (CharacterToDamage)
	{
		CharacterToDamage->DamageHealth(Damage);
	}
}
