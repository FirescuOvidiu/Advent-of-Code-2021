#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stack> 
#include <bitset>
#include <numeric>
#include <functional>
#include <array>
#include <optional>
#include <cstdlib>

using namespace std;

#define aux 10000000

int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::out);

    vector<vector<int>> v;
    string line;
    int maxsum = 0;

    while (getline(in, line)) {
        vector<int> aux2;
        for (int i = 0; i < line.size(); i++)
            if (line[i] >= '0' && line[i] <= '9')
                aux2.push_back(line[i] - '0');
            else
                aux2.push_back(line[i]+aux);
        v.push_back(aux2);
    }

    for (int i = 0; i < v.size()  ; i++)
    {
        for (int j =0; j < v.size(); j++)
        {
			if(v[i]==v[j])
				continue;
            auto keepV = v[i];
            v[i].insert(begin(v[i]), '[' + aux);
            v[i].push_back(',' + aux);
            v[i].insert(v[i].end(), v[j].begin(), v[j].end());
            v[i].push_back(']' + aux);

            bool found = true;
            bool found2 = true;
            while (found || found2)
            {
                found = false;
                int count = 0;

                for (auto it = v[i].begin(); it < v[i].end(); it++)
                {
                    if (*it == ('[' + aux))
                    {
                        count++;
                        continue;
                    }
                    if (*it == (']' + aux))
                    {
                        count--;
                        continue;
                    }
                    if (*it == (',' + aux))
                    {
                        continue;
                    }
                    if (count > 4)
                    {
                        if (*(it + 2) < aux)
                        {
                            found = true;

                            auto left = it - 1;
                            while (left != v[i].begin() && *left > aux)
                                left--;
                            if (left != v[i].begin())
                                *left += (*(it));

                            auto right = it + 4;
                            while (right != v[i].end() && *right > aux)
                                right++;
                            if (right != v[i].end())
                                *right += (*(it + 2));


                            it = v[i].erase(it - 1, it + 3);
                            *it = 0;
                            break;
                        }
                    }
                }

                if (found)
                    continue;

                found2 = false;
                for (auto it = v[i].begin(); it < v[i].end(); it++)
                {
                    if (*it < aux && *it >9)
                    {
                        found2 = true;
                        int number = *it;
                        it = v[i].erase(it);
                        vector<int> in2;
                        in2.push_back('[' + aux);
                        in2.push_back(number / 2);
                        in2.push_back(',' + aux);
                        in2.push_back(ceil((double)number / 2));
                        in2.push_back(']' + aux);

                        v[i].insert(it, begin(in2), end(in2));
                        break;
                    }
                }
            }

            auto result = v[i];

            int sum = 0;
            while (result.size() > 4)
            {
                for (auto it = result.begin(); it < result.end(); it++)
                {
                    if (*it == ('[' + aux))
                    {

                        continue;
                    }
                    if (*it == (']' + aux))
                    {
                        continue;
                    }
                    if (*it == (',' + aux))
                    {
                        continue;
                    }
                    if (*(it + 2) < aux)
                    {
                        int number = *it, number2 = *(it + 2);
                        it = result.erase(it - 1, it + 3);
                        *it = number * 3 + number2 * 2;
                        break;
                    }
                }
            }

            if (maxsum < result[0])
                maxsum = result[0];

            v[i] = keepV;
        }
    }
    cout << maxsum;

    in.close();
    out.close();
}