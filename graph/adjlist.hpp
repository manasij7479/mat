#ifndef MAT_GRAPH_ADJLIST_HPP
#define MAT_GRAPH_ADJLIST_HPP
namespace mat
{

	
	template <typename Vertex, typename Edge, typename EdgePolicy> class AdjacencyList;
	
	//TODO: Interface description

	
	//Sample EdgePolicy
	struct SimpleDigraph
	{
		static const bool multi = false;
		static const bool directed = true;
	};
	

}
#include "adjlist.cxx"
#endif