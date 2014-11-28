#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> traversal;
	void generate(int nRows)
	{
		for (int i=0 ;i<nRows; i++)
		{
			traversal.push_back(i);
		}
		for (int i=nRows-2; i>0; i--)
		{
			traversal.push_back(i);
		}
	}
    string convert(string s, int nRows) {
		generate(nRows);
		string ans = "";
		vector<string> zigzag(nRows);
		for (int i=0,index=0; index<s.length(); (i=(i+1)%traversal.size()), index++)
		{
			zigzag[traversal[i]] = zigzag[traversal[i]] + s[index];
		}
		for (int i=0; i<nRows; i++)
		{
			ans += zigzag[i];
		}
		return ans;
    }
};
int main()
{
	Solution sol;
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
	cout << "PAHNAPLSIIGYIR"<<endl;
	system("pause");
}