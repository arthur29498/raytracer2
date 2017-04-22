/*
** opt.h for raytracer in /home/arthur/Projects/raytracer2/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 22 14:32:54 2017 Arthur Philippe
** Last update Sat Apr 22 15:40:29 2017 Arthur Philippe
*/

#ifndef OPT_H_
# define OPT_H_

# define OPT_RDR	'r'
# define OPT_EXP	'e'
# define OPT_IMP	'i'

typedef struct	s_rtc_opt
{
  int		render;
  int		exprt;
  int		imprt;
  char		file_name[256];
}		t_rtc_opt;

char		*my_strcpy(char *, char *);
t_rtc_opt	*get_rtc_opt(int ac, char **av);

#endif /* !OPT_H_ */
