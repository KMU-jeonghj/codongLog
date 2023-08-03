// 백준 1874 번 / 스택으로 수열 만들기
// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <vector>
#include <stack> // cpp 스택 헤더 사용
using namespace std;

int main()
{
    int N;
    cin >> N;

    // 수열 저장 vector
    vector<int> A(N, 0);
    // 출력 vector
    vector<char> resultV;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> stack;
    int num = 1;
    // 출력 여부 플래그 변수
    bool out = true;

    for (int i = 0; i < A.size(); i++)
    {
        int e = A[i]; // 현재 수열 원소

        if (e >= num)
        {
            while (e >= num)
            {
                stack.push(num++);      // 후위연산
                resultV.push_back('+'); // push
            }

            // 스택 맨 위에 e 가 push됨
            stack.pop();
            resultV.push_back('-');
        }

        // e < num , 이미 스택 안에 e가 있는 상태
        else
        {
            int top = stack.top();

            // top이 현재 수열 원소보다 커져버리면 아래 값을 뺄 수 없다, 후입선출 원리
            if (top > e)
            {
                cout << "NO";
                out = false;
                break;
            }

            // top == e
            else
            {
                stack.pop();
                resultV.push_back('-');
            }
        }
    }

    // 출력
    if (out)
    {
        for (int i = 0; i < resultV.size(); i++)
        {
            cout << resultV[i] << '\n';
        }
    }
}