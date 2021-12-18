#include "../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string command;
  int    units{ 0 };
  int    depth{ 0 }, horizontal{ 0 }, aim{ 0 };

  while (in >> command >> units)
    if (command == "forward")
    {
      horizontal += units;
      depth += aim * units;
    }
    else if (command == "down")
      aim += units;
    else if (command == "up")
      aim -= units;

  out << horizontal * depth;

  in.close();
  out.close();
}
