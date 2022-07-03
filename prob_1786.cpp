#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string n)
{
    int size = n.size(), j = 0;
    vector<int> pi(size, 0);
    for (int i = 1; i < size; i++)
    {
        while (j > 0 && n[i] != n[j])
        {
            j = pi[j - 1];
        }
        if (n[j] == n[i])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

void kmp(string n, string m)
{
    vector<int> pi = getPi(m);
    vector<int> idx;
    int cnt = 0, j = 0;
    for (int i = 0; i < n.size(); i++)
    {
        while (j > 0 && n[i] != m[j])
        {
            j = pi[j - 1];
        }

        if (n[i] == m[j])
        {
            if (j == m.size() - 1)
            {
                idx.push_back(i-m.size()+2);
                cnt++;
                j=pi[j];
            }
            else
                j++;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < idx.size(); i++)
    {
        cout << idx[i] << " ";
    }
}

int main()
{
    string n, m;
    getline(cin, n);
    getline(cin, m);

    kmp(n, m);

    return 0;
}
