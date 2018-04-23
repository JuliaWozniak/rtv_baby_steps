#include "../rtv.h"

int does_intersect(t_shape *cur_shape, t_point pos, t_intersect *i)
{
	float intersected_any;
	t_shape *cur;

	cur = cur_shape;
	intersected_any = 0;
	while (cur != NULL)
	{
		if (cur->type == PLANE)
			intersected_any = inter_plane(pos, i, cur);
		if (cur->type == SPHERE)
			intersected_any = inter_sphere(pos, i, cur);
		if (cur->type == CONE)
			intersected_any = inter_cone(pos, i, cur);
		if (cur->type == CYLINDER)
			intersected_any = inter_cylinder(pos, i, cur);
		cur = cur->next;
	}
	return (intersected_any);
}