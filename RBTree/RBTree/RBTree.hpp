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
		//���������
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

		//�ҵ�Ҫ�����λ��
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

		//����
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
		//����
		//�������������ĺ�ɫ����Ҫ��������ǰ�����cur����Ǻ�ģ�������ĸ��׽���Ǻ�ɫ�ľ�Ҫ����
		while (cur != _header->_pParent && cur->_pParent->_color == RED) {
			//������صĽ���� cur(�Լ�)��parent(�����)��gParent(�游���)��uncle(������)
			PNode parent = cur->_pParent;
			PNode gParent = parent->_pParent;
			if (gParent->_pLeft = parent) {
				PNode uncle = gParent->_pRight;
				//���һ�����������Ϊ�죬��gParentȾ�죬��parent��uncleȾ��
				if (uncle && uncle->_color == RED) {
					parent->_color = uncle->_color = BLACK;
					gParent->_color = RED;
					cur = gParent;
				}
				else {
					//�������curΪ�졢parentΪ�졢gParentΪ�ڣ����岻���ڻ����������Ϊ�ڣ�
					//����Ҫ��ת+��ɫ���Լ��ж��Ƿ���Ҫ˫���������ߵ��ұ߸߻��ұߵ���߸���ֱ���Ҫ����˫��������˫����
					if (cur = parent->_pRight) {
						//��ʱ���游��ߵĸ��׵��ұ߸ߣ���������ת��Ϊ�������
						RotateL(parent);
						swap(parent, cur);
					}
					//�������curΪ�졢parentΪ�졢gParentΪ�ڣ����岻���ڻ����������Ϊ��
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