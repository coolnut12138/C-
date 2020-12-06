#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

//µü´úÆ÷
void test_string()
{
	string s("hello");
	for (size_t i = 0; i < s.length(); i++){
		cout << s[i] << " ";
	}
	cout << endl;

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		*it++;
	}
	cout << endl;

	vector<int> v(10, 5);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;

	list<int> l(10, 5);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;


}

string ReverseStr(const string& s)
{
	string ret;
	string::const_reverse_iterator it = s.crbegin();
	while (it != s.crbegin())
	{
		ret += *it;
		++it;
	}
	return ret;
}
int main()
{
	test_string();
	return 0;
}

//leetcode 38.±¨Êý
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1){
			return "1";
		}
		//µÝ¹é
		string str = countAndSay(n - 1);
		string res;
		int count = 1;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == str[i + 1]){
				count++;
				continue;
			}
			else{
				if (str[i] != str[i + 1]){
					res += to_string(count) + str[i];
					count = 1;
				}
			}
		}
		return res;
	}
};
  
 
//test
