// Created by heyue on 2022/4/13
/*
 *kill the linklist
 *
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

struct  ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//剑指 Offer II 027. 回文链表
ListNode* find_mid_node_sPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

ListNode* reverse_sPalindrome(ListNode*  head){
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* pre = nullptr;
    ListNode* cur = head;

    while (cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;

}

//剑指 Offer II 027. 回文链表
bool isPalindrome(ListNode* head){
    if (head == nullptr) return true;

    ListNode* mid_node = find_mid_node_sPalindrome(head);
    ListNode* second_start = reverse_sPalindrome(mid_node->next);
    ListNode* list2 = second_start;
    ListNode* list1 = head;

    bool result = true;
    while (list2 != nullptr){
        if (list1->val != list2->val) {
            result = false;
            break;
        }else{
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    //recover back
    mid_node->next = reverse_sPalindrome(second_start);
    return result;
}


//剑指 Offer II 026. 重排链表

ListNode* find_mid_node(ListNode* head){
    //using slow and fast pointer
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse_reorder_list(ListNode* head){
    //edge
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* pre = nullptr;
    ListNode* cur = head;

    while (cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

void combine_reorder_list(ListNode* list1, ListNode* list2){
    //recreation
    ListNode* p = list1;
    ListNode* q = list2;

    while (list1 != nullptr && list2 != nullptr){
        p = list1->next;
        q = list2->next;

        list1->next = list2;
        list1 = p;

        list2->next = list1;
        list2 = q;
    }

}

void reorderList(ListNode* head){
    if (head == nullptr || head->next == nullptr) return;
    ListNode* list1 = head;
    ListNode* mid_node = find_mid_node(head);
    ListNode* list2 = mid_node->next;
    mid_node->next = nullptr;//cut off

    list2 = reverse_reorder_list(list2);
    combine_reorder_list(list1, list2);
}


//剑指 Offer II 025. 链表中的两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    stack<int> stack1;
    stack<int> stack2;

    while (l1){
        stack1.push(l1->val);
        l1 = l1->next;
    }
    while (l2){
        stack2.push(l2->val);
        l2 = l2->next;
    }

    int up = 0;//进位数
    ListNode* res = nullptr;

    //loop add
    while (!stack1.empty() || !stack2.empty() || up != 0){
        //a + b
        int a = stack1.empty() ? 0 : stack1.top();
        int b = stack2.empty() ? 0 : stack2.top();
        if (!stack1.empty()) stack1.pop();
        if (!stack2.empty()) stack2.pop();

        int cur_sum = a + b + up;
        up = cur_sum / 10;
        cur_sum = cur_sum % 10;

        auto new_node = new ListNode(cur_sum);
        new_node->next = res;
        res = new_node;
    }
    return res;

}


// method2 re-loop
ListNode* reverseList_method2(ListNode* head){
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* ans = reverseList_method2(head->next);
    //VIP
    head->next->next = head;
    head->next = nullptr;
    return ans;
}


//method1  iteration
ListNode* reverseList(ListNode* head){
    //edge
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* pre = nullptr;
    ListNode* cur = head;

    while (cur){
        ListNode* next = cur->next;
        //most VIP
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;

}



//
ListNode *detectCycle(ListNode *head){
    ListNode* slow = head;
    ListNode* fast = head;

    //find first meet
    while(true){
        if (fast == nullptr || fast->next== nullptr) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;//slow and first first meet
    }

    //fast reback
    fast = head;

    //find the entrance of circle
    while (slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


//
ListNode* removeNthFromEnd(ListNode* head, int n){
    //dummy node
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy->next;

    //move fast
    for(int i = 0; i < n; ++i){
        fast = fast->next;
    }

    //move together
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }

    //right now delete Nth node
    slow->next = slow->next->next;
    ListNode* res = dummy->next;//avoid only a node
    delete dummy;
    return res;
}


//剑指 Offer II 023. 两个链表的第一个重合节点 [双指针]
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr){
        return nullptr;
    }

    ListNode* girl = headA;
    ListNode* boy = headB;

    while(girl != boy){
        girl = (girl != nullptr) ? girl->next : headB;
        boy = (boy != nullptr) ? boy->next : headA;
    }
    return girl;

}














