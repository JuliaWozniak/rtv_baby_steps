#ifndef RTV_H
# define RTV_H

#include "./minilibx_macos/mlx.h"
#include "./libft/includes/libft.h"
#include <math.h>
#include <unistd.h>
#include "ft_color.h"
#include "ft_vector.h"
#include "ray.h"


#include <stdio.h> // delete me

#ifndef M_PI
    #define M_PI 3.14159265358979
#endif
# define K_RAY_MIN 0.00001f
# define WIDTH 5
# define HEIGHT 5

# define PLANE 1 

typedef struct s_shape t_shape;

typedef struct s_intersect
{
	t_ray ray;
	float t;
	t_shape *shape;
	t_color color;
	t_vector normal;
}				t_intersect;

typedef struct s_shape
{
	void *data;
	t_shape *next;
	int type;
	int (*intersect)(t_intersect, void *);
}				t_shape;

typedef struct	s_img
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		strd;
	int		endn;
	int		width;
	int		height;
}				t_img;

typedef struct s_plane
{
	t_point position;
	t_vector normal;
	t_color color;
}				t_plane;

typedef struct s_glob
{
	void *m_p;
	void *w_p;
	t_img	*img;
	t_shape *shape_set;
}				t_glob;


void	set_pixel(t_img *img, int x, int y, int color);
void	clear_image(t_glob *g);
t_img	*create_image(void *mlx);
t_glob	*init_glob(void);
int inter_plane(t_intersect *inter, void *data);
int does_intersect(t_intersect i, t_shape *shape);
t_plane new_plane(t_point position, t_vector normal, t_color color);
t_shape *new_shape(int type, void *data);


#endif 