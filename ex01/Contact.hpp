/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:41 by rilliano          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:42 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
    private:
		std::string	_fname;
		std::string	_lname;
		std::string	_nickname;
		std::string	_phone_num;
		std::string	_secret;

	public:
		Contact(void);
		~Contact(void);

		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_num(void) const;
		std::string	get_secret(void) const;

		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nickname(std::string str);
		void		set_phone_num(std::string str);
		void		set_secret(std::string str);
};

#endif