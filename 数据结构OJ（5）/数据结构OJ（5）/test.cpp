//给定一个整数数组 nums 和一个整数目标值 target
//请你在该数组中找出 和为目标值 target  的那 两个 整数
//并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。
//但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int* cur = (int*)malloc(2 * sizeof(int));
                cur[0] = i;
                cur[1] = j;
                *returnSize = 2;
                if (i != j)
                {
                    return cur;
                }
            }
        }
    }
    return NULL;
}

//给你一个单链表的头节点 head ，
//请你判断该链表是否为回文链表。
//如果是，返回 true ；否则，返回 false 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
bool isPalindrome(struct ListNode* head)
{
    struct ListNode* mid = middleNode(head);
    struct ListNode* rhead = reverseList(mid);
    while (head && rhead)
    {
        if (head->val != rhead->val)
        {
            return false;
        }
        head = head->next;
        rhead = rhead->next;
    }
    return true;
}
//感觉自己站在了巨人的肩膀上

//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random 
//该指针可以指向链表中的任何节点或空节点。
//
//构造这个链表的 深拷贝。
//深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
//并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//复制链表中的指针都不应指向原链表中的节点 。
//单链表叠加随机指针，随机指向链表结点或者是空
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node* cur = head;
    struct Node* copy = NULL;
    while (cur)
    {
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur)
    {
        copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    struct Node* newhead = NULL;
    struct Node* tail = NULL;
    cur = head;
    while (cur)
    {
        copy = cur->next;
        struct Node* next = copy->next;
        if (tail == NULL)
        {
            newhead = tail = copy;
        }
        else
        {
            tail->next = copy;
            tail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return newhead;
}
//给你一个链表的头节点 head 。删除 链表的 中间节点 ，
//并返回修改后的链表的头节点 head 。
//
//长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），
//其中 ⌊x⌋ 表示小于或等于 x 的最大整数。
//
//对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    struct ListNode* slow = head, * fast = head;
    struct ListNode* pre = NULL;
    while (fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = slow->next;
    free(slow);
    slow = NULL;
    return head;
}


//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；
//否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//例如，121 是回文，而 123 不是。

bool isPalindrome(int x)
{
    int arr[10] = { 0 };
    int count = 0;
    if (x < 0)
    {
        return false;
    }
    while (x)
    {
        arr[count] = x % 10;
        count++;
        x /= 10;
    }
    int m = 0;
    for (int j = count - 1; j > (count / 2 - 1); j--)
    {
        if (arr[j] != arr[m])
        {
            return false;
        }
        m++;
    }
    return true;
}




//题目背景
//语文考试结束了，成绩还是一如既往地有问题。
//
//题目描述
//语文老师总是写错成绩，所以当她修改成绩的时候，总是累得不行。她总是要一遍遍地给某些同学增加分数，又要注意最低分是多少。你能帮帮她吗？
//
//输入格式
//第一行有两个整数n，p，代表学生数与增加分数的次数。
//第二行有n 个数，代表各个学生的初始成绩。
//接下来p 行，每行有三个数，x，y，z，代表给第x 个到第y 个学生每人增加z 分。
//输出格式
//输出仅一行，代表更改分数后，全班的最低分。
#include <stdio.h>
int a[5000005], dif[5000005], n, p, mina;
int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dif[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        dif[x] += z;
        dif[y + 1] -= z;
    }
    mina = dif[1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + dif[i];
        if (a[i] < mina)
        {
            mina = a[i];
        }
    }
    printf("%d", mina);
    return 0;
}

