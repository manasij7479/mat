#ifndef MAT_GENERIC_CXX
#define MAT_GENERIC_CXX

#include<algorithm>
namespace mat
{
	template<typename T,std::size_t D>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef T const* const_iterator;
		Vector()
		{
			std::fill(d,d+D,T());
		}
		Vector(const Vector<T,D>& v)
		{
			std::copy(v.cbegin(),v.cend(),d);
		}
		inline T& operator[](std::size_t i)
		{
			return d[i];
		}
		T at(std::size_t i) const
		{
			return d[i];
		}
		iterator begin(){return d;}
		iterator end(){return d+D;}
		const_iterator cbegin()const{return d;}
		const_iterator cend()const{return d+D;}
		
	private:
		T d[D] ;
	};
}

#endif
