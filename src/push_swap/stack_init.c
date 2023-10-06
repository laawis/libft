#include <stdlib.h>
#include <errno.h>

#include "libft.h"

#include "stack.h"

static int	  is_correct_input(char **argv);
static int    is_number(const char *s);
static int    have_duplicates(char **argv);
static size_t give_index(char **arguments, int argc, int nb);

int stack_init(int argc, char **argv, t_stack **stackA)
{
  t_stack	*new_element;
  int	    index;
  int		i;

  i = 1;
  while (argc > 1 && i < argc)
  {
    if (!is_correct_input(argv))
	   return (-1);
	index = give_index(argv, argc, ft_atoi(argv[i]));
    new_element = stack_new_element(atoi(argv[i]), index);
    if (new_element == NULL)
        return (-1);
    stack_add_front(stackA, new_element);
    i++;
  }
  reverse_stack(stackA);
  return (0);
}

static int	is_correct_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
        ft_atoi(argv[i]);
		if (errno == ERANGE)
			return (0);
		i++;
	}
	if (have_duplicates(argv))
		return (0);
	return (1);
}

static int    is_number(const char *s)
{
	int    i;
    
    i = 0;
    while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
    if (s[i] == '-' || s[i] == '+')
        i++;
    if (s[i] == '\0')
        return (0);
    while (s[i])
    {
        if (ft_isdigit(s[i])) 
            i++;
        else
            return (0);
    }
	return (1);
}

static int    have_duplicates(char **argv)
{
   int	i;
   int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0); 
}

static size_t give_index(char **arguments, int argc, int nb)
{
  int i;
  int index;

  i = 1;
  index = 0;
  while (i < argc) 
  {
    if (ft_atoi(arguments[i]) < nb) 
    {
      index++;
    }
    i++;
  }
  return (index);
}

