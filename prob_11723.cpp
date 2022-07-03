#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> s;
    int M, n;
    string t;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> t;
        if (t == "add")
        {
            cin >> n;
            if (1 != count(s.begin(), s.end(), n))
            {
                s.push_back(n);
                sort(s.begin(), s.end());
            }
        }
        else if (t == "remove")
        {
            cin >> n;
            int left, right, mid;
            left = 0;
            right = s.size() - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (s[mid] == n)
                {
                    s.erase(s.begin() + mid);
                    break;
                }
                else if (s[mid] >= n)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        else if (t == "check")
        {
            cin >> n;
            int left, right, mid;
            bool flag = false;
            left = 0;
            right = s.size() - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (s[mid] == n)
                {
                    flag = true;
                    break;
                }
                else if (s[mid] >= n)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            cout << (int)flag << endl;
        }
        else if (t == "toggle")
        {
            cin >> n;
            int left, right, mid;
            bool flag = false;
            left = 0;
            right = s.size() - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (s[mid] == n)
                {
                    flag = true;
                    break;
                }
                else if (s[mid] >= n)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (flag)
                s.erase(s.begin() + mid);
            else
            {
                s.push_back(n);
                sort(s.begin(), s.end());
            }
        }
        else if (t == "all")
        {
            s.clear();
            for (int j = 0; j < 20; j++)
                s.push_back(j + 1);
        }
        else if (t == "empty")
        {
            s.clear();
        }
    }

    return 0;
}