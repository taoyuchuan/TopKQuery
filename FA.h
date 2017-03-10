/***************************************************************************
Defines the header of FA class
The class inherits from TopKAlgorithm class
Additional private data members, topKQuery and seenAllList idMap are added
the topK result will be stored in a vector topKQuery
the seenAllList set will store the items have been seen in all lists
the idMap records the seen data information   
The actual implementation is in file FA.cpp
***************************************************************************/

#ifndef FA_H
#define FA_H

#include "DataItem.h"
#include "DataSet.h"
#include "DataOverallScore.h"
#include "TopKAlgorithm.h"

#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

class FA: public TopKAlgorithm
{
  public:
    // constructors
    FA();
    FA(const DataSet& rhs_dataSet, const size_t& rhs_topK);
    FA(const FA& rhs);
    FA(FA&& rhs);
    FA& operator=(const FA& rhs);
    FA& operator=(FA&& rhs);
	
    // destructor
    ~FA();
	
    // get functions
    vector<DataOverallScore> getTopKQuery() const;
    unordered_map<size_t, vector<int>> getIdMap() const;
    unordered_map<size_t, size_t> getIdTimes() const;
    set<size_t> getSeenAllList() const;
	
    // set functions
    void setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery);
    void setIdMap(const unordered_map<size_t, vector<int>>& rhs_idMap);
    void setIdTimes(const unordered_map<size_t, size_t>& rhs_idTimes);
    void setSeenAllList(const set<size_t>& rhs_seenAllList);
	
    // function that will implement FA algorithm
    void FASolution();
    void FASolution2();

    // print function
    void printTopK();

    // helper function to clear the class data member
    void clear();
	
  private:
    // private data member
    vector<DataOverallScore> topKQuery;         // store the result of topK query
    unordered_map<size_t, vector<int>> idMap;   // store data item id and all the local score
    unordered_map<size_t, size_t> idTimes;      // store the number of times data item show up in all lists
    set<size_t> seenAllList;                    // store the id of data items seen in all list

    // helper function
    int sumVector(const vector<int>& scoreVector) const;
};

#endif
