#include "DataItem.h"
#include "DataSet.h"
#include "FA.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  FA myFA1;
  myFA1.FASolution();
  myFA1.printTopK();
  cout << endl << endl;

  DataSet myDataSet(20000, 5);
  FA myFA2(myDataSet, 10);
  int start = clock();
  myFA2.FASolution();
  int stop = clock();
  cout << "time for FA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA2.printTopK();
  cout << endl << endl;
  
  return 0;
}
