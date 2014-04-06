#include<stack>
namespace mat
{
	template<typename T>
	class StackDFS
	{
	public:
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