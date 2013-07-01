#ifndef MAT_GRAPH_MAKE_GRAPH_HPP
#define MAT_GRAPH_MAKE_GRAPH_HPP
#include<tuple>
namespace mm
{
	template
	<
		typename V,
		typename E,
		typename EP,
		template<typename,typename,typename> class G,
		typename Iterator
	>
	G<V,E,EP> make_graph(Iterator vl,Iterator el)
	{
		G<V,E,EP> g;
		for(auto& v:vl)
			g.insertVertex(v);
		for(auto& e:el)
			g.insertEdge(std::get<0>(e),std::get<1>(e),std::get<2>(e));
		return g;
	}
}
#endif