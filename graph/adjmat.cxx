#ifndef MAT_GRAPH_ADJMAT_CXX
#define MAT_GRAPH_ADJMAT_CXX
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <memory>
#include "edge_policy.hpp"
namespace mat
{
	template <typename Vertex, typename Edge, typename EdgePolicy = SimpleDigraph>
	class AdjacencyMatrix:private EdgePolicy
	{
		typedef std::vector<std::vector<Edge>> MatType;
		typedef std::unordered_map<Vertex,std::size_t> MapType;
	public:
		AdjacencyMatrix()
		{
			static_assert
			(
				!EdgePolicy::multi,
				"Multigraph in Adjacency Matrix not available."
			);
		}
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
				map[v] = tam.size();
				tam.push_back(v);
			}
		}
		void removeVertex(const Vertex& v)
		{
			auto i = map[v];
			mat.erase(mat.begin()+i);
			auto it=tam.erase(tam.begin()+i);
			
			for(auto& v:mat)
				v.erase(v.begin()+i);
			
			while(it!=tam.end())
				map[*it++]--;
		}
		void insertEdge(const Vertex& x,const Vertex& y,const Edge& e)
		{
			Edge& ref = getEdge(x,y);
			if(ref==e)
				return;
			else ref=e;
			if(!EdgePolicy::directed)
				insertEdge(y,x,e);
		}
		void removeEdge(const Vertex& x,const Vertex& y,const Edge& = Edge())
		{
			Edge& ref = getEdge(x,y);
			if(ref==Edge())
				return;
			else 
				ref=Edge();
			if(!EdgePolicy::directed)
				removeEdge(y,x);
		}
		std::size_t size()
		{
			return mat.size();
		}
		class EdgeList 
		{
		public:
			EdgeList(MapType& map_,std::vector<Vertex>& tam_,std::vector<Vertex>& vec_)
			:map(map_),tam(tam_),vec(vec_){};
			
			EdgeList(const EdgeList& e)
			:map(e.map),tam(e.tam),vec(e.vec){}
			
			EdgeList& operator=(const EdgeList& e)
			{
				map = e.map;
				tam = e.tam;
				vec = e.vec;
				return *this;
			}
			
			class iterator
			{
			public:
				iterator(std::size_t cur_,std::vector<Edge>& vec_,MapType& map_,std::vector<Vertex>& tam_)
				:vec(vec_),cur(set(cur_)),map(map_),tam(tam_){};
				std::pair<Vertex,Edge> operator*()
				{
					return std::make_pair(tam[cur],vec[cur]);
				}
				std::unique_ptr<std::pair<Vertex,Edge>> operator->()
				{
					return std::unique_ptr<std::pair<Vertex,Edge>>
					(new std::pair<Vertex,Edge>(tam[cur],vec[cur]));
				}
				bool operator==(iterator it){return cur==it.cur;}
				bool operator!=(iterator it){return cur!=it.cur;}
				iterator operator++(int)
				{
					cur=set(cur+1);
					return iterator(cur,vec,map,tam); 
				}
				iterator operator++()
				{
					auto x=cur;
					cur=set(cur+1);
					return iterator(x,vec,map,tam);
				}
			private:
				std::vector<Edge>& vec;
				std::size_t cur;
				
				MapType& map;
				std::vector<Vertex>& tam;
				
				
				std::size_t set(std::size_t i)
				{
					while(vec[i]==Edge()&&i<=vec.size())
						++i;
					return i;
				}
			};
			iterator begin()
			{
				return iterator(0,vec,map,tam);
			}
			iterator end()
			{
				return iterator(vec.size(),vec,map,tam);
			}

		private:
			MapType& map;
			std::vector<Vertex>& tam;
			std::vector<Vertex>& vec;
		};
		typedef typename EdgeList::iterator edge_iterator;
		edge_iterator nbegin(const Vertex& v)
		{
			return EdgeList(map,tam,mat[map[v]]).begin();
		}
		edge_iterator nend(const Vertex& v)
		{
			return EdgeList(map,tam,mat[map[v]]).end();
		}
		
		class vertex_iterator
		{
		public:
			class VertexData 
			{
			public:
				VertexData(const Vertex& v_,const EdgeList& e):v(v_),list(e){};
				Vertex v;
				EdgeList list;
			};
			vertex_iterator(std::size_t cur_,MapType& map_,MatType& mat_,std::vector<Vertex>& tam_)
			:cur(cur_),map(map_),mat(mat_),tam(tam_){}
			VertexData operator*()
			{
				VertexData v(tam[cur],EdgeList(map,tam,mat[map[v.v]]));
				return v;
			}
			std::unique_ptr<VertexData> operator->()
			{
				return 
				std::unique_ptr<VertexData>
				(new VertexData(tam[cur],EdgeList(map,tam,mat[cur])));
			}
			bool operator==(vertex_iterator it){return cur==it.cur;}
			bool operator!=(vertex_iterator it){return cur!=it.cur;}
			
			vertex_iterator operator++(int)
			{
				cur++;
				return vertex_iterator(cur,map,mat,tam);
			}
			vertex_iterator operator++()
			{
				auto x = cur++;
				return vertex_iterator(x,map,mat,tam);
			}
		private:
			std::size_t cur;
			MapType& map;
			MatType& mat;
			std::vector<Vertex>& tam;
		};
		
		vertex_iterator begin()
		{
			return vertex_iterator(0,map,mat,tam);
		}
		vertex_iterator end()
		{
			return vertex_iterator(size(),map,mat,tam);
		}
		
		Edge& getEdge(const Vertex& x,const Vertex& y)
		{
			auto xit = map.find(x);
			auto yit = map.find(y);
			
			if(xit == map.end() || yit==map.end())
				throw(std::runtime_error("Vertex absent in Graph.\n"));
			
			return mat[xit->second][yit->second];
		}
	private:
		MatType mat;
		MapType map;
		
		std::vector<Vertex> tam;
		

	};
}
#endif