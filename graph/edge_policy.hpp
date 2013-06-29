#ifndef MAT_GRAPH_EDGE_POLICY_HPP
#define MAT_GRAPH_EDGE_POLICY_HPP
namespace mat
{
	//Sample EdgePolicy
	struct SimpleDigraph
	{
		static const bool multi = false;
		static const bool directed = true;
	};
}
#endif
