#include "../rtv.h"

int does_intersect(t_shape *cur_shape, t_point pos, t_intersect *i)
{
	float intersected_any;

	intersected_any = 0;
	while (cur_shape != NULL)
	{
		// if (cur_shape->type == PLANE)
		// 	intersected_any = inter_plane(pos, i, cur_shape);
		if (cur_shape->type == SPHERE)
			intersected_any = inter_sphere(pos, i, cur_shape);
		// if (i->shape == NULL)
		// 	printf("interesting\n");
		// if (cur_shape->type == CONE)
		// 	intersected_any = inter_cone(pos, i, cur_shape);
		// if (cur_shape->type == CYLINDER)
		// 	intersected_any = inter_cylinder(pos, i, cur_shape);
		cur_shape = cur_shape->next;
	}
	return (intersected_any);
}