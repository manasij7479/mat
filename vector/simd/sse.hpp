#ifndef MAT_VECTOR_SIMD_HPP
#define MAT_VECTOR_SIMD_HPP

#include <emmintrin.h> 

namespace mat {

	class sse2f
	{
	public:
		sse2f(__m128 ob) : xmm(ob) {}

		sse2f(float ob){ xmm = _mm_set1_ps(ob); }

		sse2f(float w, float x, float y, float z)
		{ xmm = _mm_set_ps(w, x, y, z); }

		sse2f(const float* array4)
		{ sse2f(array4[0], array4[1], array4[2], array4[3]); }  

		sse2f operator*(const sse2f &ob) const
		{ return sse2f(_mm_mul_ps(xmm, ob.xmm)); }

		sse2f operator+(const sse2f &ob) const
		{ return sse2f(_mm_add_ps(xmm, ob.xmm)); }

		sse2f operator-(const sse2f &ob) const
		{ return sse2f(_mm_sub_ps(xmm, ob.xmm)); }

		sse2f operator/(const sse2f &ob) const
		{ return sse2f(_mm_div_ps(xmm, ob.xmm)); }

		void operator*=(const sse2f &ob)
		{ xmm = _mm_mul_ps(xmm, ob.xmm); }

		void operator+=(const sse2f &ob)
		{ xmm = _mm_add_ps(xmm, ob.xmm); }

		void operator-=(const sse2f &ob)
		{ xmm = _mm_sub_ps(xmm, ob.xmm); }

		void operator/=(const sse2f &ob)
		{ xmm = _mm_div_ps(xmm, ob.xmm); }

		void operator>>(float *array4)
		{ _mm_store_ps(array4, xmm); }

	private:
		__m128 xmm;
	};

}

#endif 
#include "sse_impl.cxx"  //TODO