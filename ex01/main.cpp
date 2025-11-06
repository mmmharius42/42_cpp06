/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:37:25 by mpapin            #+#    #+#             */
/*   Updated: 2025/11/06 03:38:27 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.id = 42;
    data.name = "Test";
    data.value = 3.14;
    
    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data content: id=" << data.id 
              << ", name=" << data.name 
              << ", value=" << data.value << std::endl;
    std::cout << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << std::endl;
    
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data content: id=" << ptr->id 
              << ", name=" << ptr->name 
              << ", value=" << ptr->value << std::endl;
    std::cout << std::endl;
    
    if (ptr == &data)
        std::cout << "✓ Success: Pointers are equal!" << std::endl;
    else
        std::cout << "✗ Error: Pointers are different!" << std::endl;
    
    return 0;
}