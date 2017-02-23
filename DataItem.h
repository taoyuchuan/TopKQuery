/*******************************************************************
Definition for DataItem class
The object of DataItem is the member in the sorted list in data set
Actually implementation is in DataItem.cpp
*******************************************************************/

#ifndef DataItem_H
#define DataItem_H

#include <cstdio>

class DataItem
{  
  public:
    // constructor
    DataItem();
    DataItem(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum);
    DataItem(const size_t& rhs_id, const int& rhs_score);
    DataItem(const DataItem& rhs);
    DataItem(DataItem&& rhs);
    DataItem& operator=(const DataItem& rhs);
    DataItem& operator=(DataItem&& rhs);

    // destructor
    ~DataItem();

    // get functions
    size_t getId() const;
    int getScore() const;
    size_t getPosition() const;
    size_t getListNum() const;

    // set functions
    void setId(const size_t& rhs_id);
    void setScore(const int& rhs_score);
    void setPosition(const size_t& rhs_position);
    void setListNum(const size_t& rhs_listNum);

    // print function
    void print() const;

    // midify function
    void update(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum);

    // overload comparison operator
    bool operator<(const DataItem& rhs) const;
    bool operator>(const DataItem& rhs) const;
  
  private:
    // private data member
    size_t id;                  // id of data item, primary key, start from 1
    int score;                  // score of item in a list
    size_t position;            // position of item in a list, start from 1
    size_t listNum;             // the list number
};

#endif
