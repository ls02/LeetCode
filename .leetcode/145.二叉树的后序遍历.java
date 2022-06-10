/*
 * @Author: ls02 <2877455773@qq.com>
 * @Date: 2022-06-10 12:51:40
 * @LastEditors: ls02 <2877455773@qq.com>
 * @LastEditTime: 2022-06-10 12:53:46
 * @FilePath: \CPPe:\GitHub\LeetCode\.leetcode\145.二叉树的后序遍历.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ${ls02 <2877455773@qq.com>}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void _postorderTraversal(TreeNode root, List<Integer> result) {
        if (null == root) {
            return;
        }

        _postorderTraversal(root.left, result);
        _postorderTraversal(root.right, result);

        result.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        _postorderTraversal(root, result);

        return result;
    }
}
// @lc code=end

