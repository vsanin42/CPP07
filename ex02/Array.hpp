/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/11 21:20:50 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
	private:
		T* array;
		size_t len;
	public:
		Array();
		Array(unsigned int n); // Tip: Try to compile int * a = new int(); then display *a.
		Array(const Array& ref);
		Array& operator=(const Array& ref);
		~Array();
		size_t size(void) const;
		T& operator[](int);
};

#include "Array.tpp"

#endif
