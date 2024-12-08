/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:53 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/08 22:15:34 by rilliano         ###   ########.fr       */
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
    std::cout << "Destroying phonebook. Goodbye!" << std::endl;
    return ;
}

void    Phonebook::add_contact(void) {
    std::string str;

    if (this->_nb_contacts > 7) {
        std::cout << "Overwriting contact: " 
                  << this->_contacts[this->_nb_contacts % 8].get_fname() 
                  << " - ID: " 
                  << this->_nb_contacts % 8 
                  << std::endl;
    }

    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << "Enter first name: ";
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

    if (!std::cin.eof())
        this->_nb_contacts++;
}

int string_to_int(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return result;
}

void    Phonebook::search_contact(void) {
    int id;
    std::string str;

    if (this->_nb_contacts == 0) {
        std::cout << "No contacts available" << std::endl;
        return ;
    }

    while (!std::cin.eof() && str == "") {
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
        id = string_to_int(str);
        if (id >= this->_nb_contacts) {
            std::cout << "Contact not found. Please enter a valid id." << std::endl << std::endl;
            str = "";
        }
    }

    if (!std::cin.eof())
        this->display_contact(id);
}

Contact Phonebook::get_contact_by_id(int id) {
    if (id >= 0 && id < this->_nb_contacts) {
        return _contacts[id];
    } else {
        std::cerr << "Invalid contact ID" << std::endl;
        return Contact();
    }
}

std::string format_field(const std::string& field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    } else {
        return std::string(10 - field.length(), ' ') + field;
    }
}

void    Phonebook::display_contact(int id) {
    Contact contact = get_contact_by_id(id);

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    std::stringstream ss;
    ss << id;
    std::string index = format_field(ss.str());
    std::string first_name = format_field(contact.get_fname());
    std::string last_name = format_field(contact.get_lname());
    std::string nickname = format_field(contact.get_nickname());

    std::cout << index << "|" << first_name << "|" << last_name << "|" << nickname << std::endl;
}
