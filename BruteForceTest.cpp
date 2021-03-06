#include "DataItem.h"
#include "DataSet.h"
#include "BruteForce.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  BruteForce myBF1;
  myBF1.bruteForceSolution();
  myBF1.printTopK();
  myBF1.setTopK(5);
  myBF1.bruteForceSolution();
  myBF1.printTopK();
  cout << endl << endl;

  DataSet myDataSet(1000000, 5);
  BruteForce myBF2(myDataSet, 5);
  int start = clock();
  myBF2.bruteForceSolution();
  int stop = clock();
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF2.printTopK();
  cout << endl << endl;

  /*
  myBF1.clear();
  myBF1 = myBF2;
  myBF1.printTopK();
  myBF1.bruteForceSolution();
  myBF1.printTopK();
  cout << endl << endl;
  */

  BruteForce myBF3(myDataSet, 5);
  start = clock();
  myBF3.bruteForceSolution2();
  stop = clock();
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF3.printTopK();
  cout << endl << endl;
  
  return 0;
}
