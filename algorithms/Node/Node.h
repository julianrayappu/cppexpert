
// Node
#include <iostream>
#include <ostream>
#include <list>

using namespace std;

class Node
{
public:
	explicit Node(char val) : _val(val) {}
	Node(const Node& node) :
		_val(node._val),
		_adjList(node._adjList)
	{
		cout << "copying node " << node._val << endl;
	}

	virtual ~Node() {}

	char getVal() const { return _val; }
	list<Node*> getAdjacencyList() const { return _adjList; }

	void add(Node* node)
	{
		//cout << *this << " Node::add(" << *node << ")" << endl;
		_adjList.push_back(node);
	}

	ostream& toStream(ostream& ostr) const;
	friend ostream& operator<<(ostream& lhs, const Node& node);
	
private:
	char _val;
	list<Node*> _adjList;
};
