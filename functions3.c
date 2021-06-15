#include "swap.h"

void	creata(int i, int j, int c, t_global *gl)
{
	gl->pa = (t_pa *)malloc(sizeof(t_pa) * 1);
	gl->pa->index[0] = i;
	gl->pa->index[1] = j;
	gl->pa->statut = c;
	gl->pa->next = NULL;
}

void	addb(t_global *gl)
{
	t_pa	*tmp;

	tmp = (t_pa *)malloc(sizeof(t_pa) * 1);
	tmp->index[0] = gl->pa->index[1];
	tmp->index[1] = gl->pa->index[1];
	tmp->statut = 0;
	tmp->next = gl->pb;
	gl->pb = tmp;
}

void	adda(t_global *gl)
{
	t_pa	*tmp;

	tmp = (t_pa *)malloc(sizeof(t_pa) * 1);
	tmp->index[0] = gl->pa->index[1];
	tmp->index[1] = gl->pa->index[1];
	tmp->statut = 0;
	tmp->next = gl->pa;
	gl->pa = tmp;
}
