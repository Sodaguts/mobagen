#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
    int neighborCount = 0;
    for(int y = 0; y <= world.SideSize(); y++)
    {
        for(int x = 0; x <= world.SideSize(); x++)
        {
            Point2D currentPoint = Point2D(x,y);
            if(world.Get(currentPoint) == true)
            {
                neighborCount = CountNeighbors(world, currentPoint);
                if(neighborCount <= 0)
                {
                    //die
                    world.SetNext(currentPoint, false);
                }
                else if(neighborCount >= 4)
                {
                    //die
                    world.SetNext(currentPoint, false);
                }
                else if(neighborCount == 2 || neighborCount == 3)
                {
                    //survive
                    world.SetNext(currentPoint, true);
                }
                else
                {
                    world.SetNext(currentPoint, false);
                }
            }
            else if(world.Get(currentPoint) == false)
            {
                neighborCount = CountNeighbors(world, currentPoint);
                if(neighborCount == 3)
                {
                    world.SetNext(currentPoint, true);
                }
                else
                {
                    world.SetNext(currentPoint, false);
                }
            }
        }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
    int numNeighbors = world.Get(point.Up()) + world.Get(point.Up().Left()) + world.Get(point.Up().Right()) + world.Get(point.Right()) + world.Get(point.Left()) + world.Get(point.Down()) + world.Get(point.Down().Left()) + world.Get(point.Down().Right());
    return numNeighbors;
}
