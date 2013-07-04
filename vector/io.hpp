#ifndef MAT_VECTOR_IO_HPP
#define MAT_VECTOR_IO_HPP
#include "vector.hpp"
#include <istream>
#include <ostream>
namespace mat
{
	template<typename T, std::size_t D>
	Vector<T,D> make_vector(std::istream& in)
	{
		Vector<T,D> result;
		for(auto i=0;i<D && in;++i)
		{
			T t;
			in>>t;
			result[i]=t;
		}
		in.clear();
		return result;
	}
	
	template<typename T,std::size_t D>
	void debug_display(const Vector<T,D>& v,std::ostream& out)
	{
		out<<"(";
		for(auto i=0;i<D-1;++i)
			out<<v.at(i)<<",";
		out<<v.at(D-1)<<")\n";
	}
}
#endif