#include "../AOCHeaders/stdafx.h"

bool checkInMap(int x, int y, int lines, int columns)
{
	return x >= 0 && y >= 0 && x < lines&& y < columns;
}

int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::out);

	vector<int> dx{ 0,1,0,-1 };
	vector<int> dy{ -1,0,1,0 };

    vector<vector<int>> m;
    string line;
  
	while (getline(in, line))
	{
		vector<int> v;
		for (int i = 0; i < line.length(); i++)
		{
			v.push_back(line[i]-'0');
		}
		m.push_back(v);
	}

	long long sum = 0;

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			bool isLowPoint = true;
			for (int k = 0; k < 4; k++)
			{
				if (checkInMap(i + dx[k], j + dy[k], m.size(), m[i].size()))
				{
					if (m[i + dx[k]][j + dy[k]] <= m[i][j])
					{
						isLowPoint = false;
					}
				}
			}
			if (isLowPoint)
			{
				sum += m[i][j] + 1;
			}
		}
	}
	
	out << sum;

    in.close();
    out.close();
}