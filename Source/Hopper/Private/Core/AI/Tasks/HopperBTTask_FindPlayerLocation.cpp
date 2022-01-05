// © 2021, Matthew Barham. All rights reserved.


#include "Core/AI/Tasks/HopperBTTask_FindPlayerLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Core/Hopper.h"
#include "Perception/AIPerceptionComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Sight.h"

UHopperBTTask_FindPlayerLocation::UHopperBTTask_FindPlayerLocation()
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UHopperBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* OwnerPawn = AIController->GetPawn();
	FVector PlayerLocation{};

	TArray<AActor*> ActorsArray;
	UGameplayStatics::GetAllActorsWithTag(this, "Player", ActorsArray);
	for (AActor*& Actor : ActorsArray)
	{
		for (auto It{AIController->GetPerceptionComponent()->GetPerceptualDataConstIterator()}; It; ++It)
		{
			const FActorPerceptionInfo& ActorPerceptionInfo = It.Value();
			const AActor* Target = ActorPerceptionInfo.Target.Get();
			if (Target)
			{
				for (const FAIStimulus& Stimulus : ActorPerceptionInfo.LastSensedStimuli)
				{
					const UAISenseConfig* SenseConfig = AIController->GetPerceptionComponent()->GetSenseConfig(
						Stimulus.Type);
					if (Stimulus.IsValid() && !Stimulus.IsExpired() && SenseConfig)
					{
						const UAISenseConfig_Sight* SightConfig = Cast<UAISenseConfig_Sight>(SenseConfig);
						if (SightConfig && Actor->GetDistanceTo(OwnerPawn) <= SightConfig->SightRadius)
						{
							PlayerLocation = Actor->GetActorLocation();
						}
					}
				}
			}
		}
	}

	if (SearchRandom)
	{
		FNavLocation Location;
		const UNavigationSystemV1* NavSystem{UNavigationSystemV1::GetCurrent(GetWorld())};
		if (NavSystem && NavSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, Location, nullptr))
		{
			AIController->GetBlackboardComponent()->SetValueAsVector(*BlackboardKey.SelectedKeyName.ToString(),
			                                                         Location.Location);
		}
	}
	else
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(*BlackboardKey.SelectedKeyName.ToString(),
		                                                         PlayerLocation);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UHopperBTTask_FindPlayerLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Location: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
