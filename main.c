// Maak hier nog codam header

#include "codexion.h"

void *coder_routine(void *arg)
{
    printf("Here comes the coder routine\n");
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t coder1;

    // parsing (losse file) parset de argumenten en geeft struct args terug
    pthread_create(&coder1, NULL, coder_routine, NULL);
    pthread_join(coder1, NULL);
    return 0;
}
