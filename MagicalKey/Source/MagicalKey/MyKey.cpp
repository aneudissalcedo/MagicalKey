// Fill out your copyright notice in the Description page of Project Settings.


#include "MyKey.h"

#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "MyPlayerCharacter.h"

// Sets default values
AMyKey::AMyKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Key = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Key"));
	SM_Key->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(5.0f, 5.0f, 5.0f));

	RootComponent = BoxCollision;

}

// Called when the game starts or when spawned
void AMyKey::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyKey::OnOverlapBegin);
	
}

// Called every frame
void AMyKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyKey::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		AMyPlayerCharacter* MyPlayerCharacter = Cast<AMyPlayerCharacter>(OtherActor);

		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyKey::DestroyKey, 0.1f, false);
	}
}

void AMyKey::DestroyKey()
{
	this->Destroy();
}



