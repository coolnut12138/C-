#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	String(char* str = "")
	{
		assert(str != nullptr);
		// _size:有效字符数量，不包含'\0'
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);		//while(*_str++ = *str++);
		_capacity = _size;
	}

	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}

	void Swap(String& s)
	{	
		//成员函数swap，完成指针的交换，无深拷贝，效率高
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String& operator=(String s)
	{
		Swap(s);
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator begin() const
	{
		return _str;
	}

	const_iterator end() const
	{
		return _str + _size;
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	const char* c_str() const
	{
		return _str;
	}

	void PushBack(char c)
	{
		//检查空间是否足够
		if (_size == _capacity)
		{
			//初始容量设置为15
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			//申请空间
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			//更新指针
			_str = tmp;
			//更新容量
			_capacity = n;
		}
	}

	void PopBack()
	{
		if (_size > 0)
		{
			_str[--_size] = '\0';
		}
	}

	void Resize(size_t n, char c = '\0')
	{
		//大于容量，重新分配容量
		if (n > _capacity)
		{
			Reserve(n);
		}
		//大于_size，重新分配_size,多的补'\0'
		if (n > _size)
		{
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			//从pos + len的位置开始挪动数据，每个数据向前挪动 len 个位置
			for (size_t i = pos + len; i <= _size; i++)
			{
				_str[pos++] = _str[i];
			}
			_size -= len;
		}
	}

	void Append(const char* str)
	{
		size_t sz = strlen(str);
		if (_size + sz >= _capacity)
		{
			Reserve(_size + sz);
		}
		//从'\0'的位置开始插入字符串str
		strcpy(_str + _size, str);
		_size = _size + sz;
	}

	void Insert(size_t pos, char c)
	{
		assert(pos <= _size);
		//扩容
		if (_size >= _capacity)
		{
			size_t newCapacity = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newCapacity);
		}
		//元素挪动，从后往前挪动，留出pos位置插入新元素
		size_t end = _size;
		//注意此处不要用
		//while (end >= pos){
		//	_str[end + 1] = _str[end];
		//	--end;		
		//因为当头插时，end减到0的时候循环还会进来，然后再减1，由于end是size_t类型，所以会变成整型最大值
		//}
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		//插入元素
		_str[pos] = c;
		_size++;
		_str[_size] = '\0';
	}

	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t sz = strlen(str);
		//增容。因为是插入字符串，所以不能简单的增容二倍，增加的容量要能够放下原有的和新的字符
		if (_size >= _capacity)
		{
			Reserve(_size + sz);
		}

		//挪动元素,从最后一个到最前面，一个一个往后挪
		size_t end = _size + sz;
		while (end > pos + sz - 1)
		{
			_str[end] = _str[end - sz];
			end--;
		}

		//插入新元素，注意不能用strcpy，因为会把新字符串的'\0'也拷贝过去而覆盖原有的数据
		//strncpy可以使用
		strncpy(_str + pos, str, sz);
		//或者一个一个拷贝
		//while(*str)
		//{
		//	  _str[pos++] = *str++;
		//}
		_size += sz;
	}

	size_t find(char c)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == c){
				return i;
			}
		}
		//如果没找到返回npos
		return npos;
	}
	//静态成员在类外初始化
	static const size_t npos;

	//字符串第一次出现的位置
	size_t find(size_t pos, char* str)
	{
		char* posPtr = strstr(_str + pos, str);
		if (posPtr)
		{
			return posPtr - _str;	//返回坐标
		}
		else
		{
			return npos;
		}
	}

	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	String& operator+=(const String& s)
	{
		//多种写法
		//1）*this += s._str;
		//2）*this += s.c_str();
		Append(s._str);
		return *this;
	}

private:
	friend ostream& operator<<(ostream& _cout, const String& s);
	char* _str;
	size_t _size;
	size_t _capacity;
};
const size_t String::npos = -1;

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s.c_str();
	return _cout;
}

//char* subStrPos(char* dest, char* src)
//{
//	char* dst = dest;
//	char* sc = src;
//	while (*dst)
//	{	
//		//第一个字符相等再往后走
//		if (*dst == *sc){
//			char* mathdest = dst + 1;
//			char* mathsrc = sc + 1;
//			//匹配剩余子串
//			while (*mathdest && *mathsrc){
//				if (*mathdest != *mathsrc){
//					break;
//				}
//				mathdest++;
//				mathsrc++;
//			}
//			if (*mathsrc == '\0')
//			{
//				//匹配成功返回子串在目标字符串中第一次出现的位置
//				return dst;
//			}
//		}
//		++dst;
//	}
//	return nullptr;
//}

//测试[]
void PrintString(const String& s)
{
	for (size_t i = 0; i < s.Size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
}

//测试iterator
void PrintWithIterator(const String& s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << endl;
		++sit;
	}
	cout << endl;
}

void test1()
{
	String s1;
	s1.PushBack('1');
	s1.PushBack('2');
	s1.PushBack('3');
	s1.PushBack('4');
	s1[0] = 'e';
	s1.PopBack();
	s1.Append("asd");
	s1.Resize(3, '\0');
	s1.Reserve(20);
	cout << s1.Capacity() << endl;
	cout << s1.Size() << endl;
	cout << s1.c_str() << endl;
	cout << s1 << endl;
	String s2;
	s2 = s1;
	cout << s2 << endl;
	String s3(s1);
	cout << s3 << endl;
	s3.Erase(2, 1);
	cout << s3 << endl;
	s3.Insert(1, '9');
	cout << s3 << endl;
	s3.Insert(1, "lzl");
	cout << s3 << endl;
	//PrintString(s1);
	//PrintWithIterator(s1);

	cout << s3.find('l') << endl;
	cout << s3.find('w') << endl;
	cout << s3.find(0, "lzl") << endl;
	cout << s3.find(3, "lzl") << endl;

	s3 += 'a';
	cout << s3 << endl;
	s3 += s1;
	cout << s3 << endl;
	s3 += "lzl";
	cout << s3 << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}