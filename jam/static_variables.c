/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:24:53 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/24 23:28:38 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

int	add_one_static(void)
{
	static int nbr = 0;
	nbr++;
	return (nbr);
}

int	add_one_non_static(void)
{
	int nbr = 0;
	nbr++;
	return (nbr);
}

int main(void)
{
	printf("Value of static nbr: %d\n", add_one_static());
	printf("Value of static nbr: %d\n", add_one_static());
	printf("Value of static nbr: %d\n", add_one_static());
	printf("Value of static nbr: %d\n", add_one_static());
	printf("Value of static nbr: %d\n", add_one_static());
	printf("Value of dynamic nbr: %d\n", add_one_non_static());
	printf("Value of dynamic nbr: %d\n", add_one_non_static());
	printf("Value of dynamic nbr: %d\n", add_one_non_static());
	printf("Value of dynamic nbr: %d\n", add_one_non_static());
	printf("Value of dynamic nbr: %d\n", add_one_non_static());
}
