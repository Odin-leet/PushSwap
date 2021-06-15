#include "swap.h"

void	printtable(int *tab, t_global *gl)
{
	int	i;

	i = 0;
	while (i < gl->topindex)
	{
		printf("---- %d\n", tab[i]);
		i++;
	}
}

void	printtable2(int *tab, t_global *gl)
{
	int	i;

	i = gl->topindex;
	while (i < gl->argc - 1)
	{
		printf("---- %d\n", tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_global	gl;

	i = 1;
	init(&gl, argc, argv);
	if (argc == 4)
	{
		sortvaleures(&gl);
		printtable(gl.tab, &gl);
		return (0);
	}
	gl.sortedtable = BubbleSort(gl.sortedtable, argc - 1);
	creata(0, gl.topindex, 0, &gl);
	while (1)
	{
		if (checkifsorted(gl.tab, 0, gl.argc - 1) == 1
			&& (gl.topindex == (gl.argc - 1)))
			break ;
		if (checkifsorted(gl.tab, gl.pa->index[0],
				gl.pa->index[1] - gl.pa->index[0]) == 0)
			atob(&gl);
		else
			btoa(&gl);
	}
	printtable(gl.tab, &gl);
	printf("--------- tab1\n");
	printtable2(gl.tab, &gl);
	printf("--------- tab2\n");
	freefuntion(&gl);
	while (1);
	return (0);
}
