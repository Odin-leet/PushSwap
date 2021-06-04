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
t_global gl;
void    swapa(t_pa *temp);
void    swapb(t_pa *temp);
void    pushb();
void    pusha();
void    rotatea();
void    rotateb();
void    reverserotatea(void);
void    reverserotateb(void);
void    creatb(int i, int j, int c);
void    creata(int i, int j, int c);
void    printtable();
void    printtable2();



#endif