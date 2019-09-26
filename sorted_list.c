#include "sorted_list.h"

void	do_op(int operation, int n)
{
	static t_list	*list;

	if (operation == 0) //add
		add(&list, n);
	else if (operation == 1) //del
	{}
	else if (operation == 2) //print
		print(&list);
}

void	add(t_list **list, int n)
{
	t_list	*new;
	t_list	*prev;

	prev = NULL;
	while (*list && (*list)->n <= n)
	{
		if ((*list)->n == n)
		{
			(*list)->count++;
			return;
		}
		prev = *list;
		list = &(*list)->next;
	}
	new = (t_list*)malloc(sizeof(t_list));
	new->n = n;
	new->count = 1;
	new->next = NULL;
	if (!prev)
	{
		if (*list)
			new->next = *list;
		*list = new;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
}

void	print(t_list **list)
{
	while (*list)
	{
		printf("n: %d, count: %d\n", (*list)->n, (*list)->count);
		list = &(*list)->next;
	}
	printf("\n");
}
