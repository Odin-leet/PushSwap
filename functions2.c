#include "swap.h"

int	*BubbleSort(int *a, int array_size)
{
	int	i;
	int	j;
	int	temp;
	int	*temp2;

	temp2 = a;
	i = 0;
	while (i < (array_size - 1))
	{
		j = 0;
		while (j < array_size - 1 - i)
		{
			if (temp2[j] < temp2[j + 1])
			{
				temp = temp2[j + 1];
				temp2[j + 1] = temp2[j];
				temp2[j] = temp;
			}
			++j;
		}
		i++;
	}
	return (a);
}

int	checkifsortedfinal(int *tab, int start, int size, t_global *gl)
{
	int	i;
	int	check;

	i = start;
	check = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			check++;
		else
			check--;
		i++;
	}
	if (check == size - 1 )
	{
		gl->pa->statut = 1;
		return (1);
	}
	return (0);
}

int	checkifsorted(int *tab, int start, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[start + i] < tab[start + i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	functionwhile2(t_global *gl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < gl->top)
	{
		if (gl->tab[gl->topindex] > gl->pivot)
		{
			pusha(gl);
			i++;
		}
		else if (gl->tab[gl->argc - 2] > gl->pivot && gl->pb->next == NULL)
		{
			reverserotateb(gl);
			pusha(gl);
			i++;
		}
		else
		{
			rotateb(gl);
			count++;
		}
	}
	return (count);
}

void	functioneelse(t_global *gl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = functionwhile2(gl);
	while (count--)
		reverserotateb(gl);
}

int	functionwhile(t_global *gl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < gl->top)
	{
		if (gl->tab[gl->topindex - 1] < gl->pivot)
		{
			pushb(gl);
			i++;
		}
		else if (gl->tab[0] < gl->pivot && gl->pa->next == NULL)
		{
			reverserotatea(gl);
			pushb(gl);
			i++;
		}
		else
		{
			rotatea(gl);
			count++;
		}
	}
	return (count);
}
