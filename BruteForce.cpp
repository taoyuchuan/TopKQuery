/*************************************************************
Implementation for all member functions for class BruteForce
*************************************************************/

#include "BruteForce.h"
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

// overload < comparison operator for DataOverallScore 
// the comparison is first based on overall score
// if overall score is the same, the one with smaller id is considered as larger
bool operator<(const DataOverallScore& lhs, const DataOverallScore& rhs)
{
  if(lhs.overallScore < rhs.overallScore)
    {
      return true;
    }
  else if(lhs.overallScore == rhs.overallScore)
    {
      if(lhs.id > rhs.id)
	{
	  return true;
	}
    }
  else
    {
      return false;
    }
}

// overload > comparison operator
bool operator>(const DataOverallScore& lhs, const DataOverallScore& rhs)
{
  return !(lhs < rhs);
}

// default constructor
// calls the default constructor of class DataSet to initialize data set
// default value for top K is defined as 3
BruteForce::BruteForce():dataSet()
{
  topK = 3;
}

// constructor
// data set and topK is provided as the parameter
BruteForce::BruteForce(const DataSet& rhs_dataSet, const size_t& rhs_topK)
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
BruteForce::BruteForce(const BruteForce& rhs)
{
  dataSet = rhs.dataSet;
  topK = rhs.topK;
  topKQuery = rhs.topKQuery;
}

// move constructor
BruteForce::BruteForce(BruteForce&& rhs)
{
  dataSet = std::move(rhs.dataSet);
  topK = std::move(rhs.topK);
  topKQuery = std::move(rhs.topKQuery);
}

// copy assignment operator
BruteForce& BruteForce::operator=(const BruteForce& rhs)
{
  if(this != &rhs)
    {
      BruteForce copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
BruteForce& BruteForce::operator=(BruteForce&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSet, rhs.dataSet);
      std::swap(topK, rhs.topK);
      std::swap(topKQuery, rhs.topKQuery);
    }
  return *this;
}

// destructor
BruteForce::~BruteForce()
{
}

// re-construct the data set and topK
// new data set and topK value are provided
void BruteForce::reInit(const DataSet& rhs_dataSet, const size_t& rhs_topK)
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
DataSet BruteForce::getDataSet() const
{
  return dataSet;
}

// return the value of topK
size_t BruteForce::getTopK() const
{
  return topK;
}

// return top k query result
vector<DataOverallScore> BruteForce::getTopKQuery() const
{
  return topKQuery;
}

//return all data item
vector<DataOverallScore> BruteForce::getAllData() const
{
  return allData;
}

// re set the data set
void BruteForce::setDataSet(const DataSet& rhs_dataSet)
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
void BruteForce::setTopK(const size_t& rhs_topK)
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
void BruteForce::setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery)
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

// set the value of allData
void BruteForce::setAllData(const vector<DataOverallScore>& rhs_allData)
{
  if(!rhs_allData.empty())
    {
      allData = rhs_allData;
    }
  else
    {
      cout <<"Invalid allData value" << endl;
      return;
    }
}

// the core function to perform the brute force algorithm for top-k query
// the top-K query result will be stored in topKQuery vector
// the result will contain the id and overall score of top-k data item
void BruteForce::bruteForceSolution()
{
  // check the input value is correct
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }

  // retrive the dataset for top-k query
  vector<vector<DataItem>> allLists = dataSet.getLists();
  // resize the allData to the size of data size
  allData.resize(dataSet.getDataSize());
  // initialize the allData vector to the value of the first list
  for(auto& oneItem: allLists[0])
    {
      DataOverallScore temp;
      temp.id = oneItem.getId();
      temp.overallScore = oneItem.getScore();
      allData[temp.id-1] = temp;
    }
  // add the all the local scores to the corresponding place
  for(int i=1; i<allLists.size(); i++)
    {
      for(int j=0; j<allLists[i].size(); j++)
	{
	  allData[allLists[i][j].getId()-1].overallScore += allLists[i][j].getScore();
	}
    }
  /*
  for(auto& x: allData)
    {
      cout << x.id << " " << x.overallScore << endl;
    }
  */
  priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> myPriorityQueue;
  for(auto& oneItem: allData)
    {
      if(myPriorityQueue.size() < topK)
	{
	  myPriorityQueue.push(oneItem);
	}
      else
	{
	  if(myPriorityQueue.top() < oneItem)
	    {
	      myPriorityQueue.pop();
	      myPriorityQueue.push(oneItem);
	    }
	}
    }
  
  // resize the topKQuery vector
  topKQuery.resize(topK);

  // store the top-k query result in topKQuery vector
  size_t index = topK - 1;
  while(!myPriorityQueue.empty())
    {
      topKQuery[index] = myPriorityQueue.top();
      myPriorityQueue.pop();
      index--;
    }
}

// function to print topK result
void BruteForce::printTopK()
{
  if(topKQuery.size() == 0)
    {
      cout << "No top-k query results" << endl;
      return;
    }
  cout << "The results for the top " << topK << " queries are:" << endl;
  cout << std::left << std::setw(20) << "Id" << std::left << std::setw(20) << "Overall Score" << endl;
  for(auto& oneItem: topKQuery)
    {
      cout << std::left <<std::setw(20) << oneItem.id
	   << std::left << std::setw(20) << oneItem.overallScore << endl;
    }
}

// clear the BruteForce class
void BruteForce::clear()
{
  dataSet.clear();
  topK = 0;
  allData.clear();
  topKQuery.clear();
}
