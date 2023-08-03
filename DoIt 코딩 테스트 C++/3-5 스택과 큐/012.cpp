// 백준 17298번 / 오큰수 구하기
// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> ans(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // 스택에는 인덱스 번호를 저장
    stack<int> stack;
    stack.push(0);

    for (int i = 1; i < N; i++)
    {

        // pop 해가면서 오큰수 업데이트
        while (!stack.empty() && A[stack.top()] < A[i])
        {
            ans[stack.top()] = A[i];
            stack.pop();
        }
        // 현재 인덱스 스택에 저장
        stack.push(i);
    }

    // 반복문 종료 후 스택에 남아있는 인덱스?
    // 오큰수가 없는 경우
    while (!stack.empty())
    {

        ans[stack.top()] = -1;
        stack.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}