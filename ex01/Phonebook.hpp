/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:58 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:59 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook {
    private:
        Contact _contacts[8];
        int     _nb_contacts;

    public:
        Phonebook(void);
        ~Phonebook(void);

        void    add_contact(void);
        void    search_contact(void);
        void    display_contact(int id);
};

#endif