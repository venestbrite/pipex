#include "pipex.h"
#include "libft.h"

void	exec_pipe_first_last(char **cmd_1, char **cmd_2, t_program *program)
{
	t_pipe	p;

	pipe(p.pipefd);
	p.p1 = fork();
	wait(&program->status);
	if (p.p1 < 0)
		exit(0);
	else if (p.p1 == 0)
	{
		close(p.pipefd[0]);
		dup2(p.pipefd[1], STDOUT_FILENO);
		close(p.pipefd[1]);
		if (ft_first_command(program) < 0)
			exit(-1);
	}
	else
	{
		if (program->status == 65280)
			exit(0);
		close(p.pipefd[1]);
		dup2(p.pipefd[0], STDIN_FILENO);
		close(p.pipefd[0]);
		second_command(program);
	}
}

int	execute_binaries(char *str, t_program *program, char **argv)
{
	int		i;
	char	*joined;
	char	*join_support;
	int		error;
	int		ret;

	i = 0;
	ret = -1;
	error = 1;
	while (program->path[i])
	{
		join_support = ft_strjoin(program->path[i], "/");
		joined = ft_strjoin(join_support, str);
		ret = execve(joined, argv, program->envp);
		free(joined);
		free(join_support);
		if (ret > 0)
			break ;
		i++;
	}
	return (ret);
}

void	program_setup(char **argv, int argc, t_program *program)	
{
	program->infile = ft_strdup(argv[1]);
	program->outfile = ft_strdup(argv[argc - 1]);
	program->cmd_1 = ft_split(argv[2], ' ');
	program->cmd_2 = ft_split(argv[argc - 2], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_program	program;

	program.error = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			program.path = ft_split(&envp[i][5], ':');
			break ;
		}
		i++;
	}
	if (argc == 5)
	{
		program_setup(argv, argc, &program);
		exec_pipe_first_last(program.cmd_1, program.cmd_2, &program);
		free_prog(&program);
	}
	else if (argc > 5)
		bonus(argv, argc, &program);
	return (0);
}
