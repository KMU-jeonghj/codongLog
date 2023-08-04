// 백준 2164번 / 카드게임

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queue;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        queue.push(i);
    }

    while (queue.size() > 1)
    {
        queue.pop();
        queue.push(queue.front());
        queue.pop();
    }

    cout << queue.front();
}