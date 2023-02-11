// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Vector2D.h"
#include "BlueprintFuncLibTools.generated.h"

class ASocketBase;
class UCPPGameInstance;

struct arrStruct {
	bool visited = false;
	int step = -1;
};

UCLASS()
class GAMEJAM23_API UBlueprintFuncLibTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	static bool _doesPathExists(TArray<TArray<arrStruct>> socketArray, TArray<FVector2D> neighbors, FVector2D endIndex);
	static TArray<FVector2D> getValidNeighbors(TArray<TArray<arrStruct>> socketArray, FVector2D thisIndex);
public:
	static bool doesPathExists(UCPPGameInstance* gameInstance);
};
