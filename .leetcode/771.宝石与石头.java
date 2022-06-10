/*
 * @Author: ls02 <2877455773@qq.com>
 * @Date: 2022-06-10 16:35:30
 * @LastEditors: ls02 <2877455773@qq.com>
 * @LastEditTime: 2022-06-10 17:14:32
 * @FilePath: \CPPe:\GitHub\LeetCode\.leetcode\771.宝石与石头.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ${ls02 <2877455773@qq.com>}, All Rights Reserved. 
 */
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=771 lang=java
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> s1 = new HashSet<Character>();

        for (char ch : jewels.toCharArray()) {
            s1.add(ch);
        }

        int count = 0;

        for (char ch : stones.toCharArray()) {
            if (s1.contains(ch)) {
                count++;
            }
        }

        return count;
    }
}
// @lc code=end

