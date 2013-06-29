#ifndef MAT_MATRIX_IO_HPP
#define MAT_MATRIX_IO_HPP
#include <istream>
#include <ostream>
#include <iterator>
#include "matrix.hpp"
namespace mat
{
	template<typename T,std::size_t R,std::size_t C,bool Order>
	Matrix<T,R,C,Order> make_matrix(std::istream& in)
	{
		std::istream_iterator<T> it(in);
		return make_matrix<T,R,C,Order>(it);
	}
}
#endif