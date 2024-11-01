#include <stdio.h>
#include <inttypes.h>
#include <math.h>

struct point {
  int coordinates[3];
  struct point *next;
};

struct path {
  double distance;
  struct point *points;
};

void calculate_path_distance(struct path *path);

void calculate_path_distance(struct path *path)
{
    double d = 0;
    while (path->points->next!=NULL)
    {
        d += sqrt(pow(path->points->coordinates[0]-path->points->next->coordinates[0], 2) + pow(path->points->coordinates[1]-path->points->next->coordinates[1], 2) + pow(path->points->coordinates[2]-path->points->next->coordinates[2], 2));
        path->points = path->points->next;
    }
    path->distance = d;    
}

