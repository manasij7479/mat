#include "../predicates.hpp"
#include "../search.hpp"
#include "../../io.hpp"
#include <iostream>
int main()
{
	mat::AdjacencyList<int,int> g=mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(std::cin);
	mat::debug_display(g,std::cout);
	
	mat::Search<int,int,mat::SimpleDigraph,mat::AdjacencyList,mat::QueueBFS> s(g,1);
	std::cout<<s.distanceTo(3);
}