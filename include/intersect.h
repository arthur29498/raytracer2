/*
** intersect.h for raytracer in /home/arthur/delivery/raytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Mar 18 11:07:48 2017 Arthur Philippe
** Last update Sat May 27 15:56:29 2017 HexA
*/

#ifndef INTERSECT_H_
# define INTERSECT_H_

# include "raytracer_structs.h"

typedef struct	s_tore_poly
{
  float		a;
  float		b;
  float		c;
  float		d;
  float		e;
}		t_tore_poly;

float	solve_quadric_eq(float discriminant, float a, float b);
float	solve_ltd_quadric_eq(sfVector3f abc,
			     sfVector3f eye_pos,
			     sfVector3f dir_vector,
			     t_object *object);
float	obj_fctn_tore(t_object *object,
		      t_render_in *in_arg);
#endif /* !INTERSECT_H_ */
