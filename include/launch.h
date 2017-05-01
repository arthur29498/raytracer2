/*
** lauch.h for raytracer in /home/arthur/delivery/raytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Mar 18 11:16:50 2017 Arthur Philippe
** Last update Mon May  1 11:38:29 2017 Arthur Philippe
*/

#ifndef LAUNCH_H_
# define LAUNCH_H_

int	window_loop(t_my_window *, t_env *, char *);
int	raytracer_launcher(char *file_name, int exprt);
int	import_launcher(char *file_name);
void	find_light(t_env* env);
void	find_eye(t_env* env);
int	raytracer_thread_launch(t_env *env);


#endif /* !LAUNCH_H_ */
