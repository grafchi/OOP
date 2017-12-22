#include "BTreeItem.h"

template <typename T> BTreeItem<T>::BTreeItem() : value(nullptr) {
    for (int i = 0; i < max_; i++) children[i] = nullptr;
}
template <typename T> BTreeItem<T>::BTreeItem(T t) : value(t) {
    for (int i = 0; i < max_; i++) children[i] = nullptr;
}

#include <functional>
template class BTreeItem<std::function<void(void)>>;
