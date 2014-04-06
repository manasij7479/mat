#include "../predicates.hpp"
#include "../search/search.hpp"
#include "../../io.hpp"
#include <sstream>
int main()
{
	std::string input("v 1\nv 2\nv 3\ne 1 2 1\ne 1 3 4\ne 2 3 1\nq");
	std::istringstream in(input);
	mat::AdjacencyList<int,int> g=mat::make_graph<int,int,mat::SimpleDigraph,mat::AdjacencyList>(in);
	mat::debug_display(g,std::cout);
	
	mat::Search<int,int,mat::SimpleDigraph,mat::AdjacencyList,mat::QueueBFS> s(g,1);
	std::cout<<s.distanceTo(3)<<std::endl;
	auto p=s.getPath(3);
	for(auto x:p)
		std::cout<<x<<' ';
}