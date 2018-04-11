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
	float color;
	int col;

	color = c.r * 255;
	color = color * 255;
	color += c.g * 255;
	color = color * 255;
	color += c.b * 255;
	color += 0.5;
	col = (int)color;
	return (col);
}
