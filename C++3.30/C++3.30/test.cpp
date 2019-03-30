#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//leetcode 344.反转字符串
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		//reverse(s.begin(), s.end());
//
//		int left = 0;
//		注意此处要使用int，不能使用size_t，因为输入空字符串，right就变成负的，size_t是非负的
//		int right = s.size() - 1;
//		while (left < right){
//			swap(s[left], s[right]);
//			left++;
//			right--;
//		}
//	}
//};

//leetcode 387.字符串中第一个唯一字符
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int hashtable[26] = { 0 };
//		for (auto& e : s){
//			//统计每一个字符e出现的次数，放在e - 'a'的位置上
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

//牛客：找字符串中第一个只出现一次出现的字符
//方法一：利用 find 和 rfind 的特性
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
//方法二：利用哈希数组
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

//字符串最后一个单词的长度
//int main()
//{
//	string s;
//	while (getline(cin, s)){
//		size_t pos = s.rfind(" ");
//		cout << s.size() - pos - 1 << endl;
//	}
//	return 0;
//}

//验证回文串
//class Solution {
//public:
//	bool isLetterNumber(char c){
//		//大于等于和小于等于
//		return (c >= '0' && c <= '9')
//			|| (c >= 'a' && c <= 'z')
//			|| (c >= 'A' && c <= 'Z');
//	}
//	bool isPalindrome(string s) {
//		int begin = 0;
//		int end = s.size() - 1;
//
//		//让字符串中所有字母小写转大写
//		for (auto& e : s){
//			//大于等于，不是大于
//			if (e >= 'a'){
//				e -= 32;
//			}
//		}
//
//		while (begin < end){
//			//从头开始找第一个字母或数字
//			while (begin < end){
//				if (isLetterNumber(s[begin])){
//					break;
//				}
//				else{
//					begin++;
//				}
//			}
//			//从尾开始找第一个字母或数字
//			while (begin < end){
//				if (isLetterNumber(s[end])){
//					break;
//				}
//				else{
//					end--;
//				}
//			}
//			//判断两个字符是否相同
//			if (s[begin] != s[end]){
//				return false;
//			}
//			begin++;
//			end--;
//		}
//		return true;
//	}
//};

//字符串相加
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		//从低位开始相加，低位存放在字符串的高地址处
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		string ret;
//		int capacity = (len1 > len2 ? len1 + 1 : len2 + 1);
//		ret.reserve(capacity);
//		int step = 0;   //进位
//		//以长字符串长度结束循环
//		while (len1 >= 0 || len2 >= 0){
//			int curSum = 0;
//			//先加上上一次的进位
//			curSum += step;
//			//加上两个数当前位的值
//			if (len1 >= 0){
//				curSum += num1[len1] - '0';
//			}
//			if (len2 >= 0){
//				curSum += num2[len2] - '0';
//			}
//
//			//获取当前位相加后的值，看是否需要进位
//			if (curSum > 9){
//				curSum -= 10;
//				step = 1;
//			}
//			else{
//				step = 0;
//			}
//
//			//保存当前位相加后的值
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