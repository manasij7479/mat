#ifndef MAT_GRAPH_EDGETRAITS_HPP
#define MAT_GRAPH_EDGETRAITS_HPP
#include<string>
namespace mat
{
	template<typename E>
	struct edge_traits{typedef E sum;};
	
	template<>
	struct edge_traits<int>{typedef long sum;};
	
	template<>
	struct edge_traits<unsigned int>{typedef unsigned long sum;};
	
	template<>
	struct edge_traits<char>{typedef std::string sum;};
}
#endif