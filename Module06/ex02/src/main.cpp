/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:42:33 by volmer            #+#    #+#             */
/*   Updated: 2025/09/26 12:43:42 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Base.hpp"
#include "../inc/creator.hpp"

int main() {
    for (int i = 0; i < 10; ++i) {
        Base* p = generate();
        identify(p);    // versión puntero
        identify(*p);   // versión referencia
        delete p;
    }
    return 0;
}
