#include "DataItem.h"
#include "DataSet.h"
#include "BruteForce.h"
#include "FA.h"
#include "BPA.h"
#include "BPA2.h"
#include <iostream>
#include <ctime>
#include "TA.h"

using namespace std;

int main()
{
  DataSet myDataSet(100000, 8);

  BruteForce myBF(myDataSet, 20);
  int start = clock();
  myBF.bruteForceSolution2();
  int stop = clock();
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF.printTopK();
  cout << endl << endl;

  FA myFA(myDataSet, 20);
  start = clock();
  myFA.FASolution();
  stop = clock();
  cout << "time for FA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA.printTopK();
  cout << endl << endl;

  TA myTA(myDataSet, 20);
  start = clock();
  myTA.TASolution();
  stop = clock();
  cout << "time for TA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myTA.printTopK();
  cout << endl << endl;

  BPA myBPA(myDataSet, 20);
  start = clock();
  myBPA.BPASolution();
  stop = clock();
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA.printTopK();
  cout << endl << endl;
  
  BPA2 myBPA2(myDataSet, 20);
  start = clock();
  myBPA2.BPA2Solution();
  stop = clock();
  cout << "time for BPA2 algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA2.printTopK();
  cout << endl << endl;


  DataSet myDataSet2(500000, 8,10);

  BruteForce myBF2(myDataSet2, 20);
  start = clock();
  myBF2.bruteForceSolution2();
  stop = clock();
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF2.printTopK();
  cout << endl << endl;

  FA myFA2(myDataSet2, 20);
  start = clock();
  myFA2.FASolution();
  stop = clock();
  cout << "time for FA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA2.printTopK();
  cout << endl << endl;

  TA myTA2(myDataSet2, 20);
  start = clock();
  myTA2.TASolution();
  stop = clock();
  cout << "time for TA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myTA2.printTopK();
  cout << endl << endl;


  BPA myBPA_2(myDataSet2, 20);
  start = clock();
  myBPA_2.BPASolution();
  stop = clock();
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA_2.printTopK();
  cout << endl << endl;
  
  BPA2 myBPA2_2(myDataSet2, 20);
  start = clock();
  myBPA2_2.BPA2Solution();
  stop = clock();
  cout << "time for BPA2 algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA2_2.printTopK();
  cout << endl << endl;
  
  return 0;
}
