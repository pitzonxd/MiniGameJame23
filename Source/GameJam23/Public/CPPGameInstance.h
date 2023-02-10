// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool pathExists = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ARoom> selectedRoom;
};
