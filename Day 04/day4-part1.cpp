#include "../AOCHeaders/stdafx.h"

vector<int> getNumbers(fstream & in)
{
  string line;
  getline(in, line);

  stringstream ss(line);
  vector<int>  numbers;
  int          number = 0;
  char         _;

  while (ss >> number)
  {
    numbers.push_back(number);
    ss >> _;
  }

  return numbers;
}

vector<vector<vector<pair<int, bool>>>> getBoards(fstream & in)
{
  vector<vector<vector<pair<int, bool>>>> boards;

  string line;
  int    number = 0;

  getline(in, line);
  while (getline(in, line))
  {
    vector<vector<pair<int, bool>>> board;

    do
    {
      vector<pair<int, bool>> currLine;
      stringstream            ss(line);

      while (ss >> number)
        currLine.push_back({ number, false });
      board.push_back(currLine);
    } while (getline(in, line) && line != "");
    boards.push_back(board);
  }

  return boards;
}

vector<vector<pair<int, bool>>> transposeMatrix(const vector<vector<pair<int, bool>>> & aMatrix)
{
  vector<vector<pair<int, bool>>> matrixTranpose(
    aMatrix[0].size(), vector<pair<int, bool>>(aMatrix.size(), { 0, false }));

  for (int i = 0; i < aMatrix.size(); i++)
    for (int j = 0; j < aMatrix[i].size(); j++)
      matrixTranpose[j][i] = aMatrix[i][j];

  return matrixTranpose;
}

bool checkLines(const vector<vector<pair<int, bool>>> & board)
{
  for (const auto & line : board)
    if (all_of(begin(line), end(line),
               [](const auto & number)
               {
                 return number.second == true;
               }))
      return true;
  return false;
}

bool checkIfBoardWins(const vector<vector<pair<int, bool>>> & board)
{
  return checkLines(board) || checkLines(transposeMatrix(board));
}

int getUnmarkedNumbersSum(const vector<vector<pair<int, bool>>> & board)
{
  return accumulate(begin(board), end(board), 0,
                    [](auto acc, const auto & lines)
                    {
                      return acc + accumulate(begin(lines), end(lines), 0,
                                              [](auto acc2, const auto & number)
                                              {
                                                return acc2 + (number.second ? 0 : number.first);
                                              });
                    });
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<int>                             numbers = getNumbers(in);
  vector<vector<vector<pair<int, bool>>>> boards  = getBoards(in);

  bool foundWinnedBoard = false;

  for (const auto & number : numbers)
  {
    for (auto & board : boards)
    {
      for (auto & line : board)
      {
        auto numberFound = find_if(begin(line), end(line),
                                   [number](const auto & num)
                                   {
                                     return num.first == number;
                                   });

        if (numberFound != end(line))
          (*numberFound).second = true;
      }

      if (checkIfBoardWins(board))
      {
        out << number * getUnmarkedNumbersSum(board);
        foundWinnedBoard = true;
        break;
      }
    }
    if (foundWinnedBoard)
      break;
  }

  in.close();
  out.close();
}