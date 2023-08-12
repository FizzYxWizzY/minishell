/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:42:54 by mflury            #+#    #+#             */
/*   Updated: 2023/08/12 03:15:22 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// sa_handler for sigint.
void	sigint_handle(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// handling function for sigint (ctrl + c)
void	sigint_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sigint_handle;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT , &sa, NULL);
}

// handling function for sigquit (ctrl + \)
void	sigquit_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT , &sa, NULL);
}

// sa_handler for sigterm.
void	sigterm_handle(int sig)
{
	(void)sig;
	printf("sigterm\n");
	exit (0);
}

// handling function for sigterm (ctrl + d)
void	sigterm_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sigterm_handle;
	sigaction(SIGTERM , &sa, NULL);
}

// set all the signal handling functions.
void	set_handlers(void)
{
	sigquit_handler();
	sigterm_handler();
	sigint_handler();
}

// int	main(void)
// {
// 	// set_handlers();
// 	while (1)
// 	{
// 		write (1, "Hello World!\n", 13);
// 		sleep(2);
// 	}
// 	return (0);
// }