#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//leetcode 344.��ת�ַ���
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		//reverse(s.begin(), s.end());
//
//		int left = 0;
//		ע��˴�Ҫʹ��int������ʹ��size_t����Ϊ������ַ�����right�ͱ�ɸ��ģ�size_t�ǷǸ���
//		int right = s.size() - 1;
//		while (left < right){
//			swap(s[left], s[right]);
//			left++;
//			right--;
//		}
//	}
//};

//leetcode 387.�ַ����е�һ��Ψһ�ַ�
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int hashtable[26] = { 0 };
//		for (auto& e : s){
//			//ͳ��ÿһ���ַ�e���ֵĴ���������e - 'a'��λ����
//			hashtable[e - 'a']++;
//		}
//
//		for (int i = 0; i < s.size(); i++){
//			if (hashtable[s[i] - 'a'] == 1){
//				return i;
//			}
//		}
//		return -1;
//	}
//};

//ţ�ͣ����ַ����е�һ��ֻ����һ�γ��ֵ��ַ�
//����һ������ find �� rfind ������
//int main()
//{
//	using namespace std;
//	string str;
//	while (getline(cin, str))
//	{
//		unsigned int i;
//		for (i = 0; i<str.size(); i++)
//		{
//			if (str.find(str[i]) == str.rfind(str[i]))
//			{
//				cout << str[i] << endl;
//				break;
//			}
//		}
//		if (i == str.size())
//			cout << '.';
//	}
//	return 0;
//}
//�����������ù�ϣ����
//int main()
//{
//	string s;
//	while (cin >> s){
//		int flag = 0;
//		int hashtable[26] = { 0 };
//		for (int i = 0; i < s.size(); i++){
//			hashtable[s[i] - 'a']++;
//		}
//		for (int i = 0; i < s.size(); i++){
//			if (hashtable[s[i] - 'a'] == 1){
//				cout << s[i] << endl;
//				flag = -1;
//				break;
//			}
//		}
//		if (flag == 0){
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}

//�ַ������һ�����ʵĳ���
//int main()
//{
//	string s;
//	while (getline(cin, s)){
//		size_t pos = s.rfind(" ");
//		cout << s.size() - pos - 1 << endl;
//	}
//	return 0;
//}

//��֤���Ĵ�
//class Solution {
//public:
//	bool isLetterNumber(char c){
//		//���ڵ��ں�С�ڵ���
//		return (c >= '0' && c <= '9')
//			|| (c >= 'a' && c <= 'z')
//			|| (c >= 'A' && c <= 'Z');
//	}
//	bool isPalindrome(string s) {
//		int begin = 0;
//		int end = s.size() - 1;
//
//		//���ַ�����������ĸСдת��д
//		for (auto& e : s){
//			//���ڵ��ڣ����Ǵ���
//			if (e >= 'a'){
//				e -= 32;
//			}
//		}
//
//		while (begin < end){
//			//��ͷ��ʼ�ҵ�һ����ĸ������
//			while (begin < end){
//				if (isLetterNumber(s[begin])){
//					break;
//				}
//				else{
//					begin++;
//				}
//			}
//			//��β��ʼ�ҵ�һ����ĸ������
//			while (begin < end){
//				if (isLetterNumber(s[end])){
//					break;
//				}
//				else{
//					end--;
//				}
//			}
//			//�ж������ַ��Ƿ���ͬ
//			if (s[begin] != s[end]){
//				return false;
//			}
//			begin++;
//			end--;
//		}
//		return true;
//	}
//};

//�ַ������
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		//�ӵ�λ��ʼ��ӣ���λ������ַ����ĸߵ�ַ��
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		string ret;
//		int capacity = (len1 > len2 ? len1 + 1 : len2 + 1);
//		ret.reserve(capacity);
//		int step = 0;   //��λ
//		//�Գ��ַ������Ƚ���ѭ��
//		while (len1 >= 0 || len2 >= 0){
//			int curSum = 0;
//			//�ȼ�����һ�εĽ�λ
//			curSum += step;
//			//������������ǰλ��ֵ
//			if (len1 >= 0){
//				curSum += num1[len1] - '0';
//			}
//			if (len2 >= 0){
//				curSum += num2[len2] - '0';
//			}
//
//			//��ȡ��ǰλ��Ӻ��ֵ�����Ƿ���Ҫ��λ
//			if (curSum > 9){
//				curSum -= 10;
//				step = 1;
//			}
//			else{
//				step = 0;
//			}
//
//			//���浱ǰλ��Ӻ��ֵ
//			ret += curSum + '0';
//			len1--;
//			len2--;
//		}
//
//		if (step == 1){
//			ret += '1';
//		}
//
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};