/*
** quadric.h for  in /home/hexa/delivery/CGP/raytracer2/include
** 
** Made by HexA
** Login   <hexa@epitech.net>
** 
** Started on  Sun May 28 16:53:56 2017 HexA
** Last update Sun May 28 17:00:38 2017 HexA
*/

#ifndef QUADRIC_H_
# define QUADRIC_H_
# define P2(x) (x * x)
# define P3(x) (x * x * x)
# define P4(x) (x * x * x)
# define absf(x) ((x < 0) ? -x : x)

int		cardran(t_object *obj, float b, float c, float d);
float		ferari(t_object *obj, t_tore_poly poly);

#endif /* QUADRIC_H_ */
