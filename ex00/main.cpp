/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/20 18:23:18 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~ Subject case ~~~\n" << std::endl;
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	{
		std::cout << "\n~~~ Class with comparison operator overload ~~~\n" << std::endl;
		YesOpOverload a(2);
		YesOpOverload b(3);

		std::cout << "a = " << a.getI() << ", b = " << b.getI() << std::endl;
		::swap(a, b);
		std::cout << "a = " << a.getI() << ", b = " << b.getI() << std::endl;
	
		std::cout << "min(a, b) = " << ::min(a, b).getI() << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b).getI() << std::endl;
	}
	{
		std::cout << "\n~~~ Class without comparison operator overload ~~~\n" << std::endl;
		NoOpOverload a(2);
		NoOpOverload b(3);

		std::cout << "a = " << a.getI() << ", b = " << b.getI() << std::endl;
		::swap(a, b);
		std::cout << "a = " << a.getI() << ", b = " << b.getI() << std::endl;
	
		std::cout << "using min/max with objects of this class will cause a compile error\n" << std::endl;
		// compile errors
		// std::cout << "min(a, b) = " << ::min(a, b).getI() << std::endl;
		// std::cout << "max(a, b) = " << ::max(a, b).getI() << std::endl;
	}
	{
		std::cout << "~~~ Extras ~~~\n" << std::endl;

		std::cout << "~~ if equal, returns the second one:" << std::endl;
		double a = 4.2;
		double b = 4.2;
 
		std::cout << "a address " << &a << std::endl;
		std::cout << "b address " << &b << std::endl;
		
		std::cout << "\nmin(a, b) = " << &::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << &::max(a, b) << std::endl;
		a += 1;
		std::cout << a << std::endl;

		std::cout << "\n~~ pointers comparison:" << std::endl;  
		double* ptrA = &a;
		double* ptrB = &b;
		std::cout << "min(ptrA, ptrB) = " << ::min(ptrA, ptrB) << std::endl;
		std::cout << "max(ptrA, ptrB) = " << ::max(ptrA, ptrB) << std::endl;
		
		std::cout << "\n~~ const swap impossible (floats):" << std::endl;
		const float c = 1.5f;
		const float d = 5.1f;
		
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "using swap with const objects will cause a compile error\n" << std::endl;
		// compile errors
		// ::swap(c, d);
		// std::cout << "c = " << c << ", d = " << d << std::endl;

		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

		std::cout << "\n~~ type mismatch:" << std::endl;  
		double i = 111.1;
		int j = 222;
		std::cout << "passing parameters of two different types will cause a compile error" << std::endl;
		// compile errors
		// std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
		// std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
		(void)i;
		(void)j;
	}
	return 0;
}
