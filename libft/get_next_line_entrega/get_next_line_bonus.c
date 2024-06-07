/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:09:50 by jperpect          #+#    #+#             */
/*   Updated: 2024/05/24 18:26:01 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fre(int va1, int va2, char *cha1, char *cha2)
{
	if (va1 == 1)
		free(cha1);
	if (va2 == 1)
		free(cha2);
	return (NULL);
}

static void	*whilee(char *save, int fd, char *rest)
{
	int		n;
	char	*ret_tmp;

	ret_tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (ret_tmp == NULL)
		return (NULL);
	while (ft_caract_cont(save) <= 0)
	{
		ft_bzero(ret_tmp, BUFFER_SIZE + 1);
		n = read(fd, ret_tmp, BUFFER_SIZE);
		if (n != 0)
		{
			save = ft_concatenat_str(save, ret_tmp);
			if (save == NULL)
				fre(1, 0, ret_tmp, rest);
		}
		if (ft_strlen(ret_tmp) == 0 && ft_strlen(save) == 0)
			return (fre(1, 1, ret_tmp, save));
		ft_bzero(ret_tmp, ft_strlen(ret_tmp) + 1);
		if (n != BUFFER_SIZE)
			break ;
	}
	if (ret_tmp)
		free(ret_tmp);
	return (save);
}

static char	*get_next_lines(int fd)
{
	char		*save[1024];
	static char	*rest[1024];
	int			len_save;
	int			i;

	i = 0;
	save[fd] = rest[fd];
	len_save = 0;
	save[fd] = whilee((char *)save[fd], fd, (char *)rest[fd]);
	if (save[fd] == NULL)
		return (NULL);
	if (len_save == 0)
		len_save = ft_strlen(save[fd]);
	while (save[fd][i] != '\n' && len_save > i)
		i++;
	if (i == 0 && save[fd][i] != '\n')
		return (fre(1, 1, (char *)rest[fd], (char *)save[fd]));
	rest[fd] = ft_copy(&save[fd][i + 1], len_save - i, 0);
	if (rest[fd] == NULL)
		return (fre(1, 0, (char *)save[fd], (char *)rest[fd]));
	return (ft_copy((char *)save[fd], i + 1, 1));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_next_lines(fd));
}

//  int main(void)
// {
// 	int id_arqi = 0;//"open("0", O_RDONLY);"
// 	int id_arqi2 = open("testecopy.text", O_RDONLY);
// 	char *ok;
// 	char *oks;
// 	ok =  get_next_line(id_arqi);
// 	oks =  get_next_line(id_arqi2);
// 	 while(ok !=NULL)
// 	 {	printf("-%s",ok);
// 	 	printf("-%s",oks);
// 		free (ok);
// 		free (oks);
// 	 	ok = get_next_line(id_arqi);
// 		oks = get_next_line(id_arqi2);
// 	 }
//  }