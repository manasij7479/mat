#ifndef MAT_VECTOR_OPS_HPP
#define MAT_VECTOR_OPS_HPP 

#include "simd/sse2.hpp" 

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
