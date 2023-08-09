// 백준 2751 / 수 정렬하기 2

// 병합 정렬 사용

#include <iostream>
#include <vector>
using namespace std;

// 합수 선언
void mergeSort(int s, int e);

static vector<int> A;
static vector<int> tmp;

void mergeSort(int s, int e)
{
    // 탈출
    if (e - s < 1)
        return;

    // e 부분을 미리 나눠줌으로써 큰 값일 시 발생할 수 있는 overflow를 방지한다.
    int m = s + (e - s) / 2;

    // 분할 정복
    mergeSort(s, m);
    mergeSort(m + 1, e);

    // 임시 배열에 덮어쓰기
    for (int i = s; i <= e; i++)
    {
        tmp[i] = A[i];
    }

    // 포인터 변수 선언
    int k = s;
    int p = s;
    int q = m + 1;

    // tmp 에서 비교하고 A에 병합
    while (p <= m && q <= e)
    {
        if (tmp[p] > tmp[q])
        {
            A[k++] = tmp[q++];
        }
        else
        {
            A[k++] = tmp[p++];
        }
    }

    // 남은거 싹 다 때려 넣기
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

    mergeSort(1, N);

    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << '\n';
    }
}