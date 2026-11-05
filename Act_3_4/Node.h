#pragma once
#include <string>
using namespace std;

class Node
{
private:
	int key; // numero de accesos
	string value; // dirección IP
	Node* left;
	Node* right;
public:
	Node(int, string);
	void setLeft(Node*);
	void setRight(Node*);
	Node* getLeft();
	Node* getRight();

	int getKey();
	string getValue();
};


