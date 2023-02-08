// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GridSpawner.h"
#include "BlueprintFuncLibTools.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM23_API UBlueprintFuncLibTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	bool _doesPathExists();
public:
	UFUNCTION(BlueprintCallable, Category = "SetUp")
	static bool doesPathExists(AGridSpawner* spawner);
};
