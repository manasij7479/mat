#ifndef MAT_GRAPH_ALGORITHM_SEARH
#define MAT_GRAPH_ALGORITHM_SEARH
#include<unordered_map>
#include<vector>
#include "../edgetraits.hpp"
#include <queue>
#include <stack>

//Generic Search Template
namespace mat
{
	/*
	 *FringeContainer:
	 * 1.Must have `V get()` and `put(V)` 
	 */
	template
	<
		typename V,
		typename E,
		typename EP,
		template <typename,typename,typename>class Graph,
		template<typename> class FringeContainer
	>
	class Search
	{
	public:
		Search(Graph<V,E,EP>& g_,const V& s_):g(g_),s(s_)
		{
			parent.reserve(g_.order());
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
						fringe.put(y->first);
						parent[g.vi(y->first)]=v;
					}
				}
			}
		}
		std::vector<V> getPath(const V& v);
		typename mat::edge_traits<E>::sum distanceTo(const V& v)
		{
			return distance[v];
		}
	private:
		Graph<V,E,EP>& g;
		V s;
		FringeContainer<V> fringe;
		std::vector<V> parent;
		
		std::unordered_map<V,typename mat::edge_traits<E>::sum> distance;
	};
	template<typename T>
	class QueueBFS
	{
	public:
		void put(const T& t)
		{
			data.push(t);
		}
		T get()
		{
			auto t=data.front();
			data.pop();
			return t;
		}
		bool empty()
		{
			return data.empty();
		}
	private:
		std::queue<T> data;
	};
	template<typename T>
	class StackDFS
	{
	public:
		void put(const T& t)
		{
			data.push(t);
		}
		T get()
		{
			auto t=data.top();
			data.pop();
			return t;
		}
		bool empty()
		{
			return data.empty();
		}
	private:
		std::stack<T> data;
	};
// 	template<typename T,class Compare>
// 	class PriorityQueueGEN
// 	{
// 	public:
// 		void put(const T& t)
// 		{
// 			data.push(t);
// 		}
// 		T get()
// 		{
// 			auto t=data.front();
// 			data.pop();
// 			return t;
// 		}
// 		bool empty()
// 		{
// 			return data.empty();
// 		}
// 	private:
// 		std::priority_queue<T,Compare> data;
// 	};
// 	template
// 	<
// 		typename V,
// 		typename E,
// 		typename EP,
// 		template <typename,typename,typename>class Graph
// 		
// 	>
// 	class BestFirstSearch
// 	{
// 		
// 	};
	
}
#endif