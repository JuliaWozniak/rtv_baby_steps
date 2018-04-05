#include "../rtv.h"

t_shape *new_shape(int type, void *data)
{
	t_shape *new;

	new = (t_shape *)ft_memalloc(sizeof(t_shape));
	new->data = data;
	new->type = type;
	// if (type == PLANE)
	// 	new->intersect = &inter_plane;
	// else
		new->intersect = NULL;
	return (new);
}