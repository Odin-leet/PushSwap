#ifndef SWAP_H
# define SWAP_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>



typedef struct pa{
    int     index[2];
    int     statut;
    struct pa* next;
}           t_pa;



typedef struct global{
    t_pa    *pa;
    t_pa    *pb;
    int     *tab;
    int     *sortedtable;
    int     top;
    int     pivot;
    int     topindex;
    int     argc;
}           t_global;

void    swapa(t_global *gl);
void    swapb(t_global *gl);
void    pushb(t_global *gl);
void    pusha(t_global *gl);
void    rotatea(t_global *gl);
void    rotateb(t_global *gl);
void    reverserotatea(t_global *gl);
void    reverserotateb(t_global *gl);
void    creatb(int i, int j, int c,t_global *gl);
void    creata(int i, int j, int c,t_global *gl);
void    printtable(int *tab,t_global *gl);
void    printtable2(int *tab,t_global *gl);
void    sortvaleures(t_global *gl);

void    all_clear(void  *addr);

#endif