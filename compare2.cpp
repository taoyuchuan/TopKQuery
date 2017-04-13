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
  double t1, t2, t3, t4, t5;
  
  DataSet myDataSet(500000, 8, 20);

  BruteForce myBF(myDataSet, 50);
  int start = clock();
  myBF.bruteForceSolution2();
  int stop = clock();
  t1 = (stop - start) / double(CLOCKS_PER_SEC);
  cout << "time for brute force algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBF.printTopK();
  cout << endl << endl;

  FA myFA(myDataSet, 50);
  start = clock();
  myFA.FASolution();
  stop = clock();
  t2 = (stop - start) / double(CLOCKS_PER_SEC);
  cout << "time for FA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myFA.printTopK();
  cout << endl << endl;

  TA myTA(myDataSet, 50);
  start = clock();
  myTA.TASolution();
  stop = clock();
  t3 = (stop - start) / double(CLOCKS_PER_SEC);
  cout << "time for TA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myTA.printTopK();
  cout << endl << endl;

  BPA myBPA(myDataSet, 50);
  start = clock();
  myBPA.BPASolution();
  stop = clock();
  t4 = (stop - start) / double(CLOCKS_PER_SEC);
  cout << "time for BPA algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA.printTopK();
  cout << endl << endl;
  
  BPA2 myBPA2(myDataSet, 50);
  start = clock();
  myBPA2.BPA2Solution();
  stop = clock();
  t5 = (stop - start) / double(CLOCKS_PER_SEC);
  cout << "time for BPA2 algorithm: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;
  myBPA2.printTopK();
  cout << endl << endl;
  
  cout << "Performnce Evaluation on Correlated Dataset (n = 100000, m = 8, k = 50, p = 20):" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| Algorithm " << std::left << std::setw(17) << "| Stop Position "
       << std::left << std::setw(17) << "| Sorted Access " << std::left << std::setw(17) 
	   << "| Random Access " << std::left << std::setw(17) << "| Execution Cost "
       << std::left << std::setw(17) << "| Execution Time " << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| BF " << "| " 
       << std::left << std::setw(15) << myBF.getSequenceAccess() / myDataSet.getListSize() 
       << "| " << std::left << std::setw(15) << myBF.getSequenceAccess() 
       << "| " << std::left << std::setw(15) << myBF.getRandomAccess() << "| " << std::left << std::setw(15) 
	   << myBF.getExecutionCost() << "| " << std::left << std::setw(15) << t1 << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| FA " << "| " 
       << std::left << std::setw(15) << myFA.getSequenceAccess() / myDataSet.getListSize() 
       << "| " << std::left << std::setw(15) << myFA.getSequenceAccess() 
       << "| " << std::left << std::setw(15) << myFA.getRandomAccess() << "| " << std::left << std::setw(15) 
	   << myFA.getExecutionCost() << "| " << std::left << std::setw(15) << t2 << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| TA " << "| " 
       << std::left << std::setw(15) << myTA.getSequenceAccess() / myDataSet.getListSize() 
       << "| " << std::left << std::setw(15) << myTA.getSequenceAccess() 
       << "| " << std::left << std::setw(15) << myTA.getRandomAccess() << "| " << std::left << std::setw(15) 
	   << myTA.getExecutionCost() << "| " << std::left << std::setw(15) << t3 << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| BPA " << "| " 
       << std::left << std::setw(15) << myBPA.getSequenceAccess() / myDataSet.getListSize() 
       << "| " << std::left << std::setw(15) << myBPA.getSequenceAccess() 
       << "| " << std::left << std::setw(15) << myBPA.getRandomAccess() << "| " << std::left << std::setw(15) 
	   << myBPA.getExecutionCost() << "| " << std::left << std::setw(15) << t4 << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 
  cout << std::left << std::setw(12) << "| BPA2 " << "| " 
       << std::left << std::setw(15) << myBPA2.getSequenceAccess() / myDataSet.getListSize() 
       << "| " << std::left << std::setw(15) << myBPA2.getSequenceAccess() 
       << "| " << std::left << std::setw(15) << myBPA2.getRandomAccess() << "| " << std::left << std::setw(15) 
	   << myBPA2.getExecutionCost() << "| " << std::left << std::setw(15) << t5 << "|" << endl;
  cout << std::left << std::setfill('-') << std::setw(98) << '-' << endl << std::setfill(' '); 

  cout << "n: number of data items      m: number of lists      k: top k value       p: percet of fluctation" << endl << endl << endl;

  return 0;
}
