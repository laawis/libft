i#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

t_stack *stack_new_element(int nb, int index)
{
  t_stack *new_element;

  new_element = malloc(sizeof(t_stack));
  if (new_element == NULL)
    return (NULL);
  new_element->nb = nb;
  new_element->index = index;
  new_element->next = NULL;
  return (new_element);
}

int stack_add_front(t_stack **list, t_stack *new_element)
{
  if (new_element == NULL || list == NULL)
    return (0);
  new_element->next = *list;
  *list = new_element;
  return (1);
}

t_stack    *last_element(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (stack)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

int    stack_add_back(t_stack **stack, t_stack *new_element)
{
	t_stack	*tmp;

	if (stack != NULL)
	{
		if (*stack == NULL)
        {
			*stack = new_element;
            return (0);
        }
		else
		{
			tmp = last_element(*stack);
			tmp->next = new_element;
            return (0);
		}
	}
    return (-1);
}

int stack_size(t_stack *stack) {
  int i;
  t_stack *tmp;

  tmp = stack;
  i = 0;
  while (tmp != NULL) {
    tmp = tmp->next;
    i++;
  }
  return (i);
}
