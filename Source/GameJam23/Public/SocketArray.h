// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketArray.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSocketArray
{
	GENERATED_BODY()

public:

	TArray<AActor*> SocketArr;

	AActor& operator[] (int32 index) {
		return *SocketArr[index];
	}

	void Add(AActor* socket) {
		SocketArr.Add(socket);
	}

	void RemoveAt(int32 index) {
		SocketArr.RemoveAt(index, 1, true);
	}
	FSocketArray();
	~FSocketArray();
};
