#include "BTree.h"

template <class T1, class T2, class T3> BTree<T1,T2,T3>::BTree(){
	head = nullptr;
	size_ = 0;
}
template <class T1, class T2, class T3> BTree<T1,T2,T3>::BTree(std::shared_ptr<T1> & t){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = std::make_shared<BTreeItem<T1,T2,T3>>(t);
	head = item;
	size_ = 1;
}
template <class T1, class T2, class T3> BTree<T1,T2,T3>::BTree(std::shared_ptr<T2> & t){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = std::make_shared<BTreeItem<T1,T2,T3>>(t);
	head = item;
	size_ = 1;
}
template <class T1, class T2, class T3> BTree<T1,T2,T3>::BTree(std::shared_ptr<T3> & t){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = std::make_shared<BTreeItem<T1,T2,T3>>(t);
	head = item;
	size_ = 1;
}
template <class T1, class T2, class T3> std::shared_ptr<BTreeItem<T1,T2,T3>> BTree<T1,T2,T3>::minValueNode(std::shared_ptr<BTreeItem<T1,T2,T3>> root){
	std::shared_ptr<BTreeItem<T1,T2,T3>> min = root;

	while (min->leftT != nullptr) {
		min = min->leftT;
	}

	return min;
}

/*template <class T1, class T2, class T3> std::shared_ptr<BTreeItem<T1,T2,T3>> BTree<T1,T2,T3>::find(std::shared_ptr<T1> &obj){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (item != nullptr) {
		if (item->Area() == obj->Area()) {
			return item;
		}
		else if (item->Area() > obj->Area()) {
			item = item->leftT;
		}
		else if (item->Area() < obj->Area()) {
			item = item->rightT;
		}
	}
	return nullptr;
}
template <class T1, class T2, class T3> std::shared_ptr<BTreeItem<T1,T2,T3>> BTree<T1,T2,T3>::find(std::shared_ptr<T2> &obj){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (item != nullptr) {
		if (item->Area() == obj->Area()) {
			return item;
		}
		else if (item->Area() > obj->Area()) {
			item = item->leftT;
		}
		else if (item->Area() < obj->Area()) {
			item = item->rightT;
		}
	}
	return nullptr;
}
template <class T1, class T2, class T3> std::shared_ptr<BTreeItem<T1,T2,T3>> BTree<T1,T2,T3>::find(std::shared_ptr<T3> &obj){
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (item != nullptr) {
		if (item->Area() == obj->Area()) {
			return item;
		}
		else if (item->Area() > obj->Area()) {
			item = item->leftT;
		}
		else if (item->Area() < obj->Area()) {
			item = item->rightT;
		}
	}
	return nullptr;
} */
template <class T1, class T2, class T3> std::shared_ptr<BTreeItem<T1,T2,T3>> BTree<T1,T2,T3>::deleteNode(std::shared_ptr<BTreeItem<T1,T2,T3>> root, double area){
	if (root == nullptr) {
		return root;
	}

	if (area < root->Area()) {
		root->leftT = deleteNode(root->leftT, area);
	}
	else if (area > root->Area()) {
		root->rightT = deleteNode(root->rightT, area);
	}
	else {
		if (root->leftT == nullptr) {
			std::shared_ptr<BTreeItem<T1,T2,T3>> temp = root->rightT;
			root->leftT = nullptr;
			root->rightT = nullptr;
			return temp;
		}
		else if (root->rightT == nullptr) {
			std::shared_ptr<BTreeItem<T1,T2,T3>> temp = root->leftT;
			root->leftT = nullptr;
			root->rightT = nullptr;
			return temp;
		}

		std::shared_ptr<BTreeItem<T1,T2,T3>> temp = minValueNode(root->rightT);
		root->t1 = temp->t1;
		root->t2 = temp->t2;
		root->t3 = temp->t3;
		root->rightT = deleteNode(root->rightT, temp->Area());
	}
	return root;
}

template <class T1, class T2, class T3> void BTree<T1,T2,T3>::remove(double area){
	head = BTree<T1,T2,T3>::deleteNode(head, area);

}

template <class T1, class T2, class T3> void BTree<T1,T2,T3>::push(std::shared_ptr<T1> & obj){
	if(size_>5){
        std::cout << "Добавление невозможно, выберете дркгой эл-т массива" << std::endl;
        return;
	}
	if (head == nullptr) {
		head = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
		size_++;
		return;
	}
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (true) {
		if (obj->Area() <= item->Area()) {
			if (item->leftT == nullptr) {
				item->leftT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->leftT;
			}
		}
		else {
			if (item->rightT == nullptr) {
				item->rightT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->rightT;
			}
		}
	}
}
template <class T1, class T2, class T3> void BTree<T1,T2,T3>::push(std::shared_ptr<T2> & obj){
	if(size_>5){
        std::cout << "Добавление невозможно, выберете дркгой эл-т массива" << std::endl;
        return;
	}
	if (head == nullptr) {
		head = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
		size_++;
		return;
	}
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (true) {
		if (obj->Area() <= item->Area()) {
			if (item->leftT == nullptr) {
				item->leftT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->leftT;
			}
		}
		else {
			if (item->rightT == nullptr) {
				item->rightT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->rightT;
			}
		}
	}
}
template <class T1, class T2, class T3> void BTree<T1,T2,T3>::push(std::shared_ptr<T3> & obj){
	if(size_>5){
        std::cout << "Добавление невозможно, выберете дркгой эл-т массива" << std::endl;
        return;
	}
	if (head == nullptr) {
		head = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
		size_++;
		return;
	}
	std::shared_ptr<BTreeItem<T1,T2,T3>> item = head;
	while (true) {
		if (obj->Area() <= item->Area()) {
			if (item->leftT == nullptr) {
				item->leftT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->leftT;
			}
		}
		else {
			if (item->rightT == nullptr) {
				item->rightT = std::make_shared<BTreeItem<T1,T2,T3>>(obj);
				break;
			}
			else {
				item = item->rightT;
			}
		}
	}
}
template <class T1, class T2, class T3> void BTree<T1,T2,T3>::print_tree(std::shared_ptr<BTreeItem<T1,T2,T3>> item, int32_t a, std::ostream& os){
	for (int32_t i = 0; i < a; i++) {
		os << "  ";
	}
	os << *item;       //item->Area();  //item->GetFigure()->Print();
	if (item->leftT != nullptr) {
		BTree<T1,T2,T3>::print_tree(item->leftT, a + 1, os);
	}
	else if (item->rightT != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
	if (item->rightT != nullptr) {
		BTree<T1,T2,T3>::print_tree(item->rightT, a + 1, os);
	}
	else if (item->leftT != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
}

template <class T1, class T2, class T3> void BTree<T1,T2,T3>::print(){
	if (head != nullptr) {
		BTree<T1,T2,T3>::print_tree(head, 0, std::cout);
	}
}

template <class T1, class T2, class T3> void BTree<T1,T2,T3>::print(std::ostream& os){
	if (head != nullptr) {
		BTree<T1,T2,T3>::print_tree(head, 0, os);
	}
}

template <class T1, class T2, class T3> bool BTree<T1,T2,T3>::isEmpty(){
	return head == nullptr;
}
template <class A1, class A2, class A3> std::ostream& operator<<(std::ostream& os, BTree<A1,A2,A3>& tree) {
	tree.print(os);
	return os;
}
template <class T1, class T2, class T3> BTree<T1,T2,T3>::~BTree(){
}

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
template class BTree<Rectangle, Rhombus, Trapezium>;
template std::ostream& operator <<(std::ostream & os, BTree<Rectangle, Rhombus, Trapezium> & cont);
