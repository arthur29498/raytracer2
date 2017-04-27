/*
** raytracer.c for raytracer.c in /home/arthur/delivery/bsraytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 10:44:55 2017 Arthur Philippe
** Last update Thu Apr 27 14:08:04 2017 Arthur Philippe
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# include "raytracer_structs.h"
# define EXIT_SUCCESS	0
# define EXIT_FAIL	84
# define EXIT_ARG_COUNT	84
# define BUFFER_SIZE	10000
# define SC_W		1280
# define SC_H		720
# define PROGRAM_NAME	" -- Raytracer"
# define FILE_NAME	"objects.tracr"
# define OBJ_START	"OBJECT*"
# define OBJ_END	"END_OBJECT*"
# define OBJ_SPHERE	"SPHERE*"
# define OBJ_PLANE	"PLANE*"
# define OBJ_CYLINDER	"CYLINDER*"
# define OBJ_CONE	"CONE*"
# define OBJ_LIGHT	"LIGHT*"
# define OBJ_EYE	"EYE*"
# define ID_SPHERE	1
# define ID_PLANE	2
# define ID_CYLINDER	3
# define ID_CONE	4
# define ID_LIGHT	5
# define ID_EYE		6
# define PI		3.14159265359
# define TILE_SIZE	50
# define XA		angles.x
# define YA		angles.y
# define ZA		angles.z
# define DEFAULT_COLOR	sfBlack
# define DEFAUT_LIGHT	(sfVector3f) {-300, 600, 200}
# define X_TR_X	(to_rotate.x)
# define Y_TR_X	((to_rotate.y * cosf(XA)) + (to_rotate.z * -sinf(XA)))
# define Z_TR_X	((to_rotate.y * sinf(XA)) + (to_rotate.z * cosf(XA)))
# define X_TR_Y	((to_rotate.x * cosf(YA)) + (to_rotate.z * sinf(YA)))
# define Y_TR_Y	((to_rotate.y))
# define Z_TR_Y	((to_rotate.x * -sinf(YA)) + (to_rotate.z * cosf(YA)))
# define X_TR_Z	((to_rotate.x * cosf(ZA)) + (to_rotate.y * -sinf(ZA)))
# define Y_TR_Z	((to_rotate.x * sinf(ZA)) + (to_rotate.y * cosf(ZA)))
# define Z_TR_Z	(to_rotate.z)
/*
** Mandatory
*/
void		my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector3f	calc_dir_vector(float, sfVector2i, sfVector2i);
float		intersect_sphere(sfVector3f, sfVector3f, float radius);
float		intersect_plane(sfVector3f, sfVector3f);
float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector,
				   float radius);
float		intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector,
			       float radius);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle);
sfVector3f	get_normal_plane(int);
float		get_light_coef(sfVector3f light_vector,
			       sfVector3f normal_vector);
sfVector3f	translate_inv(sfVector3f to_translate,
			      sfVector3f translations);
sfVector3f	get_intersection(sfVector3f eye_pos,
				 sfVector3f dir_vector,
				 float k);
/*
** window related implements.
*/
int			open_window(t_my_window *w, char *file_name);
sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
void			wf_window_destroy(t_my_window *);
void			reset_pixels(t_my_framebuffer *buffer);
/*
** Objects
*/
sfColor			get_def_color_ob(t_object *obj);
sfColor			get_def_color_ty(int type);
int			resolve_object_type(char *str);
char			*get_object_type(int type);
sfColor			get_color_from_objs(t_object *objs, int id);
int			add_limit(char *buffer,
				  int *idx,
				  t_object *new_object);

/*
** Render
*/
void			objects_hit_attempt(t_env *env,
					    t_render_in *in,
					    t_render_out *out);
float			obj_fctn_shunter(t_object *object,
					 t_render_in *in_arg);
void			raytrace_full_scene(t_env *env);
void			progress_to_next_px(int *total_px,
					    sfVector2i *px);
void			display_progress(int *pr, int runing);
float			std_color_effect(t_env *env, t_render_out *pr_out);
void			apply_colored_light_effect(sfColor *color,
						   t_object *objects);
/*
** Export
*/
int	export_render(char *, t_my_framebuffer *);
/*
** Math
*/
float			get_quadric_discriminant(sfVector3f);
sfVector3f		define_quadric_eq_vars(sfVector3f eye_pos,
					       sfVector3f dir_vector,
					       float radius);
float			solve_quadric_eq(float discriminant,
					 float a,
					 float b);
/*
** Data obliteration - for your destructive needs.
*/
void			window_destroy(t_my_window *);
void			destroy_objects(t_object *);
int			acp_putstr(int fd, char *str);
void			*my_memset(void *str, int c, int size);
int			my_getnbr(char *);
char			*my_strcpy(char *dest, char *src);
char			*my_strcat(char *dest, char *src);
void			set_chessboard_color(sfVector3f last_intersect,
					     sfColor *color);

#endif /* !RAYTRACER_H_ */
