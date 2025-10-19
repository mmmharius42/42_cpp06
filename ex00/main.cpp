/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:37:29 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/19 18:21:07 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "You should have 1 arg" << std::endl;
        return 0;
    }
    std::string str(argv[1]);
    if (str.)
        std::cout << "catsh" << std::endl;
    else
        std::cout << "pas catsh" << std::endl;

}