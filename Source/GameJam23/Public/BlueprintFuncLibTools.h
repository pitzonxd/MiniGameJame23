// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFuncLibTools.generated.h"

class ASocketBase;

UCLASS()
class GAMEJAM23_API UBlueprintFuncLibTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	bool _doesPathExists();
public:
	static bool doesPathExists(TArray<TArray<ASocketBase*>> socketGrid);
};
