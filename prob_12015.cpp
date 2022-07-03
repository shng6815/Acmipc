#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int solve(int t)
{
    int left = 0, right = v.size()-1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] < t)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    int temp;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (v.size() == 0)
            v.push_back(temp);
        else if (v.back() < temp)
            v.push_back(temp);
        else
        {
            v[solve(temp)] = temp;
        }
    }
    cout<<v.size();
    return 0;
}