// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Collectables.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Recipe.h"
#include "ShrinkSeekMode.generated.h"

UCLASS()
class SHRINKSEEK_API AShrinkSeekMode : public AGameModeBase {
  GENERATED_BODY()

public:
  AShrinkSeekMode();

  UFUNCTION(BlueprintCallable, Category = "ShrinkSeekMode")
  URecipe *GetSharedRecipe() const;

protected:
  virtual void BeginPlay() override;
};
