#include<iostream>
#include "../adjlist.hpp"
int main()
{
	mat::AdjacencyList<int,int> g;
	g.insertVertex(3);
	g.insertVertex(5);
	g.insertVertex(2);
	g.insertVertex(9);
	
	g.insertEdge(3,5,4);
	g.insertEdge(2,9,3);
	g.insertEdge(2,5,1);
	g.insertEdge(2,3,8);
	g.insertEdge(5,9,7);
	
	
	for(auto x = g.begin();x!=g.end();++x)
	{
		std::cout<<"["<<x->v<<"]->";
		for(auto y = g.nbegin(x->v);y!=g.nend(x->v);++y)
		{
			std::cout<<"("<< y->first<<","<< y->second<<")->";
		}
		std::cout<<"***"<<std::endl;
	}
}