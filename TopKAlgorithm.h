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
	
    // set functions
    void setDataSet(const DataSet& rhs_dataSet);
    void setTopK(const size_t& rhs_topK);
		
    // helper function to clear the private data
    void clear();
	
  protected:
    // private data member
    DataSet dataSet;               // a dataset that is included in the class
    size_t topK;                   // stores the value of top K
};

#endif