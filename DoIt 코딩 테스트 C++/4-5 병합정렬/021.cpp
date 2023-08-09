// 백준 1517 / 버블 정렬 프로그램 2

// 버블정렬 swap 회수 계산 프로그램
// swap 회수 == 원소가 이동한 거리

#include <iostream>
#include <vector>
using namespace std;

// 함수선언
void mergeSort(int s, int e);

static vector<int> A;
static vector<int> tmp;
static long result;

void mergeSort(int s, int e)
{
    if (e - s < 1)
        return;

    int m = s + (e - s) / 2;

    mergeSort(s, m);
    mergeSort(m + 1, e);

    for (int i = s; i <= e; i++)
    {
        tmp[i] = A[i];
    }

    int k = s;
    int p = s;
    int q = m + 1;

    while (p <= m && q <= e)
    {
        // 뒷쪽 원소가 앞으로 올 땐
        if (tmp[p] > tmp[q])
        {
            A[k] = tmp[q];

            // 원소 이동 거리 추가
            result += (q++ - k++);
        }
        // 앞 원소는 뒤로 간다.
        // 앞원소는 카운트하지 않는다. 위 swap에 이미 카운트 되었으므로
        else
        {
            A[k++] = tmp[p++];
        }
    }

    // 남은거 넣어주기, no swap

    while (p <= m)
    {
        A[k++] = tmp[p++];
    }
    while (q <= e)
    {
        A[k++] = tmp[q++];
    }
}

int main()
{
    int N;
    cin >> N;

    A = vector<int>(N + 1, 0);
    tmp = A;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    result = 0;

    mergeSort(1, N);
    cout << result << '\n';
}