/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/25 15:13:14 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/11/25 15:13:14 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void *coder_routine(void *coder, void * args)
{
    while (time < args.time_to_burnout)
    {
    	take_dongle(coder);
    	take_dongle(coder);
    	compile(coder, args);
    }
	if (time >= args.time_to_burnout)
		// stop due to burnout
	if (coder.times_compiled >= args.number_of_compiles_required)
		// stop sim
    debug(coder, args);
	refactor(coder, args);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t   *coders;
    t_args      args;
    int         n;
    int         i;

    memset(&args, 0, sizeof(args));
    args.number_of_coders = 2;
    n = args.number_of_coders;
    coders = malloc(sizeof(pthread_t) * n);
    if (!coders)
        return (1);
    i = 0;
    while (i < n)
    {
        // pthread_create()
        // dit nog maken
        i++;
    }
    // parsing (losse file) parset de argumenten en geeft struct args terug
    pthread_create(&coder1, NULL, coder_routine, NULL);
    pthread_join(coder1, NULL);
    return 0;
}
