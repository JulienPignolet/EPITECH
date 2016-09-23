/*
** my.h for minishell in /home/pignol_j/rendu/test/minishell1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Jan 23 16:04:53 2016 Julien Pignolet
** Last update Wed Feb  3 09:29:22 2016 Pignolet Julien
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEFAULT_CD (chdir("/home"), env = my_setenv(env, my_strcat( \
								   "RUMBLE OLDPWD ", buf)), \
		    env = my_setenv(env, "RUMBLE PWD /home"))

#define CD_MINUS (env = my_setenv(env, my_strcat("RUMBLE PWD ", \
						 get_oldpwd(env))), \
		  chdir(get_oldpwd(env)), env = my_setenv \
		  (env, my_strcat("RUMBLE OLDPWD ", buf)))

#define READ_IN (((i > 1) ? (tmp = buf) : (0)), \
		 buf = malloc(sizeof(char) * (i + 1)), \
		 ((i > 1) ? (buf = my_strcpy(buf, tmp), free(tmp)) : (buf[0] = '\0')), \
		 read(0, tmpr, 1), tmpr[1] = '\0', \
		 ((tmpr[0] != '\n') ? (buf = my_strcat(buf, tmpr)) : (0)), ++i)

#define BUILTINS_EXEC (((check_builtins(buf) == 3 && my_strlen(tab[0]) == 2) ? \
			(env = my_cd(tab, env)) : (((check_builtins(buf) == 4 && \
					       my_strlen(tab[0]) == 6) ? \
						    (env = my_setenv(env, buf)) : \
					      (((check_builtins(buf) == 5 && \
						 my_strlen(tab[0]) == 8) ? \
						(env = my_unsetenv(env, buf, 1)) : \
						(pid = fork(), ((pid == 0) ? \
								(((check_builtins(buf) == 1 && \
								   (my_strlen(buf) == 3 || \
								    buf[4] == ' ')) ? (my_env(buf, env)) : \
								  ((((execve(path, tab, env)) == -1) ? \
								    (my_putstr(tab[0]), \
								     my_putstr(": Command not found.\n")) : \
								    (0)))), exit(1)) : (wait(&pid_stat), \
											(WTERMSIG(pid_stat) \
											 == SIGSEGV ? (write(2, \
													     "Segmentation fault\n", \
													     19)) : (0)))))))))))

#define COPY_ENV (new_env[i] = env[i], ++i)

#define MATCH_SETENV ((match(env[i], tab[1]) == 1) ? \
		      (env = my_unsetenv(env, buf, 1), ++i) : (++i))

int	my_strlen(char *);
int	my_atoi(char *);
int	match(char *, char *);
int	check_builtins(char *);
int	check_number(char *);
int	minishell(char **);
int	my_exit(char *);
void	my_putchar(char);
void	my_putstr(char *);
void	my_env(char *, char **);
void	show_tab(char **);
char	*get_path(char **, char *);
char	*get_oldpwd(char **);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);
char	**str_tab(char *);
char	**str_tab_path(char *);
char	**str_tab_path2(char *);
char	**my_setenv(char **, char *);
char	**my_unsetenv(char **, char *, int);
char	**my_cd(char **, char **);

#endif /* !MY_H_ */
