#pragma once
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Recipe.h"

#include "Collectables.generated.h"

UCLASS()
class SHRINKSEEK_API ACollectables : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ACollectables();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectables")
  UStaticMeshComponent *MeshComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectables")
  UBoxComponent *CollisionComponent;

  UFUNCTION()
  void OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor,
                      UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,
                      bool bFromSweep, const FHitResult &SweepResult);

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectables")
  EIngredientType IngredientType;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectables")
  bool IsCollected;

  static URecipe *Recipe;

  static void InitializeSharedRecipe(URecipe *SharedRecipe);
};