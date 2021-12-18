#include "../AOCHeaders/stdafx.h"

vector<string> transposeMatrix(const vector<string> & aMatrix)
{
  vector<string> matrixTranpose(aMatrix[0].size(), string(aMatrix.size(), '0'));

  for (int i = 0; i < aMatrix.size(); i++)
    for (int j = 0; j < aMatrix[i].size(); j++)
      matrixTranpose[j][i] = aMatrix[i][j];

  return matrixTranpose;
}

string findRate(const vector<string> & aDiagReport,
                const vector<string> & aDiagReportTraponse,
                const string &         aBitCriteria)
{
  string rate;
  int    countZeros = 0, countOnes = 0, it = 0;

  for (; it < aDiagReportTraponse.size(); it++)
  {
    countZeros = 0, countOnes = 0;

    for (int j = 0; j < aDiagReportTraponse[it].size(); j++)
      if (aDiagReport[j].substr(0, it) == rate)
        aDiagReportTraponse[it][j] == '0' ? countZeros++ : countOnes++;

    if (countZeros + countOnes != 1)
    {
      if (aBitCriteria == "most common")
        rate += countZeros <= countOnes ? '1' : '0';
      else if (aBitCriteria == "least common")
        rate += countZeros <= countOnes ? '0' : '1';
      continue;
    }

    return *find_if(begin(aDiagReport), end(aDiagReport),
                    [&rate, it](const auto & el)
                    {
                      return el.substr(0, it) == rate;
                    });
  }

  return rate;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<string> diagReport(istream_iterator<string>(in), {});
  vector<string> diagReportTraponse = transposeMatrix(diagReport);
  string         gammaRate          = findRate(diagReport, diagReportTraponse, "most common");
  string         epsilonRate        = findRate(diagReport, diagReportTraponse, "least common");

  out << bitset<64>(gammaRate).to_ullong() * bitset<64>(epsilonRate).to_ullong();

  in.close();
  out.close();
}
