// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	
	// move platform
	if(FVector::Distance(GetActorLocation(),startLocation)>moveDistance){
		startLocation += moveDistance*velocity.GetSafeNormal();
		velocity = -velocity;
		SetActorLocation(startLocation);
	}
	else{
		FVector currentLocation = GetActorLocation();
		currentLocation += DeltaTime*velocity;
		SetActorLocation(currentLocation);
	}
	// rotate platform
	AddActorLocalRotation(rotationVelocity*DeltaTime);
}

