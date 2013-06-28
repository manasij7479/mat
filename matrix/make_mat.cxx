#ifndef MAT_MATRIX_MAKE_MAT_CXX
#define MAT_MATRIX_MAKE_MAT_CXX
#include <algorithm>
namespace mat
{
	template<typename T,std::size_t R,std::size_t C,typename Iterator>
	Matrix<T,R,C> make_matrix(Iterator data,bool order=true)
	{
		Matrix<T,R,C> result(order);
		std::copy_n(data,R*C,result.begin());
		return result;
	}
	
}
#endif