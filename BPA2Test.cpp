#include "DataItem.h"
#include "DataSet.h"
#include "BPA2.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  BPA2 myBPA2;
  myBPA2.BPA2Solution();
  myBPA2.printTopK();
  cout << endl << endl;
  
  DataSet myDataSet(20000, 5);
  BPA2 myBPA22(myDataSet, 10);
  int start = clock();
  myBPA22.BPA2Solution();
  int stop = clock();
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA22.printTopK();
  cout << endl << endl;
  
  return 0;
}
