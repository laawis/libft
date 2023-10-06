
#include "stack.h"
#include "libft.h" 

int    sa(t_stack **stackA)
{
    if (stack_swap(stackA) == -1)
        return (-1);
    ft_putendl_fd("sa", 1);
    return (0);
}

int    sb(t_stack **stackB)
{
    if (stack_swap(stackB) == -1)
        return (-1);
    ft_putendl_fd("sb", 1);
    return (0);
}

int    ss(t_stack **stackA, t_stack **stackB)
{
    if((stack_size(*stackA) < 2) || (stack_size(*stackB) < 2))
        return (-1);
    stack_swap(stackA);
    stack_swap(stackB);
    ft_putendl_fd("ss", 1);
    return (0);
}

int    pa(t_stack **stackA, t_stack **stackB)
{
    if (stack_push(stackB, stackA) == -1)
        return (-1);
    ft_putendl_fd("pa", 1);
    return (0);
}

int    pb(t_stack **stackA, t_stack **stackB)
{
    if (stack_push(stackA, stackB) == -1)
        return (-1);
    ft_putendl_fd("pb", 1);
    return (0);
}

int    ra(t_stack **stackA)
{
    if (stack_rotate(stackA) == -1)
        return (-1);
    ft_putendl_fd("ra", 1);
    return (0);
}

int    rb(t_stack **stackB)
{
    if (stack_rotate(stackB) == -1)
        return(-1);
    ft_putendl_fd("rb", 1);
    return (0);
}

int    rr(t_stack **stackA, t_stack **stackB)
{
    if ((stack_size(*stackA) < 2) || (stack_size(*stackB) < 2))
        return (-1);
    stack_rotate(stackA);
    stack_rotate(stackB);
    ft_putendl_fd("rr", 1);
    return (0);
}

int    rra(t_stack **stackA)
{
    if (stack_reverse_rotate(stackA) == -1)
        return (-1);
    ft_putendl_fd("rra", 1);
    return (0);
}

int    rrb(t_stack **stackB)
{
    if (stack_reverse_rotate(stackB) == -1)
        return (-1);
    ft_putendl_fd("rrb", 1);
    return (0);
}

int    rrr(t_stack **stackA, t_stack **stackB)
{
    if ((stack_size(*stackA) <2) || (stack_size(*stackB) < 2))
        return (-1);
    stack_reverse_rotate(stackA);
    stack_reverse_rotate(stackB);
    ft_putendl_fd("rrr", 1);
    return (0);
}
