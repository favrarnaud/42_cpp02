/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:05:14 by afavre            #+#    #+#             */
/*   Updated: 2023/05/22 19:05:16 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(Fixed const &copy);

	int getRawBits() const;
    void setRawBits(int const raw);
private:
	int value;
	int const static bits = 8;
};

#endif
