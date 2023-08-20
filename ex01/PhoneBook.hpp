/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:42:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/20 19:47:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  PhoneBook(const PhoneBook & obj);
  PhoneBook& operator=(const PhoneBook& obj);

 private:
  
};

#endif  // PHONEBOOK_HPP_
