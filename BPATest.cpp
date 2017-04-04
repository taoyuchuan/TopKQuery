#include "DataItem.h"
#include "DataSet.h"
#include "BPA.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  BPA myBPA1;
  myBPA1.BPASolution();
  myBPA1.printTopK();
  cout << endl << endl;
  
  DataSet myDataSet(20000, 5);
  BPA myBPA2(myDataSet, 10);
  int start = clock();
  myBPA2.BPASolution();
  int stop = clock();
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA2.printTopK();
  cout << endl << endl;
  
  return 0;
}
