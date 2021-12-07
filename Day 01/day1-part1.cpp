#include "../AOCHeaders/stdafx.h"

int main()
{
	fstream in("input.in", fstream::in);
	fstream out("output.out", fstream::out);

	vector<int> v(istream_iterator<int>{ in }, {});
	int         measurements{ 0 };

	for (int it = 1; it < v.size(); it++)
		if (v[it - 1] < v[it])
			measurements++;

	out << measurements;
	
	in.close();
	out.close();
}