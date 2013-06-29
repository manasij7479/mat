#ifndef MAT_MATRIX_MAKE_MAT_CXX
#define MAT_MATRIX_MAKE_MAT_CXX
#include <algorithm>
namespace mat
{
	template<typename T,std::size_t R,std::size_t C,bool Order =true,typename Iterator>
	Matrix<T,R,C,Order> make_matrix(Iterator data)
	{
		Matrix<T,R,C,Order> result;
		std::copy_n(data,R*C,result.begin());
		return result;
	}
	
}
#endif