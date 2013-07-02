#ifndef MAT_MATRIX_ARITHMETIC_HPP
#define MAT_MATRIX_ARITHMETIC_HPP
#include "matrix.hpp"
namespace mat
{
	template<typename T,std::size_t P,std::size_t Q,std::size_t R,bool Order>
	Matrix<T,P,R,Order> multiply(Matrix<T,P,Q,Order>& a,Matrix<T,Q,R,Order>& b)
	{
		Matrix<T,P,R,Order> m;
		for(auto i=0;i<P;++i)
		{
			for(auto j=0;j<R;++j)
			{
				m[i][j]=0;
				for(auto k=0;k<Q;++k)
				{
					m[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		return m;
	}
	
	
	template<typename T,std::size_t R,std::size_t C,bool Order>
	void transpose(Matrix<T,R,C,Order>& m)
	{
		for(auto i=0;i<R;++i)
			for(auto j=0;i<C;++j)
				std::swap(m[i][j],m[j][i]);
	}
	
}
#endif