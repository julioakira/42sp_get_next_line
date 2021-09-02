/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:24:53 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/02 03:52:09 by jakira-p         ###   ########.fr       */
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

// Works as a global variable.
// Variable lifetime -> Automatic or Static.
// Scope -> Local or Global.
// Automatic or Local Variables -> Stored in the stack and deallocated after call stack.
// Static or Global Variables -> Stored in the heap deallocated only after program finishes execution.
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
