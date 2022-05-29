// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlatform.generated.h"

class UBoxComponent;

using namespace UP;
using namespace UF;

UCLASS()
class MAGICALKEY_API AMyPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Platform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
