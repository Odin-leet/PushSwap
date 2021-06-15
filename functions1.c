#include "swap.h"

void	functionif(int size, t_global *gl)
{
	t_pa	*tmp;
	if (size == 2)
	{
		if (gl->tab[gl->topindex] < gl->tab[gl->topindex + 1])
			swapb(gl);
		pusha(gl);
	}
	pusha(gl);
	tmp = gl->pb->next;
	free(gl->pb);
	gl->pb = tmp;
}

void	btoa(t_global *gl)
{
	int		i;
	int		size;
	int		count;
	t_pa	*tmp;

	i = 0;
	count = 0;
	size = gl->pb->index[1] - gl->pb->index[0];
	adda(gl);
	gl->top = ((gl->pb->index[1] - gl->pb->index[0]) / 2);
	gl->pivot = gl->sortedtable[(gl->pb->index[1] + gl->pb->index[0]) / 2];
	if (size == 1 || size == 2)
		functionif(size, gl);
	else
		functioneelse(gl);
}

void	reversefunction(t_global *gl, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		reverserotatea(gl);
		i++;
	}
}

void	atob(t_global *gl)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	count = 0;
	size = gl->pa->index[1] - gl->pa->index[0];
	if (size == 2)
	{
		if (gl->tab[gl->topindex - 1] > gl->tab[gl->topindex - 2])
			swapa(gl);
		return ;
	}
	addb(gl);
	gl->top = ((gl->pa->index[1] - gl->pa->index[0]) / 2);
	if (size % 2 == 1)
		gl->pivot = gl->sortedtable[(gl->pa->index[1] + gl->pa->index[0]) / 2];
	else
		gl->pivot = gl->sortedtable[(gl->pa->index[1]
				+ gl->pa->index[0]) / 2 - 1];
	count = functionwhile(gl);
	reversefunction(gl, count);
}
