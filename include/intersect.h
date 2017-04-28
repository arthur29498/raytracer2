/*
** intersect.h for raytracer in /home/arthur/delivery/raytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Mar 18 11:07:48 2017 Arthur Philippe
** Last update Fri Apr 28 14:27:23 2017 mael drapier
*/

#ifndef INTERSECT_H_
# define INTERSECT_H_

# include "raytracer_structs.h"

float	solve_quadric_eq(float discriminant, float a, float b);
float	solve_ltd_quadric_eq(sfVector3f abc,
			     sfVector3f eye_pos,
			     sfVector3f dir_vector,
			     t_object *object);

#endif /* !INTERSECT_H_ */
