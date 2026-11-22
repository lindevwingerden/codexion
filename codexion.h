/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   codexion.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/20 17:45:42 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/11/20 17:47:25 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_args
{
	int	    number_of_coders;
	int	    time_to_burnout;
    int     time_to_compile;
    int     time_to_debug;
    int     time_to_refactor;
    int     number_of_compiles_required;
    int     dongle_cooldown;
    char*   scheduler;
    
}	t_args;

#endif