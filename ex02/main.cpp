/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:53 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/13 21:42:13 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <typeinfo>

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "~~~ Subject tests ~~~\n" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	{
		std::cout << "\n~~~ Default constructor ~~~\n" << std::endl;
		
		Array<int> ints;
		try
		{
			ints[0] = 0;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << ": empty array\n";
		}
	}
	{
		std::cout << "\n~~~ Types ~~~\n" << std::endl;
		
		Array<bool> bools(2);
		bools[0] = false;
		bools[1] = true;
		std::cout << "bools: '" << bools[0] << "' '" << bools[1] << "'\n\n";
		
		Array<char> chars(2);
		chars[0] = 'a';
		chars[1] = 'b';
		std::cout << "chars: '" << chars[0] << "' '" << chars[1] << "'\n\n";

		Array<std::string> strings(2);
		strings[0] = "biba";
		strings[1] = "boba";
		std::cout << "strings: '" << strings[0] << "' '" << strings[1] << "'\n\n";

		Array< Array<char> > nested(2);
		Array<char> chars2(2);
		chars2[0] = 'c';
		chars2[1] = 'd';
		nested[0] = chars;
		nested[1] = chars2;
		std::cout << "nested (Array of Array<char> types):" << "\n";
		std::cout << "chars 1: ['" << nested[0][0] << "' '" << nested[0][1] << "']\n";
		std::cout << "chars 2: ['" << nested[1][0] << "' '" << nested[1][1] << "']\n\n";

		std::cout << "pointer:" << "\n";
		Array<char>* ptr = new Array<char>(3);
		(*ptr)[0] = 'a';
		(*ptr)[1] = 'b';
		(*ptr)[2] = 'c';
		std::cout << "chars: '" << (*ptr)[0] << "' '" << (*ptr)[1] << "' '" << (*ptr)[2] << "'\n";
		delete ptr;
	}
	{
		std::cout << "\n~~~ Copy operator from smaller to larger ~~~\n" << std::endl;
		
		Array<int> threeNums(3);
		threeNums[0] = 10;
		threeNums[1] = 20;
		threeNums[2] = 30;
		std::cout << "Three nums: " << threeNums[0] << " " << threeNums[1] << " " << threeNums[2] << std::endl;

		Array<int> twoNums(2);
		twoNums[0] = 100;
		twoNums[1] = 200;
		std::cout << "Two nums: " << twoNums[0] << " " << twoNums[1] << std::endl;

		threeNums = twoNums;
		std::cout << "Three nums after copy op: " << threeNums[0] << " " << threeNums[1] << "\n";
		try
		{
			std::cout << threeNums[2] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << ": threeNums[2] is now out of bounds" << std::endl;
		}
	}
	{
		std::cout << "\n~~~ Copy operator from larger to smaller ~~~\n" << std::endl;
		
		Array<int> threeNums(3);
		threeNums[0] = 10;
		threeNums[1] = 20;
		threeNums[2] = 30;
		std::cout << "Three nums: " << threeNums[0] << " " << threeNums[1] << " " << threeNums[2] << std::endl;

		Array<int> twoNums(2);
		twoNums[0] = 100;
		twoNums[1] = 200;
		std::cout << "Two nums: "<< twoNums[0] << " " << twoNums[1] << std::endl;

		twoNums = threeNums;
		std::cout << "Two nums after copy op: "<< twoNums[0] << " " << twoNums[1] << " " << twoNums[2] << std::endl;;
	}
	{
		std::cout << "\n~~~ Const ~~~\n" << std::endl;
		const Array<int> ints(2, 0);
		std::cout << "const ints: " << ints[0] << " " << ints[1] << ". size: " << ints.size() << std::endl;

		const Array<int> test(1, 42);
		Array< Array<int> > nested(1, test);
		std::cout << "const array nested in an array\n"
				  << "value at nested[0][0]: " << nested[0][0] << std::endl;
	}
	{
		std::cout << "\n~~~ Size ~~~\n" << std::endl;
		Array<int> empty;
		Array<int> five(5);
		Array<int> copy(five);
		std::cout << "empty size: " << empty.size() << std::endl;
		std::cout << "five size: " << five.size() << std::endl;
		std::cout << "copy size: " << copy.size() << std::endl;
		empty = five;
		std::cout << "new empty size: " << empty.size() << std::endl;
	}
    return 0;
}
