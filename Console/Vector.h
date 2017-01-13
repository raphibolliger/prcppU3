#pragma once

#include <array>
#include <iostream>
#include "Expression.h"

using namespace std;

template<typename T, size_t S> class Vector : public array<T, S> {

	public:

	Vector<T, S>() : array<T, S>() {

	}

	Vector<T, S>(const initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	bool operator==(const Vector& vector)
	{
		return false;
	}

	template<typename Left, typename Op, typename Right>
	bool operator==(const Expression<Left, Op, Right>& expression) {
		for (size_t i = 0; i < S; i++)
		{
			if (this->at(i) != expression[i]) return false;
		}
		return true;

	}

	template<typename Left, typename Op, typename Right>
	Vector& operator=(const Expression<Left, Op, Right>& expression) {
		for (size_t i = 0; i < S; i++)
		{
			this->at(i) = expression[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Vector& v)
	{
		os << "[";
		for (size_t i = 0; i < v.size(); i++)
		{
			if (i != 0) os << ",";
			os << v.at(i);
		}
		os << "]" << endl;
		return os;
	}

};