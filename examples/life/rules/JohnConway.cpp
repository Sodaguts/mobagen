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
            }
            else if(world.Get(currentPoint) == false)
            {
                neighborCount = CountNeighbors(world, currentPoint);
                if(neighborCount == 3)
                {
                    world.SetNext(currentPoint, true);
                }
            }
        }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
    int numNeighbors = 0;
    for(int y = -1; y <= 1; y++)
    {
        for(int x = -1; x <= 1; x++)
        {
            if(x != 0 && y !=0)
            {
                //check around the point
                if(world.Get(Point2D(point.x + x, point.y + y)))
                {
                    numNeighbors++;
                }
            }
        }
    }
    return numNeighbors;
}
