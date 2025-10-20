/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:36:16 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/20 13:17:16 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_shade(double distance, int color)
{
	int		t;
	int		r;
	int		g;
	int		b;
	double	factor;

	if (distance == 0)
		return (color);
	factor = 1 / distance;
	if (factor > 1.0)
		factor = 1.0;
	t = get_t(color);
	r = get_r(color) * factor;
	g = get_g(color) * factor;
	b = get_b(color) * factor;
	return (create_trgb(t, r, g, b));
}

int	get_opposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(t, r, g, b));
}
