#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	int				started;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
}	t_data;

typedef struct s_worker
{
	int		id;
	t_data	*data;
}	t_worker;

void	*routine(void *arg)
{
	t_worker	*w;

	w = (t_worker *)arg;
	pthread_mutex_lock(&w->data->lock);
	while (w->data->started == 0)                       // let op: while, geen if
		pthread_cond_wait(&w->data->cond, &w->data->lock);
	pthread_mutex_unlock(&w->data->lock);

	printf("Thread %d gaat aan de slag\n", w->id);
	return (NULL);
}

int	main(void)
{
	t_data		data;
	t_worker	workers[3];
	pthread_t	threads[3];
	int			i;

	data.started = 0;
	pthread_mutex_init(&data.lock, NULL);
	pthread_cond_init(&data.cond, NULL);

	i = 0;
	while (i < 3)
	{
		workers[i].id = i + 1;
		workers[i].data = &data;
		pthread_create(&threads[i], NULL, routine, &workers[i]);
		i++;
	}

	printf("Main: alle threads gestart, even wachten...\n");
	sleep(1);

	pthread_mutex_lock(&data.lock);
	data.started = 1;                    // 1. verander de toestand (onder de lock)
	pthread_cond_broadcast(&data.cond);  // 2. maak alle wachtende threads wakker
	pthread_mutex_unlock(&data.lock);

	i = 0;
	while (i < 3)
		pthread_join(threads[i++], NULL);
	pthread_cond_destroy(&data.cond);
	pthread_mutex_destroy(&data.lock);
	return (0);
}
