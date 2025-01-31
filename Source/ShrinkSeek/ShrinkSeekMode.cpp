// Fill out your copyright notice in the Description page of Project Settings.

#include "ShrinkSeekMode.h"
#include "Collectables.h"
#include "Recipe.h"

AShrinkSeekMode::AShrinkSeekMode() {}

void AShrinkSeekMode::BeginPlay() {
  Super::BeginPlay();

  URecipe *SharedRecipe = NewObject<URecipe>(this, URecipe::StaticClass());
  SharedRecipe->CollectedIngredients = 0;
  SharedRecipe->TotalIngredients = 5;

  ACollectables::InitializeSharedRecipe(SharedRecipe);

  UE_LOG(LogTemp, Warning, TEXT("Recipe initialized : %p"), SharedRecipe);
}

URecipe *AShrinkSeekMode::GetSharedRecipe() const {
  if (ACollectables::Recipe) {
    return ACollectables::Recipe;
  }

  UE_LOG(LogTemp, Warning, TEXT("Shared Recipe is not initialized!"));
  return nullptr;
}
