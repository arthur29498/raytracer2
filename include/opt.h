/*
** opt.h for raytracer in /home/arthur/Projects/raytracer2/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 22 14:32:54 2017 Arthur Philippe
** Last update Thu May 25 17:31:55 2017 Arthur Philippe
*/

#ifndef OPT_H_
# define OPT_H_

# define OPT_RDR	'r'
# define OPT_EXP	'e'
# define OPT_IMP	'i'
# define OPT_AAL	'a'
# define MSG_IMPL_OPT	IMPL_OPT1 IMPL_OPT2 IMPL_OPT3 IMPL_OPT4
# define IMPL_OPT1	"\033[1mraytracer: \x1b[35mwarning: \x1b[0mabsence "
# define IMPL_OPT2	"of render or import option is treated as implicit "
# define IMPL_OPT3	"render mode.\n\t\t    (to avoid this warning use "
# define IMPL_OPT4	"\"-r\" or \"-i\")"
# define MSG_NO_FILE	NO_FILE_1 NO_FILE_2
# define NO_FILE_1	"\033[1mraytracer: \x1b[31merror: \x1b[0m"
# define NO_FILE_2	"no input file"

typedef struct	s_rtc_opt
{
  int		render;
  int		exprt;
  int		imprt;
  int		a_aliasing;
  char		file_name[256];
}		t_rtc_opt;

char		*my_strcpy(char *, char *);
t_rtc_opt	*get_rtc_opt(int ac, char **av);
void		*my_memset(void *, int, int);

#endif /* !OPT_H_ */
