/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/01 18:18:03 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_mms_20200219/mlx.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
// Для gnl, открыть файл, пока он читает fd и 
// записывает line мы добавляем строки в нашу карту

void	do_map(t_list **head, int size)
{ // берем количество строк, добавляем +1 для зануления массива и
	char **map = ft_calloc(size + 1, sizeof(char *));
	int i = -1;
	t_list *temp_lst = *head; // временная переменная

	while (temp_lst)	// пока список существует (строки наши)
	{
		map[++i] = temp_lst->content; // добавляем строчку из этого списка	
		temp_lst = temp_lst->next; // проматываем список
	}
	i = -1;
	while (map[++i]) // пока есть строчки в карте, будем печатать
	{
		ft_putendl(map[i]); //  выводит строку s с символом переноса строки \n на стандартный вывод
	}
}

int		main(int argc , char *argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line = NULL;
	// t_list *head = NULL;

	while(get_next_line(fd, &line))
	{ //количество строк неопределено, потому она добавляются в список, считается размер и переводится в двумерный массив
	//  пока файл считывается	
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	// гнл вернет 0 мы считываем последний раз и отправляем функцию
	ft_lstadd_back(&head, ft_lstnew(line));
	do_map(&head, ft_lstsize(head));
}