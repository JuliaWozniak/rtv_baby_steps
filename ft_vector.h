#ifndef FT_VECTOR_H
# define FT_VECTOR_H

t_vector init_vec(float x, float y, float z);
t_vector assign_vec(t_vector old);
t_vector add_vec(t_vector a, t_vector b);
t_vector subtract_vec(t_vector a, t_vector b);
t_vector mult_vec(t_vector a, t_vector b);
t_vector mult_vec_f(t_vector c, float factor);
t_vector div_vec(t_vector a, t_vector b);
t_vector div_vec_f(t_vector c, float factor);
float vec_length(t_vector vec);
float vec_norm(t_vector v);

#endif