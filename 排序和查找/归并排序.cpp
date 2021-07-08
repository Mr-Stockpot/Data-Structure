#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//合并函数
void Merge(int a[], int low, int mid, int high)
{
    int i, k;
    int* tmp = (int*)malloc((high - low + 1) * sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for (k = 0; left_low <= left_high && right_low <= right_high; k++) {  // 比较两个指针所指向的元素
        if (a[left_low] <= a[right_low]) {
            tmp[k] = a[left_low++];
        }
        else {
            tmp[k] = a[right_low++];
        }
    }
    if (left_low <= left_high) {  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
        for (i = left_low;i <= left_high;i++)
            tmp[k++] = a[i];
    }
    if (right_low <= right_high) {
        //若第二个序列有剩余，直接复制出来粘到合并序列尾
        //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for (i = right_low; i <= right_high; i++)
            tmp[k++] = a[i];
    }
    for (i = 0; i < high - low + 1; i++)
        a[low + i] = tmp[i];
    free(tmp);
    return;
}

//归并排序函数
void MergeSort(int a[], unsigned int first, unsigned int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first + last) / 2; /* 注意防止溢出 */
		/*mid = first/2 + last/2;*/
		//mid = (first & last) + ((first ^ last) >> 1);
		MergeSort(a, first, mid);
		MergeSort(a, mid + 1, last);
		Merge(a, first, mid, last);
	}
}

int main()
{
	int a[8] = { 3,1,7,5,2,4,9,6 };

    for (int j = 0; j < 8; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");

	MergeSort(a, 0, 7);

    for (int j = 0; j < 8; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
	return 0;
}