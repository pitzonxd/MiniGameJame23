// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Math/Vector2D.h"
#include "CPPGameInstance.generated.h"

class ARoom;
class ASocketBase;

UCLASS()
class GAMEJAM23_API UCPPGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	bool destructionMode = false;

	TArray<TArray<ASocketBase*>> socketGrid;
	FVector2D startIndex;
	FVector2D endIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool pathExists = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ARoom> selectedRoom;
};
