/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:19:44 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 14:16:49 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments\n");
		exit(1);
	}
	ft_printf("Server PID: %s\nString: %s\n", argv[1], argv[2]);
	return(0);
}