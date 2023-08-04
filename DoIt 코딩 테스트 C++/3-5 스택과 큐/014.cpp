// 백준 11286 / 절댓값힙

// 우선순위 큐 정렬 기준 설정하는 문제

#include <iostream>
#include <queue>
using namespace std;

// 정렬기준 설정
struct compare
{
    bool operator()(int o1, int o2)
    {
        int firstAbs = abs(o1);
        int secondAbs = abs(o2);
        // 절댓값 같을때
        if (firstAbs == secondAbs)
        {
            return o1 > o2;
        }
        else
        {
            return firstAbs > secondAbs;
        }
    }
};

int main()
{
    // 우선순위 큐 선언, 비교함수 적용
    priority_queue<int, vector<int>, compare> queue;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int request;
        cin >> request;

        if (request == 0)
        {
            if (queue.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << queue.top() << '\n';
                queue.pop();
            }
        }
        else
        {
            queue.push(request);
            // 넣으면 알아서 힙정렬함 절댓값 기준으로
        }
    }
}