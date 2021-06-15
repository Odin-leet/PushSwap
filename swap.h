#ifndef SWAP_H
# define SWAP_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pa{
	int			index[2];
	int			statut;
	struct s_pa	*next;
}				t_pa;
typedef struct s_global{
	t_pa	*pa;
	t_pa	*pb;
	t_pa	*tmp;
	int		*tab;
	int		*sortedtable;
	int		top;
	int		pivot;
	int		topindex;
	int		argc;
}				t_global;

void	functionif(int size, t_global *gl);
void	reversefunction(t_global *gl, int count);
void	addb(t_global *gl);
void	adda(t_global *gl);
void	btoa(t_global *gl);
void	atob(t_global *gl);
void	swapa(t_global *gl);
void	swapb(t_global *gl);
void	pushb(t_global *gl);
void	pusha(t_global *gl);
void	rotatea(t_global *gl);
void	rotateb(t_global *gl);
void	reverserotatea(t_global *gl);
void	reverserotateb(t_global *gl);
void	creata(int i, int j, int c, t_global *gl);
void	printtable(int *tab, t_global *gl);
void	printtable2(int *tab, t_global *gl);
void	sortvaleures(t_global *gl);
void	all_clear(void *addr);
int	*BubbleSort(int *a, int array_size);
int	checkifsortedfinal(int *tab, int start, int size, t_global *gl);
int	checkifsorted(int *tab, int start, int size);
int	functionwhile2(t_global *gl);
void	functioneelse(t_global *gl);
int	functionwhile(t_global *gl);
void	replirtableau(t_global *gl, char **argv, int j);
void	replirsortedtable(t_global *gl);
void	init(t_global *gl, int argi, char **argv1);
void	freefuntion(t_global *gl);

#endif
