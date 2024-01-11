#include "pipex.h"

int	ft_first_command(t_program *program)
{
	pid_t	pid;
	int		status;
	int		fd;

	fd = open(program->infile, O_RDONLY);
	if (fd < 0)
	{
		perror(program->infile);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (execute_binaries(program->cmd_1[0], program, program->cmd_1) < 0)
	{
		perror(program->cmd_1[0]);
		return (-1);
	}
	return (1);
}

void	second_command(t_program *program)
{
	int		fd;
	pid_t	pid;
	int		ret;

	fd = open(program->outfile, O_CREAT | O_RDWR, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ret = execute_binaries(program->cmd_2[0], program, program->cmd_2);
	if (ret < 0)
	{
		perror(program->cmd_2[0]);
		exit(-1);
	}
}
