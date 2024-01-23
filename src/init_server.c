/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:57:23 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 17:28:07 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_signal_data g_signal_data = {0, 0, 0};

void handle_signal(int sig)
{
	char temp;
	
    if (sig == SIGUSR1)
        g_signal_data.bit = 0;
    else if (sig == SIGUSR2)
		g_signal_data.bit = 1;
	g_signal_data.character |= (g_signal_data.bit << g_signal_data.bits_received);
    g_signal_data.bits_received++;
    if (g_signal_data.bits_received == 8)
    {
        temp = g_signal_data.character;
        write(1, &temp, 1);
        g_signal_data.character = 0;
        g_signal_data.bits_received = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    ft_printf("Server PID: %d\n", getpid());

    while (1)
        pause();

    return 0;
}