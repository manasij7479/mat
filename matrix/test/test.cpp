#include "../matrix.hpp"
#include "../ops.hpp"
#include "../io.hpp"
#include<iostream>
int main()
{
// 	int x[]={1,2,3,4};
	mat::Matrix<int,3,3,false> m = mat::make_matrix<int,3,3,false>(std::cin);
	auto p = mat::multiply(m,m);
	mat::debug_display(p,std::cout);
}