#include "../includes/push_swap.h"

void    ft_rra(t_push *push)
{
    if (!ft_reverse_stack(push->stack_a))
        ft_putstr_fd("rra\n", 1);
}

void    ft_rrb(t_push *push)
{
    if (!ft_reverse_stack(push->stack_b))
        ft_putstr_fd("rrb\n", 1);
}

void    ft_rrr(t_push *push)
{
    ft_reverse_stack(push->stack_a);
    ft_reverse_stack(push->stack_b);
    ft_putstr_fd("rrr\n", 1);
}

