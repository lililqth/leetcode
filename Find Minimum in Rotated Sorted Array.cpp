#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
		int min = 0x3f3f3f3f;
		int i;
        for (i=1; i<num.size(); i++)
        {
			if (num[i-1] >= num[i])
			{
				return num[i];
			}
        }
		if (i == num.size())
		{
			return num[0];
		}
    }
};
int main()
{
	Solution sol;
	vector<int> num;
	num.push_back(2);
	num.push_back(1);
	cout << sol.findMin(num)<<endl;
	system("pause");
	return 0;
}