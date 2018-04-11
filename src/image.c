#include "../rtv.h"
void	set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIDTH) * 4)) = color;
}

void	clear_image(t_glob *g)
{
	int size;

	size = WIDTH * HEIGHT * 4;
	ft_bzero(g->img->ptr, size);
}

t_img	*create_image(void *mlx)
{
	t_img *img;

	img = (t_img *)ft_memalloc(sizeof(t_img));
	img->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd, &img->endn);
	return (img);
}
