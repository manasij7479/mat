#ifndef MATRIX_GENERIC_CXX
#define MATRIX_GENERIC_CXX
namespace mat
{
	template<typename T,std::size_t R,std::size_t C> 
	class Matrix
	{
	public:
		typedef T* iterator;
		Matrix(bool order=true):rowmajor(order){};
		T* operator[](std::size_t i)
		{
			return d+i*((rowmajor)?C:R);
		}
		iterator begin()
		{
			return d;
		}
		iterator end()
		{
			return d+R*C;
		}
		iterator next_vec(iterator& it)
		{
			return it+=(rowmajor)?C:R;
		}
		bool order(){return rowmajor;}
	private:
		T d[R*C];
		bool rowmajor;
	};
}
#endif