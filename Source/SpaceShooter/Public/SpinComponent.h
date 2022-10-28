// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpinComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACESHOOTER_API USpinComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpinComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings") //exposing the variable to the editor for read and write under the category settings
	FRotator Spin; //the rotation of the actor that the component will be attached to

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FVector Elevation; //vector made visible in the editor to manipulate elevation of actor

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float ElevationSpeed; //speed at which the elevation will happen, when it goes up and down

private:
	FVector StartLocation; //vector that will use to get the location of the actor that its attached to
};
