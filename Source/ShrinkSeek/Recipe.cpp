#include "Recipe.h"

URecipe::URecipe() {
  TotalIngredients = 5;
  CollectedIngredients = 0;

  UE_LOG(LogTemp, Warning, TEXT("Recipe Initialized!"));
}

void URecipe::AddIngredient(EIngredientType IngredientType) {
  CollectedIngredients++;
  UE_LOG(LogTemp, Warning, TEXT("Nombre d'ingrédients collectés : %d"),
         CollectedIngredients);
  UE_LOG(LogTemp, Warning, TEXT("Ingredient %s added to the recipe."),
         *UEnum::GetValueAsString(IngredientType));
  UE_LOG(LogTemp, Warning, TEXT("Ingredient missing: %d"),
         TotalIngredients - CollectedIngredients);
}

bool URecipe::IsRecipeComplete() const {
  return CollectedIngredients == TotalIngredients;
}
