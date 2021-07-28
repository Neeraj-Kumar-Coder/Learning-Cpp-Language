#include <bits/stdc++.h>

#define MODNUM 2147483648ull

using namespace std;

int createSequence(unsigned long long int n, unsigned long long int s, unsigned long long int p, unsigned long long int q)
{
    int *arr, count = 0;
    arr = new int[n];
    arr[0] = (int)s;
    for (unsigned long long int i = 1; i < n; i++)
    {
        arr[i] = (int)(((arr[i - 1] * p) % MODNUM) + q) % MODNUM;
        cout << arr[i] << '\n';
    }

    int temp = -1;
    for (unsigned long long int i = 0; i < n; i++)
    {
        if (temp != arr[i])
            temp = arr[i], count++;
    }
    return count;
}

int main(void)
{
    FILE *ptr = freopen("Bit_Array_Output.txt", "w", stdout);
    unsigned long long int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    cout << createSequence(N, S, P, Q);
    fclose(ptr);
    return 0;
}