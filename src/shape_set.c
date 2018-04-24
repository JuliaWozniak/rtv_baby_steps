#include "../rtv.h"

int does_intersect(t_shape *cur_shape, t_point pos, t_intersect *i)
{
	float intersected_any;
	t_shape *cur;
	int intersected;

	cur = cur_shape;
	intersected_any = 0;
	while (cur != NULL)
	{
		if (cur->type == PLANE)
			intersected = inter_plane(pos, i, cur);
		if (cur->type == SPHERE)
			intersected = inter_sphere(pos, i, cur);
		if (cur->type == CONE)
			intersected = inter_cone(pos, i, cur);
		if (cur->type == CYLINDER)
			intersected = inter_cylinder(pos, i, cur);
		if (intersected == 1 && intersected_any == 0)
			intersected_any = 1;
		cur = cur->next;
	}
	return (intersected_any);
}