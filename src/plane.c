#include "../rtv.h"

void *new_plane(t_point position, t_vector normal, t_color color)
{
	t_plane *new;

	new = (t_plane *)ft_memalloc(sizeof(t_plane));
	new->position = position;
	new->normal = vec_norm(normal);
	new->color = color;
	return ((void *)new);
}
