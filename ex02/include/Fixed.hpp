/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:05:14 by afavre            #+#    #+#             */
/*   Updated: 2023/06/06 15:12:30 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 value;
    static const int    bits = 8;

public:
    Fixed( void );
    Fixed( const int n );
    Fixed( const float n );
    Fixed( const Fixed &rhs );
    Fixed& operator=( const Fixed &rhs );
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    float   toFloat( void ) const;
    int     toInt( void ) const;

    bool    operator>( const Fixed &rhs ) const ;
    bool    operator<( const Fixed &rhs ) const ;
    bool    operator>=( const Fixed &rhs ) const ;
    bool    operator<=( const Fixed &rhs ) const ;
    bool    operator==( const Fixed &rhs ) const ;
    bool    operator!=( const Fixed &rhs ) const ;

    Fixed   operator+( const Fixed &rhs ) const ;
    Fixed   operator-( const Fixed &rhs ) const ;
    Fixed   operator*( const Fixed &rhs ) const ;
    Fixed   operator/( const Fixed &rhs ) const ;

    Fixed&  operator++( void ); // prefix
    int   operator++( int ); // postfix
    Fixed&  operator--( void ); // prefix
    int   operator--( int ); // postfix

    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif  // FIXED_HPP
