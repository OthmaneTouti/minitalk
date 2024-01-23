/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:57:23 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 17:10:15 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_signal_data signal_data = {0, 0, 0};

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
        signal_data.bit = 0;
    else if (sig == SIGUSR2)
		signal_data.bit = 1;
	signal_data.character |= (signal_data.bit << signal_data.bits_received);
    signal_data.bits_received++;
    if (signal_data.bits_received == 8)
    {
        char temp = signal_data.character;
        write(1, &temp, 1);
        signal_data.character = 0;
        signal_data.bits_received = 0;
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