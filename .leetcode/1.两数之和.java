/*
 * @Author: ls02 <2877455773@qq.com>
 * @Date: 2022-06-11 22:47:02
 * @LastEditors: ls02 <2877455773@qq.com>
 * @LastEditTime: 2022-06-11 22:49:05
 * @FilePath: \CPPe:\GitHub\LeetCode\.leetcode\1.两数之和.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ${ls02 <2877455773@qq.com>}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] sum = new int[2];
        
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    sum[0] = i;
                    sum[1] = j;

                    return sum;
                }
            }
        }
        
        return sum;
    }
}
// @lc code=end

