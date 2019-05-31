#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 1
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	:_left(nullptr)
	, _right(nullptr)
	, _data(val)
	{}
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _data;
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	BSTree(Node* root = nullptr)
		:_root(root)
	{}

	BSTree(const BSTree<T>& bst)
	{
		copy(_root, bst._root);
	}

	BSTree<T>& operator=(const BSTree<T>& bst)
	{
		if (this != &bst){
			if (this != nullptr){
				del(this->_root);
			}
			copy(_root, bst._root);
		}
		return *this;
	}

	void copy(Node*& newRoot, Node* root)
	{
		if (root == nullptr){
			newRoot = nullptr;
			return;
		}
		newRoot = new Node;
		newRoot->_data = root->_data;
		copy(newRoot->_left, root->_left);
		copy(newRoot->_right, root->_right);
		return;
	}

	~BSTree()
	{
		cout << "~BSTree()" << endl;
		del(_root);
	}

	void del(Node* root)
	{
		if (root == nullptr){
			return;
		}
		del(root->_left);
		del(root->_right);

		delete root;
		root = nullptr;
	}

	Node* find(const T& x)
	{
		if (_root == nullptr){
			return nullptr;
		}
		Node* cur = _root;
		while (cur){
			if (cur->_data == x){
				return cur;
			}
			else if (cur->_data < x){
				cur = cur->_right;
			}
			else if (cur->_data > x){
				cur = cur->_left;
			}
		}
		return nullptr;
	}

	bool Insert(const T& x)
	{
		//空树直接插
		if (_root == nullptr){
			_root = new Node(x);
			return true;
		}
		//插入需要记录当前结点和父节点，若插入的值存在则插入失败
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){
			if (cur->_data == x){
				return false;
			}
			else if (x > cur->_data){
				parent = cur;
				cur = cur->_right;
			}
			else if (x < cur->_data){
				parent = cur;
				cur = cur->_left;
			}
		}
		cur = new Node(x);
		if (parent->_data > x){
			parent->_left = cur;
		}
		else if (parent->_data < x){
			parent->_right = cur;
		}
		return true;
	}

	bool Erase(const T& x)
	{
		//空树
		if (_root == nullptr){
			return false;
		}
		//找结点
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){
			if (cur->_data == x){
				break;
			}
			else if (cur->_data < x){
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data > x){
				parent = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr){
			return false;
		}
		//要删除的结点是叶子节点
		if (cur->_left == nullptr && cur->_right == nullptr){
			//判断删除的结点是不是根结点
			if (cur != _root){
				if (parent->_left == cur){
					parent->_left = nullptr;
				}
				else{
					parent->_right = nullptr;
				}
			}
			else{
				_root = nullptr;
			}

			delete cur;
			cur = nullptr;
		}
		//要删除的结点孩子不完整
		//只有右孩子
		else if (cur->_left == nullptr){
			if (cur != _root){
				if (parent->_left == cur){
					parent->_left = cur->_right;
				}
				else{
					parent->_right = cur->_right;
				}
			}
			else{
				_root = cur->_right;
			}
			delete cur;
			cur = nullptr;
		}
		//只有左孩子
		else if (cur->_right == nullptr){
			if (cur != _root){
				if (parent->_left == cur){
					parent->_left = cur->_left;
				}
				else{
					parent->_right = cur->_left;
				}
			}
			else{
				_root = cur->_left;
			}

			delete cur;
			cur = nullptr;
		}
		//左右结点都存在，选左边最大值或者右边最小值替换要删除的值，然后删除这个最大值或最小值的位置
		else{
			Node* leftMax = cur->_left;
			parent = cur;
			//找到左边最大
			while (leftMax->_right){
				parent = leftMax;
				leftMax = leftMax->_right;
			}
			//替换
			cur->_data = leftMax->_data;
			if (parent->_left == leftMax){
				parent->_left = nullptr;
			}
			else{
				parent->_right = nullptr;
			}
			//删除结点
			delete leftMax;
			leftMax = nullptr;
		}
		return true;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root){
			_Inorder(root->_left);
			cout << root->_data << " ";
			_Inorder(root->_right);
		}
	}
private:
	Node* _root;
};

int main()
{
	BSTree<int> bst;
	bst.Insert(0);
	bst.Insert(10);
	bst.Insert(9);
	bst.Insert(4);
	bst.Insert(2);
	bst.Insert(19);
	bst.Insert(31);
	bst.Insert(7);
	bst.Insert(8);
	bst.Insert(90);
	bst.Insert(-1);
	bst.Insert(6);
	bst.Inorder();
	bst.Erase(6);
	bst.Inorder();
	bst.Erase(7);
	bst.Inorder();
	bst.Erase(0);
	bst.Inorder();
	BSTree<int> bst2(bst);
	bst2.Inorder();
	BSTree<int> bst3;
	bst3 = bst2;
	bst3.Inorder();
	return 0;
}
#endif

