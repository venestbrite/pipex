#ifndef PIPEX_H

# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_program
{
	char		**path;
	char		**envp;
	char		*infile;
	char		**cmd_1;
	char		**cmd_2;
	char		*outfile;
	int			status;
	int			error;
	int			fd;
	int			num_of_cmds;
	t_list		*cmds;
	t_list		*supp;
}				t_program;

typedef struct s_pipe
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	p1;
	pid_t	p2;
	int		fd_in;
}				t_pipe;

char	**ft_split(char const *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
int		execute_binaries(char *str, t_program *program, char **argv);
int		ft_first_command(t_program *program);
void	second_command(t_program *program);
void	loop_pipe(t_list *cmds, t_program *program);
void	free_bid(char **to_free);
void	free_prog(t_program *program);
void	free_prog_bonus(t_program *program);
void	bonus(char **argv, int argc, t_program *program);
void	exec_bonus(t_list *cmds, t_program *program);
void	program_setup(char **argv, int argc, t_program *program);

#endif
