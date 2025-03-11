/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:29 by jcologne          #+#    #+#             */
/*   Updated: 2025/03/11 19:26:48 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_path(char *cmd)
{
    char *path = getenv("PATH"); 
    char *path_copy = ft_strdup(path); 
    char *dir = strtok(path_copy, ":");

    while (dir)
    {
        char *full_path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
        sprintf(full_path, "%s/%s", dir, cmd);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }
        
        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}