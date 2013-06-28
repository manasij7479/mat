///TODO: Create a good testing framework
#include "../vector.hpp"
#include "../ops.hpp"
#include<iostream>
int main()
{
	mat::Vector<int,3> x,y;
	x = mat::make_vector<int,3>(2,3,4);
	for(auto t:x)
		std::cout<<t<<' ';
	y = mat::make_vector<int,3>(1,2,3);
	for(auto t:y)
		std::cout<<t<<' ';
	std::cout<<mat::dot(x,y);
}
