/*
** maze.h for  in /home/bertha_e/rendu/Initiation_IA/dante/include
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Wed Apr 27 16:00:25 2016 Berthaud Elodie
** Last update Sun May 22 22:59:34 2016 Berthaud Elodie
*/

#ifndef MAZE_H_
# define MAZE_H_

/*
**structe de position de départ/arrivée
*/
typedef struct	s_pos
{
  int		i;
  int		j;
}		t_pos;

/*
**stockage de taille de malloc
*/
typedef struct	s_data
{
  int		i;
  int		j;
}		t_data;

/*
**tree's structure
*/
typedef struct	s_tree
{
  int		i;
  int		j;
  int		bol;
  struct s_tree	**next;
}		t_tree;

/*                                                                              
**structure de position/malloc de next                                          
*/
typedef struct  s_manage
{
  int           i;
  int           j;
}               t_manage;

/*
**maze's ganerator
*/
typedef struct	s_cell
{
  int		i;
  int		j;
  struct s_cell	*next;
  struct s_cell	*prev;
}		t_cell;

/*
**pile de sauvegarde de pos
*/
typedef struct	s_pile
{
  t_tree	*cell;
  int		bol;
  struct s_pile	*next;
  struct s_pile	*prev;
}		t_pile;

/*
**structture de traitement
*/
typedef struct		s_treat
{
  t_tree		*cell;
  t_pile		*pile;
  int			x;
}			t_treat;

/*
**generation_arbre/ressources.c
*/
void	my_putchar(const char);
void	my_putstr(const char *);
int	my_strlen(const char *);
char	*my_strdup(char *);

/*
**generation_arbre/file.c
*/
char	**add_in_tab(char **, char *);
char	**strcp(char **, char *, int, int);
char	**stock_maze(char *);

/*
**generation_arbre/tab_cell.c
*/
int	get_high_size(char **);
t_tree	**tree_tab(char **, int, int, int);
void	print_datas(t_tree **);
int	first_browse(char **, int, int);
t_tree	**malloc_tree(char **, int, int);

/*
**generation_arbre/link_cells.c
*/
int	malloc_cell_next(t_tree *, int);
void	loop(t_tree *, t_manage *, t_tree **);
void	link_cells(char **tab, t_data *, t_tree *, t_tree **);
t_tree	*get_current_cell(t_tree **, int, int);
void	*build_tree(char **, t_tree **, int, int);

/*
**src/generation_arbre/link_cell_suite.c
*/
int	get_next_nbr(char **, int, int);
void	init_to_null(t_tree *, int);

/*
**src/generation_arbre/link_cell_conditions.c
*/
void	check_on_right(char **, t_data *, t_tree *, t_tree **);
void	check_on_left(char **, t_data *, t_tree *, t_tree **);
void	check_at_bottom(char **, t_data *, t_tree *, t_tree **);
void	check_at_top(char **, t_data *, t_tree *, t_tree **);

/*
**src/pathfinding/path.c
*/
int	depile(t_pile **);
int	check_bol(t_tree *);
int	path_empile(t_tree **, t_pile **, int);
int	path_depile(t_tree **, t_pile **, int);
int	path(t_tree *, int, char **, t_pos *);

/*
**call_function.c
*/
int	call_functions(char *);

/*
**my_circ_list.c
*/
int	add_in_list(t_pile **, t_tree *);

/*
**print_end_maze.c
*/
void	print_final(char **);
void	print_end(char **, t_pile *);

/*
**src/pathfiding/check_avaible_maze.c
*/
int	check_all_next(t_tree *);
int	check_maze(t_tree *);

#endif /* !MAZE_H */
