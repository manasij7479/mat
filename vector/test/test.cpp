///TODO: Create a good testing framework
#include "../vector.hpp"
#include "../ops.hpp"
#include "../io.hpp"
#include<iostream>
int main()
{
	mat::Vector<int,3> x = mat::make_vector<int,3>(std::cin);
	mat::debug_display(x,std::cout);
}
