#ifndef FT_COLOR_H
# define FT_COLOR_H

t_color init_color(float r, float g, float b);
t_color assign_color(t_color old);
t_color add_colors(t_color a, t_color b);
t_color subtract_color(t_color a, t_color b);
t_color mult_colors(t_color a, t_color b);
t_color mult_col_f(t_color c, float factor);
t_color div_colors(t_color a, t_color b);
t_color div_col_f(t_color c, float factor);

#endif