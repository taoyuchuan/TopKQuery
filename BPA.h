/***************************************************************************
Defines the header of BPA class
The class inherits from TopKAlgorithm class
Additional private data members, bestPosition and topKQueue are added
bestPosition store the current seen best position for each list
topKQueue store the current top k data item
A user define struct BP is defined to maintain the best position 
The actual implementation is in file BPA.cpp
***************************************************************************/

#ifndef BPA_H
#define BPA_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include "TopKAlgorithm.h"

#include <queue>
#include <set>
#include <cstdio>

using namespace std;

// define a struct to help to maintain the best position in a list
struct BP
{
	size_t bp;                   // value of best position
	vector<bool> bitArray;       // bit array that can help to maintain the best position
};

class BPA: public TopKAlgorithm
{
  public:
    // constructors
    BPA();
    BPA(const DataSet& rhs_dataSet, const size_t& rhs_topK);
    BPA(const BPA& rhs);
    BPA(BPA&& rhs);
    BPA& operator=(const BPA& rhs);
    BPA& operator=(BPA&& rhs);
	
    // destructor
    ~BPA();
	
    // get functions
	priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> getTopKQueue() const;
	vector<BP> getBestPosition() const;
	set<size_t> getSeenDataItem() const;
	
    // set functions
	void setTopKQueue(const priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> rhs_topKQueue);
	void setBestPosition(const vector<BP> rhs_bestPosition);
	void setSeenDataItem(const set<size_t> rhs_seenDataItem);

    // function that will implement BPA algorithm
    void BPASolution();
    // void BPA2Solution();

    // helper function to clear the class data member
    void clear();
	
  private:
    // private data member
	priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> topKQueue;
	vector<BP> bestPosition;
	set<size_t> seenDataItem;
};

#endif
