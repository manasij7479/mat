#include <xmmintrin.h> 

namespace mat {

class sse2f
{
public:
  sse2f(__m128 v) : xmm(v) {}

  sse2f(float v){ xmm = _mm_set1_ps(v); }

  sse2f(float x, float y, float z, float w)
  { xmm = _mm_set_ps(w,z,y,x); }

  sse2f(const float *v){ xmm = _mm_load_ps(v); }

  sse2f operator*(const sse2f &v) const
  { return sse2f(_mm_mul_ps(xmm, v.xmm)); }

  sse2f operator+(const sse2f &v) const
  { return sse2f(_mm_add_ps(xmm, v.xmm)); }

  sse2f operator-(const sse2f &v) const
  { return sse2f(_mm_sub_ps(xmm, v.xmm)); }

  sse2f operator/(const sse2f &v) const
  { return sse2f(_mm_div_ps(xmm, v.xmm)); }

  void operator*=(const sse2f &v)
  { xmm = _mm_mul_ps(xmm, v.xmm); }

  void operator+=(const sse2f &v)
  { xmm = _mm_add_ps(xmm, v.xmm); }

  void operator-=(const sse2f &v)
  { xmm = _mm_sub_ps(xmm, v.xmm); }

  void operator/=(const sse2f &v)
  { xmm = _mm_div_ps(xmm, v.xmm); }

  void operator>>(float *v)
  { _mm_store_ps(v, xmm); }

private:
  __m128 xmm;
};

}