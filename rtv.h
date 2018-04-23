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


# define MAX_DIST 100000
# define WIDTH 500
# define HEIGHT 500
# define FOV 2.0

# define PLANE 1
# define SPHERE 2
# define CONE 3
# define CYLINDER 4

typedef struct s_shape t_shape;

typedef struct s_intersect
{
	float dist;
	t_shape *shape;
	t_color color;
	t_vector ray_dir;
	t_vector v_dist;
}				t_intersect;

typedef struct s_shape
{
	t_shape *next;
	int type;
	t_point pos;
	t_color color;
	t_vector dir;
	int size;
}				t_shape;

typedef struct	s_img
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		strd;
	int		endn;
}				t_img;

typedef struct s_plane
{
	t_point position;
	t_vector normal;
	t_color color;
}				t_plane;

typedef struct s_coord
{
	int x;
	int y;
	float xu;
	float yu;
}				t_coord;

typedef struct s_glob
{
	void *m_p;
	void *w_p;
	t_img	*img;
	t_shape *shape_set;
	t_shape *lights;
	t_coord c;
	t_vector cam_dir;
	t_point cam_pos;
}				t_glob;


void	set_pixel(t_img *img, int x, int y, int color);
void	clear_image(t_glob *g);
t_img	*create_image(void *mlx);
t_glob	*init_glob(void);
int inter_plane(t_point pos, t_intersect *i, t_shape *shape);
int does_intersect(t_shape *cur_shape, t_point cam_pos, t_intersect *i);
void * new_plane(t_point position, t_vector normal, t_color color);
t_intersect *intersection(t_vector ray);
t_intersect default_intersection(void);
int make_int_clr(t_color c);
void print_vector(t_vector v);
void print_ray(t_ray r);
void print_intersection(t_intersect i);
void print_color(t_color clr);
int inter_sphere(t_point pos, t_intersect *i, t_shape *shape);
int inter_cone(t_point pos, t_intersect *i, t_shape *shape);
int inter_cylinder(t_point pos, t_intersect *i, t_shape *shape);

#endif 