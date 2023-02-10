// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector2D.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SocketBase.generated.h"

class UCPPGameInstance;
class ARoom;

UCLASS()
class GAMEJAM23_API ASocketBase : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASocketBase();

	//Adding static meshes to the SocketBase
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Border1;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Border2;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Border3;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Border4;

	bool bIsVisited = false;
	FVector2D socketIndex = {0.0f, 0.0f};
	UCPPGameInstance* gameInstance = nullptr;
	ARoom* placedRoom = nullptr;
	ARoom* hoverRoom = nullptr;

	void Initialize(double X, double Y);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void NotifyActorOnClicked(FKey ButtonPressed) override;
	void NotifyActorBeginCursorOver() override;
	void NotifyActorEndCursorOver() override;

};
