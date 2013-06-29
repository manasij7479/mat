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
		typedef std::vector<std::vector<Edge>> MatType;
		std::unordered_map<Vertex,std::size_t> MapType;
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
		
		struct vertex_iterator
		{
			
		};
		
		
		class EdgeList 
		{
		public:
			class iterator
			{
			public:
				iterator(const Vertex& v_,std::size_t cur_,MatType& mat_,MapType& map_,std::vector<Vertex>& tam_)
				:v(v_),cur(set(cur_)),vec(mat_[map_[v]]),map(map_),tam(tam_){};
				std::pair<Vertex,Edge> operator*()
				{
					return std::make_pair(tam[cur],vec[cur]);
				}
				///TODO: Other operators
			private:
				Vertex v;
				std::size_t cur;
				std::vector<Edge>& vec;
				MapType& map;
				std::vector<Vertex>& tam;
				
				
				std::size_t set(std::size_t i)
				{
					while(vec[i]==Edge())
						++i;
					return i;
				}
			};
		};
		
		struct VertexData {Vertex v;EdgeList list;};
	private:
		MatType mat;
		MapType map;
		
		std::vector<Vertex> tam;
		
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