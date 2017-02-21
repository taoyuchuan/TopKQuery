/*******************************************************
Defines the header of brute force class
The class includes a dataset as the data member
the topK result will be stored in a vector topKQuery   
The actual implementation is in file BruteForce.cpp
*******************************************************/

#ifndef BruteForce_H
#define BruteForce_H

#include <DataItem.h>
#include <DataSet.h>

class BruteForce
{
  public:
    // constructors
    BruteForce();
	BruteForce(const DataSet& rhs_dataSet, const size_t& rhs_topK);
	BruteForce(const BruteForce& rhs);
	BruteForce(BruteForce&& rhs);
	BruteForce& operator=(const BruteForce& rhs);
	BruteForce& operator=(BruteForce&& rhs);
	
	// destructor
	~BruteForce();
	
	// re-initializer
	void reInit(const DataSet& rhs_dataSet, const size_t& rhs_topK);
	
	// get functions
	DataSet& getDataSet() const;
	size_t getTopK() const;
	vector<DataItem>& getTopKQuery() const;
	
	// set functions
	void setDataSet(const DataSet& rhs_dataSet);
	void setTopK(const size_t& rhs_topK);
	void setTopKQuery(const vector<DataItem>& rhs_topKQuery);
	
	// function that will implement brute force algorithm
	void bruteForceSolution();
	
  private:
    // private data member
    DataSet dataSet;                    // a dataset that is included in the class
	size_t topK;                        // stores the value of top K
	vector<DataItem> topKQuery;         // store the result of topK query
	
	// helper functions 
	void clear();
};

#endif