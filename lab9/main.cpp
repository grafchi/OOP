#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include <memory>
#include <queue>
#include "ContItem.h"
#include "Cont.h"
#include "Allocator.h"
#include "BTree.h"
#include "BTreeItem.h"
#include <cstdlib>
#include <random>
#include <functional>
#include <future>
#include <thread>

typedef std::function<void(void)> command;
Cont<Rectangle, Rhombus, Trapezium> container(10);
BTree<command> tree;

void Circumvention(BTreeItem<command> *root){
    std::queue <BTreeItem<command>*> nodes_to_visit;
	BTreeItem<command>* current_node;
	nodes_to_visit.push(root);
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		command cmd = current_node->value;
		cmd();

		for (int i = 0; i < max_; i++)
		{
			if (current_node->children[i])
			{
				nodes_to_visit.push(current_node->children[i]);
			}
		}
	}
}

int main()
{
    setlocale(LC_CTYPE,"rus");
    int pos = 0;
    command cmd_push = [&]()
	{
		int n;
		std::cout << "Колличество фигур: ";
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			int figure_number = rand() % 3;
			int a = rand() % 10;
			int b = rand() % 10;
			int c = rand() % 10;

			if (figure_number == 0)
				container.push(std::shared_ptr<Rectangle>(new Rectangle(a, b)), pos);
			else if (figure_number == 1)
				container.push(std::shared_ptr<Rhombus>(new Rhombus(a, b)), pos);
			else if (figure_number == 2)
				container.push(std::shared_ptr<Trapezium>(new Trapezium(a, b, c)), pos);
            pos++;
		}
	};

	command cmd_remove_by_area = [&]()
	{
		double area;
		std::cout << "Введите площадь: ";
		std::cin >> area;
		container.removeIt_area(area);
	};

	command cmd_print = [&]()
	{
		std::cout << "Массив:\n" << container << std::endl;
	};

    tree.root = tree.push(tree.root, cmd_push);
	tree.root = tree.push(tree.root, cmd_push);
	tree.root = tree.push(tree.root, cmd_push);
	tree.root = tree.push(tree.root, cmd_print);
	tree.root = tree.push(tree.root, cmd_remove_by_area);
	tree.root = tree.push(tree.root, cmd_print);

	Circumvention(tree.root);
    return 0;
}
