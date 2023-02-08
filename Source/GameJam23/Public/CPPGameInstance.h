// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Room.h"
#include "CPPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM23_API UCPPGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool pathExists = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ARoom> selectedRoom;
};
