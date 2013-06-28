#ifndef MAT_VECTOR_OPS_HPP
#define MAT_VECTOR_OPS_HPP
namespace mat
{
	template<typename T,std::size_t D>
	T dot(Vector<T,D>& x,Vector<T,D>& y)
	{
		T result=T();
		std::size_t i;
		while(i<D)
			result+=x[i]*y[i++];
		return result;
	}
	
	float dot(Vector<float,4>& x,Vector<float,4>& y)
	{
		///TODO:
		return -1.0f;
	}
	
}
#endif
