/*
** raytracer_messages.h for raytracer1 in /home/arthur/delivery/raytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 16 16:35:31 2017 Arthur Philippe
** Last update Sat Mar 18 11:22:04 2017 Arthur Philippe
*/

#ifndef RAYTRACER_MESSAGES_H_
# define RAYTRACER_MESSAGES_H_

# define MSG_FD_ERROR		"file related error: "
# define MSG_FC_ERROR		"file content error: "
# define MSG_MISSING_FILE	"No such file or directory\n"
# define MSG_PERMISSION		"Permission denied\n"
# define MSG_IS_DIR		"Is a directory\n"
# define MSG_UNKNOWN		"Unexpected error\n"
# define MSG_TOO_FEW_ARG	"raytracer: too few arguments\n"
# define MSG_INTERUPTED		"%sraytracer: %serror:%s was not able to\
 continue\nrun terminated.\n"
# define MSG_PLAUSIBLE_WARNING	"%s%s: %swarning:%s configuration file\
 contains an inconsistency.\n"
# define MSG_QUIT		"raytracer: user exited. (ESC)\
\nrun terminated.\n"
# define MSG_RELOAD		"----------------\n\nReloading\n"
# define MSG_RENDER		"Rendering:\n[          ]\r"
# define MSG_RENDER_DONE	"-\x1b[32mCOMPLETE\x1b[0m-\n"
# define LOAD_CHAR		'#'
# define MSG_WIN_OPEN		"\nOpenning window"
# define MSG_SUCCES		" [SUCCESS]\n"

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RST			"\x1b[0m"
# define BOLD			"\033[1m"

# define TYPE_SPHERE		"sphere"
# define TYPE_PLANE		"plane"
# define TYPE_CYLINDER		"cylinder"
# define TYPE_CONE		"cone"
# define TYPE_LIGHT		"light"
# define TYPE_EYE		"camera"
# define TYPE_UNK		"beautiful princess or a rune of hyrule"

int	acp_putstr(int, char *);

#endif /* !RAYTRACER_MESSAGES_H_ */
