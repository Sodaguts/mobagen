#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();
  float maxMagnitude; //clamp so that accumulating forces don't get too high
  float separationRadius = boid->getDetectionRadius() / 2.0f; //radius in which boids will separate

  //    float desiredDistance = desiredMinimalDistance;
  //
  //    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
  //    if (!neighborhood.empty()) {
  //        Vector2f position = boid->transform.position;
  //        int countCloseFlockmates = 0;
  //        // todo: find and apply force only on the closest mates
  //    }
  Vector2f currentNeighborPos;
  int closeFlockmates = 0;
  Vector2f accumulatedForce;
  for(int i = 0; i < neighborhood.size(); i++)
  {
      currentNeighborPos = neighborhood[i]->getPosition();
      Vector2f directionToNeighbor = currentNeighborPos - boid->getPosition();
      float magnitudeToNeighbor = (directionToNeighbor.x * directionToNeighbor.x)+(directionToNeighbor.y * directionToNeighbor.y);
      if(magnitudeToNeighbor <= (separationRadius*separationRadius) && magnitudeToNeighbor > 0)
      {
          closeFlockmates++;
          //accumulatedForce += directionToNeighbor/(magnitudeToNeighbor*magnitudeToNeighbor);
      }
  }
  //get accumulated force from close flockmates

  //todo: apply forces based on closeFlockmates
  //similar to cohesion rule
  //if the magnitude of the agent->boid[i] <= radius and > 0
  //    apply a force of PaPi/|PaPi|^2
  // otherwise if |PaPi| = 0 or |PaPi| > radius
  //    apply a force of 0

  separatingForce = Vector2f::normalized(separatingForce);

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
