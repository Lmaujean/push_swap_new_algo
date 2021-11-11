#include "../includes/push_swap.h"

void    ft_ra(t_push *push)
{
    if (!ft_rotate_stack(push->stack_a))
        ft_putstr_fd("ra\n", 1);
}

void    ft_rb(t_push *push)
{
    if (!ft_rotate_stack(push->stack_b))
        ft_putstr_fd("rb\n", 1);
}

void    ft_rr(t_push *push)
{
    ft_rotate_stack(push->stack_a);
    ft_rotate_stack(push->stack_b);
    ft_putstr_fd("rr\n", 1);
}