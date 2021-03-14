﻿#include "RB-TREE(DEF).h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		RB_TREE_Node<int, const char*> tree;
		LinkedList<int> values;

		tree.NIL_N_Root();

		tree.Insert(55, "fifty five");
		tree.Insert(40, "forty");
		tree.Insert(65, "sixty five");
		tree.Insert(60, "sixty");
		tree.Insert(75, "seventy five");
		tree.Insert(57, "fifty seven");

		cout << "Вывод элементов дерева в порядке обхода в глубину до удаления корня:\n";
		tree.Print(tree.Get_Root());

		tree.Remove(55);

		cout << "\nВывод элементов дерева в порядке обхода в глубину после удаления корня:\n";
		tree.Print(tree.Get_Root());

		cout << "\nВывод элементов дерева в виде списка:\n";
		tree.Get_Keys(tree.Get_Root(), &values);
		values.print_to_console();
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception << endl;
	}

	return 0;
}