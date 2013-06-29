#ifndef MAT_GRAPH_ADJLIST_CXX
#define MAT_GRAPH_ADJLIST_CXX
#include <algorithm>
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
			std::remove_if(begin(),end(),[&](VertexData& vd){return vd.v==v;});
			for(auto& x = begin();x!=end();++x)
			{
				std::remove_if(nbegin(x->v),nend(x->v),[&](std::pair<Vertex,Edge> ve){return v==ve.first;});
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
			auto list = getList(x);
			std::remove(list.first(),list.second(),std::make_pair(y,e));
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