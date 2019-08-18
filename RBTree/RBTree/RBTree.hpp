#include <iostream>
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class T>
class RBTNode
{
	typedef RBTNode<T> Node;
	Node* _pLeft = nullptr;
	Node* _pRight = nullptr;
	Node* _pParent = nullptr;
	T _data;
	Color _color = RED;
};

template<class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBTNode<V> Node;
	typedef Node* PNode;
	RBTree()
	{
		_header = new Node;
		_header->_pParent = nullptr;
		_header->_pLeft = _header;
		_header->_pRight = _header;
	}
	pair<iterator, bool> Insert(const V& data)
	{
		//空树的情况
		if (_header->_pParent == nullptr) {
			PNode root = new Node;
			root->_data = data;
			root->_color = BLACK;
			
			root->_pParent = _header;
			_header->_pParent = root;

			_header->_pLeft = root;
			_header->_pRight = root;

			return make_pair(iterator(root), true);
		}

		KeyOfValue keyOfVal;
		PNode cur = _header->_pParent;
		PNode parent = nullptr;

		//找到要插入的位置
		while (cur) {
			if (keyOfVal(data) > keyOfVal(cur->_data)) {
				parent = cur;
				cur = cur->_pRight;
			}
			else if (keyOfVal(data) < keyOfVal(cur->_data)) {
				parent = cur;
				cur = cur->_pLeft;
			}
			else {
				return make_pair(iterator(cur), false);
			}
		}

		//插入
		PNode newNode = new Node;
		newNode->_data = data;
		if (parent->_pLeft == cur) {
			parent->_pLeft = newNode;
		}
		else if (parent->_pRight == cur) {
			parent->_pRight == newNode;
		}
		newNode->_pParent = parent;

		cur = newNode;
		//调整
		//出现两个连续的红色结点就要调整，当前插入的cur结点是红的，如果它的父亲结点是红色的就要调整
		while (cur != _header->_pParent && cur->_pParent->_color == RED) {
			//调整相关的结点有 cur(自己)、parent(父结点)、gParent(祖父结点)、uncle(叔叔结点)
			PNode parent = cur->_pParent;
			PNode gParent = parent->_pParent;
			if (gParent->_pLeft = parent) {
				PNode uncle = gParent->_pRight;
				//情况一：叔叔存在且为红，则将gParent染红，将parent和uncle染黑
				if (uncle && uncle->_color == RED) {
					parent->_color = uncle->_color = BLACK;
					gParent->_color = RED;
					cur = gParent;
				}
				else {
					//情况三：cur为红、parent为红、gParent为黑，叔叔不存在或叔叔存在且为黑，
					//则需要旋转+调色（以及判断是否需要双旋：如果左边的右边高或右边的左边高则分别需要左右双旋和右左双旋）
					if (cur = parent->_pRight) {
						//此时是祖父左边的父亲的右边高，则先左旋转化为情况二；
						RotateL(parent);
						swap(parent, cur);
					}
					//情况二：cur为红、parent为红、gParent为黑，叔叔不存在或叔叔存在且为黑
					RotateR(gParent);
					gParent->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
			else if (gParent->_pRight == parent) {
				PNode uncle = gParent->_pLeft;
				if (uncle && uncle->_color == RED) {
					gParent->_color = RED;
					parent->_color = uncle->_color = BLACK;
					cur = parent;
				}
				else {
					if (cur = parent->_pLeft) {
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gParent);
					gParent->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
			_header->_pParent->_color = BLACK;
			_header->_pParent->_pParent = _header;
			_header->_pLeft = leftMost();
			_header->_pRight = rightMost();
			return make_pair(iterator(newNode), true);
		}

		PNode leftMost()
		{
			PNode cur = _header->_pParent;
			while (cur && cur->_pLeft) {
				cur = cur->_pLeft;
			}
			return cur;
		}

		PNode rightMost()
		{
			PNode cur = _header->_pParent;
			while (cur && cur->_pRight) {
				cur = cur->_pRight;
			}
			return cur;
		}

		void RotateL(PNode parent) {
			PNode subR = parent->_pRight;
			PNode subRL = subR->_pLeft;

			subR->_pLeft = parent;
			parent->_pRight = subRL;

			if (subRL) {
				subRL->_pParent = parent;
			}

			if (parent != _header->_pParent) {
				PNode gParent = parent->_pParent;
				if (gParent->_pLeft = parent) {
					gParent->_pLeft = subR;
				}
				else {
					gParent->_pRight = subR;
				}
				subR->_pParent = gParent;
			}
			else {
				subR->_pParent = _header;
				_header->_pParent = subR;
			}
			parent->_pParent = subR;
		}

		void RotateR(PNode parent) {
			PNode subL = parent->_pLeft;
			PNode subLR = subL->_pRight;
		}
	}
private:
	PNode _header;
};