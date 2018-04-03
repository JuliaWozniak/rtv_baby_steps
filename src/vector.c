#include "../rtv.h"

t_vector init_vec(float x, float y, float z)
{
	t_vector new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector assign_vec(t_vector old)
{
	t_vector new;

	new.x = old.x;
	new.y = old.y;
	new.z = old.z;
	return (new);
}

t_vector add_vec(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x + b.x;
	res.g = a.y + b.y;
	res.b = a.z + b.z;
	return (res);
}

t_vector subtract_vec(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector mult_vec(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vector mult_vec_f(t_vector c, float factor)
{
	t_vector res;

	res.x = c.x * factor;
	res.g = c.y * factor;
	res.b = c.z * factor;
	return (res);
}

t_vector div_vec(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}

t_vector div_vec_f(t_vector c, float factor)
{
	t_vector res;

	res.x = c.x / factor;
	res.y = c.y / factor;
	res.z = c.z / factor;
	return (res);
}

float vec_length(t_vector vec)
{
	float squared;

	squared = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	return (sqrt(squared));
}

float vec_norm(t_vector v)
{
	t_vector res;
	float len;

	len = vec_length(v);
	res.x = v.x /len;
	res.y = v.y / len;
	res.z = v.z / len;
	return (res);
}

float vec_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}






