/***************************************************************************
Defines the header of BPA2 class
The class inherits from TopKAlgorithm class
Additional private data members, bestPosition and topKQueue are added
bestPosition store the current seen best position for each list
topKQueue store the current top k data item
A user define struct BP is defined to maintain the best position 
The actual implementation is in file BPA2.cpp
***************************************************************************/

#ifndef BPA2_H
#define BPA2_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include "TopKAlgorithm.h"

#include <queue>
#include <set>
#include <cstdio>

using namespace std;

class BPA2: public TopKAlgorithm
{
  public:

    // constructors
    BPA2();
    BPA2(const DataSet& rhs_dataSet, const size_t& rhs_topK);
    BPA2(const BPA2& rhs);
    BPA2(BPA2&& rhs);
    BPA2& operator=(const BPA2& rhs);
    BPA2& operator=(BPA2&& rhs);
	
    // destructor
    ~BPA2();
	
    // get functions
	priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> getTopKQueue() const;
	vector<BP> getBestPosition() const;
	
    // set functions
	void setTopKQueue(const priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> rhs_topKQueue);
	void setBestPosition(const vector<BP> rhs_bestPosition);

    // function that will implement BPA2 algorithm
    void BPA2Solution();

    // helper function to clear the class data member
    void clear();
	
  private:
    // private data member
	priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> topKQueue;
	vector<BP> bestPosition;
};

#endif
