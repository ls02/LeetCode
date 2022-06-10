/*
 * @Author: ls02 <2877455773@qq.com>
 * @Date: 2022-06-10 10:48:05
 * @LastEditors: ls02 <2877455773@qq.com>
 * @LastEditTime: 2022-06-10 11:14:17
 * @FilePath: \CPPe:\GitHub\LeetCode\.leetcode\94.二叉树的中序遍历.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ${ls02 <2877455773@qq.com>}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
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
    public void _inorderTraversal(TreeNode root, List<Integer> result) {
        if (null == root) {
            return;
        }

        _inorderTraversal(root.left, result);
        result.add(root.val);
        _inorderTraversal(root.right, result);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();

        _inorderTraversal(root, result);

        return result;
    }
}
// @lc code=end

