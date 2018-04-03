#ifndef RTV_H
# define RTV_H

#include "./minilibx_macos/mlx.h"
#include "./libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_color.h"
#include "ft_vector.h"

#ifndef M_PI
    #define M_PI 3.14159265358979
#endif

typedef struct s_color
{
	float r;
	float g;
	float b;
}				t_color;

typedef struct s_vector
{
	float x;
	float y;
	float z;
}				t_vector;

#endif 