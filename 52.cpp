/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* res = NULL;
//         deque<ListNode*> dequeA,dequeB;
//         while(headA) {
//             dequeA.push_back(headA);
//             headA = headA->next;
//         }
//         while(headB) {
//             dequeB.push_back(headB);
//             headB = headB->next;
//         }

//         while(dequeA.size() > 0 && dequeB.size() > 0 && dequeA.back() == dequeB.back()) {
//             res = dequeA.back();
//             dequeA.pop_back();
//             dequeB.pop_back();
//         }

//         return res;
//     }
// };
//  以上方法考虑的是使用双端队列来从后面开始判断结点的地址，找到最后一个相同的地址就是目标地址，这样的时间复杂度为O(N)，但是空间复杂度较大
// 下面考虑题解中提到的双指针的方法。这个方法非常的巧妙，我们不妨这样假设，链表1种的非公共部分为len1，公共部分为len,链表2中的非公共部分为len2,公共部分为len
// 这样我们将会发现，len1 + len + len2 = len2 + len + len1.即将链表1遍历一遍之后再将链表2的非公共部分遍历一遍的长度和将链表2的遍历一遍和将链表1的非公共部分
// 的长度是一样的。因此我们可以利用这一特点找到第一个公共的结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* res = NULL;
//         deque<ListNode*> dequeA,dequeB;
//         while(headA) {
//             dequeA.push_back(headA);
//             headA = headA->next;
//         }
//         while(headB) {
//             dequeB.push_back(headB);
//             headB = headB->next;
//         }

//         while(dequeA.size() > 0 && dequeB.size() > 0 && dequeA.back() == dequeB.back()) {
//             res = dequeA.back();
//             dequeA.pop_back();
//             dequeB.pop_back();
//         }

//         return res;
//     }
// };
//  以上方法考虑的是使用双端队列来从后面开始判断结点的地址，找到最后一个相同的地址就是目标地址，这样的时间复杂度为O(N)，但是空间复杂度较大
// 下面考虑题解中提到的双指针的方法。这个方法非常的巧妙，我们不妨这样假设，链表1种的非公共部分为len1，公共部分为len,链表2中的非公共部分为len2,公共部分为len
// 这样我们将会发现，len1 + len + len2 = len2 + len + len1.即将链表1遍历一遍之后再将链表2的非公共部分遍历一遍的长度和将链表2的遍历一遍和将链表1的非公共部分
// 的长度是一样的。因此我们可以利用这一特点找到第一个公共的结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        // 这里flag的作用是防止出现没有相同的元素时不断的重复
        bool flag1 = true;
        bool flag2 = true;
        while (tmp1 != tmp2) {
            if(tmp1 && tmp1->next == NULL && flag1) {
                tmp1 = headB;
                flag1 = false;
                tmp2 = tmp2 == NULL ? NULL : tmp2->next;
                continue;
            }
            if(tmp2 && tmp2->next == NULL && flag2) {
                tmp2 = headA;
                flag2 = false;
                tmp1 = tmp1 == NULL ? NULL : tmp1->next;
                continue;
            }
            tmp1 = tmp1 == NULL ? NULL : tmp1->next;
            tmp2 = tmp2 == NULL ? NULL : tmp2->next;
        }
        return tmp1;
    }
};