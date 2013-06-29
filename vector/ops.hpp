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
	
	template<typename T,std::size_t D>
	Vector<T,D> add(Vector<T,D>& x,Vector<T,D>& y)
	{
		Vector<T,D> result;
		for(auto i=0;i<D;++i)
			result[i]=x[i]+y[i];
		return result;
	}
	
	template<typename T,std::size_t D>
	Vector<T,D> mul(Vector<T,D> x,const T& t)
	{
		for(auto i=0;i<D;++i)
			x[i]*=t;
		return x;
	}
	
	template<typename T,std::size_t D>
	Vector<T,D> flip(Vector<T,D> x)
	{
		for(auto i=0;i<D;++i)
			x[i]=-x[i];
		return x;
	}
	
	
	
}
// #include "simd/overloads.cxx"
//Uncomment this when done overloading
#endif
