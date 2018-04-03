#include "../rtv.h"

t_color init_color(float r, float g, float b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color assign_color(t_color old)
{
	t_color new;

	new.r = old.r;
	new.g = old.g;
	new.b = old.b;
	return (new);
}

t_color add_colors(t_color a, t_color b)
{
	t_color res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_color subtract_color(t_color a, t_color b)
{
	t_color res;

	res.r = a.r - b.r;
	res.g = a.g - b.g;
	res.b = a.b - b.b;
	return (res);
}

t_color mult_colors(t_color a, t_color b)
{
	t_color res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	return (res);
}

t_color mult_col_f(t_color c, float factor)
{
	t_color res;

	res.r = c.r * factor;
	res.g = c.g * factor;
	res.b = c.b * factor;
	return (res);
}

t_color div_colors(t_color a, t_color b)
{
	t_color res;

	res.r = a.r / b.r;
	res.g = a.g / b.g;
	res.b = a.b / b.b;
	return (res);
}

t_color div_col_f(t_color c, float factor)
{
	t_color res;

	res.r = c.r / factor;
	res.g = c.g / factor;
	res.b = c.b / factor;
	return (res);
}

