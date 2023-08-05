// 백준 2750 / 수 정렬하기 1

// 버블 정렬 구현

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // swap 플래그
    bool swap = false;

    for (int i = 0; i < N; i++)
    {
        swap = false;

        for (int j = 0; j < N - 1 - i; j++)
        {

            // swap
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swap = true;
            }
        }

        if (!swap)
        {
            cout << i << '\n';
            break;
        }
    }

    // print
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << '\n';
    }
}