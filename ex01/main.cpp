/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:45 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 19:07:47 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void) {

    Phonebook pb;
    std::string str;

    while (str != "EXIT") {
        std::cout << "Enter a command: ";
        std::getline(std::cin, str);
        if (!std::cin.good())
        {
            std::cout << "EXIT" << std::endl;
            break;
        }
        if (str == "ADD") {
            pb.add_contact();
            std::cout << std::endl;
        } else if (str == "SEARCH") {
            pb.search_contact();
            std::cout << std::endl;
        } else if (str != "" && str != "EXIT") {
            std::cout << std::endl << "Invalid command! Available commands:\nADD\nSEARCH\nEXIT" << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "Destroying phonebook. Goodbye!" << std::endl;
    return (0);
}