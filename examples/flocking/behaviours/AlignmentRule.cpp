#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();
  float alignmentRadius = boid->getDetectionRadius();

  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood
  int numNeighbors = 0;
  Vector2f totalVelocity = Vector2f::zero();
  for(int i = 0; i < neighborhood.size(); i++)
  {
      //find boids within the alignment radius
      Vector2f difference =  neighborhood[i]->getPosition() - boid->getPosition();
      auto distance = difference.getMagnitude();
      if(distance <= alignmentRadius)
      {
          numNeighbors++;
          totalVelocity += neighborhood[i]->getVelocity();
      }

  }
  //compute average velocity of the group
  Vector2f newVelocity = Vector2f::zero();
  if(numNeighbors != 0)
  {
      averageVelocity = totalVelocity / numNeighbors;
      newVelocity = (1/averageVelocity.getMagnitude()) * boid->getPosition();
  }
  //compute force that will move the agent towards the average velocity

  return Vector2f::normalized(newVelocity);
}