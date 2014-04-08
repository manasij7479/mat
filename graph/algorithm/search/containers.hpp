#ifndef MAT_GRAPH_ALGORITHM_CONTAINER_HPP
#define MAT_GRAPH_ALGORITHM_CONTAINER_HPP
#include "../../edgetraits.hpp"
#include <unordered_map>
namespace mat
{
	template <typename T>
	using dmap = std::unordered_map<T,typename mat::edge_traits<T>::sum>;
	
	template <typename T>
	class FringeContainer
	{
	public:
		FringeContainer(dmap<T>& d):distance(d){}
		virtual T get(){return T();};
		virtual void put(const T&){};
		virtual bool empty(){return true;}
	protected:
		dmap<T>& distance;
	};
}
#include "stack.hpp"
#include "queue.hpp"
#include "heap.hpp"
#endif