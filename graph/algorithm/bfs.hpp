#ifndef MAT_GRAPH_ALGORITHM_BFS_HPP
#define MAT_GRAPH_ALGORITHM_BFS_HPP
#include "../graph.hpp"
#include "unordered_map"
#include <queue>
namespace mat
{
	template<typename T>
	struct distance_type
	{
		typedef T type;
	};
	template<>
	struct distance_type<bool>
	{
		typedef std::size_t type;
	};
	template
	<
		typename V,
		typename E,
		typename EP,
		template<typename,typename,typename=SimpleDigraph> class G,
		typename Action
	>
	std::unordered_map<V,typename distance_type<E>::type>
	bfs(G<V,E,EP>& g, const V& s, Action f)
	{
		std::unordered_map<V,typename distance_type<E>::type> distance;
		std::queue<V> q;
		distance[s]=0;
		q.push(s);
		while(!q.empty())
		{
			V v = q.front();
			q.pop();
			for(auto y = g.nbegin(v);y!=g.nend(v);++y)
			{
				if(distance.find(y->first)==distance.end())
				{
					distance[y->first] = distance[v]+y->second;
					q.push(y->first);
					f(v,y->first);
				}
			}
			
		}
		return distance;
	}
	
}
#endif
