#ifndef MAT_VECTOR_HPP
#define MAT_VECTOR_HPP

///TODO: License Information, Detailed Description.
#include <cstddef>
namespace mat
{
	template<typename T,std::size_t D> class Vector;
}
#endif

#include "makevec.cxx" // Wide variety of factory functions
#include "generic.cxx" // Generic definition
//#include "special.cxx" // Specializations, especially for float SIMD operations 

