#ifndef MAT_MAKEVEC_CXX
#define MAT_MAKEVEC_CXX

#include<algorithm>
#include<initializer_list>
namespace mat
{
	template
	<
		typename T,
		std::size_t D,
		typename Iterator
	>
	Vector<T,D> make_vector(Iterator begin)
	{
		Vector<T,D> result;
		std::copy_n(begin,D,result.begin());
		return result;
	};

	template
	<
		typename T,
		std::size_t D
	>
	Vector<T,D> make_vector(std::initializer_list<T> values)
	{
		Vector<T,D> result;
		std::copy_n(values.begin(),D,result.begin());
		return result;
	}
	
	
	/* GCC converts float to double for ... arguments. 
	Function generates a runtime error.
	Needs fix */ 
// 	template
// 	<
// 		typename T = float,
// 		std::size_t D = 4
// 	>
// 	Vector<T,D> make_vector(T t,...)
// 	{
// 		Vector<T,D> result;
// 		unsigned int i=0;
// 		result[i++]=t;
// 		std::va_list vl;
// 		va_start(vl,t);
// 		while(i<D)
// 			result[i++]=va_arg(vl,T);
// 		va_end(vl);
// 		return result;
// 	}

	///TODO: Other Overloads
}
#endif
