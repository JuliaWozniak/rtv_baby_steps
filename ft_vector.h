#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct s_vector
{
	float x;
	float y;
	float z;
}				t_vector;

typedef t_vector t_point;

t_vector init_vec(float x, float y, float z);
t_vector add_vec(t_vector a, t_vector b);
t_vector subtract_vec(t_vector a, t_vector b);
t_vector mult_vec(t_vector a, t_vector b);
t_vector mult_vec_f(t_vector c, float factor);
t_vector div_vec(t_vector a, t_vector b);
t_vector div_vec_f(t_vector c, float factor);
float vec_length(t_vector vec);
t_vector vec_norm(t_vector v);
float vec_dot(t_vector a, t_vector b);
t_vector vec_cross(t_vector a, t_vector b);

#endif