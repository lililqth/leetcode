package com.helloqiji;

import java.util.Arrays;
import java.util.Comparator;

public class Largest_Number {
        public String largestNumber(int[] nums) {
            int n = nums.length;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (compare(nums[j], nums[j + 1]) == -1) {
                        nums = exchange(nums, j, j + 1);
                    }
                }
            }
            String ans = "";
            for (int i = 0; i < n; i++) {
                ans += nums[i];
            }
            int i;
            for (i = 0; i < ans.length(); i++) {
                if (ans.charAt(i) != '0') {
                    break;
                }
            }
            if (i == ans.length()) {
                ans = "0";
            } else {
                ans = ans.substring(i);
            }
            return ans;
        }

        private int[] exchange(int[] array, int i, int j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            return array;
        }

        private int compare(int num1, int num2) {
            String str1 = String.valueOf(num1);
            String str2 = String.valueOf(num2);
            String n1 = str1 + str2;
            String n2 = str2 + str1;

            for (int i = 0; i < n1.length(); ) {
                char ch1 = n1.charAt(i);
                char ch2 = n2.charAt(i);
                if (ch1 == ch2) {
                    i++;
                } else if (ch1 < ch2) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return 0;
        }

    public static void main(String[] args) {
        int[] nums = {2, 2281};
        Largest_Number test = new Largest_Number();
        System.out.println(test.largestNumber(nums));
//        test.largestNumber(nums);
    }
}
