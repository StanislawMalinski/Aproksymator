#include "points.h"
#include <stdlib.h>

static int
realloc_pts_failed (points_t * pts, int size)
{
	double *tmp_x = realloc(pts->x, size * sizeof *pts->x);
	double *tmp_y = realloc(pts->y, size * sizeof *pts->y);
	if(tmp_x == NULL)
	{
		free(pts->x);
		free(pts->y);
		return 1;
	}
	else if (tmp_y == NULL)
	{
		free(tmp_x);
		free(pts->x);
		free(pts->y);
		return 1;
	}
	else
	{
		pts->x = tmp_x;
		pts->y = tmp_y;
		return 0;
	}
}

int
read_pts_failed (FILE * inf, points_t * pts)
{
  int size;
  double x, y;

  if (pts->n == 0) {
    pts->x = malloc (100 * sizeof *pts->x);
    if (pts->x == NULL)
      return 1;
    pts->y = malloc (100 * sizeof *pts->y);
    if (pts->y == NULL) {
      free (pts->x);
      return 1;
    }
    size = 100;
  }
  else
    size = pts->n;

  while (fscanf (inf, "%lf %lf", &x, &y) == 2) {
    pts->x[pts->n] = x;
    pts->y[pts->n] = y;
    pts->n++;
    if (!feof (inf) && pts->n == size) {
      if (realloc_pts_failed (pts, 2 * size))
        return 1;
      else
        size *= 2;
    }
  }

  if (pts->n != size)
    if (realloc_pts_failed (pts, pts->n))
      return 1;

  return 0;
}

void free_pts(points_t *pts)
{
	free(pts->x);
	free(pts->y);
}
