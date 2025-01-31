#include "Collectables.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"

URecipe *ACollectables::Recipe = nullptr;

ACollectables::ACollectables() {
  PrimaryActorTick.bCanEverTick = true;

  CollisionComponent =
      CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
  RootComponent = CollisionComponent;
  CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
  CollisionComponent->SetGenerateOverlapEvents(true);

  MeshComponent =
      CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
  MeshComponent->SetupAttachment(RootComponent);

  MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
  MeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
  MeshComponent->SetCollisionResponseToAllChannels(
      ECollisionResponse::ECR_Block);

  CollisionComponent->OnComponentBeginOverlap.AddDynamic(
      this, &ACollectables::OnOverlapBegin);

  IngredientType = EIngredientType::None;
  IsCollected = false;
}

void ACollectables::BeginPlay() { Super::BeginPlay(); }

void ACollectables::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACollectables::OnOverlapBegin(UPrimitiveComponent *OverlappedComp,
                                   AActor *OtherActor,
                                   UPrimitiveComponent *OtherComp,
                                   int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult &SweepResult) {

  UE_LOG(LogTemp, Warning, TEXT("Recipe Instance Address: %p"), Recipe);
  if (OtherActor && OtherActor->ActorHasTag(TEXT("Player")) &&
      MeshComponent->IsVisible()) {
    if (Recipe) {
      if (Recipe && IngredientType != EIngredientType::None) {

        Recipe->AddIngredient(IngredientType);
        IsCollected = true;

        MeshComponent->SetVisibility(false, true);
        MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
      }
    }
  }
}

void ACollectables::InitializeSharedRecipe(URecipe *SharedRecipe) {
  Recipe = SharedRecipe;
}