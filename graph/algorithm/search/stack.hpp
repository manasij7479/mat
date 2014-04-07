#include "containers.hpp"
#include<stack>
namespace mat
{
	template<typename T>
	class StackDFS : public FringeContainer<T>
	{
	public:
		StackDFS(dmap<T>& d):FringeContainer<T>(d){}
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
}