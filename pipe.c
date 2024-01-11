#include "pipex.h"

void	while_pipe_first_pid(int *counter, t_list *cmds,
							t_pipe *p_struct, t_program *program)
{
	dup2(p_struct->fd_in, 0);
	if (cmds->next->next != NULL)
		dup2(p_struct->pipefd[1], 1);
	close(p_struct->pipefd[0]);
	if (counter[0] == 1)
		ft_first_command(program);
	else if (counter[0] == program->num_of_cmds - 1)
		second_command(program);
	else
		execute_binaries((char *) cmds->content, program,
			ft_split((char *)cmds->content, ' '));
}

void	while_pipe(t_list *cmds, int i, t_pipe *p_struct, t_program *program)
{
	int	counter;

	counter = 1;
	while (cmds->next != NULL)
	{
		pipe(p_struct->pipefd);
		p_struct->pid = fork();
		if (p_struct->pid == -1)
			exit(EXIT_FAILURE);
		else if (p_struct->pid == 0)
		{
			while_pipe_first_pid(&counter, cmds, p_struct, program);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&program->status);
			close(p_struct->pipefd[1]);
			p_struct->fd_in = p_struct->pipefd[0];
			cmds = cmds->next;
			counter++;
		}
	}
}

void	loop_pipe(t_list *cmds, t_program *program)
{
	t_pipe	p_struct;
	int		i;

	p_struct.fd_in = 0;
	i = 0;
	while_pipe(cmds, i, &p_struct, program);
}
