/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:04:41 by afavre            #+#    #+#             */
/*   Updated: 2023/05/22 19:04:50 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed( const int n ) : value( n << bits ) {
}

Fixed::Fixed( const float n ) : value( roundf( n * ( 1 << bits ) ) ) {
}

Fixed::Fixed( const Fixed &rhs ) {
    *this = rhs;
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    if ( this != &rhs )
        this->value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const {
    return this->value;
}

void    Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << bits );
}

int     Fixed::toInt( void ) const {
    return this->value >> bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

// comparaison operator

bool    Fixed::operator>( const Fixed &rhs ) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const {
    return this->getRawBits() != rhs.getRawBits();
}

// basic math operator

Fixed   Fixed::operator+( const Fixed &rhs ) const {
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ) const {
    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) const {
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ) const {
    return Fixed( this->toFloat() / rhs.toFloat() );
}

// increment - decrement operator

Fixed&   Fixed::operator++( void ) {
    ++this->value;
    return *this;
}

int   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp.value = this->value++;
    return tmp.toInt();
}

Fixed& Fixed::operator--( void ) {
    --this->value;
    return *this;
}

int Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp.value = this->value--;
    return tmp.toInt();
}

// MIN and MAX

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
