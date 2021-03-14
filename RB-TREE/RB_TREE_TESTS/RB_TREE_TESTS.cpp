#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Руслан\source\repos\RB-TREE\RB-TREE\LinkedList.h"
#include "C:\Users\Руслан\source\repos\RB-TREE\RB-TREE\RB-TREE(DEF).h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RBTREETESTS
{
	TEST_CLASS(RBTREETESTS)
	{
	public:
		
		TEST_METHOD(Left_Rotate)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(2);
			check.push_back(1);
			check.push_back(0);

			tree.Insert(1, 0);
			tree.Insert(2, 0);
			tree.Insert(0, 0);

			tree.Left_Rotate(tree.Get_Root());

			tree.Get_Keys(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
			Assert::AreEqual(test.at(2), check.at(2));
		}

		TEST_METHOD(Right_Rotate)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(0);
			check.push_back(1);
			check.push_back(2);

			tree.Insert(1, 0);
			tree.Insert(2, 0);
			tree.Insert(0, 0);

			tree.Right_Rotate(tree.Get_Root());

			tree.Get_Keys(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
			Assert::AreEqual(test.at(2), check.at(2));
		}

		TEST_METHOD(Insert)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(1);
			check.push_back(0);
			check.push_back(2);

			tree.Insert(1, 0);
			tree.Insert(2, 0);
			tree.Insert(0, 0);

			tree.Get_Keys(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
			Assert::AreEqual(test.at(2), check.at(2));
		}

		TEST_METHOD(Remove)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(2);
			check.push_back(0);

			tree.Insert(1, 0);
			tree.Insert(2, 0);
			tree.Insert(0, 0);

			tree.Remove(1);

			tree.Get_Keys(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
		}

		TEST_METHOD(Find)
		{
			RB_TREE_Node<int, int> tree;
			RB_TREE_Node<int, int>* test_tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(2);

			try
			{
				tree.Insert(1, 0);
				tree.Insert(2, 0);
				tree.Insert(0, 0);

				test_tree = tree.Find(2, tree.Get_Root());

				test_tree->Get_Keys(test_tree, &test);

				Assert::AreEqual(test.at(0), check.at(0));
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "RB Tree is empty");
			}
		}

		TEST_METHOD(Get_Keys)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(1);
			check.push_back(0);
			check.push_back(2);

			tree.Insert(1, 0);
			tree.Insert(2, 0);
			tree.Insert(0, 0);

			tree.Get_Keys(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
			Assert::AreEqual(test.at(2), check.at(2));
		}

		TEST_METHOD(Get_Values)
		{
			RB_TREE_Node<int, int> tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(89);
			check.push_back(47);
			check.push_back(63);

			tree.Insert(1, 89);
			tree.Insert(2, 63);
			tree.Insert(0, 47);
			
			tree.Get_Values(tree.Get_Root(), &test);

			Assert::AreEqual(test.at(0), check.at(0));
			Assert::AreEqual(test.at(1), check.at(1));
			Assert::AreEqual(test.at(2), check.at(2));
		}

		TEST_METHOD(Tree_Minimum)
		{
			RB_TREE_Node<int, int> tree;
			RB_TREE_Node<int, int>* test_tree;
			LinkedList<int> check, test;

			tree.NIL_N_Root();

			check.push_back(0);
			try
			{
				tree.Insert(1, 0);
				tree.Insert(2, 0);
				tree.Insert(0, 0);

				test_tree = tree.Tree_Minimum(tree.Get_Root());

				test_tree->Get_Keys(test_tree, &test);

				Assert::AreEqual(test.at(0), check.at(0));
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception, "RB Tree is empty");
			}
		}

		TEST_METHOD(Print)
		{
			RB_TREE_Node<int, int> tree;

			tree.NIL_N_Root();

			try
			{
				tree.Print(tree.Get_Root());
			}
			catch (const char* exception)
			{
				Assert::AreEqual(exception ,"RB Tree is empty");
			}

		}
	};
}
