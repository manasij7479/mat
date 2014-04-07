#ifndef MAT_GRAPH_ALGORITHM_SEARH
#define MAT_GRAPH_ALGORITHM_SEARH
#include<unordered_map>
#include<vector>
#include "../../edgetraits.hpp"
#include <queue>
#include<iostream>
#include "containers.hpp"
//Generic Search Template
namespace mat
{
	template
	<
		typename V,
		typename E,
		typename EP,
		template <typename,typename,typename>class Graph,
		template<typename> class ContainerType
	>
	class Search
	{
	public:
		Search(Graph<V,E,EP>& g_,const V& s_):g(g_),s(s_)
		{
			distance[s]=0;
			parent[s]=s;
			fringe =new ContainerType<V>(distance);
			fringe->put(s);
			while(!fringe->empty())
			{
				V v = fringe->get();
				for(auto y = g.nbegin(v);y!=g.nend(v);++y)
				{
					if(distance.find(y->first)==distance.end())//neighbour not in fringe
					{
						distance[y->first]=distance[v]+y->second;
						fringe->put(y->first);
						parent[y->first]=v;
					}
				}
			}
		}
		std::vector<V> getPath(const V& v)
		{
			std::vector<V> result;
			V temp=v;
			while(parent[temp]!=temp)
			{
				result.push_back(temp);
				temp=parent[temp];
			}
			result.push_back(temp);
			std::reverse(result.begin(),result.end());
			return result;
		}
		typename mat::edge_traits<E>::sum distanceTo(const V& v)
		{
			return distance[v];
		}
		~Search()
		{
			delete fringe;
		}
		
	private:
		Graph<V,E,EP>& g;
		V s;
		FringeContainer<V>* fringe;
		std::unordered_map<V,V> parent;
		
		std::unordered_map<V,typename mat::edge_traits<E>::sum> distance;
	};

}

#endif