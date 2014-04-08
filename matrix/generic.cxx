#ifndef MATRIX_GENERIC_CXX
#define MATRIX_GENERIC_CXX
#include<algorithm>
namespace mat
{
	
	template<typename T,std::size_t R,std::size_t C,bool Order>  // Order = true means Row Major Matrix
	class Matrix
	{
	public:
		typedef T* iterator;
		typedef T const* const_iterator;
		Matrix(){};
		Matrix(const Matrix<T,R,C,Order>& m)
		{
			std::copy(m.cbegin(),m.cend(),d);
		}
		
		T* operator[](std::size_t i)
		{
			return d+i*((Order)?C:R);
		}
		
		operator Matrix<T,R,C,!Order>() const
		{
			Matrix<T,R,C,!Order> r;
			std::copy(cbegin(),cend(),r.begin());
			for(auto i=0;i<R;++i)
				for(auto j=0;i<C;++j)
					std::swap(r[i][j],r[j][i]);
			return r;
		}
		
		iterator begin(){return d;}
		const_iterator cbegin()const {return d;}
		iterator end(){return d+R*C;}
		const_iterator cend()const{return d+R*C;}
		
		iterator next_vec(iterator& it)
		{
			return it+=(Order)?C:R;
		}
	private:
		T d[R*C];
	};
}
#endif