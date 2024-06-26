#include "libft.h"

void					ft_lstptint(t_list *lst,int dg)
{
	t_list	*lsts = lst;
	while(lsts != NULL)
	{
		ft_putstr_fd(lsts->content,dg);
		free(lsts->content);

		lsts = lsts	->next;
	}	
}