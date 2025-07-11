/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/11 18:29:20 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cmath>

void square(int& num)
{
	num *= num;
}

void printSquare(const int& num)
{
	std::cout << num * num << " ";
}

int main(void)
{
	{
		std::cout << "~~~ Passing NULL as array ~~~" << std::endl;
		::iter(static_cast<int *>(NULL), static_cast<size_t>(10), ::square);
	}
	{
		std::cout << "~~~ Passing NULL as function ~~~" << std::endl;

		int arr[10];
		for (size_t i = 0; i < 10; i++)
			arr[i] = i;
		void (*nullFuncPtr)(int&) = NULL;
		::iter(arr, sizeof(arr)/sizeof(*arr), nullFuncPtr);
	}
	{
		std::cout << "~~~ Empty array ~~~" << std::endl;

		int arr[0];
		::iter(arr, 0, print<int>);
		std::cout << std::endl;
	}
	{
		std::cout << "~~~ Array of ints ~~~" << std::endl;

		int arr[10];
		std::cout << "Old: ";
		for (size_t i = 0; i < 10; i++)
		{	
			arr[i] = i;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		
		::iter(arr, sizeof(arr)/sizeof(*arr), ::square);
		
		std::cout << "New: ";
		for (size_t i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\n~~~ Instantiated function template ~~~" << std::endl;

		int arr[3];
		std::cout << "Ints: ";
		for (size_t i = 0; i < 3; i++)
		{	
			arr[i] = i;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		
		::iter(arr, sizeof(arr)/sizeof(*arr), print<int>);

		std::string arr2[3];
		std::cout << "Strings: ";
		arr2[0] = "biba";
		arr2[1] = "boba";
		arr2[2] = "buba";
		for (size_t i = 0; i < 3; i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
		
		::iter(arr2, sizeof(arr2)/sizeof(*arr2), print<std::string>);
		
		std::string* arr3[3];
		std::cout << "Pointers to strings: ";
		arr3[0] = &arr2[0];
		arr3[1] = &arr2[1];
		arr3[2] = &arr2[2];
		for (size_t i = 0; i < 3; i++)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;
		
		::iter(arr3, sizeof(arr3)/sizeof(*arr3), print<std::string*>);
	}
	{
		std::cout << "\n~~~ Consts ~~~" << std::endl;
		
		const int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::cout << "Const ints (printed, not replaced):\n" << "Old: ";
		for (size_t i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		
		std::cout << "New: ";
		::iter(arr, sizeof(arr)/sizeof(*arr), ::printSquare);
		std::cout << std::endl;
		
		const std::string arr2[3] = { "biba", "boba", "buba" };
		std::cout << "Const strings: ";
		for (size_t i = 0; i < 3; i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
		
		::iter(arr2, sizeof(arr2)/sizeof(*arr2), print<const std::string>);
	}
	return 0;
}
