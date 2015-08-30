/*题目要求小于n的素数的数量
采用埃拉托色尼筛法实现*/
package test;
import java.util.*;
public class Solution {
    public int countPrimes(int n) {
        boolean[] arr = new boolean[n];
        int bound = (int)Math.sqrt(n);
        int num = 0;
        for (int i=2 ; i<n; i++)
        {
            if (!arr[i])
            {
                num++;
            }
            if (i < bound)
            {
                for (int j=i*i; j<n; j+=i)
                {
                    arr[j] = true;
                }
            }
        }
        return num;
    }
}
