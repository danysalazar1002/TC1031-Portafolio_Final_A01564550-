#include "Node.h"

Node::Node(int keyT, string valueT) 
{
	key = keyT;
	value = valueT;
	left = right = nullptr;
}

void Node::setLeft(Node* Node)
{
	left = Node;
}

void Node::setRight(Node* Node)
{
	right = Node;
}

Node* Node::getRight()
{
	return right;
}

int Node::getKey()
{
	return key;
}

string Node::getValue()
{
	return value;
}

Node* Node::getLeft()
{
	return left;
}
