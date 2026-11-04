#include "sync_car.h"

void station_init(struct station *station)
{
	station->waiting_passengers = 0;
	station->free_seats = 0;
	station->boarding_passengers = 0;
	pthread_mutex_init(&station->lock, NULL);
	pthread_cond_init(&station->car_arrived, NULL);
	pthread_cond_init(&station->all_boarded, NULL);
}

void station_load_car(struct station *station, int count)
{
	/* TODO: implementar na próxima etapa */
	(void) station;
	(void) count;
}

void station_wait_for_car(struct station *station)
{
	/* Os contadores são compartilhados entre as threads; sem exclusão mútua, atualizações se perderiam. */
	pthread_mutex_lock(&station->lock);

	/* O vagão precisa saber que há alguém na plataforma para decidir se pode partir. */
	station->waiting_passengers++;

	/* É while porque o wakeup pode ser espúrio ou outro passageiro pode ter pego o último lugar antes. */
	while (station->free_seats == 0)
		pthread_cond_wait(&station->car_arrived, &station->lock);

	/* Reservar o lugar ainda com o mutex impede que dois passageiros fiquem com o mesmo assento. */
	station->free_seats--;

	/* Quem já tem lugar garantido não pode mais ser contado como demanda para este vagão. */
	station->waiting_passengers--;

	/* O vagão não pode partir até este passageiro sentar, então ele precisa constar como pendente. */
	station->boarding_passengers++;

	/* Sentar acontece depois do retorno e station_on_board precisará do mutex, então ele não pode ficar preso. */
	pthread_mutex_unlock(&station->lock);
}

void station_on_board(struct station *station)
{
	/* TODO: implementar na próxima etapa */
	(void) station;
}
