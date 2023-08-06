// 백준 11399 / ATM 인출 시간 계산하기

// 정렬 후 합배열 구하기

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> S(N, 0); // 합배열 벡터

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // 삽입정렬
    for (int i = 1; i < N; i++)
    {
        int p = i;
        int v = A[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                p = j + 1;
                break;
            }
            if (j == 0)
                p = 0;
        }

        for (int j = i; j > p; j--)
            A[j] = A[j - 1];

        A[p] = v;
    }

    // 합 배열 만들기
    S[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + A[i];
    }

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += S[i];
    }

    cout << sum << '\n';
}