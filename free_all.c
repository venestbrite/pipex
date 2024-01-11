#include "pipex.h"

void	free_bid(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	free_prog(t_program *program)
{
	free_bid(program->path);
	free_bid(program->cmd_1);
	free_bid(program->cmd_2);
	free(program->outfile);
	free(program->infile);
}

void	free_prog_bonus(t_program *program)
{
	free_bid(program->path);
	free_bid(program->cmd_1);
	free_bid(program->cmd_2);
	free(program->outfile);
	free(program->infile);
	while (program->cmds)
	{
		free(program->cmds);
		program->cmds = program->cmds->next;
	}
}
