/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:27:04 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/30 03:24:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& number) {
    if (isChar(number))
        convertChar(number);
    if (isInt(number))
        convertInt(number);
    if (isFloat(number))
        convertFloat(number);
    if (isDouble(number))
        convertDouble(number);
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
