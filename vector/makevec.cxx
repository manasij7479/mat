#ifndef MAT_MAKEVEC_CXX
#define MAT_MAKEVEC_CXX

#include<algorithm>
#include<cstdarg>
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
	Vector<T,D> make_vector(T t,...)
	{
		Vector<T,D> result;
		unsigned int i=0;
		result[i++]=t;
		std::va_list vl;
		va_start(vl,t);
		while(i<D)
			result[i++]=va_arg(vl,T);
		va_end(vl);
		return result;
	}

	///TODO: Other Overloads
}
#endif
