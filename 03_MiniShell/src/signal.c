#include "minishell.h"

static void	sig_handler(int signo)
{
	if (signo == SIGQUIT)
		return ;
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("\n");
		rl_redisplay();
		g_status = 1;
		return ;
	}
}

int	handle_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	return (0);
}

static void	child_handler(int signo)
{
	if (signo == SIGQUIT)
	{
		write(2, "^\\Quit: 3\n", ft_strlen("^\\Quit: 3\n"));
	}
	if (signo == SIGINT)
	{
		write(2, "^C\n", 3);
	}
}

int	handle_signal_child(void)
{
	signal(SIGINT, child_handler);
	signal(SIGQUIT, child_handler);
	return (0);
}