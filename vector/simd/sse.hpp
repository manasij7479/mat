/*
Implements SSE intrinsics to leverage vectorization
*/

#ifndef MAT_VECTOR_SSE_HPP
#define MAT_VECTOR_SSE_HPP

#include <xmmintrin.h> //for SSE

namespace mat {

	class ssef
	{
	public:
		ssef() {} 
		
		ssef(__m128 ob) : xmm(ob) {}

		ssef(float ob){ xmm = _mm_set1_ps(ob); }

		ssef(float w, float x, float y, float z)
		{ xmm = _mm_set_ps(z, y, x, w); }

		/* This constructor doesn't work properly */ 
		ssef(const float* array4)
		{ ssef(array4[0], array4[1], array4[2], array4[3]); }  

		ssef operator*(const ssef &ob) const
		{ return ssef(_mm_mul_ps(xmm, ob.xmm)); }

		ssef operator+(const ssef &ob) const
		{ return ssef(_mm_add_ps(xmm, ob.xmm)); }

		ssef operator-(const ssef &ob) const
		{ return ssef(_mm_sub_ps(xmm, ob.xmm)); }

		ssef operator/(const ssef &ob) const
		{ return ssef(_mm_div_ps(xmm, ob.xmm)); }

		void operator*=(const ssef &ob)
		{ xmm = _mm_mul_ps(xmm, ob.xmm); }

		void operator+=(const ssef &ob)
		{ xmm = _mm_add_ps(xmm, ob.xmm); }

		void operator-=(const ssef &ob)
		{ xmm = _mm_sub_ps(xmm, ob.xmm); }

		void operator/=(const ssef &ob)
		{ xmm = _mm_div_ps(xmm, ob.xmm); }

		void operator>>(float *array4)
		{ _mm_store_ps(array4, xmm); }
		
		ssef sqrt() 
		{ return _mm_sqrt_ps(xmm); } 
		
		ssef recp()
		{ return _mm_rcp_ps(xmm); } 
		
		ssef rsqrt()
		{ return _mm_rsqrt_ps(xmm); }
		
		friend ssef min(const ssef &lhs, const ssef &rhs)
		{ return _mm_min_ps(lhs.xmm, rhs.xmm); } 
		
		friend ssef max(const ssef &lhs, const ssef &rhs)
		{ return _mm_max_ps(lhs.xmm, rhs.xmm); } 
		
	private:
		__m128 xmm;
	};
	
}

#endif 
