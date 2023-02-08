// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SocketArray.h"
#include "SocketBase.h"
#include "GameFramework/Actor.h"
#include "GridSpawner.generated.h"

UCLASS(BlueprintType)
class GAMEJAM23_API AGridSpawner : public AActor
{
	GENERATED_BODY()

public:
	TArray<TArray<ASocketBase*>> socketGrid;
	// Sets default values for this actor's properties
	AGridSpawner();
	~AGridSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int32 RowNumber;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int32 ColumnNumber;
};
