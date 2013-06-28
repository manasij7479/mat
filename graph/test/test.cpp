#include<iostream>
#include "../graph.hpp"
int main()
{
	Graph<int,int,AdjacencyList,Bimap> g;
	g.insertVertex(2);
	g.insertVertex(5);
	g.insertEdge(2,{5,1});
	g.insertEdge(2,{2,6});
	
	for(auto x = g.nbegin(0);x!=g.nend(0);++x)
		std::cout<<x->second;
// 	
// 	Graph<int,void,AdjacencyList,Bimap> h;
// 	h.insertVertex(2);
// 	h.insertVertex(5);
// 	h.insertEdge(2,5);
// 	h.insertEdge(2,2);
// 	for(auto x = h.nbegin(2);x!=h.nend(2);++x)
// 		std::cout<<*x<<std::endl;
}