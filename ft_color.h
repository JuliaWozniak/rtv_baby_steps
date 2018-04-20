#ifndef FT_COLOR_H
# define FT_COLOR_H

typedef struct s_color
{
	int r;
	int g;
	int b;
}				t_color;

t_color init_clr(float r, float g, float b);
t_color add_clr(t_color a, t_color b);
t_color subtract_clr(t_color a, t_color b);
t_color mult_clr(t_color a, t_color b);
t_color mult_clr_f(t_color c, float factor);
t_color div_clr(t_color a, t_color b);
t_color div_clr_f(t_color c, float factor);

#endif