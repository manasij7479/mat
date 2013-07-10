#ifndef MAT_VECTOR_MATRIX_OPS_HPP
#define MAT_VECTOR_MATRIX_OPS_HPP
#include "../matrix/matrix.hpp"
#include "arithmetic.hpp"
namespace mat
{
	template<typename T,std::size_t D>
	Vector<T,D> mul(Matrix<T,D,D,true>& m,const Vector<T,D>& v)///TODO: Not tested, please verify
	{
		Vector<T,D> result;
		for(auto i=0;i<D;++i)
		{
			result[i]=mat::dot<T,D>(m[i],v.begin());//calls the pointer overload of dot
		}
		return result;
	}
}
#endif