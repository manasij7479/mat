#ifndef MAT_VECTOR_ARITHMETIC_HPP
#define MAT_VECTOR_ARITHMETIC_HPP
#include "vector.hpp"
#include "simd/sse2.hpp"
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
	
	float dot(Vector<float,4>& lhs,Vector<float,4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs[0], lhs[1], lhs[2], lhs[3]), b(rhs[0], rhs[1], rhs[2], rhs[3]), r ; 
		r = a * b ;    
		r >> result ;
		return (result[0] + result[1] + result[2] + result[3]); 
    }
  
    Vector<float, 4> add(Vector<float, 4>& lhs, Vector<float, 4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs[0], lhs[1], lhs[2], lhs[3]), b(rhs[0], rhs[1], rhs[2], rhs[3]), r ; 
		r = a + b ;
		r >> result ; 
		return result ;
    }
  
    Vector<float, 4> subtract(Vector<float, 4>& lhs, Vector<float, 4>& rhs)
    {
		Vector<float, 4> result ; 
		sse2f a(lhs[0], lhs[1], lhs[2], lhs[3]), b(rhs[0], rhs[1], rhs[2], rhs[3]), r ; 
		r = a - b ;
		r >> result ; 
		return result ;
	}
}
#endif