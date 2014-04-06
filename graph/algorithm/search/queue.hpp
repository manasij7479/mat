#include<queue>
namespace mat
{
	template<typename T>
	class QueueBFS
	{
	public:
		void put(const T& t)
		{
			data.push(t);
		}
		T get()
		{
			auto t=data.front();
			data.pop();
			return t;
		}
		bool empty()
		{
			return data.empty();
		}
	private:
		std::queue<T> data;
	};
}