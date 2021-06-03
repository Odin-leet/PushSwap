#include "swap.h"

void    swapa(t_pa *temp)
{
    int     swap;

    swap = gl.tab[temp->index[1]];
    gl.tab[temp->index[1]] = gl.tab[temp->index[1] - 1];
    gl.tab[temp->index[1] - 1] = swap; 
}

void    swapb(t_pa *temp)
{
    int     swap;

    swap = gl.tab[temp->index[1]];
    gl.tab[temp->index[1]] = gl.tab[temp->index[1] - 1];
    gl.tab[temp->index[1] - 1] = swap; 
}

void    pushb()
{
    gl.pa->index[1]--;
    gl.pb->index[0]++; 
}
void    pusha()
{
    gl.pa->index[1]++;
    gl.pb->index[0]--; 
}
void    rotatea()
{
    int     temp;
    int     temp2;
    int     i;

    i = gl.pa->index[1];
    temp = gl.tab[gl.pa->index[1]];
    while (i >= 1)
    {
        temp2 = gl.tab[i];
        gl.tab[i] = gl.tab[i - 1];
        i--;
    }
    gl.tab[0] = temp;
}

void    rotateb()
{
    int     i;
    int     temp;

    i = gl.pb->index[0];
    temp = gl.tab[gl.pb->index[0]];
    while (i > gl.pb->index - 1)
    {
        gl.tab[i] = gl.tab[i - 1];
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
    temp = gl.tab[gl.pa->index[0]];
    while (i < gl.pa->index[1])
    {
        temp2 = gl.tab[i];
        gl.tab[i ] = gl.tab[i + 1];
        i++;
    }
    gl.tab[gl.pa->index[1]] = temp;

}
void    reverserotateb(void)
{
    int     i;
    int     temp;

    i = gl.pa->index[1];
    temp = gl.tab[gl.pb->index[1]];
    while (i >  gl.pb->index[0])
    {
        gl.tab[i] = gl.tab[i - 1];
        i--;
    }
    gl.tab[gl.pb->index[0]] = temp;

}