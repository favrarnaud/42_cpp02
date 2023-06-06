/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:04:41 by afavre            #+#    #+#             */
/*   Updated: 2023/06/06 15:11:01 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
    if (this != &copy)
        this->value = copy.getRawBits();
}

Fixed::Fixed(int valueI)
{
    std::cout << "contructor with int value" << std::endl;
    this->value = valueI << this->bits;
}

Fixed::Fixed(float valueF)
{
    this->value = roundf(valueF * (1 << this->bits));
    std::cout << "contructor with float value" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy.getRawBits());
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float   Fixed::toFloat() const
{
    return static_cast<float>(this->getRawBits()) / (1 << this->bits);
}

int     Fixed::toInt() const
{
    return this->value >> this->bits;
}

std::ostream & operator<<( std::ostream &o, Fixed const &i )
{
    o << i.toFloat();
    return o;
}
