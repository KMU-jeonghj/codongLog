// 백준 11004/ K번째 수

// 퀵정렬로 정렬해보기

#include <iostream>
#include <vector>
using namespace std;

// 함수 선언
void quickSort(vector<int> &A, int s, int e, int K);
int partition(vector<int> &A, int s, int e);
void swap(vector<int> &A, int i, int j);

void quickSort(vector<int> &A, int s, int e, int K)
{
    int pivot = partition(A, s, e);
    // pivot 자체는 정렬 되었으므로, pivot == K 면 종료해도 된다
    if (pivot == K)
    {
        return;
    }

    // 분할 정복
    else if (K < pivot)
    {
        quickSort(A, s, pivot - 1, K);
    }

    else
    {
        quickSort(A, pivot + 1, e, K);
    }
}

int partition(vector<int> &A, int s, int e)
{
    if (s + 1 == e)
    {
        if (A[s] > A[e])
            swap(A, s, e);
        return e;
    }
    // 중간값
    int m = (s + e) / 2;

    swap(A, s, m);
    // 여기선 피벗을 맨 앞으로 뺀 다음 포인터 이동
    int pivot = A[s];
    int i = s + 1;
    int j = e;

    while (i <= j)
    {
        while (pivot < A[j] && j > 0)
        {
            j--;
        }
        while (pivot > A[i] && i < A.size() - 1)
        {
            i++;
        }

        // i, j 교환
        if (i <= j)
            swap(A, i++, j--);
    }

    // 피벗 제자리 이동
    A[s] = A[j];
    A[j] = pivot;
    // 피벗 인덱스 반환
    return j;
}

void swap(vector<int> &A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    quickSort(A, 0, N - 1, K - 1);

    cout << A[K - 1] << '\n';
}