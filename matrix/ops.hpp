#ifndef MAT_MATRIX_OPS
#define MAT_MATRIX_OPS
#include "matrix.hpp"
#include<cassert>
namespace mat
{
	template<typename T,std::size_t P,std::size_t Q,std::size_t R>
	Matrix<T,P,R> multiply_r(Matrix<T,P,Q>& a,Matrix<T,Q,R>& b)
	{
		Matrix<T,P,R> m;
		assert(a.order() && b.order());
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
	
	//TODO:Plenty of ops remaining..add and optimize as needed 
}
#endif