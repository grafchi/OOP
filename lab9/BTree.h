#ifndef BTREE_H
#define BTREE_H

#include <memory>
#include <future>
#include <mutex>
#include <thread>
#include <iostream>
#include "BTreeItem.h"

template <class T>
class BTree{
public:
    BTree();
    BTreeItem<T> * push(BTreeItem<T>* root, T value);

    BTreeItem<T> * root;
    size_t size_;
private:
};

#endif // BTREE_H
