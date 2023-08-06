// 백준 1427 / 내림차순 정렬
// 선택 정렬로 정렬해보기

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 자릿수로 나누기 위해 문자열 입력
    string str;
    cin >> str;
    vector<int> A(str.size(), 0);

    // 자릿수 마다 정수로 변환하여 벡터에 저장
    for (int i = 0; i < str.size(); i++)
    {
        A[i] = stoi(str.substr(i, 1));
    }

    // 선택정렬
    for (int i = 0; i < str.length(); i++)
    {
        // 최댓값 선택
        int max = i;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (A[j] > A[max])
                max = j;
        }

        // swap, 내림차순 정렬
        if (A[i] < A[max])
        {
            int temp = A[i];
            A[i] = A[max];
            A[max] = temp;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
    }
}