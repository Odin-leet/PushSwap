#include "swap.h"

void	rotateb(t_global *gl)
{	
	int	i;
	int	temp;

	i = gl->topindex;
	temp = gl->tab[gl->topindex];
	while (i < gl->argc - 2)
	{
		gl->tab[i] = gl->tab[i + 1];
		i++;
	}
	gl->tab[i] = temp;
	printf("rb\n");
}

void	reverserotatea(t_global *gl)
{
	int	i;
	int	temp;
	int	temp2;

	i = 0;
	temp = gl->tab[0];
	while (i < gl->topindex - 1)
	{
		gl->tab[i] = gl->tab[i + 1];
		i++;
	}
	gl->tab[i] = temp;
	printf("rra\n");
}

void	reverserotateb(t_global *gl)
{	
	int	i;
	int	temp;

	i = gl->argc - 2;
	temp = gl->tab[gl->argc - 2];
	while (i > gl->topindex)
	{
		gl->tab[i] = gl->tab[i - 1];
		i--;
	}
	gl->tab[gl->topindex] = temp;
	printf("rrb\n");
}
