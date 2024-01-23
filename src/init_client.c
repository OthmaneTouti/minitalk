/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:19:44 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 15:42:52 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main (int argc, char **argv)
{
    pid_t server_pid;
    const char *message;
    int i;
    int bit;

    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    if (argc != 3)
    {
        ft_printf("Invalid number of arguments\n");
        exit(1);
    }
    while (*message)
    {
        i = 0;
        while (i < 8)
        {
            bit = (*message >> i) & 1;
            if (bit == 0)
            {
                if (kill(server_pid, SIGUSR1) < 0)
                {
                    ft_printf("PID Error\n");
                    exit(1);
                }
            }
            else
            {
                if (kill(server_pid, SIGUSR2) < 0)
                {
                    ft_printf("PID Error\n");
                    exit(1);
                }
            }
            usleep(100);
            i++;
        }
        message++;
    }
    return(0);
}