/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/27 11:40:00 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	free_stack(t_stack *stack)
// {
// 	if (stack)
// 	{
// 		if (stack->data)
// 			free(stack->data);
// 		free(stack);
// 	}
// }

void	cleanup_and_exit(int status_code, const char *error_msg)
{
	if (status_code != 0)
	{
		ft_printf("Error\n");
		if (error_msg)
			ft_printf("%s\n", error_msg);
	}
	exit(status_code);
}
