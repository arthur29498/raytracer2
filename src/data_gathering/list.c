/*
** list.c for raytracer1 in raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Feb 20 12:30:23 2017 Arthur Philippe
** Last update Tue May  2 14:03:23 2017 Arthur Philippe
*/

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_data.h"
#include "raytracer_messages.h"

t_object	*add_to_object_list(t_object *new_object,
				    t_object *objects)
{
  t_object	*current_obj;

  current_obj = objects;
  if (!objects)
    return (new_object);
  while (current_obj->next)
    current_obj = current_obj->next;
  current_obj->next = new_object;
  return (objects);
}

t_object	*create_list_node()
{
  t_object	*obj;

  obj = malloc(sizeof(t_object));
  if (!obj)
    return (NULL);
  my_memset(obj, 0, sizeof(t_object));
  return (obj);
}

void	find_eye(t_env *env)
{
  t_object	*list;

  list = env->objects;
  while (list)
    {
      if (list->type == ID_EYE)
	{
	  env->eye_pt = list->pos;
	  env->eye_rt = list->rot;
	  return ;
	}
      list = list->next;
    }
}

void	find_light(t_env *env)
{
  t_object	*list;

  list = env->objects;
  while (list)
    {
      if (list->type == ID_LIGHT)
	{
	  env->light = list->pos;
	  return ;
	}
      list = list->next;
    }
}

int		check_list_content(t_object *list,
				   char *file_name)
{
  int		i;
  int		err;
  t_object	*current;

  i = 1;
  err = 0;
  if (!list)
    return (-1);
  current = list;
  acp_print(HINT_SUMMARY);
  while (current->next)
    {
      acp_print(HINT_SINGLE_OBJ_SUM, i, get_object_type(current->type));
      if (!current->type)
	err = 1;
      current = current->next;
      i += 1;
    }
  acp_print(HINT_SINGLE_OBJ_SUM, i, get_object_type(current->type));
  acp_print(HINT_TOTAL_LOADED, BOLD, i, RST);
  if (err)
    acp_print(MSG_PLAUSIBLE_WARNING, BOLD, file_name, MAGENTA, RST);
  return (i);
}
