// 백준 1377 / 버블정렬1

// 버블 정렬을 쓰지 않고 버블 정렬 몇 번 수행되는지 구하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 입출력 속도 향상 시키는 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i; // second 에는 인덱스 번호 저장
    }

    // 일단 sort()로 정렬
    sort(A.begin(), A.end());

    int max = 0;

    for (int i = 0; i < N; i++)
    {

        // 정렬 전 인덱스 - 정렬 후 인덱스 의 최댓값 구하기
        //  인덱스 변화가 가장 큰 항이 가장 많이 swap 된 것, 즉 내부 for 문의 실행 횟수
        if (max < A[i].second - i)
        {
            max = A[i].second - i;
        }
    }

    cout << max + 1;
}