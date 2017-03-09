/***************************************************************
Implementation for all member functions for class TopKAlgorithm
***************************************************************/

#include "TopKAlgorithm.h"
#include <iostream>
#include <iomanip>

using namespace std;

// default constructor
// calls the default constructor of class DataSet to initialize data set
// default value for top K is defined as 3
TopKAlgorithm::TopKAlgorithm():dataSet()
{
  topK = 3;
}

// constructor
// data set and topK is provided as the parameter
TopKAlgorithm::TopKAlgorithm(const DataSet& rhs_dataSet, const size_t& rhs_topK)
{
  if(rhs_dataSet.getDataSize() < rhs_topK)
    {
      cout << "Incorrect value of topK";
      return;
    }
  dataSet = rhs_dataSet;
  topK = rhs_topK;
}

// copy constructor
TopKAlgorithm::TopKAlgorithm(const TopKAlgorithm& rhs)
{
  dataSet = rhs.dataSet;
  topK = rhs.topK;
}

// move constructor
TopKAlgorithm::TopKAlgorithm(TopKAlgorithm&& rhs)
{
  dataSet = std::move(rhs.dataSet);
  topK = std::move(rhs.topK);
}

// copy assignment operator
TopKAlgorithm& TopKAlgorithm::operator=(const TopKAlgorithm& rhs)
{
  if(this != &rhs)
    {
      TopKAlgorithm copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
TopKAlgorithm& TopKAlgorithm::operator=(TopKAlgorithm&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSet, rhs.dataSet);
      std::swap(topK, rhs.topK);
    }
  return *this;
}

// destructor
TopKAlgorithm::~TopKAlgorithm()
{
}

// re-construct the data set and topK
// new data set and topK value are provided
void TopKAlgorithm::reInit(const DataSet& rhs_dataSet, const size_t& rhs_topK)
{
  if(rhs_dataSet.getDataSize() < rhs_topK)
    {
      cout << "Incorrect value of topK";
      return;
    }
  clear();
  dataSet = rhs_dataSet;
  topK = rhs_topK;
}

// return the inside data set
DataSet TopKAlgorithm::getDataSet() const
{
  return dataSet;
}

// return the value of topK
size_t TopKAlgorithm::getTopK() const
{
  return topK;
}

// re set the data set
void TopKAlgorithm::setDataSet(const DataSet& rhs_dataSet)
{
  if(rhs_dataSet.getDataSize() > 0)
    {
      dataSet = rhs_dataSet;
    }
  else
    {
      cout << "Empty data set" << endl;
      return;
    }
}

// set the value of top k
void TopKAlgorithm::setTopK(const size_t& rhs_topK)
{
  if(rhs_topK > 0)
    {
      topK = rhs_topK;
    }
  else
    {
      cout << "Incorrect value of topK" << endl;
      return;
    }
}

// clear the TopKAlgorithm class
void TopKAlgorithm::clear()
{
  dataSet.clear();
  topK = 0;
}
