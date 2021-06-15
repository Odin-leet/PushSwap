#include "swap.h"

void	sortvaleures(t_global *gl)
{
	int	i;

	while (checkifsorted(gl->tab, 0, gl->topindex) == 0)
	{
		if (gl->tab[gl->topindex - 1] > gl->tab[gl->topindex - 2])
			swapa(gl);
		else if (gl->tab[gl->topindex - 1] > gl->tab[0])
		{
			reverserotatea(gl);
		}
		else
			rotatea(gl);
	}
}

void	replirtableau(t_global *gl, char **argv, int j)
{
	int	i;

	i = 0;
	while (j > 0)
	{
		gl->tab[i] = atoi(argv[j]);
		i++;
		j--;
	}
}

void	replirsortedtable(t_global *gl)
{
	int	i;	

	gl->sortedtable = malloc(sizeof(int) * gl->topindex);
	i = 0;
	while (i < gl->topindex)
	{
		gl->sortedtable[i] = gl->tab[i];
		i++;
	}
}

void	init(t_global *gl, int argi, char **argv1)
{
	gl->topindex = argi - 1;
	gl->argc = argi;
	gl->pb = NULL;
	gl->pa = NULL;
	gl->tab = malloc(sizeof(int) * gl->topindex);
	replirtableau(gl, argv1, argi - 1);
	replirsortedtable(gl);
}

void	freefuntion(t_global *gl)
{
	t_pa	*tmp;

	while (gl->pa != NULL)
	{
		tmp = gl->pa;
		gl->pa = gl->pa->next;
		free(tmp);
	}
	free(gl->tab);
	free(gl->sortedtable);
}
