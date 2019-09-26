#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>
#include <stdio.h>
typedef struct	s_list
{
	int				n;
	int				count;
	struct s_list *next;
}				t_list;
void	do_op(int operation, int n);
void	add(t_list **list, int n);
void	print(t_list **list);
#endif
