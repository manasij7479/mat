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
		Vector()
		{
			std::fill(d,d+D,T());
		}

		inline T& operator[](std::size_t i)
		{
			return d[i];
		}
		
		iterator begin(){return d;}
		iterator end(){return d+D;}
	private:
		T d[D] ;
	};
}

#endif
