// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPortal.h"

#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>

#include "MyPlayerCharacter.h"

// Sets default values
AMyPortal::AMyPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AMyPortal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	AMyPlayerCharacter* MyPlayerCharacter = Cast<AMyPlayerCharacter>(OtherActor);

	if (OtherActor->ActorHasTag("Player") && MyPlayerCharacter->ObtainedKey == true)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "WinScreen");
	}

}



