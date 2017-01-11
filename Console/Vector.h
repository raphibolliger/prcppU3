#pragma once

#include <array>
#include <iostream>

using namespace std;

template<class T, size_t S> class Vector : public array<T, S> {

	public:

	Vector() : array<T, S>() {

	}

	Vector(const initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
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