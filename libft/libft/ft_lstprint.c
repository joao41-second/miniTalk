#include "libft.h"

void					ft_lstptint(t_list *lst,int dg)
{
	while(lst != NULL)
	{
		ft_putstr_fd(lst->content,dg);
		lst = lst->next;
	}	
}
