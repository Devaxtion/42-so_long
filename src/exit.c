/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/21 13:37:10 by leramos-         ###   ########.fr       */
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

void	cleanup_and_exit(int status_code)
{
	if (status_code != 0)
		ft_printf("Error\n");
	// free_stack(a);
	// free_stack(b);
	exit(status_code);
}