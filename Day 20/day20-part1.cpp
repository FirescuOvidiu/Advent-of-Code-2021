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


bool checkInMap(int x, int y, int lines, int columns)
{
    return x >= 0 && y >= 0 && x < lines&& y < columns;
}


int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::in);

    vector<vector<char>> m(500, vector<char>(500, '.'));
    vector<char> v;
    string line, img;
    char c;

    getline(in, img);
    getline(in, line);

    int i = 100;
    int j = 100;
    while (getline(in, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            v.push_back(line[i]);
        }
        for (int i1 = i; i1 < v.size() + i; i1++)
        {
            m[j][i1] = v[i1 - 100];
        }
        j++;
        v.clear();
    }
 
    for (int k = 0; k < 2; k++)
    {
        vector<vector<char>> m1(500, vector<char>(500, '.'));

        for (int i = 0; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                string number;
                char value;
                long long newValue;

                for (int l = i - 1; l <= i + 1; l++)
                {
                    for (int l1 = j - 1; l1 <= j + 1; l1++)
                    {
                        if (checkInMap(l, l1, 500, 500))
                        {
                            if (m[l][l1] == '.')
                                value = '0';
                            else
                                value = '1';
                        }
                        else
                        {
                            if (k % 2 == 0)
                                value = '0';
                            else
                                value = '1';
                        }
                        number += value;
                    }

                }

                newValue = stoll(number, NULL, 2);
                m1[i][j] = img[newValue];
            }
        }

        m = m1;
    }
    
    int count = 0;

    for (int i = 2; i < m.size(); i++)
    {
        for (int j = 2; j < m[0].size(); j++)
        {
            if (m[i][j] == '#')
                count++;
        }
    }

    cout << "\n" << count;

    in.close();
    out.close();
}