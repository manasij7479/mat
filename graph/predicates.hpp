#include "graph.hpp"
namespace mat
{
	template
	<
		typename V,
		typename E,
		typename EP
	>
	bool is_adjacent(mat::AdjacencyMatrix<V,E,EP>& g,const V& x,const V& y)
	{
		return g.getEdge(x,y)!=Edge();
	}
	
	template
	<
		typename V,
		typename E,
		typename EP
	>
	bool is_adjacent(mat::AdjacencyList<V,E,EP>& g,const V& x,const V& y)
	{
		for(auto y = g.nbegin(x);y!=g.nend(x);++y)
			if(y->first==y)
				return true;
		return false;
	}
}