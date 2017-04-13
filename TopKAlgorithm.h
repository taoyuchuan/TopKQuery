/***************************************************************
Defines the header of Top-k algorithm class
This class is the base class for all other specific algorithms
The class includes a dataset as the data member
the topK value is a data member   
The actual implementation is in file TopKAlgorithm.cpp
***************************************************************/

#ifndef TopKAlgorithm_H
#define TopKAlgorithm_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include <cstdio>
#include <math.h>
#include <iomanip>
    
// define a struct to help to maintain the best position in a list
struct BP
{
  int bp;                   // value of best position
  vector<bool> bitArray;       // bit array that can help to maintain the best position
};

class TopKAlgorithm
{
  public:
    // constructors
    TopKAlgorithm();
    TopKAlgorithm(const DataSet& rhs_dataSet, const size_t& rhs_topK);
    TopKAlgorithm(const TopKAlgorithm& rhs);
    TopKAlgorithm(TopKAlgorithm&& rhs);
    TopKAlgorithm& operator=(const TopKAlgorithm& rhs);
    TopKAlgorithm& operator=(TopKAlgorithm&& rhs);
	
    // destructor
    ~TopKAlgorithm();
	
    // re-initializer
    void reInit(const DataSet& rhs_dataSet, const size_t& rhs_topK);
	
    // get functions
    DataSet getDataSet() const;
    size_t getTopK() const;
 	vector<DataOverallScore> getTopKQuery() const;
	size_t getSequenceAccess() const;
	size_t getRandomAccess() const;
	size_t getExecutionCost() const;
	
    // set functions
    void setDataSet(const DataSet& rhs_dataSet);
    void setTopK(const size_t& rhs_topK);
	void setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery);
	void setSequenceAccess(const size_t rhs_sequenceAccess);
	void setRandomAccess(const size_t rhs_randomAccess);
	void setExecutionCost(const size_t rhs_executionCost);
		
    // helper function to clear the private data
    void clear();

	// print function
	void printTopK();
	
  protected:
    // protected data member
    DataSet dataSet;               // a dataset that is included in the class
    size_t topK;                   // stores the value of top K
	vector<DataOverallScore> topKQuery;   // store the result of topK query
	size_t sequenceAccess;
	size_t randomAccess;
	size_t executionCost;

	// helper function to return the sum of a vector
	int sumVector(const vector<int>& scoreVector) const;
};

#endif
