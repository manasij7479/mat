///TODO: Create a good testing framework

#include "../vector.hpp"
#include "../ops.hpp"
#include<iostream>

int main()
{
	mat::Vector<int,3> x;
	int z[3]={1,2,3};
	x = mat::make_vector<int,3>({2,3,4});
	for(auto t:x)
		std::cout<<t<<' ';
	mat::Vector<int,3> y(z);
	for(auto t:y)
		std::cout<<t<<' ';
	std::cout<<mat::dot(x,y);
	
	mat::Vector<float, 4> test1, test2, result ; 
	test1[0] = 1.0f, test1[1] = 1.0f, test1[2] = 1.0f, test1[3] = -1.0f ; 
	test2[0] = 2.0f, test2[1] = 4.0f, test2[2] =  6.0f, test2[3] = -8.0f ; 
	std::cout << "\n" << mat::dot(test1, test2); 
	result = mat::mul(test1, 2.0f);
	std::cout << "\n" ;
	for(auto t:result)
		std::cout<<t<<' ';
	std::cout << "\n" ;
	result = mat::normalize(test1);
	for(auto t:result)
		std::cout<<t<<' ';
}
