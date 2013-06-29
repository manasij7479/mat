#ifndef MAT_VECTOR_OPS_HPP
#define MAT_VECTOR_OPS_HPP
namespace mat
{
	template<typename T,std::size_t D>
	T dot(const Vector<T,D>& x,const Vector<T,D>& y)
	{
		T result=T();
		for(auto i=0;i<D;++i)
			result+=x.at(i)*y.at(i);
		return result;
	}
	
	template<typename T,std::size_t D>
	Vector<T,D> add(const Vector<T,D>& x,const Vector<T,D>& y)
	{
		Vector<T,D> result;
		for(auto i=0;i<D;++i)
			result[i]=x.at(i)+y.at(i);
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
