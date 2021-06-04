#include "swap.h"

void    swapa(t_pa *temp)
{
    int     swap;

    swap = gl.tab[gl.topindex - 1];
    gl.tab[gl.topindex - 1] = gl.tab[gl.topindex - 2];
    gl.tab[gl.topindex - 2] = swap; 
}

void    swapb(t_pa *temp)
{
    int     swap;

    swap = gl.tab[gl.topindex ];
    gl.tab[gl.topindex ] = gl.tab[gl.topindex + 1];
    gl.tab[gl.topindex + 1] = swap; 
}

void    pushb()
{
    gl.pa->index[1]--;
    gl.pb->index[0]--;
    gl.topindex--; 
}
void    pusha()
{
    gl.pa->index[1]++;
    gl.pb->index[0]++; 
    gl.topindex++;
}
void    rotatea()
{
    int     temp;
    int     temp2;
    int     i;

    i = gl.topindex - 1;
    temp = gl.tab[gl.topindex - 1];
    while (i > 0)
    {
        temp2 = gl.tab[i];
        gl.tab[i] = gl.tab[i - 1];
        i--;
    }
      printf("rra ------- %d --- %d\n  ",temp,gl.topindex);
    gl.tab[0] = temp;
}

void    rotateb()
{
    int     i;
    int     temp;

    i = gl.topindex ;
    temp = gl.tab[gl.topindex];
    while (i < gl.argc - 2)
    {
        gl.tab[i] = gl.tab[i + 1];
        i++;
    }
    gl.tab[i] = temp;
}
void    reverserotatea(void)
{
    int     i;
    int     temp;
    int     temp2;

    i = 0;
    temp = gl.tab[0];
    while (i < gl.topindex - 1)
    {
        //temp2 = gl.tab[i];
        gl.tab[i ] = gl.tab[i + 1];
        i++;
    }
  
    gl.tab[gl.topindex - 1] = temp;

}

void    reverserotateb(void)
{
    int     i;
    int     temp;

    i = gl.argc;
    temp = gl.tab[gl.argc - 1];
    while (i >  gl.topindex + 1)
    {
        gl.tab[i] = gl.tab[i - 1];
        i--;
    }
    gl.tab[gl.topindex ] = temp;

}