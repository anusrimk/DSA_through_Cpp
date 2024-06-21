#include <iostream>
#include <algorithm>

using namespace std;

int lengthof(int arr[])
{
    int n = 0;

    while (arr[n] != -1)
    {
        n += 1;
    }
    return n;
}

int *sortwhileinsert(int arr1[], int arr2[])
{

    int *arr3 = new int[lengthof(arr1) + lengthof(arr2) + 5];
    fill_n(arr3, lengthof(arr1) + lengthof(arr2) + 5, -1);
    int first = 0, second = 0;
    for (int i = 0; i < (lengthof(arr1) + lengthof(arr2) + 5); i++)
    {
        if (arr1[first] == -1 && arr2[second] == -1)
        {
            break;
        }
        else if (arr1[first] == -1)
        {
            arr3[i] = arr2[second];
            second += 1;
        }
        else if (arr2[second] == -1)
        {
            arr3[i] = arr1[first];
            first += 1;
        }
        else
        {
            if (arr1[first] < arr2[second])
            {
                arr3[i] = arr1[first];
                first += 1;
            }
            else
            {
                arr3[i] = arr2[second];
                second += 1;
            }
        }
    }
    return arr3;
}

int main()
{
    int girls[100] = {};
    fill_n(girls, 100, -1);
    int boys[100] = {};
    fill_n(boys, 100, -1);
    int i = 0;

    cout << "Enter for boys \n";
    while (true)
    {
        cout << "Enter the marks " << i + 1 << "  (-1 to stop) :";
        cin >> boys[i];
        if (boys[i] == -1)
        {
            break;
        }
        i += 1;
    }

    i = 0;
    cout << "Enter for girls\n";
    while (true)
    {
        cout << "Enter the marks " << i + 1 << "  (-1 to stop) :";
        cin >> girls[i];
        if (girls[i] == -1)
        {
            break;
        }
        i += 1;
    }

    for (int i = 0; i < lengthof(girls); i++)
    {
        for (int j = i + 1; j < lengthof(girls); j++)
        {
            if (girls[j] < girls[i])
            {
                int temp = girls[i];
                girls[i] = girls[j];
                girls[j] = temp;
            }
        }
    }
    for (int i = 0; i < lengthof(boys); i++)
    {
        for (int j = i + 1; j < lengthof(boys); j++)
        {
            if (boys[j] < boys[i])
            {
                int temp = boys[i];
                boys[i] = boys[j];
                boys[j] = temp;
            }
        }
    }

    int *arr;
    arr = sortwhileinsert(girls, boys);

    i = 0;
    while (arr[i] != -1)
    {
        cout << arr[i] << " ";
        i += 1;
    }
    delete[] arr;
    return 0;
}
