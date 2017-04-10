/*
** rotate.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 19:51:13 2017 Arthur Philippe
** Last update Sun Mar 19 14:39:14 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

static inline sfVector3f	rotate_angle_converter(sfVector3f angles)
{
  angles.x = angles.x * (PI / 180);
  angles.y = angles.y * (PI / 180);
  angles.z = angles.z * (PI / 180);
  return (angles);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = rotate_angle_converter(angles);
  tmp.x = X_TR_X;
  tmp.y = Y_TR_X;
  tmp.z = Z_TR_X;
  to_rotate = tmp;
  tmp.x = X_TR_Y;
  tmp.y = Y_TR_Y;
  tmp.z = Z_TR_Y;
  to_rotate = tmp;
  tmp.x = X_TR_Z;
  tmp.y = Y_TR_Z;
  tmp.z = Z_TR_Z;
  to_rotate = tmp;
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = rotate_angle_converter(angles);
  tmp.x = X_TR_Z;
  tmp.y = Y_TR_Z;
  tmp.z = Z_TR_Z;
  to_rotate = tmp;
  tmp.x = X_TR_Y;
  tmp.y = Y_TR_Y;
  tmp.z = Z_TR_Y;
  to_rotate = tmp;
  tmp.x = X_TR_X;
  tmp.y = Y_TR_X;
  tmp.z = Z_TR_X;
  to_rotate = tmp;
  return (to_rotate);
}
