/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:46:45 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/20 17:43:03 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& param1, T& param2)
{
	T tmp = param1;
	param1 = param2;
	param2 = tmp;
}

template <typename T>
const T& min(const T& param1, const T& param2)
{
	return param1 < param2 ? param1 : param2;
}

template <typename T>
const T& max(const T& param1, const T& param2)
{
	return param1 > param2 ? param1 : param2;
}

class YesOpOverload
{
	private:
		int i;
	public:
		YesOpOverload() : i(0) {}
		YesOpOverload(int i) : i(i) {}
		YesOpOverload(const YesOpOverload& ref) : i(ref.i) {}
		YesOpOverload& operator=(const YesOpOverload& ref)
		{
			if (this != &ref)
				i = ref.i;
			return *this;
		}
		~YesOpOverload() {};
		int getI() const { return i; }
		bool operator<(const YesOpOverload& ref) const { return this->i < ref.i; }
		bool operator>(const YesOpOverload& ref) const { return !((*this) < ref) && !((*this) == ref); }
		bool operator==(const YesOpOverload& ref) const { return this->i == ref.i; }
		bool operator!=(const YesOpOverload& ref) const { return !(*this == ref); }
		bool operator<=(const YesOpOverload& ref) const { return (*this) < ref || (*this) == ref; }
		bool operator>=(const YesOpOverload& ref) const { return !((*this) < ref); }
};

class NoOpOverload
{
	private:
		int i;
	public:
		NoOpOverload() : i(0) {}
		NoOpOverload(int i) : i(i) {}
		NoOpOverload(const NoOpOverload& ref) : i(ref.i) {}
		NoOpOverload& operator=(const NoOpOverload& ref)
		{
			if (this != &ref)
				i = ref.i;
			return *this;
		}
		~NoOpOverload() {};
		int getI() { return i; }
};

#endif

