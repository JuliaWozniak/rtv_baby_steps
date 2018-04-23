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
	int ri;
	int gi;
	int bi;

	color = 0;
if (c.r != 0 || c.g != 0 || c.b != 0)
{
	// printf("first = ");
	// print_color(c);
	ri = ((int)(c.r * 255) & 0xff) << 16;
	gi = ((int)(c.g * 255) & 0xff) << 8;
	bi = ((int)(c.b * 255) & 0xff);
	color = ri + gi + bi;
	//printf("%i\n", color);

	// color = (((int)(c.r * 255) & 0xff) << 16) +
	// ((int)(c.g * 255) & 0xff << 8) +
	// ((int)(c.b * 255) & 0xff);
}
else
	return (0);
	// color = c.r;
	// color = color << 8;
	// color += c.g;
	// color = color << 8;
	// color += c.b;
	return (color);
}
