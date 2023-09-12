#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  int countFlock = 0;
  Vector2f accumulatedForce = Vector2f::zero();
  if(!neighborhood.empty())
  {
      for(int i = 0; i < neighborhood.size(); i++){
          Vector2f differenceVector =   boid->getPosition()- neighborhood[i]->getPosition();
          auto distance = differenceVector.getMagnitude();

          if(distance < desiredMinimalDistance)
          {
              countFlock++;
              Vector2f hat = differenceVector.normalized();
              Vector2f Force = hat/(distance/desiredMinimalDistance);//todo: check if we need this division
              accumulatedForce += Force;
          }
      }
      if(countFlock != 0)
      {
          accumulatedForce /= countFlock;
      }

  }

  return accumulatedForce.normalized();
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
