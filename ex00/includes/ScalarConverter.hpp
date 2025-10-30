/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:15:35 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/30 03:22:52 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
// #include <cstdlib>

class ScalarConverter {
    // private :
    //     ScalarConverter();
    //     ScalarConverter(const ScalarConverter& other);
    //     ScalarConverter& operator=(const ScalarConverter& other);
    //     ~ScalarConverter();
    
    public :
        static void convert(const std::string& number);

        static bool    isChar(const std::string& number);
        static bool    isInt(const std::string& number);
        static bool    isFloat(const std::string& number);
        static bool    isDouble(const std::string& number);
        static void    convertChar(const std::string& number);
        static void    convertInt(const std::string& number);
        static void    convertFloat(const std::string& number);
        static void    convertDouble(const std::string& number);
};