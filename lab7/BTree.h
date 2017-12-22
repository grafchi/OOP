#ifndef BTREE_H
#define BTREE_H

#include <memory>
#include <iostream>
#include "BTreeItem.h"

template <class T1, class T2, class T3> class Cont;
template <class T1, class T2, class T3>
class BTree{
public:
    BTree();
    BTree(std::shared_ptr<T1> & t);
    BTree(std::shared_ptr<T2> & t);
    BTree(std::shared_ptr<T3> & t);
    /*std::shared_ptr<BTreeItem<T1,T2,T3>> find(std::shared_ptr<T1> &obj);
    std::shared_ptr<BTreeItem<T1,T2,T3>> find(std::shared_ptr<T2> &obj);
    std::shared_ptr<BTreeItem<T1,T2,T3>> find(std::shared_ptr<T3> &obj); */
    void remove(double area);

    void push(std::shared_ptr<T1> & obj);
	void push(std::shared_ptr<T2> & obj);
	void push(std::shared_ptr<T3> & obj);

	void print();
	void print(std::ostream& os);
    bool isEmpty();
    template <class A1, class A2, class A3> friend std::ostream& operator<<(std::ostream& os, BTree<A1,A2,A3> &tree);

    friend Cont<T1,T2,T3>;
    virtual ~BTree();
private:
    std::shared_ptr<BTreeItem<T1,T2,T3>> head;
    std::shared_ptr<BTreeItem<T1,T2,T3>> minValueNode(std::shared_ptr<BTreeItem<T1,T2,T3>> root);
	std::shared_ptr<BTreeItem<T1,T2,T3>> deleteNode(std::shared_ptr<BTreeItem<T1,T2,T3>> root, double area);
	void print_tree(std::shared_ptr<BTreeItem<T1,T2,T3>> item, int32_t a, std::ostream& os);
    int size_;
};

#endif // BTREE_H
