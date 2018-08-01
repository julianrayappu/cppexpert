
// depth first search

#include <iostream>
#include <ostream>
#include <list>
#include <stack>
#include <algorithm>
#include "Node/Node.h"

using namespace std;

ostream& operator<<(ostream& lhs, list<Node*> list)
{
	lhs << "list {";
	for (Node* node : list)
	{
		lhs << node->getVal() << ", " ;
	}
	lhs << "}";

	return lhs;
}

void dfs(Node* current, list<Node*>& visited)
{
	if (current == NULL)
	{
		return;
	}

	cout << "dfs begin for : " << current->getVal() << endl;
	cout << "\tvisited is: " << visited << endl;
	
	list<Node*> adjacencyNodeList = current->getAdjacencyList();

	for (Node* next : adjacencyNodeList)
	{
		if ((next != NULL) && 
			(std::find(visited.begin(), visited.end(), next) == visited.end()))
		{
			cout << "\t" << current->getVal() << " adding : " << next->getVal() << endl; 
			visited.push_back(next);
			dfs(next, visited);
		}
	}

	cout << "dfs complete for : " << current->getVal() << endl;
}

list<Node*> dfs(Node* start)
{
	list<Node*> visited;
	visited.push_back(start);
	
	dfs(start, visited);
	return visited;
}

Node* buildGraph()
{
	Node* a = new Node('a');
	Node* b = new Node('b');
	Node* c = new Node('c');
	Node* d = new Node('d');
	Node* e = new Node('e');
	Node* f = new Node('f');
	Node* g = new Node('g');
	Node* h = new Node('h');
	Node* i = new Node('i');

	a->add(b); a->add(c);
	b->add(a); 
	c->add(a); c->add(d); c->add(g);
	d->add(c); d->add(e); d->add(f); d->add(h);
	e->add(d); 
	f->add(d);
	g->add(c); g->add(h);
	h->add(g); h->add(d); h->add(i); 
	i->add(h);

	return a;
}


int main()
{
	Node* start = buildGraph();
	list<Node*> output = dfs(start);

	cout << "Starting node is " << *start << endl;
	cout << "Traversal path is " << output << endl;

	return 0;
}
