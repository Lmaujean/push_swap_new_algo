#include "../includes/push_swap.h"

int	ft_stack_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

t_list		*ft_new_dlist(int content)
{
	t_list *new_dlist;

	new_dlist = malloc(sizeof(*new_dlist));
	if (new_dlist == NULL)
		return (NULL);
	new_dlist->value = content;
	new_dlist->next = NULL;
	new_dlist->back = NULL;
	return(new_dlist);
}

t_stack		*ft_new_stack(int content)
{
	t_list *new_dlist;
	t_stack *new_stack;

	new_stack = malloc(sizeof(*new_stack));
	new_dlist = ft_new_dlist(content);
	if (new_dlist == NULL && new_stack == NULL)
		return (NULL);
	new_stack->len = 1;
	new_stack->start = new_dlist;
	new_stack->end = new_dlist;
	return (new_stack);
}

t_stack		*ft_stack_addback(t_stack *stack, int content)
{
	t_list *list;

    if (ft_stack_empty(stack))
    {
		stack = ft_new_stack(content);
		return (stack);
    }
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->end->next = list;
	list->back = stack->end;
	stack->end = list;
	stack->len++;
	return (stack);
}

t_stack		*ft_stack_addfront(t_stack *stack, int content)
{
	t_list	*list;

	if (ft_stack_empty(stack))
	{
		stack = ft_new_stack(content);
		return (stack);
	}
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->start->back = list;
	list->next = stack->start;
	stack->start = list;
	stack->len++;
	return (stack);
}

t_stack		*ft_stack_delback(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->end);
		stack->end = NULL; 
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->end;
	stack->end = stack->end->back;
	stack->end->next = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

t_stack		*ft_stack_delfront(t_stack	*stack)
{
	t_list *temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->start);
		stack->start = NULL;
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->start;
	stack->start = stack->start->next;
	stack->start->back = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

t_stack		*ft_clear_stack(t_stack *stack)
{
	while (stack)
		stack = ft_stack_delback(stack);
	return (stack);
}


void	print_list(t_stack *stack)
{
	t_list *tmp;
	
	if (ft_stack_empty(stack))
	{
		printf("La stack est vide\n");
		return;
	}
	tmp = stack->start;
	while (tmp)
	{
		printf("[%d] \n", tmp->value);
		tmp = tmp->next;
	}
}

int		ft_reverse_stack(t_stack *stack)
{
	t_list 	*temp;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = stack->end;
	stack->end = temp->back;
	stack->start->back = temp;
	temp->next = stack->start;
	stack->start = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return(0);
}

int		ft_rotate_stack(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	temp = stack->start;
	stack->start = temp->next;
	stack->end->next = temp;
	stack->end = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return (0);
}

int	ft_swap_stack(t_stack *stack)
{
	int first;
	int	second;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->start == stack->end)
		return (1);
	first = stack->start->value;
	second = stack->start->next->value;
	stack = ft_stack_delfront(stack);
	stack = ft_stack_delfront(stack);
	stack = ft_stack_addfront(stack, first);
	stack = ft_stack_addfront(stack, second);
	return (0);
}

int		ft_push_stack(t_stack **dest, t_stack **src)
{
	if (ft_stack_empty(*src))
		return (1);
	*dest = ft_stack_addfront(*dest, (*src)->start->value);
	*src = ft_stack_delfront(*src);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_size_stack(t_stack * stack)
{
	t_list *temp;
	size_t size;

	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int		ft_stack_is_sort(t_stack *stack)
{
	t_list	*temp;
	
	temp = NULL;
	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	while (temp)
	{
		if (!temp->next)
			break ;
		if (temp->next->value < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_sort_3(t_push *push)
{
	if (!ft_stack_is_sort(push->stack_a))
		return (0);
	else if (push->stack_a->start->value < push->stack_a->start->next->value &&\
		push->stack_a->start->value < push->stack_a->end->value)
		{
			ft_sa(push);
			ft_ra(push);
		}
	else if (push->stack_a->start->value > push->stack_a->start->next->value &&\
			push->stack_a->start->value < push->stack_a->end->value)
		ft_sa(push);
	else if (push->stack_a->start->value < push->stack_a->start->next->value &&\
			push->stack_a->start->next->value > push->stack_a->end->value)
		ft_rra(push);
	else if (push->stack_a->start->value > push->stack_a->start->next->value &&\
			push->stack_a->start->next->value < push->stack_a->end->value)
		ft_ra(push);
	else
	{
			ft_sa(push);
			ft_rra(push);
	}
	return (0);
}



int		ft_get_index_min(t_stack *stack)
{
	int next_value;
	int value;
	int pos;
	t_list *tmp;

	pos = 1;
	value = stack->start->value;
	tmp = stack->start;
	while (tmp)
	{
		if (tmp->next)
		{
			next_value = tmp->next->value;
			if (value > next_value)
			{
				value = next_value;
			}
		}
		tmp = tmp->next;
		pos++;
	}
	return (value);
}



void ft_move(t_push *push)
{
	int min;
	
	min = ft_get_index_min(push->stack_a);
	while (push->stack_a->start->value != min)
		ft_ra(push);
	ft_pb(push);
}

void	ft_sort_4(t_push *push)
{
	ft_move(push);
	ft_sort_3(push);
	ft_pa(push);
}

void	ft_sort_5(t_push *push)
{
	ft_move(push);
	ft_move(push);
	ft_sort_3(push);
	ft_pa(push);
	ft_pa(push);
}

void	ft_sort(t_push *push)
{
	if (ft_stack_is_sort(push->stack_a) && push->stack_a->len == 2)
	 	ft_sa(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 3)
		ft_sort_3(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 4)
		ft_sort_4(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 5)
		ft_sort_5(push);
}

t_push	*ft_init_stack(t_push *push)
{
	push = malloc(sizeof(*push));
	push->stack_a = NULL;
	push->stack_b = NULL;
	return (push);
}

t_push	*ft_clear_push(t_push *push)
{
	while (push->stack_a)
		push->stack_a = ft_stack_delback(push->stack_a);
	while (push->stack_b)
		push->stack_b = ft_stack_delback(push->stack_b);
	free(push);
	push = NULL;
	return (push);
}