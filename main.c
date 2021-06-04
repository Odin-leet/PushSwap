#include "swap.h"

int		*BubbleSort(int *a, int array_size)
{
	int i, j, temp;
    int *temp2;
    temp2 = a;
	for (i = 0; i < (array_size - 1); ++i)
	{

		for (j = 0; j < array_size - 1 - i; ++j )
		{
			if (temp2[j] < temp2[j+1])
			{
				temp = temp2[j+1];
				temp2[j+1] = temp2[j];
				temp2[j] = temp;
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

void creatb(int i, int j, int c)
{
	gl.pb = (t_pa *)malloc(sizeof(t_pa) * 1);
    gl.pb->index[0] = i;
    gl.pb->index[1] = j;
    gl.pb->statut = c;
	gl.pb->next = NULL;
}

int     checkifsorted(int   *tab, int size)
{
    int i;
    int check;

    i = 0;
    check = 0;
    while (i < size )
    {
        if(tab[i] > tab[i + 1])
        check++;
        else
        check--;
        i++;
    }
    if(check == size )
    return(1);
    return(0);
}
void    atob()
{
    int     i;

    i = 0;
    gl.top = ((gl.topindex - 1 )/ 2);
    gl.pivot = gl.sortedtable[gl.top];
    if(gl.topindex - 1 == 1)
    {
        if(gl.tab[gl.topindex - 1] > gl.tab[0])
        swapa(gl.pa);
    }
    //printf("%d ---- %d\n",gl.pivot,gl.top);
    while (i < gl.top)
    {
        printf("%d ---- %d\n",gl.pivot,gl.top);
       
        
        if(gl.tab[gl.topindex - 1] <= gl.pivot)
        {
            pushb();
            i++;
        }
        else if(gl.tab[gl.topindex - 2] <= gl.pivot)
        {
            swapa(gl.pa);
            pushb();
            i++;
        }
        else if (gl.tab[gl.pa->index[0]] <= gl.pivot)
        {
            reverserotateb();
            pushb();
            i++;

        }
        else
        rotatea();
         printtable(gl.tab);
        printf("--------- tab1\n");
        printtable2(gl.tab);
        printf("--------- tab2\n");

    }
}

void    printtable(int  *tab)
{
    int i;

    i = 0;

    while (i < gl.topindex  )
    {
        printf("---- %d\n",tab[i]);
        i++;
    }
}

void    printtable2(int  *tab)
{
    int i;

    i = gl.topindex ;
    while (i < gl.argc - 1)
    {
        printf("---- %d\n",tab[i]);
        i++;
    }
}


int     main(int argc, char **argv)
{
    int     i;
  
    int     *temp;
    i = 1;
    gl.topindex = argc - 1;
    gl.argc = argc;
    gl.pb = NULL;
    gl.pa = NULL;
    gl.tab = malloc(sizeof(int) * gl.topindex);
    printf("%d\n",argc);

 while (i < argc )
 {
     gl.tab[i - 1] = atoi(argv[i]);
     printf("%d\n",gl.tab[i - 1]);
     i++;
 }
 
 temp = gl.tab;
 gl.sortedtable = malloc(sizeof(int) * gl.topindex );
 i = 0;
 while (i < gl.topindex)
 {
     gl.sortedtable[i] = gl.tab[i];
     i++;
 }
printtable(gl.tab) ;    
 gl.sortedtable = BubbleSort(gl.sortedtable,argc - 1);
while (checkifsorted(gl.tab,gl.topindex - 1) == 0)
{
    creata(0,gl.topindex - 1, 0);
    creatb(gl.topindex , gl.topindex, 0);
    atob();
}
}
