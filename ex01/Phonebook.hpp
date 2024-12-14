/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:58 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/08 23:30:30 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook {
    private:
        Contact _contacts[8];
        int     _nb_contacts;

    public:
        Phonebook(void);
        ~Phonebook(void);

        Contact get_contact_by_id(int id);
        
        void    add_contact(void);
        void    search_contact(void);
        void    display_contact(int id);
};

#endif