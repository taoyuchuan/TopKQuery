/*******************************************************************
self-defined class to store the id and overall score of data item
*******************************************************************/

#ifndef DataOverallScore_H
#define DataOverallScore_H

#include <cstdio>

class DataOverallScore
{
  public:
    // get functions
    size_t getId() const;
    int getOverallScore() const;

    // set functions
    void setId(const size_t rhs_id);
    void setOverallScore(const int rhs_overallScore);

    // overload comparison operator for DataOverallScore
    bool operator<(const DataOverallScore& rhs) const;
    bool operator>(const DataOverallScore& rhs) const;
  
  private:
    size_t id;              // id of selected data item
    int overallScore;       // overall score of data item
};

#endif