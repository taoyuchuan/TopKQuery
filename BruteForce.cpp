/*************************************************************
Implementation for all member functions for class BruteForce
*************************************************************/

#include "BruteForce.h"
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

// default constructor
// calls the base class default constructor to initialize data set
// default value for top K is defined as 3
BruteForce::BruteForce():TopKAlgorithm()
{
}

// constructor
// call base class constructor
// data set and topK is provided as the parameter
BruteForce::BruteForce(const DataSet& rhs_dataSet, const size_t& rhs_topK)
  :TopKAlgorithm(rhs_dataSet, rhs_topK)
{ 
}

// copy constructor
BruteForce::BruteForce(const BruteForce& rhs)
  :TopKAlgorithm(rhs)
{
  allData = rhs.allData;
  topKQuery = rhs.topKQuery;
}

// move constructor
BruteForce::BruteForce(BruteForce&& rhs)
  :TopKAlgorithm(std::move(rhs))
{
  allData = std::move(rhs.allData);
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
      std::swap(allData, rhs.allData);
      std::swap(topKQuery, rhs.topKQuery);
    }
  return *this;
}

// destructor
BruteForce::~BruteForce()
{
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
      temp.setId(oneItem.getId());
      temp.setOverallScore(oneItem.getScore());
      allData[temp.getId()-1] = temp;
    }
  // add the all the local scores to the corresponding place
  for(int i=1; i<allLists.size(); i++)
    {
      for(int j=0; j<allLists[i].size(); j++)
	{
	  int temp1 = allLists[i][j].getScore();
	  int temp2 = allData[allLists[i][j].getId()-1].getOverallScore();
	  allData[allLists[i][j].getId()-1].setOverallScore(temp1 + temp2);
	}
    }

  // using priority queue to store the top K
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

// the second method to implement brute force
// access the element of every list one by one
// comparable to other method as the sequential access
void BruteForce::bruteForceSolution2()
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
  
  // nested for loops sum up all the local scores of every id and store them in allData vector
  int j = 0;
  while(j < dataSet.getDataSize())
    {
      for(int i=0; i<allLists.size(); i++)
        {
	  DataItem tempItem = allLists[i][j];
	  if(allData[tempItem.getId()-1].getId() == 0)
	    {
	      allData[tempItem.getId()-1].setId(tempItem.getId());
	    }
	  int temp1 = tempItem.getScore();
	  int temp2 = allData[tempItem.getId()-1].getOverallScore();
	  allData[allLists[i][j].getId()-1].setOverallScore(temp1 + temp2);
        }
      j++;
    }

  // using priority queue to store the top K
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
  cout << "The results for the top " << topK << " queries on " << dataSet.getDataSize()
       << " data items with " << dataSet.getListSize() << " lists by BF algorithm are:" << endl;
  cout << std::left << std::setw(20) << "Id" << std::left << std::setw(20) << "Overall Score" << endl;
  for(auto& oneItem: topKQuery)
    {
      cout << std::left <<std::setw(20) << oneItem.getId()
	   << std::left << std::setw(20) << oneItem.getOverallScore() << endl;
    }
}

// clear the BruteForce class
void BruteForce::clear()
{
  TopKAlgorithm::clear();
  allData.clear();
  topKQuery.clear();
}
