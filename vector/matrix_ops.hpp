#ifndef MAT_VECTOR_MATRIX_OPS_HPP
#define MAT_VECTOR_MATRIX_OPS_HPP
#include "../matrix/matrix.hpp"
#include "../matrix/ops.hpp"
namespace mat
{
	template<typename T,std::size_t D>
	Vector<T,D> mul(const Matrix<T,D,D,true>& m,const Vector<T,D>& v)
	{
		///TODO: Too sleepy
	}
}
#endif