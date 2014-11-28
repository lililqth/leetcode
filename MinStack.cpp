#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <list>
using namespace std;

class MinStack {
	public:
		stack<int> STK;
		stack<int> minSTK;
		void push(int x) {
			if (minSTK.empty() || minSTK.top() >= x)
			{
				minSTK.push(x);
			}
			STK.push(x);
		}

		void pop() {
			int x = STK.top();
			STK.pop();
			if (x == minSTK.top())
			{
				minSTK.pop();
			}
		}

		int top() {
			return STK.top();
		}

		int getMin() {
			return minSTK.top();
		}
};

int main(int argc, char **argv)
{
	MinStack *Ms = new MinStack();
	Ms->push(0);
	Ms->push(1);
	Ms->push(0);
	cout << Ms->getMin() << endl;
	Ms->pop();	
	cout <<	Ms->getMin() << endl;
	system("pause");
	return 0;
}
