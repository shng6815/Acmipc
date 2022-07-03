#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    string temp;
    set<string> s1, s2;
    set<string>::iterator iter;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s1.insert(temp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        iter = s1.find(temp);

        if (iter != s1.end())
            s2.insert(temp);
    }
    cout << s2.size() << endl;
    for (iter = s2.begin(); iter != s2.end(); iter++)
        cout << *iter << endl;

    return 0;
}