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

void    addb()
{
    t_pa *temp;

    temp = (t_pa *)malloc(sizeof(t_pa) * 1);
    temp->index[0] = gl.pa->index[1];
    temp->index[1] = gl.pa->index[1];
    temp->statut = 0;
    temp->next = gl.pb;
    gl.pb = temp;

}
void    adda()
{
    t_pa *temp;

    temp = (t_pa *)malloc(sizeof(t_pa) * 1);
    temp->index[0] = gl.pa->index[1];
    temp->index[1] = gl.pa->index[1];
    temp->statut = 0;
    temp->next = gl.pa;
    gl.pa = temp;
}
void creatb(int i, int j, int c)
{
	gl.pb = (t_pa *)malloc(sizeof(t_pa) * 1);
	gl.pb->index[0] = i;
	gl.pb->index[1] = j;
	gl.pb->statut = c;
	gl.pb->next = NULL;
}
int     checkifsortedfinal(int   *tab, int start,int size)
{
	int i;
	int check;

	i = start;
	check = 0;

	while (i < size  - 1)
	{
		if(tab[i] > tab[i + 1])
			check++;
		else
			check--;
		i++;
	}
	if(check == size - 1 )
	{
		gl.pa->statut = 1;
		return(1);
	}
		
	return(0);
}

int     checkifsorted(int   *tab, int start,int size)
{
	int i;

	i = 0;
	while (i < (size - 1))
	{
		if(tab[start + i] < tab[start + i + 1])
			return (0);
		i++;
	}
	return(1);
}

void    btoa()
{
    int     i;
    int     size;
	int		count;

    i = 0;
	count  = 0;
	//gl.top = 0;
	size = gl.pb->index[1] - gl.pb->index[0] ;
	adda();
	gl.top = ((gl.pb->index[1] - gl.pb->index[0] )/ 2);
	gl.pivot = gl.sortedtable[(gl.pb->index[1] + gl.pb->index[0]) / 2 ];   

    if ( size == 1 || size == 2)//|| size == 2)
    {
		if (size == 2)
		{
			if (gl.tab[gl.topindex] < gl.tab[gl.topindex + 1])
				swapb(gl.pb);
			pusha();
		}
		pusha();
	//	printtable(gl.tab);
	//	printf("--------- tab1\n");
	//printtable2(gl.tab);
	//printf("--------- tab2\n");
        gl.pb = gl.pb->next;
    }

	else
	{
		while(i < gl.top)
		{
			if(gl.tab[gl.topindex] > gl.pivot)
			{
				pusha();
				i++;
			}
	//		else if(gl.tab[gl.topindex + 1] > gl.pivot)
	//	{
	//		swapb(gl.pb);
	//		pusha();
	//	}
			else if(gl.tab[gl.argc - 2] > gl.pivot && gl.pb->next == NULL)
			{
				reverserotateb();
				pusha();
				i++;
			}
			else
			{
			rotateb();
			count++;
			}

		}
		while (count--)
				reverserotateb();
	}
    
    //printtable(gl.tab);
	//printf("--------- tab1\n");
	//printtable2(gl.tab);
	//printf("--------- tab2\n");
}
void    atob()
{
	int     i;
	int     size;
	int 	count;

	size = gl.pa->index[1] - gl.pa->index[0];
	if (size == 2)
	{
		if (gl.tab[gl.topindex - 1] > gl.tab[gl.topindex - 2])
		swapa(gl.pa);
		return;
	}
	addb();
	i = 0;
	count = 0;
	gl.top = ((gl.pa->index[1] - gl.pa->index[0] )/ 2);
	if ( size % 2 == 1)
		gl.pivot = gl.sortedtable[(gl.pa->index[1] + gl.pa->index[0]) / 2 ];   
	else
		gl.pivot = gl.sortedtable[(gl.pa->index[1] + gl.pa->index[0]) / 2 - 1];

	
	while (i < gl.top)
	{
	//	printf("%d ---- %d\n",gl.pivot,gl.top);


		if(gl.tab[gl.topindex - 1] < gl.pivot)
		{
			pushb();
			i++;
		}
		//else if(gl.tab[gl.topindex - 2] < gl.pivot)
		//{
		//	swapa(gl.pa);
		//	pushb();
		//}
		else if (gl.tab[0] < gl.pivot && gl.pa->next == NULL)
		{
			reverserotatea();
			pushb();
			i++;
		}
		else
		{
			rotatea();
			count++;
		}
	//	
	//printtable(gl.tab);
	//printf("--------- tab1\n");
	//printtable2(gl.tab);
	//printf("--------- tab2\n");

	}
	i = 0;
	while (i < count)
	{
		reverserotatea();
		i++;
	}
    
}

void    printtable(int  *tab)
{
	int i;

	i = 0;

	while (i < gl.topindex )
	{
		//printf("---- %d\n",tab[i]);
		i++;
	}
}

void    printtable2(int  *tab)
{
	int i;

	i = gl.topindex ;
	
	while (i < gl.argc - 1)
	{
		//printf("---- %d\n",tab[i]);
		i++;
	}
}

void    sortvaleures()
{
	int     i;

	while(checkifsorted(gl.tab,0,gl.topindex ) == 0)
	{
		if (gl.tab[gl.topindex - 1] > gl.tab[gl.topindex - 2])
			swapa(gl.pa);
		else if (gl.tab[gl.topindex - 1] > gl.tab[0])
		{
			reverserotatea();
		}
		else
			rotatea();
	}
}
int     main(int argc, char **argv)
{
	int     i;
	int j;

	int     *temp;
	i = 1;
	gl.topindex = argc - 1;
	gl.argc = argc;
	gl.pb = NULL;
	gl.pa = NULL;
	gl.tab = malloc(sizeof(int) * gl.topindex);
	i = 0;
	j = argc - 1;
	while (j > 0 )
	{
		gl.tab[i] = atoi(argv[j]);
		i++;
		j--;
	}
	temp = gl.tab;
	gl.sortedtable = malloc(sizeof(int) * gl.topindex );
	i = 0;
	while (i < gl.topindex)
	{
		gl.sortedtable[i] = gl.tab[i];
		i++;
	}

	if (argc == 4)
	{
		sortvaleures();
		printtable(gl.tab) ;
		return(0);
	}    
	gl.sortedtable = BubbleSort(gl.sortedtable,argc - 1);
	creata(0,gl.topindex , 0);
	while (1)
	{
		if (checkifsorted(gl.tab,0, gl.argc- 1) == 1 && (gl.topindex == (gl.argc - 1)))
			break;
		if (checkifsorted(gl.tab,gl.pa->index[0], gl.pa->index[1] - gl.pa->index[0]) == 0)
        	atob();
        else
        	btoa();

		
      //  printf("%d\n",gl.pa->index[1]);

	}
	  
    //printtable(gl.tab);
	//printf("--------- tab1\n");
	//printtable2(gl.tab);
	//printf("--------- tab2\n");
	return (0);
    
}
