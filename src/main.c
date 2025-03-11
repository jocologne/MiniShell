/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:43:31 by jcologne          #+#    #+#             */
/*   Updated: 2025/03/11 19:08:24 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	char	**args;
	int 	pid;
	int		status;
	char 	*path;

	while (1)
	{
		input = readline("$_mini_shell_> ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		add_history(input);
		args = ft_split(input, 32);
		pid = fork();
		if (pid == 0)
		{
			path = find_path(args[0]);
			if (execve(path, args, NULL) == -1)
				perror("Error");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
		free(input);
	}
	return (0);
}
