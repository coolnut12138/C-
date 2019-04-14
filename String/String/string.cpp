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
		// _size:��Ч�ַ�������������'\0'
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
		//��Ա����swap�����ָ��Ľ������������Ч�ʸ�
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
		//���ռ��Ƿ��㹻
		if (_size == _capacity)
		{
			//��ʼ��������Ϊ15
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
			//����ռ�
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			//����ָ��
			_str = tmp;
			//��������
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
		//�������������·�������
		if (n > _capacity)
		{
			Reserve(n);
		}
		//����_size�����·���_size,��Ĳ�'\0'
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
			//��pos + len��λ�ÿ�ʼŲ�����ݣ�ÿ��������ǰŲ�� len ��λ��
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
		//��'\0'��λ�ÿ�ʼ�����ַ���str
		strcpy(_str + _size, str);
		_size = _size + sz;
	}

	void Insert(size_t pos, char c)
	{
		assert(pos <= _size);
		//����
		if (_size >= _capacity)
		{
			size_t newCapacity = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newCapacity);
		}
		//Ԫ��Ų�����Ӻ���ǰŲ��������posλ�ò�����Ԫ��
		size_t end = _size;
		//ע��˴���Ҫ��
		//while (end >= pos){
		//	_str[end + 1] = _str[end];
		//	--end;		
		//��Ϊ��ͷ��ʱ��end����0��ʱ��ѭ�����������Ȼ���ټ�1������end��size_t���ͣ����Ի����������ֵ
		//}
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		//����Ԫ��
		_str[pos] = c;
		_size++;
		_str[_size] = '\0';
	}

	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t sz = strlen(str);
		//���ݡ���Ϊ�ǲ����ַ��������Բ��ܼ򵥵����ݶ��������ӵ�����Ҫ�ܹ�����ԭ�еĺ��µ��ַ�
		if (_size >= _capacity)
		{
			Reserve(_size + sz);
		}

		//Ų��Ԫ��,�����һ������ǰ�棬һ��һ������Ų
		size_t end = _size + sz;
		while (end > pos + sz - 1)
		{
			_str[end] = _str[end - sz];
			end--;
		}

		//������Ԫ�أ�ע�ⲻ����strcpy����Ϊ������ַ�����'\0'Ҳ������ȥ������ԭ�е�����
		//strncpy����ʹ��
		strncpy(_str + pos, str, sz);
		//����һ��һ������
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
		//���û�ҵ�����npos
		return npos;
	}
	//��̬��Ա�������ʼ��
	static const size_t npos;

	//�ַ�����һ�γ��ֵ�λ��
	size_t find(size_t pos, char* str)
	{
		char* posPtr = strstr(_str + pos, str);
		if (posPtr)
		{
			return posPtr - _str;	//��������
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
		//����д��
		//1��*this += s._str;
		//2��*this += s.c_str();
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
//		//��һ���ַ������������
//		if (*dst == *sc){
//			char* mathdest = dst + 1;
//			char* mathsrc = sc + 1;
//			//ƥ��ʣ���Ӵ�
//			while (*mathdest && *mathsrc){
//				if (*mathdest != *mathsrc){
//					break;
//				}
//				mathdest++;
//				mathsrc++;
//			}
//			if (*mathsrc == '\0')
//			{
//				//ƥ��ɹ������Ӵ���Ŀ���ַ����е�һ�γ��ֵ�λ��
//				return dst;
//			}
//		}
//		++dst;
//	}
//	return nullptr;
//}

//����[]
void PrintString(const String& s)
{
	for (size_t i = 0; i < s.Size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
}

//����iterator
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