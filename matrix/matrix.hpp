#ifndef MAT_MATRIX_HPP
#define MAT_MATRIX_HPP
#include<cstddef>
namespace mat
{
	template<typename T,std::size_t R,std::size_t C,bool Order=true> class Matrix;
	///TODO:Needs a sparse matrix module.
}
#endif
#include "generic.cxx"
#include "make_mat.cxx"