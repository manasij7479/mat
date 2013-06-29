#include "../matrix.hpp"
#include "../ops.hpp"
#include "../io.hpp"
#include<iostream>
int main()
{
// 	int x[]={1,2,3,4};
	mat::Matrix<int,2,2,false> m = mat::make_matrix<int,2,2,false>(std::cin);
	auto p = mat::multiply(m,m);
	std::cout<<p[0][0];
}