//ĳ����������� a1, a2, a3, ... �Ķ������£� ����(n > 2)����������
//һ��������k��������еĵ�k��ģ��32767�Ľ���Ƕ��٣�
//����������
//��1���ǲ������ݵ����� n ��������� n �����롣
//ÿ���������ռ1�У�����һ�������� k(1 �� k < 1000000) ��
//	��������� n �У�ÿ�������Ӧһ�����롣���Ӧ��һ���Ǹ�����
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

//����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�������������������롣
//���ݷ�Χ��������ַ����������� 1 <= n <= 1000
//��������������һ���ַ����������пո�
//���������ͳ������Ӣ���ַ����ո��ַ��������ַ��������ַ��ĸ���
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

//һά����Ķ�̬��
//����һ������ nums �����顸��̬�͡��ļ��㹫ʽΪ��
//runningSum[i] = sum(nums[0]��nums[i]) ���뷵�� nums �Ķ�̬�͡�
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

//��������λ��
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У�����������
//����˳������λ�á������ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨
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


//����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1��
//��֪��������һ���������ֵĶ����Ʊ�ʾ
//��ʽ�����㷵�ظ���������ʾ���ֵ�ʮ����ֵ
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

//����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ
//���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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
