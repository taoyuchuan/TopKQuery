#include "DataItem.h"
#include "DataSet.h"
#include "TA.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  TA myFA1;
  myFA1.TASolution();
  myFA1.printTopK();
  cout << endl << endl;

  DataSet myDataSet(20000, 5);
  TA myFA2(myDataSet, 10);
  int start = clock();
  myFA2.TASolution();
  int stop = clock();
  cout << "time for TA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA2.printTopK();
  cout << endl << endl;
  
  return 0;
}

