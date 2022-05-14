#include "../include/philo.h"

void	*monitor_routine(void *ptr)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)ptr;
	while (1) {
		//死んでから10ms以内に見つければいいからusleep(1000) or time_keeper(monitor->data, 1000)をする。
		//mutexでロックする。
		//get_timeから最後に食事した時間を引いて、time_to_dieと比較する。
		//死んでたら、mutex_unlockして、print_actionして、終了。
		//死んでなかったら、mutex_unlockして、何もしない。
	}
	return (NULL);
}