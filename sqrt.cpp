#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int sqrt(int x) {
		if (x < 4 && x > 0)
		{
			return 1;
		}
		int high=x, low=0;
		while (true)
		{
			long long ans = (high+low)/2;
			long long a = (ans-1) * (ans-1) - x;
			long long b = ans*ans - x;
			long long c = (ans+1)*(ans+1) - x;
			if (c>b && b>a && a>0 )
			{
				high = ans;
			}
			else if (a<b && b<c && c<0)
			{
				low = ans;
			}
			else if (a<b && b<0 && c>0)
			{
				return ans;
			}
			else if (a<0 && 0<b &&b<c)
			{
				return ans-1;
			}
			else if (a==0 || b==0 || c==0)
			{
				return (a==0 ? (ans-1):(b==0 ? ans:(ans+1))); 
			}
			else
			{
				;
			}
		}
	}
};
int main()
{
	Solution sol;
	cout << sol.sqrt(2147395599) <<endl;
	system("pause");
}