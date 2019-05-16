#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//template <class T1, class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1, T2>" << endl;
//	}
//private:
//	T1 _t1;
//	T2 _t2;
//};
//
////ȫ�ػ�
//template <>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<int, char>" << endl;
//	}
//private:
//	int _t1;
//	char _t2;
//};
//
////ƫ�ػ�
////1.�ػ���������
//template <class T>
//class Data<T, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<T, char>" << endl;
//	}
//private:
//	T _t1;
//	char _t2;
//};
////ƫ�ػ�
////2.��ģ���������һ������
//template <class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*, T2*>" << endl;
//	}
//private:
//	T1* _t1;
//	T2* _t2;
//};
//int main()
//{
//	Data<int, int> d;		//������ͨ��ģ��
//	Data<int, char> d1;		//����ȫ�ػ�
//	Data<float, char> d3;	//����ƫ�ػ�
//	Data<int*, float*> d4;	//���ý�һ�����ư汾
//	return 0;
//}

//template <size_t N>
//class A
//{
//public:
//	A()
//	{
//		cout << "A(size_t N):" << N << endl;
//	}
//};
//
//template <>
//class A<10>
//{
//public:
//	A()
//	{
//		cout << "A<10>:" << 10 << endl;
//	}
//};
//
//int main()
//{
//	A<20> a1;	//������ͨ��������ģ��汾
//	A<10> a2;	//�����ػ��汾
//	return 0;
//}

#if 0
template<size_t N>
class Sum
{
public:
	enum{ RET = Sum<N - 1>::RET + N };	//����ʱ�ݹ�
};

template<>
class Sum<1>
{
public:
	enum{ RET = 1 };
};

int main()
{
	cout << Sum<10>::RET << endl;	//������Ĭ�ϱ���ʱ�ݹ�������500��
	system("pause");
	return 0;
}
#endif


#include <string>
#if 0
template <class T>
void Copy(T* dst, const T* src, size_t size, bool isTrue)
{
	if (isTrue)
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "ǳ����" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "���" << endl;
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	Copy(arrcopy, arr, 5, true);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	Copy(arrcopy, arr, 5, false);	//����ֻͨ����true��false���׳������Կ�����������д
	return 0;
}
#endif

#if 0
bool isPODType(const char* type)
{
	char* podArr[] = { "int", "double", "float", "char" };
	int sz = sizeof(podArr) / sizeof(podArr[0]);
	for (int i = 0; i < sz; i++){
		if (!strcmp(type, podArr[i]))
			return true;
	}
	return false;
}

template <class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (isPODType(typeid(T).name()))	//���Ǵ˴����жϿ��ܱ������Ч�ʻ��ͣ����Եò���ʧ
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "ǳ����" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "���" << endl;
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	Copy(arrcopy, arr, 5);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	Copy(str1, strcopy, 5);	
	return 0;
}
#endif

#if 0
//������ȡ
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

template <class T>
struct TypeTraits	//������ȡ
{
	typedef FalseType IsPodType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType IsPodType;
};

template <class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPodType::Get())	
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "ǳ����" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "���" << endl;
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	Copy(arrcopy, arr, 5);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	Copy(str1, strcopy, 5);
	return 0;
}
#endif

//������ȡ���е�ʵ��
struct FalseType
{};

struct TrueType
{};

template <class T>
struct TypeTraits	//������ȡ
{
	typedef FalseType IsPodType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType IsPodType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType IsPodType;
};

template <class T>
void Copy(T* dst, const T* src, size_t size, TrueType)
{
	memcpy(dst, src, sizeof(T)*size);
	cout << "ǳ����" << endl;
}

template <class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{
	for (size_t i = 0; i < size; i++){
		dst[i] = src[i];
	}
	cout << "���" << endl;
}

template<class T>
void _Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::IsPodType());	//���ʹ�������������
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	_Copy(arrcopy, arr, 5);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	_Copy(str1, strcopy, 5);
	return 0;
}