#include<iostream>
#include "../adjmat.hpp"
#include "../adjlist.hpp"
#include "../io.hpp"
#include <string>

int main()
{
	mat::AdjacencyMatrix<std::string,int,mat::SimpleDigraph> g 
	= mat::make_graph<std::string,int,mat::SimpleDigraph,mat::AdjacencyMatrix>(std::cin);
	
// 	for(auto x=g.begin();x!=g.end();++x)
// 	{
// 		std::cout<<x->v<<' ';
// 		for(auto y=g.nbegin(x->v);y!=g.nend(x->v);++y)
// 			std::cout<<y->first<<' '<<y->second;
// 		std::cout<<std::endl;
// 		
// 	}
	mat::debug_display(g,std::cout);

}