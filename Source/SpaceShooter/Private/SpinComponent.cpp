// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinComponent.h"

// Sets default values for this component's properties
USpinComponent::USpinComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpinComponent::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation(); // the start location is equal to the location of the actor the component is attached to

	// ...
	
}


// Called every frame
void USpinComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOwner()->AddActorWorldRotation(Spin * DeltaTime); //add spin to the world rotation for this actor and multiply by delta time, so it's frame-rate independent

	float Time = GetWorld()->GetRealTimeSeconds(); //getting world time and assigning it to the float variable Time
	
	float Sine = FMath::Sin(Time * ElevationSpeed); //using Sin function from the FMath library of Unreal, to make elevation system work
	
	GetOwner()->SetActorLocation(StartLocation + (Elevation * Sine)); //setting the actor location, and adding the elevetion on the tick, so it keeps going up and down

	// ...
}

