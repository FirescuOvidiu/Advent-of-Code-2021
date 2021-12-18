#include "../AOCHeaders/stdafx.h"

vector<string> transposeMatrix(const vector<string> & aMatrix)
{
  vector<string> matrixTranpose(aMatrix[0].size(), string(aMatrix.size(), '0'));

  for (int i = 0; i < aMatrix.size(); i++)
    for (int j = 0; j < aMatrix[i].size(); j++)
      matrixTranpose[j][i] = aMatrix[i][j];

  return matrixTranpose;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<string> diagReport(istream_iterator<string>(in), {});
  string         gammaRate, epsilonRate;

  diagReport = transposeMatrix(diagReport);

  for (size_t it = 0; it < diagReport.size(); it++)
  {
    int countZeros = count(begin(diagReport[it]), end(diagReport[it]), '0');
    int countOnes  = diagReport[it].size() - countZeros;

    gammaRate += countZeros < countOnes ? '0' : '1';
    epsilonRate += countZeros < countOnes ? '1' : '0';
  }

  out << bitset<64>(gammaRate).to_ullong() * bitset<64>(epsilonRate).to_ullong();

  in.close();
  out.close();
}