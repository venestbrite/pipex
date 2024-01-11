#include "pipex.h"

void	bonus(char **argv, int argc, t_program *program)
{
	int	i;

	program_setup(argv, argc, program);
	i = 3;
	program->cmds = ft_lstnew(argv[2]);
	while (i < (argc - 1))
	{
		program->supp = ft_lstnew(argv[i]);
		ft_lstadd_back(&program->cmds, program->supp);
		i++;
	}
	program->num_of_cmds = argc - 3;
	exec_bonus(program->cmds, program);
	free_prog_bonus(program);
}

void	exec_bonus(t_list *cmds, t_program *program)
{
	loop_pipe(cmds, program);
}
