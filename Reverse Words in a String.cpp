#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
using namespace std;
class Solution {
private:
	stack <string> stk;
public:
	string str;
	int index(char c)
	{
		int i=0;
		for (i=0; i<str.length(); i++)
		{
			if (str[i] == ' ')
			{
				break;
			}
		}
		return i;
	}
	void preTreatment(string &s)
	{
		str = "";
		int i, flag;
		for (i=0; s[i]==' '; i++){}
		for (flag=true; i<s.length();i++)
		{
			if (s[i] == ' ' && flag==true)
			{
				str += ' ';
				flag = false;
			}
			else if (s[i] != ' ')
			{
				flag = true;
				str += s[i];
			}
		}
		for (i=str.length()-1; i>=0&&str[i]==' '; i--){str.erase(i);}
	}
	void reverseWords(string &s) {
		preTreatment(s);
		s = str;
		int pos = 0;
		int index = str.find(' ', pos);
		if (index == string::npos)
		{
			return;
		}
		while (true)
		{
			string tmp = str.substr(pos, (index-pos));
			stk.push(tmp);
			if (index == str.length())
			{
				break;
			}
			pos = index+1;
			index = str.find(' ', index+1);
			if (index == string::npos)
			{
				index = str.length();
			}	
		}
		s = "";
		while (!stk.empty())
		{
			s += stk.top();
			stk.pop();
			if (!stk.empty())
			{
				s += " ";
			}
		}
	}
};
int main()
{
	Solution solu;
	string s = "  qwerqwer   qrweqwer   qewrqwer  ";
	solu.reverseWords(s);
	cout <<s<<endl;
	system("pause");
	return 0;
}