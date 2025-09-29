/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:15:15 by volmer            #+#    #+#             */
/*   Updated: 2025/09/29 15:31:27 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/iter.hpp"

void	increment(int &i) {
	i++;
}

// Colores ANSI para los prints
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printInt(const int &i)
{
	std::cout << GREEN << i << " " << RESET;
}

void printChar(const char &c)
{
	std::cout << CYAN << "'" << c << "' " << RESET;
}

void printString(const std::string &s)
{
	std::cout << YELLOW << "\"" << s << "\" " << RESET;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void addExclamation(std::string &s)
{
	s += "!";
}

int		main(void)
{
	std::cout << MAGENTA << "\n// Caso 1: Incrementar un array de enteros" << RESET << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	std::cout << BLUE << "Antes de incrementar: " << RESET;
	iter(arr, len, printInt);
	std::cout << std::endl;
	iter(arr, len, increment);
	std::cout << BLUE << "Después de incrementar: " << RESET;
	iter(arr, len, printInt);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 2: Convertir a mayúsculas un array de chars" << RESET << std::endl;
	char carr[] = {'a', 'b', 'C', 'd', 'E'};
	size_t clen = sizeof(carr) / sizeof(carr[0]);
	std::cout << BLUE << "Antes de toUpper: " << RESET;
	iter(carr, clen, printChar);
	std::cout << std::endl;
	iter(carr, clen, toUpper);
	std::cout << BLUE << "Después de toUpper: " << RESET;
	iter(carr, clen, printChar);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 3: Agregar exclamación a un array de strings" << RESET << std::endl;
	std::string sarr[] = {"hola", "mundo", "cpp"};
	size_t slen = sizeof(sarr) / sizeof(sarr[0]);
	std::cout << BLUE << "Antes de addExclamation: " << RESET;
	iter(sarr, slen, printString);
	std::cout << std::endl;
	iter(sarr, slen, addExclamation);
	std::cout << BLUE << "Después de addExclamation: " << RESET;
	iter(sarr, slen, printString);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 4: Array vacío" << RESET << std::endl;
	int emptyArr[0];
	std::cout << BLUE << "Array vacío: " << RESET;
	iter(emptyArr, 0, printInt);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 5: Array de un solo elemento" << RESET << std::endl;
	int singleArr[] = {42};
	std::cout << BLUE << "Antes de incrementar: " << RESET;
	iter(singleArr, 1, printInt);
	std::cout << std::endl;
	iter(singleArr, 1, increment);
	std::cout << BLUE << "Después de incrementar: " << RESET;
	iter(singleArr, 1, printInt);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 6: Usar iter con puntero nulo" << RESET << std::endl;
	int* nullArr = NULL;
	std::cout << BLUE << "Puntero nulo: " << RESET;
	iter(nullArr, 5, printInt);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n// Caso 7: Usar iter con función nula" << RESET << std::endl;
	std::cout << BLUE << "Función nula: " << RESET;
	iter(arr, len, (void(*)(int&))NULL);
	std::cout << std::endl;

	return 0;
}