#ifndef MAT_GRAPH_ALGO_PREDICATES_HPP
#define MAT_GRAPH_ALGO_PREDICATES_HPP
#include "../graph.hpp"
namespace mat
{
	template
	<
		typename V,
		typename E,
		typename EP,
		template<typename,typename,typename>class G
	>
	bool is_adjacent(G<V,E,EP>& g,const V& x,const V& y)
	{
		return g.getEdge(x,y)!=E();
	}
	
// 	template
// 	<
// 		typename V,
// 		typename E,
// 		typename EP
// 	>
// 	bool is_adjacent(mat::AdjacencyList<V,E,EP>& g,const V& x,const V& y)
// 	{
// 		for(auto y = g.nbegin(x);y!=g.nend(x);++y)
// 			if(y->first==y)
// 				return true;
// 		return false;
// 	}
}
#endif
