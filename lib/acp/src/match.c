/*
** match.c for lacp in /home/arthur/Projects/new_gnl/lib/acp/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon May  8 11:17:40 2017 Arthur Philippe
** Last update Mon May  8 11:17:59 2017 Arthur Philippe
*/

int	match(char *s1, char *s2)
{
  int	out;

  out = 0;
  if (*s1 && *s2 == '*')
    out = (match(s1 + 1, s2) || match(s1, s2 + 1));
  else if (!*s1 && *s2 == '*')
    out = match(s1, s2 + 1);
  else if (*s1 == *s2 && *s1)
    out = match(s1 + 1, s2 + 1);
  else if (*s1 == *s2 && !*s1)
    out = 1;
  return (out);
}

int	nmatch(char *s1, char *s2)
{
  int	out;

  out = 0;
  if (*s1 && *s2 == '*')
    out = (match(s1 + 1, s2) + match(s1, s2 + 1));
  else if (!*s1 && *s2 == '*')
    out = match(s1, s2 + 1);
  else if (*s1 == *s2 && *s1)
    out = match(s1 + 1, s2 + 1);
  else if (*s1 == *s2 && !*s1)
    out = 1;
  return (out);
}
