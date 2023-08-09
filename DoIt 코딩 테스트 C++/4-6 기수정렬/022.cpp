// 백준 10989 / 수 정렬하기 3

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int countArr[10001] = {0};
    int num = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        countArr[num]++;
    }

    for (int i = 0; i <= 10000; i++)
    {
        if (countArr[i] != 0)
        {
            for (int j = 0; j < countArr[i]; j++)
                cout << i << '\n';
        }
    }
}