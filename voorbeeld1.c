#include <pthread.h>
#include <stdio.h>

typedef struct s_data
{
	int				counter;
	pthread_mutex_t	lock;
}	t_data;

void	*routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&data->lock);    // slot dicht: nu ben ik de enige
		data->counter++;
		pthread_mutex_unlock(&data->lock);  // slot open: de volgende mag
		i++;
	}
	return (NULL);
}

int	main(void)
{
	t_data		data;
	pthread_t	t1;
	pthread_t	t2;

	data.counter = 0;
	pthread_mutex_init(&data.lock, NULL);   // 1. aanmaken

	pthread_create(&t1, NULL, routine, &data);
	pthread_create(&t2, NULL, routine, &data);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("counter = %d\n", data.counter); // altijd 2000000
	pthread_mutex_destroy(&data.lock);      // 2. opruimen
	return (0);
}
