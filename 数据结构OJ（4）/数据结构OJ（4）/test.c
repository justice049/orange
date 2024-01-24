//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣
//��������޻����򷵻� null��
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε��
//�������д��ڻ��� Ϊ�˱�ʾ���������еĻ���
//����ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ��
//����� pos �� - 1�����ڸ�������û�л���
//ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//�������޸� ����
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
//����һ������Ϊ n �������������е�Ԫ�ص�ֵΪ ai ��
//���ظ������е�����k���ڵ㡣
//�����������С��k���뷵��һ������Ϊ 0 ������
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
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

//��������������ϲ�Ϊһ���µ� ���� �������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
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

//���������������ͷ�ڵ� headA �� headB 
//�����ҳ������������������ཻ����ʼ�ڵ㡣
//�����������û�н��㣬���� null ��
//��Ŀ���� ��֤ ������ʽ�ṹ�в����ڻ���
//ע�⣬�������ؽ����������� ������ԭʼ�ṹ
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


//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε��
//�������д��ڻ��� Ϊ�˱�ʾ���������еĻ���
//����ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
//��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
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