#ifndef MAT_GRAPH_ADJMAT_CXX
#define MAT_GRAPH_ADJMAT_CXX
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "edge_policy.hpp"
namespace mat
{
	template <typename Vertex, typename Edge, typename EdgePolicy = SimpleDigraph>
	class AdjacencyMatrix:private EdgePolicy
	{
	public:
		void insertVertex(const Vertex& v)
		{
			if(map.find(v)==map.end())
			{
				for(auto& el:mat)
					el.push_back(Edge());
				if(mat.empty())
					mat.push_back(std::vector<Edge>(1,Edge()));
				else
					mat.push_back(std::vector<Edge>(mat[0].size(),Edge()));				
			}
		}
		void removeVertex(const Vertex& v)
		{
			auto i = map[v];
			mat.erase(mat.begin()+i);
			for(auto& x:mat)
				x.erase(x.begin()+i);
			map.erase(v);
		}
		void insertEdge(const Vertex& x,const Vertex& y,const Edge& e)
		{
			Edge& ref = getEdge(x,y);
			ref=e;
		}
		void removeEdge(const Vertex& x,const Vertex& y,const Edge& = Edge())
		{
			Edge& ref = getEdge(x,y);
			ref=Edge();
		}
	private:
		std::vector<std::vector<Edge>> mat;
		std::unordered_map<Vertex,std::size_t> map;
		
		Edge& getEdge(const Vertex& x,const Vertex& y)
		{
			auto xit = map.find(x);
			auto yit = map.find(y);
			
			if(xit == map.end() || yit==map.end())
				throw(std::runtime_error("Vertex absent in Graph.\n"));
			
			return mat[xit->second][yit->second];
		}
	};
}
#endif