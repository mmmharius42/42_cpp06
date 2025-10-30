/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:15:35 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/30 03:51:49 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>      // std::string
#include <iostream>    // std::cout
#include <cctype>      // isdigit(), isprint()
#include <cstdlib>     // strtod(), strtol()
#include <climits>     // INT_MAX, INT_MIN
#include <limits>      // numeric_limits
#include <cmath>       // isnan(), isinf()
#include <iomanip>     // fixed, setprecision

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool isChar(const std::string& number);
        static bool isInt(const std::string& number);
        static bool isFloat(const std::string& number);
        static bool isDouble(const std::string& number);
        
        static void convertChar(const std::string& number);
        static void convertInt(const std::string& number);
        static void convertFloat(const std::string& number);
        static void convertDouble(const std::string& number);
        
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
        static double parse(const std::string& number);
        
    public:
        static void convert(const std::string& number);
};

#endif