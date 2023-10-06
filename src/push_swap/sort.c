#include "stack.h"

void radix_sort(t_stack **stackA, t_stack **stackB) {
	int i;
	int size;
	int digit;

	digit = 1;
	size = stack_size(*stackA);
	while (!stack_is_sorted(*stackA, 1)) {
		i = 0;
		while (i < size) {
			if (((*stackA)->index & digit) > 0)
				ra(stackA);
			else
				pb(stackA, stackB);
			i++;
		}
		while (stack_size(*stackB) != 0)
			pa(stackA, stackB);
		digit = digit << 1;
	}
}

void ft_sort_3(t_stack **stack) {
	if ((*stack)->index == 2)
		ra(stack);
	else if ((*stack)->next->index == 2)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void ft_sort_5(t_stack **stackA, t_stack **stackB)
{
	while (stack_size(*stackA) > 3)
	{
		if (((*stackA)->index < (*stackA)->next->index) && (*stackA)->index != 0 && (*stackA)->index != 1)
			ra(stackA);

		else if (((*stackA)->index > (*stackA)->next->index) &&
			(*stackA)->index != 0 && (*stackA)->index != 1)
			sa(stackA);
		else if (((*stackA)->index == 0 || ((*stackA)->index == 1)))
			pb(stackA, stackB);
	}
	if ((*stackA)->index == 4)
		ra(stackA);
	else if ((*stackA)->next->index == 4)
		rra(stackA);
	if ((*stackA)->index > (*stackA)->next->index && (*stackB)->index == 1)
		sa(stackA);
	if ((*stackA)->index > (*stackA)->next->index && (*stackB)->index == 0)
		ss(stackA, stackB);
	if ((*stackB)->index == 0)
		sb(stackB);
	pa(stackA, stackB);
	pa(stackA, stackB);
}

