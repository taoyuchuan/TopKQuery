/*******************************************************
Defines the header of brute force class
The class includes a dataset as the data member
the topK result will be stored in a vector topKQuery   
The actual implementation is in file BruteForce.cpp
*******************************************************/

#ifndef BruteForce_H
#define BruteForce_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include <cstdio>

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
    DataSet getDataSet() const;
    size_t getTopK() const;
    vector<DataOverallScore> getTopKQuery() const;
    vector<DataOverallScore> getAllData() const;
	
    // set functions
    void setDataSet(const DataSet& rhs_dataSet);
    void setTopK(const size_t& rhs_topK);
    void setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery);
    void setAllData(const vector<DataOverallScore>& rhs_allData);
	
    // function that will implement brute force algorithm
    void bruteForceSolution();
    void printTopK();
	
  private:
    // private data member
    DataSet dataSet;                    // a dataset that is included in the class
    size_t topK;                        // stores the value of top K
    vector<DataOverallScore> topKQuery;         // store the result of topK query
    vector<DataOverallScore> allData;           // store the id and overall scores for all data item
      
    // helper functions 
    void clear();
};

#endif
