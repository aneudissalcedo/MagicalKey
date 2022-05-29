// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlatform.h"

#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>

// Sets default values
AMyPlatform::AMyPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Platform"));
	RootComponent = SM_Platform;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

