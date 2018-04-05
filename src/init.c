#include "../rtv.h"

t_glob	*init_glob(void)
{
	t_glob	*g;

	g = (t_glob *)ft_memalloc(sizeof(t_glob));
	g->m_p = mlx_init();
	g->w_p = mlx_new_window(g->m_p, WIDTH, HEIGHT, "rtv");
	g->img = create_image(g->m_p);
	return (g);
}