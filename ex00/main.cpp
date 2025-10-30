/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:37:29 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/30 03:59:28 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "You should have 1 arg" << std::endl;
        std::cout << "./convert <number>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}