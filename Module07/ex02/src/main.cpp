/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:53:55 by volmer            #+#    #+#             */
/*   Updated: 2025/09/30 17:49:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "../inc/array.hpp"

// Tipo de prueba para verificar copias/assign y default-init
struct Box {
    int v;
    Box() : v(0) {}                   // default-init
    Box(int x) : v(x) {}
    // copy/assign por defecto sirven para el test
};

template <typename T>
void printArray(const Array<T>& a, const std::string& name) {
    std::cout << name << " (size=" << a.size() << "): [";
    for (unsigned int i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "== Test 1: constructor por tamaño + escritura/lectura ==\n";
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i) a[i] = (int)i * 10;
    printArray(a, "a");

    std::cout << "\n== Test 2: copia profunda (ctor copia) ==\n";
    Array<int> b = a;   // copy-ctor
    b[0] = 999;
    printArray(a, "a");
    printArray(b, "b");

    std::cout << "\n== Test 3: operador= (asignación) ==\n";
    Array<int> c;
    c = a;              // operator=
    c[1] = 777;
    printArray(a, "a");
    printArray(c, "c");

    std::cout << "\n== Test 4: out_of_range en operator[] ==\n";
    try {
        std::cout << a[10] << "\n";  // debe lanzar
    } catch (const std::exception& e) {
        std::cout << "Exception capturada: " << e.what() << "\n";
    }

    std::cout << "\n== Test 5: Array vacío ==\n";
    Array<std::string> s0;
    std::cout << "s0.size() = " << s0.size() << "\n";
    try {
        std::cout << s0[0] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception en s0[0]: " << e.what() << "\n";
    }

    std::cout << "\n== Test 6: std::string ==\n";
    Array<std::string> s(3);
    s[0] = "hola";
    s[1] = "mundo";
    s[2] = "42";
    printArray(s, "s");

    std::cout << "\n== Test 7: tipo usuario (Box) default-init y copia ==\n";
    Array<Box> bx(4);           // default-init => v=0
    for (unsigned int i = 0; i < bx.size(); ++i) bx[i].v = (int)i + 1;
    std::cout << "bx: [";
    for (unsigned int i = 0; i < bx.size(); ++i) {
        std::cout << bx[i].v << (i + 1 < bx.size() ? ", " : "");
    }
    std::cout << "]\n";
    Array<Box> by = bx;         // copia
    by[0].v = 1234;
    std::cout << "bx tras modificar by[0]: [";
    for (unsigned int i = 0; i < bx.size(); ++i) {
        std::cout << bx[i].v << (i + 1 < bx.size() ? ", " : "");
    }
    std::cout << "]\n";
    std::cout << "by: [";
    for (unsigned int i = 0; i < by.size(); ++i) {
        std::cout << by[i].v << (i + 1 < by.size() ? ", " : "");
    }
    std::cout << "]\n";

    std::cout << "\n== Test 8: acceso const (operator[] const) ==\n";
    const Array<int> k = a;     // copia const
    std::cout << "k[2] = " << k[2] << "\n";
    try {
        std::cout << k[999] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception en k[999]: " << e.what() << "\n";
    }

    std::cout << "\n== OK ==\n";
    return 0;
}
