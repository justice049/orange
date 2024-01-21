//给你一个非严格递增排列 的数组 nums ，
//请你 原地 删除重复出现的元素，使每个元素 只出现一次，
//返回删除后数组的新长度。
//元素的 相对顺序 应该保持 一致然后返回 nums 中唯一元素的个数。
//去重算法
int removeDuplicates(int* nums, int numsSize)
{
    int src = 0;
    int dst = 0;
    int count = numsSize;
    while (dst != numsSize)
    {
        if (nums[dst] != nums[src])
        {
            src++;
            nums[src] = nums[dst];
            dst++;
        }
        else
        {
            dst++;
            count--;
        }
    }
    count++;
    return count;
}
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
//另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，
//其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

//思路一创建新数组依次将两数组较小元素放入
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int arr[200] = { 0 };
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            arr[k] = nums1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = nums2[j];
            j++;
            k++;
        }
    }
    while (i != m)
    {
        arr[k] = nums1[i];
        i++;
        k++;
    }
    while (j != n)
    {
        arr[k] = nums2[j];
        j++;
        k++;
    }

    for (int a = 0; a < m + n; a++)
    {
        nums1[a] = arr[a];
    }
}

//思路二从后向前覆盖数组一
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{ 
    int end1 = m - 1;
    int end2 = n - 1;
    int index = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] > nums2[end2])
        {
            nums1[index--] = nums1[end1--];
        }
        else
        {
            nums1[index--] = nums2[end2--];
        }
    }
    while (end2 >= 0)   //将剩余搬移
    {
        nums1[index--] = nums2[end2--];
    }
}

//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
struct ListNode* middleNode(struct ListNode* head)
{
    int count = 1;
    struct ListNode* mid = head;
    struct ListNode* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        count++;
        if (count % 2 == 0)
        {
            mid = mid->next;
        }
    }
    return mid;
}

//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            struct ListNode* next = cur->next;
            free(cur);
            if (pre)
            {
                pre->next = next;
                cur = next;
            }
            else
            {
                head = next;
                cur = next;
            }
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}


//法二：尾插不等于pos的数据
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* newhead = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            if (tail == NULL)
            {
                newhead = tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
        }
        else
        {
            struct ListNode* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    if (tail)
    {
        tail->next = NULL;
    }
    return newhead;
}
//输入一个链表，输出该链表中倒数第k个结点。
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

//反转链表
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

//将两个升序链表合并为一个新的 升序 链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的
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