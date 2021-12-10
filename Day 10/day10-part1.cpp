#include "../AOCHeaders/stdafx.h"

int countPoints(char lastOpenedChunk, char currentClosedChunk)
{
    if (currentClosedChunk == ')')
        return  lastOpenedChunk == '(' ? 0 : 3;

    if (currentClosedChunk == ']')
        return  lastOpenedChunk == '[' ? 0 : 57;

    if (currentClosedChunk == '}')
        return  lastOpenedChunk == '{' ? 0 : 1197;

    if (currentClosedChunk == '>')
        return  lastOpenedChunk == '<' ? 0 : 25137;
}

int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::out);

    int points = 0, currPoints = 0;
    string line;

    while (getline(in, line))
    {
        stack<char> chunks;

        for (int i = 0; i < line.size(); i++)
        {
            if ((line[i] == '(') || (line[i] == '{') || (line[i] == '<') || (line[i] == '['))
            {
                chunks.push(line[i]);
            }
            else
            {
                currPoints = countPoints(chunks.top(),line[i]);
                if (currPoints == 0)
                    chunks.pop();
                else
                {
                    points += currPoints;
                    break;
                }
            }
        }
    }

    out << points;

    in.close();
    out.close();
}