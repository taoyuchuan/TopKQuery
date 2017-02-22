/*********************************************************************************
Defines the header of dataset that will be the input for several algorithms
The dataset include all sorted lists as data member and several helper functions  
The actual implementation is in file DataSet.cpp
**********************************************************************************/

#ifndef DataSet_H
#define DataSet_H

#include "DataItem.h"
#include <cstdio>
#include <vector>

using namespace std;

class DataSet
{
  public:
    // constructors
    DataSet();
    DataSet(const size_t& rhs_dataSize, const size_t& rhs_listSize);
    DataSet(const DataSet& rhs);
    DataSet(DataSet&& rhs);
    DataSet& operator=(const DataSet& rhs);
    DataSet& operator=(DataSet&& rhs);
	
    // destructor
    ~DataSet();
	
    // re-initializer
    void reInit(const size_t& rhs_dataSize, const size_t& rhs_listSize);
	
    // get functions
    size_t getDataSize() const;
    size_t getListSize() const;
    size_t getMaxId() const;
    vector<vector<DataItem>> getLists() const;
	
    // set functions
    void setDataSize(const size_t& rhs_dataSize);
    void setListSize(const size_t& rhs_listSize);
    void setMaxId(const size_t& rhs_maxId);
    void setLists(const vector<vector<DataItem>>& rhs_lists);
	
    // modifier functions
    void insert(const vector<int>& scores);
    void remove(const size_t& rhs_id);
    void update(const size_t& rhs_id, const vector<int>& scores);
	
    // check score function
    vector<int> checkScore(const size_t& rhs_id) const;
	
    // print function
    void print() const;

  private:
    // private data member
    size_t dataSize;                      // stores number of data items
    size_t listSize;                      // stores number of sorted lists
    size_t maxId;                         // stores the largest id of data items in list
    vector<vector<DataItem>> lists;       // sotres all the sorted lists
	
    // private modifier for data set
    void clear();                          
    void generateDataSet();
	
    // private helper function to generate data set
    size_t findMaxId() const;
    size_t findPosition(const vector<DataItem>& oneList, const size_t& rhs_id) const;
    size_t insertPosition(const vector<DataItem>& oneList, const int& rhs_score) const;
};

#endif
