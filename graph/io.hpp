#ifndef MAT_GRAPH_IO_HPP
#define MAT_GRAPH_IO_HPP
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include "graph.hpp"
namespace mat
{
	template<typename Graph>
	void debug_display(Graph& g,std::ostream& out)
	{
		for(auto x = g.begin();x!=g.end();++x)
		{
			out<<"["<<x->v<<"]->";
			for(auto y = g.nbegin(x->v);y!=g.nend(x->v);++y)
			{
				out<<"("<< y->first<<","<< y->second<<")->";
			}
			out<<"***\n";
		}
	}
	template
	<
		typename V,
		typename E,
		typename EP,
		template<typename,typename,typename> class G
	>
	G<V,E,EP> make_graph(std::istream& in)
	{
		G<V,E,EP> g;
		std::string line;
		while(std::getline(in,line))
		{
			
			std::istringstream in(line);
			char c;
			in>>c;
			if(c=='v')
			{
				V v;
				in>>v;
				g.insertVertex(v);
			}
			else if (c=='e')
			{
				V x,y;
				E e;
				in>>x>>y>>e;
				g.insertEdge(x,y,e);
			}
			else break;
		}
		return g;
	}
}
#endif