/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:53 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:54 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
    this->_nb_contacts = 0;
    std::cout << "Welcome. A new phonebook has been created." << std::endl;
    std::cout << "You can ADD a new contact or SEARCH for an existing one by id." << std::endl << std::endl;
    return ;
}

Phonebook::~Phonebook(void) {
    return ;
}

void    Phonebook::add_contact(void) {
    std::string str;

    if (this->_nb_contacts > 7) {
        std::cout << "Overwriting contact: " << this->_contacts[this->_nb_contacts % 8].get_fname() << std::endl;
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter first name: ";
        std::cin.ignore();
        if (std::getline(std::cin, str) && str != "") {
            this->_contacts[this->_nb_contacts % 8].set_fname(str);
        }
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter last name: ";
        if (std::getline(std::cin, str) && str != "") {
            this->_contacts[this->_nb_contacts % 8].set_lname(str);
        }
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter nickname: ";
        if (std::getline(std::cin, str) && str != "") {
            this->_contacts[this->_nb_contacts % 8].set_nickname(str);
        }
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter phone number: ";
        if (std::getline(std::cin, str) && str != "") {
            if (str.length() != 10 || str.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "Invalid phone number. Please enter a 10-digit phone number." << std::endl << std::endl;
                str = "";
                continue ;
            }
            this->_contacts[this->_nb_contacts % 8].set_phone_num(str);
        }
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter darkest secret: ";
        if (std::getline(std::cin, str) && str != "") {
            this->_contacts[this->_nb_contacts % 8].set_secret(str);
        }
    }

    this->_nb_contacts++;
}

void    Phonebook::search_contact(void) {
    int id;
    std::string str;

    if (this->_nb_contacts == 0) {
        std::cout << "No contacts available" << std::endl;
        return ;
    }

    while (str == "") {
        std::cout << "Enter an id: ";
        std::getline(std::cin, str);
        if (str == "") {
            continue ;
        }
        if (str.find_first_not_of("01234567") != std::string::npos) {
            std::cout << "Invalid id. Please enter a number between 0 and 7." << std::endl << std::endl;
            str = "";
            continue ;
        }
        id = std::stoi(str);
        if (id >= this->_nb_contacts) {
            std::cout << "Contact not found. Please enter a valid id." << std::endl << std::endl;
            str = "";
        }
    }

    this->display_contact(id);
}

void    Phonebook::display_contact(int id) {
    std::cout << "First name: " << this->_contacts[id].get_fname() << std::endl;
    std::cout << "Last name: " << this->_contacts[id].get_lname() << std::endl;
    std::cout << "Nickname: " << this->_contacts[id].get_nickname() << std::endl;
    std::cout << "Phone number: " << this->_contacts[id].get_phone_num() << std::endl;
    std::cout << "Darkest secret: " << this->_contacts[id].get_secret() << std::endl;
}
