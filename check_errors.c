#include "push_swap.h"

int checkdb(t_list *look)
{
	t_list *look2;
	t_list *look3;
	
	look3 = look;
	look2 = look3->next;
	if(look->content > INT_MAX || look->content < INT_MIN) // HANDLE THE FIST NODE CONTENT MINMAX
		return (1);
	while (look3)
	{
		look2 = look3->next;
		while (look2)
		{
			if ((look3->content == look2->content) || (look3->content > INT_MAX || look3->content < INT_MIN)) // HANDLE: MAXMIN AND DOUBLES
				return (1);
			look2 = look2->next;
		}
		look3 = look3->next;
	}
	return (0);
}
int checksp(char *str)
{
	int i;
	i = 0;
	while (str[i] == 32)
	{
		if (str[i + 1] == '\0')
			return (1);
	i++;
	}
	return (0);
} 

int checkdig(char *str)
{
	int i;
	i = 0;

	if (str[0] == '\0')
		return (1);
	
	while (str[i])
	{
		if (((ft_isdigit(str[i]) == 0 && str[i] != 32 && str[i] != '-' && str[i] != '+')\
		|| (str[i] == '+' && ft_isdigit(str[i + 1]) == 0) || (str[i] == '-' && ft_isdigit(str[i + 1]) == 0))\
		|| (ft_isdigit(str[i]) == 1 && str[i + 1] == '-' ) || (ft_isdigit(str[i]) == 1 && str[i + 1] == '+' ))
		{
				return (1);
		}
	i++;
	}
	return (0);
}

void retatoi(char *p, t_list **stack_a)
{
	long atoiret;
	char **b;
	int i;

	atoiret = 0;
	i = 0;
	b = ft_split(p, 32);

	while (b[i])
	{
		atoiret = ft_atoi(b[i]);	
		ft_lstadd_back(stack_a, ft_lstnew(atoiret)); // NEED TO HANDLE NULL OF LSTNEW !!
		i++;
	}
}
