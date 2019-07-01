// Copyright by Jesse Finton 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class ARCHITECTURETUTORIAL_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//Components built in Blueprint------------

	UPROPERTY()
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	class UMotionControllerComponent* LeftMController;


	UPROPERTY(EditAnywhere)
	class UMotionControllerComponent* RightMController;

	UPROPERTY()
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	class USplineComponent* TeleportPath;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DestinationMarker;

	UPROPERTY()
	class UPostProcessComponent* PostProcessingComponent;

	UPROPERTY()
	class UMaterialInstanceDynamic* BlinkerMaterialInstance;

	UPROPERTY()
	TArray<class USplineMeshComponent*> TeleportPathMeshPool;


	bool FindTeleportDestination(TArray<FVector> &OutPath, FVector &OutLocation);
	void UpdateDestinationMarker();
	void UpdateBlinkers();
	void DrawTeleportPath(const TArray<FVector> &Path);
	void UpdateSpline(const TArray<FVector> &Path);
	FVector2D GetBlinkerCenter();

	void MoveForward(float throttle);
	void TurnRight(float throttle);
	void BeginTeleport();
	void EndTeleport();

	void StartFade(float FromAlpha, float ToAlpha);

private:

	//Varables-----------------

	UPROPERTY(EditAnywhere)
	float MaxTeleportDistance = 1000;

	UPROPERTY(EditAnywhere)
	float TeleportFadeTime = 0.5;

	UPROPERTY(EditAnywhere)
	float TeleportProjectileRadius = 10;

	UPROPERTY(EditAnywhere)
	float TeleportProjectileSpeed = 800;
	
	UPROPERTY(EditAnywhere)
	float TeleportSimTime = 2;
	
	UPROPERTY(EditAnywhere)
	FVector TeleportProjectionExtent = FVector(100, 100, 100);

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* BlinkerMaterialBase;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* RadiusVsVelocity;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh* TeleportArchMesh;
	
	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* TeleportArchMaterial;
};
