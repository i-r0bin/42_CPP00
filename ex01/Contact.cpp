/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:33 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:36 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
    return ;
}

Contact::~Contact(void) {
    return ;
}

std::string	Contact::get_fname(void) const {
    return (this->_fname);
}

void	Contact::set_fname(std::string str) {
    this->_fname = str;
}

std::string	Contact::get_lname(void) const {
    return (this->_lname);
}

void	Contact::set_lname(std::string str) {
    this->_lname = str;
}

std::string	Contact::get_nickname(void) const {
    return (this->_nickname);
}

void	Contact::set_nickname(std::string str) {
    this->_nickname = str;
}

std::string	Contact::get_phone_num(void) const {
    return (this->_phone_num);
}

void	Contact::set_phone_num(std::string str) {
    this->_phone_num = str;
}

std::string	Contact::get_secret(void) const {
    return (this->_secret);
}

void	Contact::set_secret(std::string str) {
    this->_secret = str;
}
