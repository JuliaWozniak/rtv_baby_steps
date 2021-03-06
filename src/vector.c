#include "../rtv.h"

t_vector subtract_vec(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector scale_vec(t_vector c, float factor)
{
	t_vector res;

	res.x = c.x * factor;
	res.y = c.y * factor;
	res.z = c.z * factor;
	return (res);
}

float vec_length(t_vector vec)
{
	float squared;

	squared = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	return (sqrt(squared));
}

t_vector vec_norm(t_vector v)
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

t_vector vec_cross(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}




