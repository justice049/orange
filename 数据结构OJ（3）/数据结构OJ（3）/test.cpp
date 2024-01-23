//某种特殊的数列 a1, a2, a3, ... 的定义如下： 其中(n > 2)。给出任意
//一个正整数k，求该数列的第k项模以32767的结果是多少？
//输入描述：
//第1行是测试数据的组数 n ，后面跟着 n 行输入。
//每组测试数据占1行，包括一个正整数 k(1 ≤ k < 1000000) 。
//	输出描述： n 行，每行输出对应一个输入。输出应是一个非负整数
#include <stdio.h>
int main() {
    int m = 0;
    scanf("%d", &m);
    int arr[1000005];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < 1000000; i++)
    {
        arr[i] = (2 * arr[i - 1] + arr[i - 2]) % 32767;
    }
    do
    {
        int t = 0;
        scanf("%d", &t);
        int q = 0;
        q = arr[t - 1];
        printf("%d\n", q);
        m--;
    } while (m != 0);

    return 0;
}

//输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。本题包含多组输入。
//数据范围：输入的字符串长度满足 1 <= n <= 1000
//输入描述：输入一行字符串，可以有空格
//输出描述：统计其中英文字符，空格字符，数字字符，其他字符的个数
#include <stdio.h>
int main()
{
    int arr[5] = { 0 };
    char s[1000] = { 0 };
    gets(s);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            arr[0]++;
            i++;
        }
        else if (s[i] == ' ')
        {
            arr[1]++;
            i++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            arr[2]++;
            i++;
        }
        else
        {
            arr[3]++;
            i++;
        }
    }
    printf("%d\n%d\n%d\n%d\n", arr[0], arr[1], arr[2], arr[3]);
    return 0;
}

//一维数组的动态和
//给你一个数组 nums 。数组「动态和」的计算公式为：
//runningSum[i] = sum(nums[0]…nums[i]) 。请返回 nums 的动态和。
int sum[10000];
int* runningSum(int* nums, int numsSize, int* returnSize)
{
    sum[0] = nums[0];
    for (int i = 0; i < numsSize - 1; i++)
    {
        sum[i + 1] = sum[i] + nums[i + 1];
    }
    *returnSize = numsSize;
    return sum;
}

//搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会
//被按顺序插入的位置。请必须使用时间复杂度为 O(log n) 的算法
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (right + left) / 2;
    while (left < right)
    {
        if (nums[mid] > target)
        {
            right = mid;
            mid = (right + left) / 2;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
            mid = (right + left) / 2;
        }
        else
        {
            return mid;
        }
    }
    if (nums[right] < target)
    {
        return right + 1;
    }
    if (nums[left] > target)
    {
        return left;
    }
    return mid;
}


//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
//已知此链表是一个整数数字的二进制表示
//形式。请你返回该链表所表示数字的十进制值
int getDecimalValue(struct ListNode* head)
{
    int a = 0b0000000000000000;
    while (head->next)
    {
        a |= head->val;
        head = head->next;
        a = a << 1;
    }
    a |= head->val;
    head = head->next;
    return a;
}

//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前
//，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cstddef>
#include <cstdlib>
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* head1, * tail1, * head2, * tail2;
        head1 = tail1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        head2 = tail2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                tail1->next = cur;
                tail1 = tail1->next;
            }
            else
            {
                tail2->next = cur;
                tail2 = tail2->next;
            }
            cur = cur->next;
        }
        tail1->next = head2->next;
        tail2->next = NULL;
        pHead = head1->next;
        free(head1);
        free(head2);
        return pHead;
    }
};
