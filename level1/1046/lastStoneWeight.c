/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastStoneWeight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:51:37 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/26 02:14:48 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int lastStoneWeight(int* stones, int stonesSize) {
	int	len = stonesSize;
	if (len == 1)
		return (len);
	int	i = 0;
	int	j = 0;
	int	max;
	int	x = 0;
	int	y = 0;

	while(len > 0)
	{
		max = stones[0];
		for (i = 1; i < stonesSize; i++) {
			if (stones[i] > max)
				max = stones[i];
		}
		x = max;
		max = stones[0];
		for (i = 1; i < stonesSize; i++) {
			if (stones[i] > max || (stones[i] < max && stones[i] > x))
				max = stones[i];
		}
		y = max;
		if (y && x)
		{
			for (int z = 0; z < stonesSize; z++) {
				if (stones[z] == x || stones[z] == y)
				{
					stones[z] = 0;
					len--;	
				}
			}
			
		}
	}
	return (len);
}


int	main(void){
	int	stones[] = {2,7,4,1,8,1};
	int size = sizeof(stones) / sizeof(int);
	int	last = lastStoneWeight(stones, size);
	printf("%d\n", last);
	return (0);
}