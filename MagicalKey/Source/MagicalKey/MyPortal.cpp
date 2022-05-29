// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPortal.h"

#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>

// Sets default values
AMyPortal::AMyPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Portal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Portal"));
	SM_Portal->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(10.0f, 10.0f, 20.0f));

	RootComponent = BoxCollision;
}

// Called when the game starts or when spawned
void AMyPortal::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyPortal::OnOverlapBegin);
	
}

// Called every frame
void AMyPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPortal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		//TODO:>>>Go to Win Screen
		printf("YOU WIN!!");
	}

}



