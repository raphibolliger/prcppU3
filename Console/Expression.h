#pragma once

#include "Op.h"
#include <ostream>

using namespace std;

template<typename T, size_t S> class Vector;

template<typename Left, typename Op, typename Right> class Expression {

	const Left& m_left;
	const Right& m_right;

public:

	typedef typename Left::value_type value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}
	
	size_t size() const { return m_left.size(); }
	
	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right[i]);
	}

	template<typename Left1, typename Op1, typename Right1>
	bool operator==(const Expression<Left1, Op1, Right1>& expression) {
		
		for (size_t i = 0; i < size(); i++)
		{
			if (this->operator[](i) != expression[i]) return false;
		}
		return true;

	}

	template<typename T, size_t S>
	bool operator==(const Vector<T, S>& vector) {
		for (size_t i = 0; i < S; i++)
		{
			if (vector.at(i) != this->operator[](i)) return false;
		}
		return true;
	}

	friend ostream& operator<<(ostream& os, const Expression& e)
	{
		os << "[";
		for (size_t i = 0; i < e.size(); i++)
		{
			if (i != 0) os << ",";
			os << e[i];
		}
		os << "]" << endl;
		return os;
	}

};

template<typename Left, typename Right>
Expression<Left, Add, Right> operator+(const Left& l, const Right& r) {
	return Expression<Left, Add, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Sub, Right> operator-(const Left& l, const Right& r) {
	return Expression<Left, Sub, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Mul, Right> operator*(const Left& l, const Right& r) {
	return Expression<Left, Mul, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Div, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Div, Right>(l, r);
}