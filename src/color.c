#include "../rtv.h"

t_color init_clr(float r, float g, float b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color add_clr(t_color a, t_color b)
{
	t_color res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_color sub_clr(t_color a, t_color b)
{
	t_color res;

	res.r = a.r - b.r;
	res.g = a.g - b.g;
	res.b = a.b - b.b;
	return (res);
}

t_color mult_clr(t_color a, t_color b)
{
	t_color res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	return (res);
}

t_color mult_clr_f(t_color c, float factor)
{
	t_color res;

	res.r = c.r * factor;
	res.g = c.g * factor;
	res.b = c.b * factor;
	return (res);
}

t_color div_clr(t_color a, t_color b)
{
	t_color res;

	res.r = a.r / b.r;
	res.g = a.g / b.g;
	res.b = a.b / b.b;
	return (res);
}

t_color div_clr_f(t_color c, float factor)
{
	t_color res;

	res.r = c.r / factor;
	res.g = c.g / factor;
	res.b = c.b / factor;
	return (res);
}




int make_int_clr(t_color c)
{
	int color;

	color = c.r;
	color = color << 8;
	color += c.g;
	color = color << 8;
	color += c.b;
	return (color);
}
