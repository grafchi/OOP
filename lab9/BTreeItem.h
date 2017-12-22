#ifndef BTREEITEM_H
#define BTREEITEM_H

#include <thread>

const int max_ = 2;
template <class T>
class BTreeItem
{
public:
    BTreeItem();
	BTreeItem(T t);

	T value;
	BTreeItem<T>* children[max_];
private:
};

#endif
