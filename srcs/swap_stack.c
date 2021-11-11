#include "../includes/push_swap.h"

void    ft_sa(t_push *push)
{
    if (!ft_swap_stack(push->stack_a))
        ft_putstr_fd("sa\n", 1);
}

void    ft_sb(t_push *push)
{
    if (!ft_swap_stack(push->stack_b))
        ft_putstr_fd("sb\n", 1);
}

void    ft_ss(t_push *push)
{
    ft_swap_stack(push->stack_a);
    ft_swap_stack(push->stack_b);
    ft_putstr_fd("ss\n", 1);
}