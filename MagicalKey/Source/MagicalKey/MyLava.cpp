// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLava.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>
#include "MyPlayerCharacter.h"

// Sets default values
AMyLava::AMyLava()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(20.0f, 20.0f, 20.0f));
	RootComponent = BoxCollision;

}

// Called when the game starts or when spawned
void AMyLava::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyLava::OnOverlapBegin);
	PlayerCharacter_Ref = Cast<AMyPlayerCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
}

// Called every frame
void AMyLava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyLava::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LoseScreen");
	}
}


