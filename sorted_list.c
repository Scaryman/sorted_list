#include "sorted_list.h"

void	do_op(int operation, int n)
{
	static t_list	*list;

	if (operation == 0) //add
		add(&list, n);
	else if (operation == 1) //del
		del(&list, n);
	else if (operation == 2) //print
		print(&list);
}

void	add(t_list **list, int n)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp && tmp->n <= n)
	{
		if (tmp->n == n)
		{
			tmp->count++;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	new = (t_list*)malloc(sizeof(t_list));
	new->n = n;
	new->count = 1;
	if (!prev)
	{
		new->next = tmp;
		*list = new;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
}

void	del(t_list **list, int n)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	if (tmp && tmp->n == n)
	{
		*list = tmp->next;
		free(tmp);
	}
	while (tmp && tmp->n != n)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return;
	prev->next = tmp->next;
	free(tmp);
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
