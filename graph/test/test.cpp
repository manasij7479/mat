#include<iostream>
#include "../adjmat.hpp"
#include "../adjlist.hpp"
#include "../io.hpp"
int main()
{
	mat::AdjacencyMatrix<int,int> g = mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyMatrix>(std::cin);
	
	mat::debug_display(g,std::cout);
	
	g.removeVertex(2);
	
	mat::debug_display(g,std::cout);
}