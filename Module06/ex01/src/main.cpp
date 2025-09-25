/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:42:24 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 18:00:50 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/serializer.hpp"
#include "../inc/data.hpp"

int main() {
    Data data = {26, "Juan"};

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original: " << &data << " -> " << data.name << ", " << data.age << std::endl;
    std::cout << "After deserialization: " << ptr << " -> " << ptr->name << ", " << ptr->age << std::endl;

    if (ptr == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Failure: pointers differ." << std::endl;

    return (0);
}
