//����һ�����ϸ�������� ������ nums ��
//���� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�Σ�
//����ɾ����������³��ȡ�
//Ԫ�ص� ���˳�� Ӧ�ñ��� һ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����
//ȥ���㷨
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
//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2��
//������������ m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
//
//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�
//Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n��
//����ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

//˼·һ�������������ν��������СԪ�ط���
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

//˼·���Ӻ���ǰ��������һ
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
    while (end2 >= 0)   //��ʣ�����
    {
        nums1[index--] = nums2[end2--];
    }
}

//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
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

//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
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


//������β�岻����pos������
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
//����һ����������������е�����k����㡣
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

//��ת����
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

//��������������ϲ�Ϊһ���µ� ���� �������ء�
// ��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
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