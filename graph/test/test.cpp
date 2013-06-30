#include<iostream>
#include "../adjmat.hpp"
#include "../adjlist.hpp"
#include "../io.hpp"
#include <string>

int main()
{
	mat::AdjacencyList<int,int,mat::SimpleDigraph> g 
	= mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(std::cin);
	
	for(auto x=g.begin();x!=g.end();++x)
	{
		std::cout<<x->v<<' ';
		for(auto y=g.nbegin(x->v);y!=g.nend(x->v);++y)
			std::cout<<y->first<<' '<<y->second;
		std::cout<<std::endl;
		
	}

}