#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood
  Vector2f totalNeighborPosition;
  for(int i = 0; i < neighborhood.size(); i++)
  {
      totalNeighborPosition += neighborhood[i]->getPosition();
  }
  Vector2f centerMassPosition = totalNeighborPosition / neighborhood.size();
  Vector2f directionToCenterMass =  centerMassPosition - boid->getPosition();
  float magnitudeToCenterMass = sqrt((directionToCenterMass.x * directionToCenterMass.x) + (directionToCenterMass.y*directionToCenterMass.y));

  if(magnitudeToCenterMass <= boid->getDetectionRadius())
  {
      cohesionForce = directionToCenterMass;
  }
  else if(magnitudeToCenterMass > boid->getDetectionRadius())
  {
      cohesionForce = Vector2f::zero();
  }

  return cohesionForce.normalized();
}