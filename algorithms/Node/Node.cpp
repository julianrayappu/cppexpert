
// Node.cpp

#include "Node.h"

ostream& Node::toStream(ostream& ostr) const
{
	ostr << "Node('" << _val << "')";
	
	ostr << " -> [";
	
	for (Node* node : _adjList)
	{
		ostr << node->_val << ", ";
	}

	ostr << "]";
	
	return ostr;
}

ostream& operator<<(ostream& lhs, const Node& node)
{
	//
	node.toStream(lhs);
	return lhs;
}