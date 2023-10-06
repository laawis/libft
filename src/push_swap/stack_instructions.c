#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int    stack_swap(t_stack **stack)
{
    t_stack    *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);
    tmp = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    tmp->next = *stack;
    *stack = tmp;
    return (0);
}


int    stack_push(t_stack **stack_src, t_stack **stack_dest)
{
    t_stack    *tmp;

    if (*stack_src == NULL)
        return (-1);
    tmp = *stack_src;
    *stack_src = (*stack_src)->next;
    stack_add_front(stack_dest, tmp);
    return (0);
}

int    stack_rotate(t_stack **stack)
{
    t_stack    *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    stack_add_back(stack, tmp);
    return (0);
}



int    stack_reverse_rotate(t_stack **stack)
{
    t_stack    *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);
    tmp = *stack;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next->next = *stack;
    *stack = tmp->next;
    tmp->next = NULL;
    return (0);
}

int    reverse_stack(t_stack **stack)
{
    t_stack    *new_stack;
    t_stack    *current;
    t_stack    *next;

    new_stack = NULL;
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        current->next = new_stack;
        new_stack = current;
        current = next;
    }
    *stack = new_stack;
    return (0);
}

