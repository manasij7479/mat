#include <xmmintrin.h> 

class sse2
{
public:
  constexpr sse2(__m128 v) : xmm(v) {}

  sse2(float v){ xmm = _mm_set1_ps(v); }

  sse2(float x, float y, float z, float w)
  { xmm = _mm_set_ps(w,z,y,x); }

  sse2(const float *v){ xmm = _mm_load_ps(v); }

  sse2 operator*(const sse2 &v) const
  { return sse2(_mm_mul_ps(xmm, v.xmm)); }

  sse2 operator+(const sse2 &v) const
  { return sse2(_mm_add_ps(xmm, v.xmm)); }

  sse2 operator-(const sse2 &v) const
  { return sse2(_mm_sub_ps(xmm, v.xmm)); }

  sse2 operator/(const sse2 &v) const
  { return sse2(_mm_div_ps(xmm, v.xmm)); }

  void operator*=(const sse2 &v)
  { xmm = _mm_mul_ps(xmm, v.xmm); }

  void operator+=(const sse2 &v)
  { xmm = _mm_add_ps(xmm, v.xmm); }

  void operator-=(const sse2 &v)
  { xmm = _mm_sub_ps(xmm, v.xmm); }

  void operator/=(const sse2 &v)
  { xmm = _mm_div_ps(xmm, v.xmm); }

  void operator>>(float *v)
  { _mm_store_ps(v, xmm); }

private:
  __m128 xmm;
};
