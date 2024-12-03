/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:16 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:18 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i;

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	argv++;
	while (*argv) {
		i = 0;
		while((*argv)[i])
			std::cout << (char)toupper((*argv)[i++]);
		argv++;
		if (*argv)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
