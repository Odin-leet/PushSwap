#include "swap.h"

int		*BubbleSort(int a[], int array_size)
{
	int i, j, temp;
	for (i = 0; i < (array_size - 1); ++i)
	{

		for (j = 0; j < array_size - 1 - i; ++j )
		{
			if (a[j] < a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	i = 0;

	return(a);
}

void creata(int i, int j, int c)
{
	gl.pa = (t_pa *)malloc(sizeof(t_pa) * 1);
    gl.pa->index[0] = i;
    gl.pa->index[1] = j;
    gl.pa->statut = c;
	gl.pa->next = NULL;
}

int     checkifsorted(int   *tab, int size)
{
    int i;
    int check;

    i = 0;
    check = 0;
    while (i < size - 1)
    {
        if(tab[i] > tab[i + 1])
        check++;
        else
        check--;
        i++;
    }
    if(check == size - 1)
    return(1);
    return(0);
}
void    atob()
{
    int     i;

    i = 0;
    gl.top = ((gl.pa->index[0] + gl.pa->index[1]) / 2);
    gl.pivot = gl.sortedtable[gl.top];
    while (i < gl.top)
    {
        if(gl.tab[gl.pa->index[1]] < gl.pivot)
        {
            pushb();
        }
        else if(gl.tab[gl.pa->index[1] - 1] < gl.pivot)
        {
            swapa(gl.pa);
            pushb();
            i--;
        }
        else if (gl.tab[gl.pa->index[0]] < gl.pivot)
        {
            reverserotateb();
            pushb();
            pushb();

        }
        else
        rotatea();

    }
}
int     main(int argc, char **argv)
{
    int     i;
  

    i = 1;
    gl.pb = NULL;
    gl.pa = NULL;
    gl.tab = malloc(sizeof(int) * argc - 1);
    while (i < argc )
    {
        gl.tab[i - 1] = atoi(argv[i]);
        i++;
    }
    gl.sortedtable = malloc(sizeof(int) * argc -1);        
    gl.sortedtable = BubbleSort(gl.tab,argc - 1);
    if (checkifsorted(gl.tab,argc - 1) == 0)
    {
        creata(0,argc - 1, 0);
        creatb(argc - 1 , argc - 1, 0);
        atob();
    }
    
    return(0);
}