/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:46:45 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/11 16:46:24 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* arr, size_t len, void (*f)(T&))
{
	if (!arr || !f)
	{
		std::cout << "Array/function can't be NULL\n" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void iter(const T* arr, size_t len, void (*f)(const T&))
{
	if (!arr || !f)
	{
		std::cout << "Array/function can't be NULL\n" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void print(const T& param)
{
	std::cout << "-> " << param << std::endl;
}

#endif
