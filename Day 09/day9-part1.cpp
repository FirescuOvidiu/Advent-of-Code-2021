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

	vector<int> x;
	vector<int> y;

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

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			bool good = true;
			for (int k = 0; k < 4; k++)
			{
				if (checkInMap(i + dx[k], j + dy[k], m.size(), m[i].size()))
				{
					if (m[i + dx[k]][j + dy[k]] <= m[i][j])
					{
						good = false;
					}
				}
			}
			if (good)
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	
	vector<int> sums;

	for (int i = 0; i < x.size(); i++)
	{
		vector<vector<bool>> visit(m.size(),vector<bool>(m[0].size(),false));
		queue<int> x1;
		queue<int> y1;
		int currSum = 1;

		x1.push(x[i]);
		y1.push(y[i]);
		visit[x[i]][y[i]]= true;

		while (!x1.empty())
		{
			int currX = x1.front(),currY=y1.front();
			x1.pop(); y1.pop();

			for (int k = 0; k < 4; k++)
			{
				if (checkInMap(currX + dx[k], currY + dy[k], m.size(), m[0].size()))
				{
					if (m[currX + dx[k]][currY + dy[k]] != 9 && visit[currX + dx[k]][currY + dy[k]] == false)
					{
						x1.push(currX + dx[k]);
						y1.push(currY + dy[k]);
						visit[currX + dx[k]][currY + dy[k]] = true;
						currSum++;
					}
				}
			}
		}
		sums.push_back(currSum);
	}

	sort(sums.begin(), sums.end());
	out << sums[sums.size()-1]* sums[sums.size() - 2]* sums[sums.size() - 3];

    in.close();
    out.close();
}