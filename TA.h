/***************************************************************************
Defines the header of TA class
The class inherits from TopKAlgorithm class
Additional private data members, topKQuery and idTimes are added
the topK result will be stored in a vector topKQuery
the idTimes records the seen data information   
The actual implementation is in file FA.cpp
***************************************************************************/

#ifndef TA_H
#define TA_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include "TopKAlgorithm.h"

#include <unordered_map>
#include <cstdio>
#include <set>
using namespace std;

class TA: public TopKAlgorithm
{
  public:
    //constructor
    TA();
    TA(const DataSet &rhs_dataSet, const size_t & rhs_topk);
    TA(const TA& rhs);
    TA(TA&& rhs);
    TA& operator=(const TA& rhs);
    TA& operator=(TA&& rhs);
    //destructor
    ~TA();
    
    //get functions
    unordered_map<size_t, size_t> getIdTimes() const;
    
    //set functions
    void setIdTimes(const unordered_map<size_t, size_t>& rhs_idTimes);

    // function that will implement FA algorithm
    void TASolution();

    // helper function to clear the class data member    
    void clear();

  private:
     //private data member
     unordered_map<size_t, size_t> idTimes;   //// store the number of times data item show up in all lists
};

#endif
