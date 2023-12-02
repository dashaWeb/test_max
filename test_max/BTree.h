#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
	T  data;
	Node* left, * right, * parent;
	Node(const T& data = T(), Node* parent = nullptr,
		Node* left = nullptr, Node* right = nullptr)
		: data(data), parent(parent), left(left), right(right)
	{
	}
};

template<typename T>
class BTree
{
public:
	BTree() = default;
	void add(const T& data);
	void print() const;
	bool isEmpty() const;
	size_t  getSize() const;
	T min() const;
	T max() const;
	bool find(const T& data)const;
	void clear();
	Node<T>* findNode(const T& data) const;
	void deleteBranch(const T& data);
private:
	void printHelper(Node<T>*node) const;
	void clearHelper(Node<T>*node) const;
	void deleteHelper(Node<T>*node) const;
	Node <T>* root = nullptr;
	size_t  size = 0;
};

template<typename T>
inline void BTree<T>::add(const T& data)
{
	Node<T>* addNode = new Node<T>(data);
	++size;
	if (isEmpty())
	{
		root = addNode;
		return;
	}
	// шукаємо місце  для  включення нового вузла addNode
	Node<T>* tmp = root; // допоміжний вказівник для  руху по дереву
	while (true)
	{
		if (data < tmp->data) // новий вузол повинен привязуватися НАЛІВО
		{
			// наліво є місце ?
			if (tmp->left == nullptr) // зліва пусто
			{
				tmp->left = addNode; // привязали новий вузол наліво
				addNode->parent = tmp;
				break;// вийшли з  циклу
			}
			else // зліва зайнято
				tmp = tmp->left;// спускаємося наліво

		}
		else
		{
			// направо є місце ?
			if (tmp->right == nullptr) //справа пусто
			{
				tmp->right = addNode; // привязали новий вузол направо
				addNode->parent = tmp;
				break;
			}
			else // справа зайнято
				tmp = tmp->right;// спускаємося направо

		}

	}
}

template<typename T>
inline void BTree<T>::print() const
{
	cout << "Tree : ";
	printHelper(root);
	cout << endl;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline size_t BTree<T>::getSize() const
{
	return size;
}

template<typename T>
inline T BTree<T>::min() const
{
	if (isEmpty()) {
		std::cerr << "Min() error : empty tree\n";
		return T();
	}
	Node <T>* tmp = root;
	while (tmp->left != nullptr) // доки зліва від поточного(tmp) вузла є вузол
	{
		tmp = tmp->left;
	}
	return tmp->data;
}

template<typename T>
inline T BTree<T>::max() const
{
	if (isEmpty()) {
		std::cerr << "Min() error : empty tree\n";
		return T();
	}
	Node <T>* tmp = root;
	while (tmp->right != nullptr) // доки справа від поточного(tmp) вузла є вузол
	{
		tmp = tmp->right;
	}
	return tmp->data;
}
template<typename T>
inline bool BTree<T>::find(const T& data) const
{
	Node <T>* tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
			return true;
		if (data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return false;
}
template<typename T>
inline void BTree<T>::clear()
{
	cout << "Start clear : " << endl;
	clearHelper(root);
	root = nullptr;
	cout << "End clear;" << endl;

}
template<typename T>
inline Node<T>* BTree<T>::findNode(const T& data) const
{
	Node <T>* tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
			return tmp;
		if (data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return nullptr;
}
// bool find(const T& data)const; - чи дерево містить вузол зі значенням data

template<typename T>
inline void BTree<T>::printHelper(Node<T>* node) const
{
	if (node != nullptr)
	{
		printHelper(node->left);// вивід лівого піддерева відносно вузла node
		cout << node->data << "\t";
		printHelper(node->right);// вивід правого піддерева відносно вузла node
	}
}

template<typename T>
inline void BTree<T>::clearHelper(Node<T>* node) const
{
	if (node != nullptr)
	{
		clearHelper(node->left);// вивід лівого піддерева відносно вузла node
		clearHelper(node->right);// вивід правого піддерева відносно вузла node
		cout << "\t" << node->data << endl;
		delete node;
	}
}

template<typename T>
inline void BTree<T>::deleteHelper(Node<T>* node) const
{
	if (node != nullptr)
	{
		clearHelper(node->left);// вивід лівого піддерева відносно вузла node
		clearHelper(node->right);// вивід правого піддерева відносно вузла node
		cout << "\t" << node->data << endl;
		if (node->parent->left == node) {
			node->parent->left = nullptr;
		}
		else {
			node->parent->right = nullptr;
		}
		delete node;
	}
}

template<typename T>
inline void BTree<T>::deleteBranch(const T& data)
{
	auto node = findNode(data);
	if (node == nullptr) {
		cout << "Node not found " << endl;
		return;
	}
	deleteHelper(node);
}
