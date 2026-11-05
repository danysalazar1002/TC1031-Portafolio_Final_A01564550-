#pragma once
#include <iostream>
#include "Node.h"

class Tree
{
private:
	Node* root;
	Node* insertHelper(Node*, int, string);
	void inorderReverseHelper(Node*, int&, int); // Se agrego un contador para que solo muestre los casos que pide
public:
	Tree();
	void insert(int, string);
	void inorderReverse(int); // Este va imprimir el inorder, pero al reves. Como el inorder siempre imprime de mayor a menor, solo cambiamo el orden de PID a PDI, para que imprima de derecha a izquierda (Mayor a menor accesos)
};

