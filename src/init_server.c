/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:57:23 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 14:14:25 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main(void)
{
	int	pid;

	pid = getpid();
	if(pid < 0)
	{
		ft_printf("PID Error\n");
		exit(1);
	}
	else
		ft_printf("Server PID: %d\n", pid);
}