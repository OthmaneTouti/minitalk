/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:58:11 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/23 16:41:50 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define _XOPEN_SOURCE 700
typedef struct s_signal_data{
    volatile sig_atomic_t bit;
    volatile sig_atomic_t character;
    volatile sig_atomic_t bits_received;
} t_signal_data;

#endif