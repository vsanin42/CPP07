/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:56:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/07/13 20:25:25 by vsanin           ###   ########.fr       */
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
		Array(unsigned int n);
		Array(unsigned int n, const T& def);
		Array(const Array& ref);
		Array& operator=(const Array& ref);
		~Array();
		size_t size(void) const;
		T& operator[](int);
		const T& operator[](int) const;
};

#include "Array.tpp"

#endif
