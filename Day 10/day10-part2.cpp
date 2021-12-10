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

    long long currPoints = 0;
    vector<long long> points;
    string line;

    while (getline(in, line))
    {
        stack<char> chunks;
        bool correctChunk = true;

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
                    correctChunk = false;
                    break;
                }
            }
        }

        if (correctChunk) 
        {
            vector<char> remainingChunks;
            while (!chunks.empty())
            {
                remainingChunks.push_back(chunks.top());
                chunks.pop();
            }

            currPoints = 0;
            for (int i = 0; i < remainingChunks.size(); i++)
            {
                if (remainingChunks[i] == '(')
                {
                    currPoints = currPoints * 5 + 1;
                }
                if (remainingChunks[i] == '[')
                {
                    currPoints = currPoints * 5 + 2;
                }
                if (remainingChunks[i] == '{')
                {
                    currPoints = currPoints * 5 + 3;
                }
                if (remainingChunks[i] == '<')
                {
                    currPoints = currPoints * 5 + 4;
                }
            }

            points.push_back(currPoints);
        }
    }
    
    sort(points.begin(), points.end());
    out << points[points.size() / 2];

    in.close();
    out.close();
}