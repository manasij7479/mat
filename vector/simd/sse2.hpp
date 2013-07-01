/*
Implements SSE2 intrinsics to leverage vectorization
*/

#ifndef MAT_VECTOR_SSE2_HPP
#define MAT_VECTOR_SSE2_HPP

#include <emmintrin.h> //for SSE2
#include "../vector.hpp"

namespace mat {

	class sse2f
	{
	public:
		sse2f() {} 
		
		sse2f(__m128 ob) : emm(ob) {}

		sse2f(float ob){ emm = _mm_set1_ps(ob); }

		sse2f(float w, float x, float y, float z)
		{ emm = _mm_set_ps(z, y, x, w); }

		/* This constructor doesn't work properly */ 
		sse2f(const float* array4)
		{ sse2f(array4[0], array4[1], array4[2], array4[3]); }  

		sse2f operator*(const sse2f &ob) const
		{ return sse2f(_mm_mul_ps(emm, ob.emm)); }

		sse2f operator+(const sse2f &ob) const
		{ return sse2f(_mm_add_ps(emm, ob.emm)); }

		sse2f operator-(const sse2f &ob) const
		{ return sse2f(_mm_sub_ps(emm, ob.emm)); }

		sse2f operator/(const sse2f &ob) const
		{ return sse2f(_mm_div_ps(emm, ob.emm)); }

		void operator*=(const sse2f &ob)
		{ emm = _mm_mul_ps(emm, ob.emm); }

		void operator+=(const sse2f &ob)
		{ emm = _mm_add_ps(emm, ob.emm); }

		void operator-=(const sse2f &ob)
		{ emm = _mm_sub_ps(emm, ob.emm); }

		void operator/=(const sse2f &ob)
		{ emm = _mm_div_ps(emm, ob.emm); }

		void operator>>(float *array4)
		{ _mm_store_ps(array4, emm); }
		
		void operator>>(Vector<float, 4>& vec4)
		{ 
			float f[4] __attribute__((aligned(sizeof(float)*4))) ; 
			_mm_store_ps(f, emm);
			vec4[0] = f[0]; vec4[1] = f[1]; 
			vec4[2] = f[2]; vec4[3] = f[3] ;
		}
		
		sse2f sqrt() 
		{ return _mm_sqrt_ps(emm); } 
		
		sse2f recp()
		{ return _mm_rcp_ps(emm); } 
		
		sse2f rsqrt()
		{ return _mm_rsqrt_ps(emm); }
		
		friend sse2f min(const sse2f &lhs, const sse2f &rhs)
		{ return _mm_min_ps(lhs.emm, rhs.emm); } 
		
		friend sse2f max(const sse2f &lhs, const sse2f &rhs)
		{ return _mm_max_ps(lhs.emm, rhs.emm); } 

	private:
		__m128 emm;
	};
	
}

#endif 
