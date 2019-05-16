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
////全特化
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
////偏特化
////1.特化部分类型
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
////偏特化
////2.对模板参数做进一步限制
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
//	Data<int, int> d;		//调用普通类模板
//	Data<int, char> d1;		//调用全特化
//	Data<float, char> d3;	//调用偏特化
//	Data<int*, float*> d4;	//调用进一步限制版本
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
//	A<20> a1;	//调用普通非类型类模板版本
//	A<10> a2;	//调用特化版本
//	return 0;
//}

#if 0
template<size_t N>
class Sum
{
public:
	enum{ RET = Sum<N - 1>::RET + N };	//编译时递归
};

template<>
class Sum<1>
{
public:
	enum{ RET = 1 };
};

int main()
{
	cout << Sum<10>::RET << endl;	//编译器默认编译时递归的深度是500次
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
		cout << "浅拷贝" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "深拷贝" << endl;
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	Copy(arrcopy, arr, 5, true);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	Copy(arrcopy, arr, 5, false);	//这样只通过传true和false容易出错，所以可以下面这样写
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
	if (isPODType(typeid(T).name()))	//但是此处的判断可能比深拷贝的效率还低，所以得不偿失
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "浅拷贝" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "深拷贝" << endl;
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
//类型萃取
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
struct TypeTraits	//类型萃取
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
		cout << "浅拷贝" << endl;
	}
	else{
		for (size_t i = 0; i < size; i++){
			dst[i] = src[i];
		}
		cout << "深拷贝" << endl;
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

//类型萃取库中的实现
struct FalseType
{};

struct TrueType
{};

template <class T>
struct TypeTraits	//类型萃取
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
	cout << "浅拷贝" << endl;
}

template <class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{
	for (size_t i = 0; i < size; i++){
		dst[i] = src[i];
	}
	cout << "深拷贝" << endl;
}

template<class T>
void _Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::IsPodType());	//类型传的是匿名对象
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