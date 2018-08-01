
#include <iostream>
#include <ostream>
#include <list>
#include <algorithm>

#include "Node/Node.h"

using namespace std;

Node* buildGraph()
{
	Node* a = new Node('a');
	Node* b = new Node('b');
	Node* c = new Node('c');
	Node* d = new Node('d');
	Node* e = new Node('e');

	a->add(b); a->add(c); a->add(d);
	b->add(a); b->add(d);
	c->add(a); c->add(d); c->add(e);
 	d->add(c); d->add(e); d->add(b); d->add(a);
	e->add(d); e->add(c);

	return e;
}

ostream& operator<<(ostream& lhs, list<Node*>& rhs) 
{
	lhs << "list {";
	for( Node* node : rhs)
	{
		lhs << ((node != NULL) ? node->getVal() : '?') << ", ";
	}
	lhs << "}";
	
	return lhs;
}

list<Node*> bfs(Node* start)
{
	list<Node*> bfs_queue;		// bfs traversal
	list<Node*> bfs_visited;	// maintain a set of visited nodes

	bfs_queue.push_back(start);
	bfs_visited.push_back(start);

	// node for iterative solution
	Node* current;

	// use iterative solution
	while (!bfs_queue.empty())
	{
		// pop front element from queue
		current = bfs_queue.front();
		bfs_queue.pop_front();
		
		// iterate through each adj node and add to queue if it is not visited
		if (current != NULL)
		{
			cout << "Visiting node: " << current->getVal() << endl;
			cout << "\tvisited nodes: " << bfs_visited << endl;

			list<Node*> adjacentNodes = current->getAdjacencyList();
			cout << "\tadjacent nodes: " << adjacentNodes << endl;

			for (Node* adjacent : adjacentNodes)
			{	
				// add to queue only if node is NOT visited
				if (adjacent != NULL && 
					(std::find(bfs_visited.begin(), bfs_visited.end(), adjacent) == bfs_visited.end()))
				{
					// add to bfs_queue
					cout << "\tcurrent: " << current->getVal() << ", adding : " << adjacent->getVal() << endl;
					bfs_queue.push_back(adjacent);
					bfs_visited.push_back(adjacent);
				}
			}
		}
	}

	return bfs_visited;
}

int main()
{
	// build our graph and get the starting node
	Node* start = buildGraph();
	list<Node*> output = bfs(start);

	cout << "Our graph starts at: " << *start << endl;
	cout << "BFS output is: " << output << endl;

	return 0;
}