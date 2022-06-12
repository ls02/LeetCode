/*
 * @Author: ls02 <2877455773@qq.com>
 * @Date: 2022-06-12 22:23:15
 * @LastEditors: ls02 <2877455773@qq.com>
 * @LastEditTime: 2022-06-12 22:44:11
 * @FilePath: \CPPe:\GitHub\LeetCode\.leetcode\83.删除排序链表中的重复元素.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ${ls02 <2877455773@qq.com>}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=83 lang=java
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (null == head) {
            return head;
        }

        ListNode cur = head;
        while (null != cur && null != cur.next) {
            ListNode next = cur.next;
            if (null != next && cur.val == next.val) {
                while (null != next && cur.val == next.val) {
                    next = next.next;
                }
            }

            cur.next = next;
            cur = next;
        }

        return head;
    }
}
// @lc code=end

