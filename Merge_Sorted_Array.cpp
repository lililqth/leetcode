/*
https://leetcode.com/problems/merge-sorted-array/
合并两个有序数组，A和B，长度分别为m和n
A的长度足够（len>m+n）
这种方法可以不用额外开辟空间，和无用的判断
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i>=0 && j>=0)
        {
            A[k--] = A[i] > B[j] ?  A[i--] : B[j--];
        }
        while (j >= 0)
        {
            A[k--] = B[j--];
        }
    }
};