#include "minishell.h"

static void	print_file(void *redir)
{
	char	*test;
	t_redir	*redirections;

	redirections = (t_redir *)redir;
	if (redirections->type == INFILE)
		test = "infile";
	else if (redirections->type == OUTFILE)
		test = "outfile";
	else if (redirections->type == HEREDOC)
		test = "heredoc";
	else if (redirections->type == HEREDOC_NO_EXP)
		test = "heredoc sans expansion";
	else
		test = "append";
	ft_printf("%s: %s\n", test, redirections->name);
}

void	print_cmd(void *commands)
{
	t_cmd_block	*cmd;

	cmd = (t_cmd_block *)commands;
	print_str_table(cmd->cmds);
	ft_lstiter(cmd->in, &print_file);
	ft_lstiter(cmd->out, &print_file);
}
