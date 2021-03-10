#include <stdio.h>
void linear_search(int array[], int length, int searchItem)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (array[i] == searchItem)
        {
            printf("%d is present at index %d.\n", searchItem, i);
            break;
        }
    }
    if (i == length)
        printf("%d isn't present in the array.\n", searchItem);
}

void binary_search(int array[], int length, int searchItem)
{
    int low = 0, high = length - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {

        if (array[mid] < searchItem)
            low = mid + 1;

        else if (array[mid] == searchItem)
        {
            printf("%d is present at index %d\n", searchItem, mid);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (low > high)
        printf("%d isn't present in array\n", searchItem);
}

void bubble_sort(int array[], int length)
{
    int i, j, swap;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1]) /* For decreasing order use '<' instead of '>' */
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }

    printf("Bubble sort list in ascending order: ");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void insertion_sort(int array[], int length)
{
    int i, j, temp;
    for (i = 1; i < length; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((temp < array[j]) && (j >= 0))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }

    printf("Insertion sort list in ascending order: ");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void selection_sort(int array[], int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("Selection sort list in ascending order: ");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void quick_sort(int array[], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (array[i] <= array[pivot] && i < last)
                i++;
            while (array[j] > array[pivot])
                j--;
            if (i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quick_sort(array, first, j - 1);
        quick_sort(array, j + 1, last);
    }
}

void counting_sort(int a[], int n, int max)
{
    int count[50] = {0}, i, j;

    for (i = 0; i < n; ++i)
        count[a[i]] = count[a[i]] + 1;

    printf("Counting Sort sort list in ascending order: ");

    for (i = 0; i <= max; ++i)
        for (j = 1; j <= count[i]; ++j)
            printf("%d ", i);

    printf("\n");
}

void radix_sort(int a[], int n)
{
    int bucket[10][10], bucket_cnt[10];
    int i, j, k, r, NOP = 0, divisor = 1, lar, pass, max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    lar = max;
    while (lar > 0)
    {
        NOP++;
        lar /= 10;
    }
    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucket_cnt[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}

void maintain_search()
{
    int searching, length, item, i;
    printf("\n1. Linear Search.\n2. Binary Search(You have to Enter Sorting list).\n");

    printf("\nEnter your choice: ");
    scanf("%d", &searching);

    printf("How many elements you want to add: ");
    scanf("%d", &length);
    int array[length];
    printf("Enter %d elements: ", length);
    for (i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Which element you want to search: ");
    scanf("%d", &item);
    switch (searching)
    {
    case 1:
        linear_search(array, length, item);
        break;
    case 2:
        binary_search(array, length, item);
        break;
    default:
        printf("Your Choice Doesn't Exist.\n");
    }
}

void maintain_sorting(){
    int sorting, length, i, max = 0;
    printf("1. Bubble Sort.\n2. Insertion Sort.\n3. Selection Sort.\n4. Quick Sort.\n5. Counting Sort.\n6. Radix Sort.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &sorting);

    printf("How many elements you want to add: ");
    scanf("%d", &length);
    int array[length];
    printf("Enter %d elements: ", length);
    for (i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] > max)
            max = array[i];
        }

        switch (sorting)
        {
        case 1:
            bubble_sort(array, length);
            break;
        case 2:
            insertion_sort(array, length);
            break;
        case 3:
            selection_sort(array, length);
            break;
        case 4:
            quick_sort(array, 0, length - 1);
            printf("Quick sort list in ascending order: ");
            for (i = 0; i < length; i++)
                printf("%d ", array[i]);
            printf("\n");
            break;
        case 5:
            counting_sort(array, length, max);
            break;
        case 6:
            radix_sort(array, length);
            printf("Radix sort list in ascending order: ");
            for (i = 0; i < length; i++)
                printf("%d ", array[i]);
            printf("\n");
            break;
        default:
            printf("Your Choice Doesn't Exist.\n");
        }
}
int main()
{
    int choice, agree;
    printf("What you want to do?\n1. Searching\n2. Sorting\n");
    printf("\nEnter you choice: ");
    scanf("%d", &choice);
    if (choice == 1){
        maintain_search();
        printf("\nDo you want try again?\npress 1 for Yes or anykey for No: ");
        scanf("%d", &agree);
        if(agree == 1){
            printf("\n");
            main();
        }
        else
            printf("Thank you\n");
    }
    else if (choice == 2){
        maintain_sorting();
        printf("\nDo you want try again?\npress 1 for Yes or anykey for No: ");
        scanf("%d", &agree);
        if(agree == 1){
            printf("\n");
            main();
        }
        else
            printf("Thank you\n");
    }
    else
        printf("Your choice doesn't exist.");
    return 0;
}
