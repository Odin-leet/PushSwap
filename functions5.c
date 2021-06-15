#include "swap.h"

void	swapa(t_global *gl)
{
	int	swap;

	swap = gl->tab[gl->topindex - 1];
	gl->tab[gl->topindex - 1] = gl->tab[gl->topindex - 2];
	gl->tab[gl->topindex - 2] = swap;
	printf("sa\n");
}

void	swapb(t_global *gl)
{
	int	swap;

	swap = gl->tab[gl->topindex];
	gl->tab[gl->topindex] = gl->tab[gl->topindex + 1];
	gl->tab[gl->topindex + 1] = swap;
	printf("sb\n");
}

void	pushb(t_global *gl)
{
	gl->pa->index[1]--;
	gl->pb->index[0]--;
	gl->topindex--;
	printf("pb\n");
}

void	pusha(t_global *gl)
{
	gl->pa->index[1]++;
	gl->pb->index[0]++;
	gl->topindex++;
	printf("pa\n");
}

void	rotatea(t_global *gl)
{
	int	temp;
	int	temp2;
	int	i;

	i = gl->topindex - 1;
	temp = gl->tab[gl->topindex - 1];
	while (i > 0)
	{
		temp2 = gl->tab[i];
		gl->tab[i] = gl->tab[i - 1];
		i--;
	}
	gl->tab[0] = temp;
	printf("ra\n");
}
