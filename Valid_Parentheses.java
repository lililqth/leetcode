package com.helloqiji;

import java.util.Stack;

/**
 * Created by qiji on 16/2/28.
 */
public class Valid_Parentheses {
    public boolean isValid(String s) {
        if (s.length() == 0) {
            return true;
        }
        Stack stack = new Stack();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            String now = s.substring(i, i + 1);
            if (!stack.empty() && judge((String) stack.peek(), now)) {
                stack.pop();
            } else {
                stack.push(now);
            }
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }

    private boolean judge(String left, String right) {
        if ((left.equals("(") && right.equals(")")) ||
                (left.equals("[") && right.equals("]")) ||
                (left.equals("{") && right.equals("}"))) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Valid_Parentheses test = new Valid_Parentheses();
        String s = "({})";
        System.out.println(test.isValid(s));
    }
}
