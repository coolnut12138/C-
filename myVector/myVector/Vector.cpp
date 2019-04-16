#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace myVector{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* const_Iterator;

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorge(nullptr)
		{}

		Vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorge(nullptr)
		{
			Reserve(n);
			while (n--){
				PushBack(value);
			}
		}

		//�������ʹ��Iterator�����������ͻᵼ�³�ʼ���ĵ���������[first��last]ֻ����Vector�ĵ�����
		//������������������������������[first, last]���������������ĵ���������
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		Vector(const Vector<T>& v)
		{
			//���--->���ռ�--->����
			_start = new T[v.Capacity()];
			for (size_t i = 0; i < v.Size(); i++)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.Size();
			_endOfStorge = _start + v.Capacity();
		}

		void PushBack(const T& val)
		{
			//��������
			if (_finish == _endOfStorge)
			{
				size_t newCapacity = (_start == nullptr ? 1 : 2 * Capacity());
				Reserve(newCapacity);
			}
			*_finish++ = val;
		}

		Vector<T> operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			//�ִ���
			//v�Ǿֲ����󣬳�����������ͷţ�����ָ��ָ�������
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorge, v._endOfStorge);
		}

		void PopBack()
		{
			Erase(end() - 1);
		}

		Iterator begin()
		{
			return _start;
		}

		Iterator end()
		{
			return _finish;
		}

		const_Iterator begin() const
		{
			return _start;
		}

		const_Iterator end() const
		{
			return _finish;
		}

		void Reserve(size_t capacity)
		{
			if (capacity > Capacity())
			{
				//���󲽣�1�����ռ� 2����� 3������ָ��
				int len = Size();
				T* newC = new T[capacity];
				if (_start)
				{
					for (int i = 0; i < len; i++)
					{
						newC[i] = _start[i];
					}
					delete[] _start;
				}
				_start = newC;
				_finish = _start + len;
				_endOfStorge = _start + capacity;
			}
		}

		void Resize(size_t n, const T& val = T())
		{
			//n С�ڵ�ǰ�� size�������ݸ�����С�� n
			if (n <= Size())
			{
				_finish = _start + n;
			}
			else{
				//n > ��ǰ����������������������
				if (n > Capacity())
				{
					Reserve(n);
				}
				//����λ�ø�ֵ
				while (_finish != _start + n){
					*_finish = val;
					++_finish;
				}
			}
		}

		void Insert(Iterator pos, const T& val)
		{
			assert(pos < _finish && pos >= _start);
			int len = pos - _start;

			//��������������
			if (_finish == _endOfStorge)
			{
				size_t newC = _start == nullptr ? 1 : 2 * Capacity();
				Reserve(newC);
			}
			
			//����֮����µ�����
			pos = _start + len;
			Iterator end = _finish;

			//�Ӻ���ǰŲ��Ԫ�أ��ڳ�pos�Ŀռ䣬������Ԫ��
			while (end != pos){
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			_finish++;
		}

		Iterator Erase(Iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			//ɾ��pos��λ�ã���pos+1��λ����ǰ����Ų��
			Iterator begin = pos + 1;
			while (begin != _finish){
				*(begin - 1) = *begin;
				begin++;
			}

			--_finish;
			return pos;
		}

		size_t Size() const
		{
			return _finish - _start;
		}

		size_t Capacity() const
		{
			return _endOfStorge - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorge = nullptr;
			}
		}
	private:
		T* _start;				//ָ�����ݿ�Ŀ�ʼ
		T* _finish;				//ָ�����ݿ��β
		T* _endOfStorge;		//ָ��洢������β
	};
}

template<class T>
void PrintVector(const myVector::Vector<T>& v)
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class T>
void PrintVectorWithIterator(const myVector::Vector<T>& v)
{
	auto vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

template<class T>
void PrintVectorWithFor(const myVector::Vector<T>& v)
{
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector1()
{
	myVector::Vector<int> first;	//��vector
	myVector::Vector<int> second(4, 100);	//4��int�Ϳռ䣬ֵΪ100
	myVector::Vector<int> third(second.begin(), second.end());	
	myVector::Vector<int> forth(third);

	int ints[] = { 2, 3, 1, 47 };
	myVector::Vector<int> fifth(ints, ints + sizeof(ints) / sizeof(ints[0]));

	PrintVectorWithIterator(first);
	PrintVectorWithIterator(second);
	PrintVectorWithIterator(third);
	PrintVectorWithIterator(forth);
	PrintVectorWithIterator(fifth);

	//����string����
	myVector::Vector<string> strV;
	strV.PushBack("abc");
	strV.PushBack("def");
	strV.PushBack("ghj");
	strV.PopBack();
	PrintVectorWithFor(strV);
}

void TestVector2()
{
	//ʹ��PushBack����4������
	myVector::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	//ʹ�õ�������ӡ
	myVector::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//ʹ�õ������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVectorWithIterator(v);
}

void TestVector3()
{
	size_t sz;
	myVector::Vector<int> foo;
	sz = foo.Capacity();
	cout << "making foo growing:" << endl;
	for (int i = 0; i < 100; i++)
	{
		foo.PushBack(i);
		if (sz != foo.Capacity())
		{
			sz = foo.Capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	//reserve
	myVector::Vector<int> bar;
	sz = bar.Capacity();
	bar.Reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.PushBack(i);
		if (sz != bar.Capacity()) {
			sz = bar.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	// resize
	myVector::Vector<int> myvector;
	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.PushBack(i);
	myvector.Resize(5);
	myvector.Resize(8, 100);
	myvector.Resize(12);
	std::cout << "myvector contains:";
	for(size_t i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

// find / insert / erase
void TestVector4()
{
	int a[] = { 1, 2, 3, 4 };
	myVector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	myVector::Vector<int>::Iterator pos = find(v.begin(), v.end(), 3);
	// ��posλ��֮ǰ����30
	v.Insert(pos, 30);
	myVector::Vector<int>::Iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ�����
	v.Erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// iteratorʧЧ����
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	myVector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	myVector::Vector<int>::Iterator pos = find(v.begin(), v.end(), 3);
	//// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	//v.Erase(pos);
	//cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	
	//// ��posλ�ò������ݣ�����pos������ʧЧ��
	//// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	//// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	//pos = find(v.begin(), v.end(), 3);
	//v.Insert(pos, 30);
	//cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	
	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ
	// ��ʧЧ�ĵ���������++it���ᵼ�³������
	myVector::Vector<int>::Iterator it = v.begin();
	/*while (it != v.end())
	{
		if (*it % 2 == 0)
			v.Erase(it);
		++it;
	}*/
	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		it = v.Erase(it);
		else
			++it;
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	TestVector5();
	system("pause");
	return 0;
}