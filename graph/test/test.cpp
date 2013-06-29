#include<iostream>
#include "../adjlist.hpp"
#include "../io.hpp"
int main()
{
	mat::AdjacencyList<int,int> g = mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(std::cin);
// 	g.insertVertex(3);
// 	g.insertVertex(5);
// 	g.insertVertex(2);
// 	g.insertVertex(9);
// 	
// 	g.insertEdge(3,5,4);
// 	g.insertEdge(2,9,3);
// 	g.insertEdge(2,5,1);
// 	g.insertEdge(2,3,8);
// 	g.insertEdge(5,9,7);
	
	mat::debug_display(g,std::cout);
	
// 	std::cout<<std::endl;
// 	g.removeVertex(9);
// 
// 	mat::debug_display(g,std::cout);
	
}