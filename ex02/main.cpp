/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:40:27 by mpapin            #+#    #+#             */
/*   Updated: 2025/11/13 15:54:15 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    Base* ptr = generate();
    std::cout << std::endl;
    
    std::cout << "Identify by pointer: ";
    identify(ptr);
    
    std::cout << "Identify by reference: ";
    identify(*ptr);
    
    std::cout << std::endl;
    
    delete ptr;
    
    std::cout << "\n--- Testing all types ---" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    std::cout << "A by pointer: ";
    identify(a);
    std::cout << "A by reference: ";
    identify(*a);
    
    std::cout << "B by pointer: ";
    identify(b);
    std::cout << "B by reference: ";
    identify(*b);
    
    std::cout << "C by pointer: ";
    identify(c);
    std::cout << "C by reference: ";
    identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}