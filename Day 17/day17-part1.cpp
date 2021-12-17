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

int main()
{
	fstream in("input.in", fstream::in);
	fstream out("output.out", fstream::out);

	vector<vector<char>> m(1000,vector<char>(1000,'.'));
	vector<char> v;
	int number = 0;
	string line;
	char c;

	int x1, x2, y1, y2;
	in >> x1 >> x2 >> y1 >> y2;

	int posX = 0, posY = 0;
	int velX = 1, velY = 1;
	int count = 0, max = 0;

	x1 =20;
	x2 = 30;
	y1 = -15;
	y2 = -5;

	for (int i = -1000; i < 1000; i++)
	{
		for (int j = -1000; j < 1000; j++)
		{
			int currMax = 0;
			int posX = 0, posY = 0;
			int velX = i, velY = j;

			while (true)
			{
				if (posX >= x1 && posX <= x2 && posY >= y1 && posY <= y2)
				{
					count++;
					if (currMax > max)
						max = currMax;
					break;
				}
				posX += velX;
				posY += velY;
				if (currMax < posY)
					currMax = posY;
				if (velX > 0)
					velX--;
				else
					if (velX < 0)
						velX++;
					velY--;
				if (velX == 0 && velY < -1000)
					break;
			}
		}
	}
	cout << count << " " << max;


	in.close();
	out.close();
}