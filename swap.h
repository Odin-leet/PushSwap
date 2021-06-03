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
}           t_global;
t_global gl;



#endif