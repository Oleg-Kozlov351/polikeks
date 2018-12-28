#include <iostream>
#include <cstdlib>

template<class T>
class tree
{
	struct Node
	{
		T item;
		Node *son;
		Node * bro;
		Node(T i, Node*s = NULL, Node *b = NULL)
		{
			item = i;
			son = s;
			bro = b;
		}
		Node() {};
	};
	Node *root;
public:
	tree() { root = NULL; }
	void add(const T &elem)
	{
		add(root, elem);
	}
	void f()
	{
		Node *temp = new Node;
		*temp = *root;
		std::cout << temp->item;
		while (temp->son != NULL)
		{
			*temp = *temp->son;
			std::cout << temp->item;
			while (temp->bro != NULL)
			{
				*temp = *temp->bro;
				std::cout << temp->item;
			}
			//*temp = *root;
		}
	}
	void print()
	{
		Node *temp = new Node;
		*temp = *root;
		if (temp->son != NULL)
		{
			*temp = *temp->son;
			while (temp->bro != NULL)
			{
				std::cout << temp->item;
				*temp = *temp->bro;
			}
			std::cout << temp->item;
		}
	}
private: void add(Node *&node, const T &item)
{
	int a;
	if (node == NULL)
	{
		node = new Node(item);
		std::cout << "Elem added. Write 0 for add bro, or 1 for add son" << std::endl;
	}
	else {
		std::cin >> a;
		if (/*item < node->item*/a > 0) {
			add(node->son, item);
		}

		else {
			add(node->bro, item);
		}
	}
}
};

int main() {
	/*	int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char * arrCh;
	double * arrD;
	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];
	std::cout << "Input arrI";
	for (int it = 0; it < sizeI; it++) {
	std::cin >> arrI[it];
	}
	std::cout << "Input arrCh";
	for (int it = 0; it < sizeCh; it++) {
	std::cin >> arrCh[it];
	}
	std::cout << "Input arrD";
	for (int it = 0; it < sizeD; it++) {
	std::cin >> arrD[it];
	}
	std::cout << "Max element int = " << myFunc(arrI, sizeI);
	std::cout << "Max element char = " << myFunc(arrCh, sizeCh);
	std::cout << "Max element double = " << myFunc(arrD, sizeD);
	*/
	/*
		myList<int> li(5);
		li.push_back(4);
		//li.push_back(7);
		li.print();*/

	tree<int> t1;
	t1.add(1); 
	t1.add(2);
	t1.add(3);
	t1.add(4);
	t1.f();
	//t1.print();
	//getchar();
	system("pause");
	return 0;
}