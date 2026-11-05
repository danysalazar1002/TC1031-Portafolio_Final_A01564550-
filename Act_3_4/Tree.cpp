#include "Tree.h"

Node* Tree::insertHelper(Node* rootT, int key, string value) //Complejidad Mejor caso: O(log n) | Peor caso O(n)
{
	if (rootT == nullptr) {
		return new Node(key, value);
	}
	else if (rootT->getKey() > key) {
		rootT->setLeft(insertHelper(rootT->getLeft(), key, value));
	}
	else if (rootT->getKey() < key) {
		rootT->setRight(insertHelper(rootT->getRight(), key, value));
	}
	return rootT;
}

void Tree::inorderReverseHelper(Node* rootT, int& count, int limit) //Complejidad Mejor caso: O(log n) | Peor caso O(n)
{
	if (rootT != nullptr && count < limit) {
		inorderReverseHelper(rootT->getRight(), count, limit);
		if (count < limit) {
			cout << "IP: " << rootT->getValue() << " | Numero de accesos: " << rootT->getKey() << "\n";
			count++;
		}
		inorderReverseHelper(rootT->getLeft(), count, limit);
	}
}

Tree::Tree()
{
	root = nullptr;
}

void Tree::insert(int key, string value) //Complejidad Mejor caso: O(log n) | Peor caso O(n)
{
	root = insertHelper(root, key, value);
}

void Tree::inorderReverse(int limit) // Para ver cuantos elementos quiere imprimir: Complejidad Mejor caso: O(log n) | Peor caso O(n)
{
	int count = 0;
	inorderReverseHelper(root, count, limit);
}
