/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:27:04 by mpapin            #+#    #+#             */
/*   Updated: 2025/11/13 15:18:49 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& number) {
    if (isChar(number))
        convertChar(number);
    else if (isInt(number))
        convertInt(number);
    else if (isFloat(number))
        convertFloat(number);
    else if (isDouble(number))
        convertDouble(number);
    else
        std::cout << "Invalid input" << std::endl;
}

bool ScalarConverter::isChar(const std::string& number) {
    return number.length() == 3 && number[0] == '\'' && number[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& number) {
    if (number.empty())
        return false;
    size_t i = 0;
    if (number[0] == '+' || number[0] == '-')
        i++;
    if (i >= number.length())
        return false;
    while (i < number.length()) {
        if (!isdigit(number[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& number) {
    if (number.empty() || number[number.length() - 1] != 'f')
        return false;
    if (number == "nanf" || number == "+inff" || number == "-inff")
        return true;
    size_t i = 0;
    bool point = false;
    bool digit = false;
    if (number[0] == '+' || number[0] == '-')
        i++;
    while (i < number.length() - 1) {
        if (isdigit(number[i]))
            digit = true;
        else if (number[i] == '.') {
            if (point)
                return false;
            else
                point = true;
        }
        else
            return false;
        i++;
    }
    return digit;
}

bool ScalarConverter::isDouble(const std::string& number) {
    if (number.empty())
        return false;
    if (number == "nan" || number == "+inf" || number == "-inf")
        return true;
    size_t i = 0;
    bool point = false;
    bool digit = false;
    if (number[0] == '+' || number[0] == '-')
        i++;
    while (i < number.length()) {
        if (isdigit(number[i]))
            digit = true;
        else if (number[i] == '.') {
            if (point)
                return false;
            else
                point = true;
        }
        else
            return false;
        i++;
    }
    return digit && point;
}

double ScalarConverter::parse(const std::string& number) {
    if (number == "nanf" || number == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    if (number == "+inff" || number == "+inf")
        return std::numeric_limits<double>::infinity();
    if (number == "-inff" || number == "-inf")
        return -std::numeric_limits<double>::infinity();
    
    char* end;
    return strtod(number.c_str(), &end);
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else if (value < 0 || value > 127 || value != static_cast<int>(value))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else if (value < static_cast<double>(INT_MIN) || 
             value > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    float f = static_cast<float>(value);
    
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else {
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convertChar(const std::string& number) {
    double value = static_cast<double>(number[1]);
    
    std::cout << "char: '" << number[1] << "'" << std::endl;
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertInt(const std::string& number) {
    double value = parse(number);
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFloat(const std::string& number) {
    double value = parse(number);
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertDouble(const std::string& number) {
    double value = parse(number);
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}