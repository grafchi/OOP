#include "BTree.h"
#include <queue>
#include <iostream>

template <typename T> BTree<T>::BTree(){
    root = nullptr;
    size_ = 0;
}
template <typename T> BTreeItem<T> * BTree<T>::push(BTreeItem<T> * root, T value){
	std::queue <BTreeItem<T>*> nodes_to_visit;
	BTreeItem<T>* current_node;
	if (!root)
	{
		root = new BTreeItem<T>(value);
		return root;
	}
	else
	{
		nodes_to_visit.push(root);
	}
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i<max_; i++)
		{
			if (!current_node->children[i])
			{
				current_node->children[i] = new BTreeItem<T>(value);
				return root;
			}
			else nodes_to_visit.push(current_node->children[i]);
		}
	}
	/*BTreeItem<T> * val = new BTreeItem<T>(value);
	if (!root){
		root = val;
		size_++;
		return root;
	}
    else if(!root->leftT){
        root->leftT = val;
        return root;
	}
	else if(!root->rightT){
        root->rightT = val;
        return root;
	}
	else if(size_<6){
        val = push(root->leftT, value);
        root->leftT = val;
	}
	else if(size_>5){
        val = push(root->rightT, value);
        root->rightT = val;
	} */
}
#include <functional>
template class BTree<std::function<void(void)>>;
