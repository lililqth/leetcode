package com.helloqiji;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by qiji on 16/3/1.
 */
public class Pascal_s_Triangle {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> pre = null;
        List<Integer> temp = new ArrayList<Integer>();
        for (int i = 0; i <= rowIndex; i++) {
            temp.add(1);
            for (int j = 1; j < i; j++) {
                temp.add(pre.get(j - 1) + pre.get(j));
            }
            if (i >= 1) {
                temp.add(1);
            }
            pre = temp;
        }
        return pre;
    }

    public static void main(String[] args) {
        Pascal_s_Triangle test = new Pascal_s_Triangle();
        System.out.println(test.getRow(5));
    }
}
