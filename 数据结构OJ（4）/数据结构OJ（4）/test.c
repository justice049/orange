//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。
//如果链表无环，则返回 null。
//
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
//则链表中存在环。 为了表示给定链表中的环，
//评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）
//。如果 pos 是 - 1，则在该链表中没有环。
//注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* low = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        low = low->next;
        if (fast == low)
        {
            struct ListNode* meet = low;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}
//输入一个长度为 n 的链表，设链表中的元素的值为 ai ，
//返回该链表中倒数第k个节点。
//如果该链表长度小于k，请返回一个长度为 0 的链表。
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    if (pListHead == NULL || k == 0)
    {
        return NULL;
    }
    int count = 1;
    struct ListNode* fast = pListHead;
    struct ListNode* low = pListHead;
    while (fast->next)
    {
        fast = fast->next;
        count++;
    }
    if (k > count)
    {
        return NULL;
    }
    int r = count - k;
    while (r)
    {
        low = low->next;
        r--;
    }
    return low;
}

//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
    {
        if (list2 != NULL)
        {
            return list2;
        }
        return NULL;
    }
    if (list2 == NULL)
    {
        if (list1 != NULL)
        {
            return list1;
        }
        return NULL;
    }
    if (list1->val <= list2->val)
    {
        struct ListNode* newhead = list1;
        struct ListNode* cur = list1;
        list1 = list1->next;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }

        }
        if (list1)
        {
            cur->next = list1;
        }
        if (list2)
        {
            cur->next = list2;
        }
        return newhead;
    }
    else
    {
        struct ListNode* newhead = list2;
        struct ListNode* cur = list2;
        list2 = list2->next;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;


            }
            else
            {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }

        }
        if (list1)
        {
            cur->next = list1;
        }
        if (list2)
        {
            cur->next = list2;
        }
        return newhead;
    }
}

//给定两个单链表的头节点 headA 和 headB 
//，请找出并返回两个单链表相交的起始节点。
//如果两个链表没有交点，返回 null 。
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* head1 = headA;
    struct ListNode* head2 = headB;
    int count1 = 0;
    int count2 = 0;
    while (head1)
    {
        count1++;
        head1 = head1->next;
    }
    while (head2)
    {
        count2++;
        head2 = head2->next;
    }
    int count = 0;
    if (count1 > count2)
    {
        count = count1 - count2;
        struct ListNode* head3 = headA;
        struct ListNode* head4 = headB;
        while (count)
        {
            head3 = head3->next;
            count--;
        }
        while (count2)
        {
            if (head3 == head4)
            {
                return head3;
            }
            head3 = head3->next;
            head4 = head4->next;
        }
        return NULL;
    }
    else
    {
        count = count2 - count1;
        struct ListNode* head3 = headA;
        struct ListNode* head4 = headB;
        while (count)
        {
            head4 = head4->next;
            count--;
        }
        while (count1)
        {
            if (head3 == head4)
            {
                return head3;
            }
            head3 = head3->next;
            head4 = head4->next;
        }
        return NULL;
    }

}


//给你一个链表的头节点 head ，判断链表中是否有环。
//
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
//则链表中存在环。 为了表示给定链表中的环，
//评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
    bool hasCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* low = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        low = low->next;
        if (fast == low)
        {
            return true;
        }
    }
    return false;
}