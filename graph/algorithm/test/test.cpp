#include "../predicates.hpp"
#include "../../io.hpp"
#include <iostream>
int main()
{
	mat::AdjacencyList<int,int> g=mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(std::cin);
	mat::debug_display(g,std::cout);
	
	std::cout<<mat::is_adjacent<int,int,mat::SimpleDigraph>(g,1,2);
}