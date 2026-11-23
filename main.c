// Maak hier nog codam header

#include "codexion.h"

void *coder_routine(void *arg)
{
    printf("Here comes the coder routine\n");
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
