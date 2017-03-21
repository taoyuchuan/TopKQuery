/*********************************************************************
Defines the header of brute force class
The class inherits from TopKAlgorithm class
Two additional private data members, topKQuery and allData are added
the allData vector will store id and overall scores for all data items
the topK result will be stored in a vector topKQuery   
The actual implementation is in file BruteForce.cpp
*********************************************************************/

#ifndef BruteForce_H
#define BruteForce_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include "TopKAlgorithm.h"
#include <cstdio>

class BruteForce: public TopKAlgorithm
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
	
    // get functions
    vector<DataOverallScore> getTopKQuery() const;
    vector<DataOverallScore> getAllData() const;
	
    // set functions
    void setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery);
    void setAllData(const vector<DataOverallScore>& rhs_allData);
	
    // function that will implement brute force algorithm
    void bruteForceSolution();
    void bruteForceSolution2();
    
    // print function
    void printTopK();

    // helper function to clear the class data member
    void clear();
	
  private:
    // private data member
    vector<DataOverallScore> topKQuery;         // store the result of topK query
    vector<DataOverallScore> allData;           // store the id and overall scores for all data item
};

#endif
