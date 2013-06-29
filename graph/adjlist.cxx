#ifndef MAT_GRAPH_ADJLIST_CXX
#define MAT_GRAPH_ADJLIST_CXX
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include<stdexcept>
#include<iostream>
namespace mat
{
	template <typename Vertex, typename Edge, typename EdgePolicy=SimpleDigraph>
	class AdjacencyList : private EdgePolicy
	{
		typedef std::list<std::pair<Vertex,Edge>> EdgeList;
		struct VertexData {Vertex v;EdgeList list;};
	public:
		void insertVertex(const Vertex& v)
		{
			if(map.find(v)==map.end())
			{
				map[v] = lists.size();
				lists.push_back({v,EdgeList()});
			}
		}
		void removeVertex(const Vertex& v)
		{
			bool done = false;
			for(auto x = begin();x!=end();)
			{
				if(done)
					map[x->v]--;
				else if(x->v==v)
				{
					x=lists.erase(x);
					done=true;
					continue;
				}
				for(auto y = x->list.begin();y!=x->list.end();)
				{
					if(y->first == v)
					{
							y=x->list.erase(y);
							continue;
					}
					++y;
				}
				++x;
			}
		}
		void insertEdge(const Vertex& x,const Vertex& y,const Edge& e)
		{
			auto& list = getList(x);
			auto p = std::make_pair(y,e);
			auto it = std::find_if(list.begin(),list.end(),[&](std::pair<Vertex,Edge> v){return v.first==y;});
			
			if(it==list.end()||EdgePolicy::multi)
				list.push_back(p);
			else
				it->second = e;
			if(!EdgePolicy::directed)
				insertEdge(y,x,e);
		}
		void removeEdge(const Vertex& x,const Vertex& y,const Edge& e)
		{
			auto& list = getList(x);
// 			std::remove(list.begin(),list.end(),std::make_pair(y,e));
			list.remove(std::make_pair(y,e));
			if(!EdgePolicy::directed)
				removeEdge(y,x,e);	
		}
		
		typedef typename std::vector<VertexData>::iterator vertex_iterator;
		vertex_iterator begin(){return lists.begin();}
		vertex_iterator end(){return lists.end();}
		
		typedef typename EdgeList::iterator edge_iterator;
		edge_iterator nbegin(const Vertex& v){return getList(v).begin();}
		edge_iterator nend(const Vertex& v){return getList(v).end();}
	private:
		
		EdgeList& getList(const Vertex& v)
		{
			if(map.find(v)==map.end())
				throw(std::runtime_error("Vertex absent in Graph.\n"));
			return lists[map[v]].list;
		}
		
		std::vector<VertexData> lists; // The data for vertex v is stored in map[v] index of this list
		std::unordered_map<Vertex,std::size_t> map;
		
	};
}

#endif