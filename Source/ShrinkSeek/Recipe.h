#pragma once

#include "CoreMinimal.h"
#include "Recipe.generated.h"

UENUM(BlueprintType)
enum class EIngredientType : uint8 {
  None UMETA(DisplayName = "None"),
  Flour UMETA(DisplayName = "Flour"),
  Sugar UMETA(DisplayName = "Sugar"),
  Chocolate UMETA(DisplayName = "Chocolate"),
  Egg UMETA(DisplayName = "Egg"),
  Milk UMETA(DisplayName = "Milk")
};

UCLASS(Blueprintable)
class SHRINKSEEK_API URecipe : public UObject {
  GENERATED_BODY()

public:
  URecipe();

  void AddIngredient(EIngredientType IngredientType);

  UFUNCTION(BlueprintCallable, Category = "Recipe")
  bool IsRecipeComplete() const;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Recipe")
  int32 CollectedIngredients;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Recipe")
  int32 TotalIngredients;
};
