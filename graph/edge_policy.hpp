#ifndef MAT_GRAPH_EDGE_POLICY_HPP
#define MAT_GRAPH_EDGE_POLICY_HPP
namespace mat
{
	//Sample EdgePolicies
	struct SimpleDigraph
	{
		static const bool multi = false;
		static const bool directed = true;
	};
	
	struct SimpleUndirectedGraph
	{
		static const bool multi = false;
		static const bool directed = false;
	};
	
	
}
#endif
