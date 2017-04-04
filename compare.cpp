#include "DataItem.h"
#include "DataSet.h"
#include "BruteForce.h"
#include "FA.h"
#include "BPA.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  DataSet myDataSet(50000, 5);

  BruteForce myBF(myDataSet, 5);
  int start = clock();
  myBF.bruteForceSolution();
  int stop = clock();
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF.printTopK();
  cout << endl << endl;

  FA myFA(myDataSet, 5);
  start = clock();
  myFA.FASolution();
  stop = clock();
  cout << "time for FA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA.printTopK();
  cout << endl << endl;

  BPA myBPA(myDataSet, 5);
  start = clock();
  myBPA.BPASolution();
  stop = clock();
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA.printTopK();
  cout << endl << endl;
  
  return 0;
}
