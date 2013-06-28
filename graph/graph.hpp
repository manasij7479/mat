#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<type_traits>
template<typename VertexType,typename EdgeCharacter>
struct iterator_element
{
typedef std::pair<VertexType,EdgeCharacter> type;
};
template<typename VertexType>
struct iterator_element<VertexType,void>
{
	typedef VertexType type;
};

/*
 * VertexMapContainer
 * Example implementation with two std::unordered_map s below
 */
template<typename F,typename S>
class Bimap
{
public:
	void insert(F f,S s){FS[f]=s;SF[s]=f;}
	void remove(F f,S s){FS.erase(f);SF.erase(s);};
	S fs(F f){return FS[f];}
	F sf(S s){return SF[s];}
	
	
	template<typename E>
	typename std::enable_if
	<
		std::is_void<E>::value,
		typename iterator_element<S,E>::type
	>::type
	fs(typename iterator_element<F,E>::type f)
	{
		return fs(f);
	}
	
	template<typename E>
	typename std::enable_if
	<
		std::is_void<E>::value,
		typename iterator_element<S,E>::type
	>::type
	sf(typename iterator_element<S,E>::type s)
	{
		return sf(s);
	}
	
	template<typename E>
	typename std::enable_if<!std::is_void<E>::value,typename iterator_element<S,E>::type>::type
	fs(typename iterator_element<F,E>::type f)
	{
		return {fs(f.first),f.second};
	}
	
	template<typename E>
	typename std::enable_if<!std::is_void<E>::value,typename iterator_element<S,E>::type>::type
	sf(typename iterator_element<S,E>::type s)
	{
		return {sf(s.first),s.second};
	}

private:
	std::unordered_map<F,S> FS;
	std::unordered_map<S,F> SF;
};

/*
 *StoragePolicy:
 * 1. typedef IntType
 * 2. typedef vit 
 * 		A vit when deref'ed gives an std::pair<IntType,EdgeCharacter>
 * 3. vit nbegin(IntType), vit nend(IntType)
 * 4. IntType insertVertex()
 * 5. void removeVertex(IntType)
 * 6. void insertEdge(IntType,std::pair<IntType,EdgeCharacter>)
 * 		also  insertEdge(IntType,IntType) for void edge
 * 7. void removeEdge(IntType,IntType)
 * 8. IntType size()
 */

template<typename EdgeCharacter>
class AdjacencyList
{
public:
	typedef int IntType;
	typedef typename iterator_element<IntType,EdgeCharacter>::type element;
	typedef typename std::list<element>::iterator vit;
	
	vit nbegin(IntType v)
	{
		return data[v].begin();
	}
	
	vit nend(IntType v)
	{
		return data[v].end();
	}
	IntType size() const
	{
		return data.size();
	}
	IntType insertVertexI()
	{
		IntType i = size();
		data.push_back(std::list<element>());
		return i;
	}
	void removeVertexI()
	{
		//O(V+E)...lot of data maintenance...TODO
	}
	void insertEdgeI(IntType i,element e)
	{
		data[i].push_back(e);
	}
	void removeEdgeI(IntType i,element e)
	{
		std::remove(data[i].begin(),data[i].end(),e);
	}
private:
	std::vector<std::list<element>> data;
	
};

/*
 * Graph Aggregate
 */
template
<
	typename Vertex,
	typename EdgeCharacter,
	template<typename> class StoragePolicy,
	template<typename,typename> class VertexMapPolicy 
>
class Graph : 
public StoragePolicy<EdgeCharacter> ,
public VertexMapPolicy<Vertex,typename StoragePolicy<EdgeCharacter>::IntType>
{
public:
	typedef typename StoragePolicy<EdgeCharacter>::IntType IntType;
	typedef typename iterator_element<Vertex,EdgeCharacter>::type element;
	typedef typename StoragePolicy<EdgeCharacter>::vit vit;

	
	
	void insertVertex(const Vertex& v)
	{
		IntType i = this->insertVertexI();
		this->insert(v,i);
	}
	void insertEdge(const Vertex& v,element e)
	{
		this->insertEdgeI(this->fs(v),this->template fs<EdgeCharacter>(e));
	}
};

