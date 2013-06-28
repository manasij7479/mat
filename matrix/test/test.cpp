#include "../matrix.hpp"
#include<iostream>
int main()
{
	int x[]={1,2,3,4};
	mat::Matrix<int,2,2> m = mat::make_matrix<int,2,2>(x);
	std::cout<<m[1][1];
	
}