/***************************************************************
Implementation for all member functions for class TopKAlgorithm
***************************************************************/

#include "TopKAlgorithm.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// default constructor
// calls the default constructor of class DataSet to initialize data set
// default value for top K is defined as 3
TopKAlgorithm::TopKAlgorithm():dataSet()
{
  topK = 3;
  sequenceAccess = 0;
  randomAccess = 0;
  executionCost = 0;
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
  sequenceAccess = 0;
  randomAccess = 0;
  executionCost = 0;
}

// copy constructor
TopKAlgorithm::TopKAlgorithm(const TopKAlgorithm& rhs)
{
  dataSet = rhs.dataSet;
  topK = rhs.topK;
  sequenceAccess = rhs.sequenceAccess;
  randomAccess = rhs.randomAccess;
  executionCost = rhs.executionCost;
}

// move constructor
TopKAlgorithm::TopKAlgorithm(TopKAlgorithm&& rhs)
{
  dataSet = std::move(rhs.dataSet);
  topK = std::move(rhs.topK);
  sequenceAccess = std::move(rhs.sequenceAccess);
  randomAccess = std::move(rhs.randomAccess);
  executionCost = std::move(rhs.executionCost);
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
      std::swap(sequenceAccess, rhs.sequenceAccess);
      std::swap(randomAccess, rhs.randomAccess);
      std::swap(executionCost, rhs.executionCost);
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
  sequenceAccess = 0;
  randomAccess = 0;
  executionCost = 0;
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

// return top k query result
vector<DataOverallScore> TopKAlgorithm::getTopKQuery() const
{
  return topKQuery;
}

// return the number of sequence access
size_t TopKAlgorithm::getSequenceAccess() const
{
	return sequenceAccess;
}

// return the number of random access
size_t TopKAlgorithm::getRandomAccess() const
{
	return randomAccess;
}

// return the value of execution cost
size_t TopKAlgorithm::getExecutionCost() const
{
	return executionCost;
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

// set the value of topKQuery
void TopKAlgorithm::setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery)
{
  if(!rhs_topKQuery.empty())
    {
      topKQuery = rhs_topKQuery;
    }
  else
    {
      cout << "Invalid topKQuery value" << endl;
      return;
    }
}

// set the value of sequence access
void TopKAlgorithm::setSequenceAccess(const size_t rhs_sequenceAccess)
{
	if(rhs_sequenceAccess >= 0)
	{
		sequenceAccess = rhs_sequenceAccess;
	}
	else
	{
		cout << "Invalid value" << endl;
		return;
	}
}

// set the value of random access
void TopKAlgorithm::setRandomAccess(const size_t rhs_randomAccess)
{
	if(rhs_randomAccess >= 0)
	{
		randomAccess = rhs_randomAccess;
	}
	else
	{
		cout << "Invalid value" << endl;
		return;
	}
}

// set the value of execution cost
void TopKAlgorithm::setExecutionCost(const size_t rhs_executionCost)
{
	if(rhs_executionCost >= 0)
	{
		executionCost = rhs_executionCost;
	}
	else
	{
		cout << "Invalid value" << endl;
		return;
	}
}

// clear the TopKAlgorithm class
void TopKAlgorithm::clear()
{
  dataSet.clear();
  topKQuery.clear();
  topK = 0;
  sequenceAccess = 0;
  randomAccess = 0;
  executionCost = 0;
}

// function to print topK result
void TopKAlgorithm::printTopK()
{
  if(topKQuery.size() == 0)
    {
      cout << "No top-k query results" << endl;
      return;
    }
  cout << "The results for the top " << topK << " queries on " << dataSet.getDataSize()
       << " data items with " << dataSet.getListSize() << " lists are:" << endl;
  cout << std::left << std::setw(20) << "Id" << std::left << std::setw(20) << "Overall Score" << endl;
  for(auto& oneItem: topKQuery)
    {
      cout << std::left <<std::setw(20) << oneItem.getId()
	   << std::left << std::setw(20) << oneItem.getOverallScore() << endl;
    }
  cout << "Stop position: " << (sequenceAccess / dataSet.getListSize()) << endl;
  cout << "Number of sequencial access: " << sequenceAccess << endl;
  cout << "Number of random access: " << randomAccess << endl;
  cout << "Number of execution cost: " << executionCost << endl;
}

// sum the local score in a vector
int TopKAlgorithm::sumVector(const vector<int>& scoreVector) const
{
  int sum = 0;
  for(auto& localScore: scoreVector)
    {
      sum += localScore;
    }
  return sum;
}
