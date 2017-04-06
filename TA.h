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
    TA();
    TA(const DataSet &rhs_dataSet, const size_t & rhs_topk);
    TA(const TA& rhs);
    TA(TA&& rhs);
    TA& operator=(const TA& rhs);
    TA& operator=(TA&& rhs);
    ~TA();

    void TASolution();    
    void clear();

  private:
     unordered_map<size_t, size_t> idTimes;
};

#endif
