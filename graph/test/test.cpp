#include<iostream>
#include "../adjlist.hpp"
#include "../io.hpp"
int main()
{
	mat::AdjacencyList<int,int> g = mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(std::cin);
	
	mat::debug_display(g,std::cout);
	
	
}