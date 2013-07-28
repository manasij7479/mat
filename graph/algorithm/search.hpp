#ifndef MAT_GRAPH_ALGORITHM_SEARH
#define MAT_GRAPH_ALGORITHM_SEARH
#include<unordered_map>
#include<vector>
#include "../edgetraits.hpp"
//Generic Search Template
namespace mat
{
	/*
	 *FringeContainer:
	 * 1.Must have `V get()` and `put(V)`
	 * 2.Must have `update()`   
	 */
	template
	<
		typename V,
		typename E,
		typename EP,
		template <typename,typename,typename> Graph,
		template<typename> class FringeContainer	
	>
	class Search
	{
	public:
		Search(Graph<V,E,EP>& g_,V& s_):g(g_),s(s_)
		{
			distance[s]=0;
			fringe.put(s);
			while(!fringe.empty())
			{
				V v = fringe.get();
				for(auto y = g.nbegin(v);y!=g.nend(v);++y)
				{
					if(distance.find(y->first)==distance.end())//neighbour not in fringe
					{
						distance[y->first]=distance[v]+y->second;
						fringe.put(v,y->first,y->second);
						parent[g.vi(y->first)]=v;
					}
				}
			}
		}
		std::vector<V> getPath(const V& v);
		typename mat::edge_traits<E>::sum distanceTo(const V& v);
	private:
		Graph<V,E,EP>& g;
		V s;
		FringeContainer<V> fringe;
		std::vector<V> parent;
		std::unordered_map<V,typename mat::edge_traits<E>::sum> distance;
	};
}
#endif