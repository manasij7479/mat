#ifndef MAT_GRAPH_ADJLIST_HPP
#define MAT_GRAPH_ADJLIST_HPP
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

namespace mat
{
	struct SimpleDigraph;
	
	template <typename Vertex, typename Edge, typename EdgePolicy=SimpleDigraph>
	class AdjacencyList : private EdgePolicy
	{
		typedef std::list<std::pair<Vertex,Edge>> EdgeList;
		struct VertexData {Vertex v;EdgeList list;};
	public:
		void insertVertex(const Vertex& v)
		{
			auto it = map.find(v);
			if(it!=map.end())
			{
				*it = lists.size();
				lists.push_back({v,EdgeList()});
			}
		}
		void insertEdge(const Vertex& x,const Vertex& y,const Edge& e)
		{
			EdgeList& list = lists[map[x]].list;
			auto p = std::make_pair(y,e);
			auto it = std::find_if(list.begin(),list.end(),[&](std::pair<Vertex,Edge> v){return v.first==y;});
			if(it==list.end()||EdgePolicy::multi)
				list.push_back(p);
			else
				it->second = e;
			if(!EdgePolicy::directed)
				insertEdge(y,x,e);
		}
		
		typedef typename std::vector<VertexData>::iterator vertex_iterator;
		vertex_iterator begin(){return lists.begin();}
		vertex_iterator end(){return lists.end();}
		
		typedef typename EdgeList::iterator edge_iterator;
		edge_iterator nbegin(const Vertex& v){return lists[map[v]].list.begin();}
		edge_iterator nend(const Vertex& v){return lists[map[v]].list.end();}
	private:
		std::vector<VertexData> lists; // The data for vertex v is stored in map[v] index of this list
		std::unordered_map<Vertex,std::size_t> map;
		
	};
	
	//Sample EdgePolicies
	struct SimpleDigraph
	{
		static const bool multi = false;
		static const bool directed = true;
	};	
}
#endif