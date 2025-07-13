/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:45:32 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/13 20:26:58 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : array(new T[0]), len(0)
{
	std::cout << "Default constructor\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n)
{
	std::cout << "Parametrized constructor\n";
}

template <typename T>
Array<T>::Array(unsigned int n, const T& def) : array(new T[n]), len(n)
{
	std::cout << "Parametrized constructor\n";
	for (size_t i = 0; i < len; i++)
		this->array[i] = def;
}

template <typename T>
Array<T>::Array(const Array<T>& ref) : array(new T[ref.len]), len(ref.len)
{
	std::cout << "Copy constructor\n";
	for (size_t i = 0; i < ref.len; i++)
		this->array[i] = ref.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& ref)
{
	std::cout << "Copy operator\n";
	if (this != &ref)
	{
		delete[] this->array;
		this->array = new T[ref.len];
		this->len = ref.len;
		for (size_t i = 0; i < ref.len; i++)
			this->array[i] = ref.array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor\n";
	delete[] array;
}

template <typename T>
size_t Array<T>::size(void) const
{
	return this->len;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<size_t>(index) >= len)
		throw std::exception();
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<size_t>(index) >= len)
		throw std::exception();
	return array[index];
}

#endif
