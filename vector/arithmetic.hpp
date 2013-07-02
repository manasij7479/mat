#ifndef MAT_VECTOR_ARITHMETIC_HPP
#define MAT_VECTOR_ARITHMETIC_HPP

#include "vector.hpp"
#include "simd/sse2.hpp"
#include <cmath> 

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
	
	float dot(const Vector<float,4>& lhs, const Vector<float,4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs), b(rhs), r ; 
		r = a * b ;    
		r >> result ;
		return (result.at(0) + result.at(1) + result.at(2) + result.at(3)); 
    }
  
    Vector<float, 4> add(const Vector<float, 4>& lhs, const Vector<float, 4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs), b(rhs), r ; 
		r = a + b ;
		r >> result ; 
		return result ;
    }
  
    Vector<float, 4> subtract(const Vector<float, 4>& lhs, const Vector<float, 4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs), b(rhs), r ;  
		r = a - b ;
		r >> result ; 
		return result ;
	}
	
	Vector<float, 4> mul(const Vector<float, 4>& lhs, float rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs), b(rhs, rhs, rhs, rhs), r ; 
		r = a * b ;
		r >> result ; 
		return result ;
    }
	
	Vector<float, 4> normalize(const Vector<float, 4>& vec)
	{
		Vector<float, 4> result ; 
		if(vec.at(0) == 0 && vec.at(1) == 0 && vec.at(2) == 0 && vec.at(3) == 0) 
			return result ; 
		float sum = std::sqrt(dot(vec, vec)) ; 
		sse2f a(vec), b(sum, sum, sum, sum) ;
		(a / b) >> result ; 
		return result ;
	} 
}
#endif