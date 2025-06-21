#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, sz, index, j = -1;
    stack<int> st;
    vector<pair<int, int>> v;

    while (cin >> n)
    {
        if (n == -1)
            break;
        v.emplace_back(n, j);
        j++;
    }
    sz = v.size() ;
    deque<int> v1(sz, -1);
    st.push(v[0].first);

    for (int i = 1; i < sz; i++)
    {
        if (v[i].first > st.top())
        {
            index = v[i].second;
            // cout << v[i].first << ' ' << index << ' ' << st.size() << endl;
            while (!st.empty() && v[i].first > st.top()) {
                if (v1[index] == -1) {
                    v1[index] = v[i].first;
                    st.pop();
                }
                index--;
            }
        }
        st.push(v[i].first);
    }


    for (auto i = v1.begin();i != v1.end();i++)
    {
        cout << *i << ' ';
    }


    return 0;
}