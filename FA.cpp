/**************************************************************
Implementation for all member functions for class FA algorithm
**************************************************************/

#include "FA.h"
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

// default constructor
// calls the base class default constructor to initialize data set
// default value for top K is defined as 3
FA::FA():TopKAlgorithm()
{
}

// constructor
// call base class constructor
// data set and topK is provided as the parameter
FA::FA(const DataSet& rhs_dataSet, const size_t& rhs_topK)
  :TopKAlgorithm(rhs_dataSet, rhs_topK)
{ 
}

// copy constructor
FA::FA(const FA& rhs):TopKAlgorithm(rhs)
{
  topKQuery = rhs.topKQuery;
  idMap = rhs.idMap;
  seenAllList = rhs.seenAllList;
}

// move constructor
FA::FA(FA&& rhs):TopKAlgorithm(std::move(rhs))
{
  topKQuery = std::move(rhs.topKQuery);
  idMap = std::move(rhs.idMap);
  seenAllList = std::move(rhs.seenAllList);
}

// copy assignment operator
FA& FA::operator=(const FA& rhs)
{
  if(this != &rhs)
    {
      FA copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
FA& FA::operator=(FA&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSet, rhs.dataSet);
      std::swap(topK, rhs.topK);
      std::swap(topKQuery, rhs.topKQuery);
      std::swap(idMap, rhs.idMap);
      std::swap(seenAllList, rhs.seenAllList);
    }
  return *this;
}

// destructor
FA::~FA()
{
}

// return top k query result
vector<DataOverallScore> FA::getTopKQuery() const
{
  return topKQuery;
}

// return the information of seen data item
unordered_map<size_t, vector<int>> FA::getIdMap() const
{
  return idMap;
}

// return the times of data items seen in all lists
unordered_map<size_t, size_t> FA::getIdTimes() const
{
  return idTimes;
}

// return the set of seen data item
set<size_t> FA::getSeenAllList() const
{
  return seenAllList;
}  

// set the value of topKQuery
void FA::setTopKQuery(const vector<DataOverallScore>& rhs_topKQuery)
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

// set the value of idMap
void FA::setIdMap(const unordered_map<size_t, vector<int>>& rhs_idMap)
{
  if(!rhs_idMap.empty())
    {
      idMap = rhs_idMap;
    }
  else
    {
      cout <<"Invalid idMap value" << endl;
      return;
    }
}

// set the value of idTimes
void FA::setIdTimes(const unordered_map<size_t, size_t>& rhs_idTimes)
{
  if(!rhs_idTimes.empty())
    {
      idTimes = rhs_idTimes;
    }
  else
    {
      cout <<"Invalid idTimes value" << endl;
      return;
    }
}

// set the value of seenAllList
void FA::setSeenAllList(const set<size_t>& rhs_seenAllList)
{
  if(!rhs_seenAllList.empty())
    {
      seenAllList = rhs_seenAllList;
    }
  else
    {
      cout << "Invalid value of seenAllList" << endl;
      return;
    }
}

// the core function to perform the FA algorithm for top-k query
// the top-K query result will be stored in topKQuery vector
// the result will contain the id and overall score of top-k data item
void FA::FASolution()
{
  // check the input value is correct
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }

  // retrive the dataset for top-k query
  vector<vector<DataItem>> allLists = dataSet.getLists();

  int j = 0;  // counter for second index
  
  // while stops when topK number of items that shows up in all lists
  while(seenAllList.size() < topK)
    {
      for(int i=0; i<allLists.size(); i++)
	{
	  DataItem tempDataItem = allLists[i][j];
	  size_t tempId = tempDataItem.getId();
	  
	  // if id has not been seen
	  if(idTimes.count(tempId) == 0) 
	    {
	      idTimes[tempId] = 1;    // set the counter as 1 for the first time the id has been seen
	    }
	  // if id has seen, add the times counter
	  else                             
	    {
	      idTimes[tempId] += 1;
	    }

	  // if the id has not been seen
	  if(idMap.count(tempId) == 0)
	    {
	      idMap[tempId].resize(allLists.size(), 0);       // initialize the map vector
	      idMap[tempId][i] = tempDataItem.getScore();     // set the corresponding local score
	    }
	  // if the id has been seen
	  else
	    {
	      idMap[tempId][i] = tempDataItem.getScore();     // set the corresponding local score
	    }

	  // check if the id has been seen in all lists
	  if(idTimes[tempId] == allLists.size())
	    {
	      seenAllList.insert(tempId);               // store in the set if id has been seen in all lists
	    }
	}
      j++;                                              // increase counter
    }

  // set all the local scores for id that has only been seen in some lists
  for(auto& oneItem: idMap)
    {
      // if the id is already seen for all lists
      if(seenAllList.count(oneItem.first) == 1)
	{
	  continue;
	}
      // retrive the unseen local score
      for(int i=0; i<oneItem.second.size(); i++)
	{
	  int& localScore = oneItem.second[i];
	  if(localScore != 0)
	    {
	      continue;
	    }
	  // call the findPosition member function
	  size_t position = dataSet.findPosition(allLists[i], oneItem.first);
	  localScore = allLists[i][position].getScore();
	}
    }

  // priority queue to store the topK
  priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> myPriorityQueue;
  for(auto& oneItem: idMap)
    {
      // temperary DataOverallScore  variable to push in the priority queue
      DataOverallScore temp;
      temp.setId(oneItem.first);
      // call sumVector member function to get the overall score
      temp.setOverallScore(sumVector(oneItem.second));
      // if less than topK, keep pushing in the queue
      if(myPriorityQueue.size() < topK)
	{
	  myPriorityQueue.push(temp);
	}
      // else check if it should be push in the queue
      else
	{
	  if(myPriorityQueue.top() < temp)
	    {
	      myPriorityQueue.pop();
	      myPriorityQueue.push(temp);
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
  
  // cout << "The number of rows access is " << j << endl;
  // cout << "The number of item that require additional access is " << idMap.size() - seenAllList.size() << endl;
}

// another way to implement FA
void FA::FASolution2()
{
  // check the input value is correct
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }

  // retrive the dataset for top-k query
  vector<vector<DataItem>> allLists = dataSet.getLists();

  // while stops when find topK number of items that shows up in all lists
  int j = 0;

  while(seenAllList.size() < topK)
    {
      for(int i=0; i<allLists.size(); i++)
	{
	  DataItem tempDataItem = allLists[i][j];
	  size_t tempId = tempDataItem.getId();
	  if(idTimes.count(tempId) == 0)
	    {
	      idTimes[tempId] = 1;
	    }
	  else
	    {
	      idTimes[tempId] += 1;
	    }
	  if(idMap.count(tempId) == 0)
	    {
	      idMap[tempId].resize(allLists.size(), 0);
	      idMap[tempId][i] = tempDataItem.getScore();
	    }
	  else
	    {
	      idMap[tempId][i] = tempDataItem.getScore();
	    }
	  if(idTimes[tempId] == allLists.size())
	    {
	      seenAllList.insert(tempId);
	    }
	}
      j++;
    }

  for(auto& oneItem: idMap)
    {
      if(seenAllList.count(oneItem.first) == 1)
	{
	  continue;
	}

      // calling checkScore member function to re set all the local scores for a data item
      // doing some redundant work, slower than the previously method
      oneItem.second = dataSet.checkScore(oneItem.first);
    }

  priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> myPriorityQueue;
  for(auto& oneItem: idMap)
    {
      DataOverallScore temp;
      temp.setId(oneItem.first);
      temp.setOverallScore(sumVector(oneItem.second));
      if(myPriorityQueue.size() < topK)
	{
	  myPriorityQueue.push(temp);
	}
      else
	{
	  if(myPriorityQueue.top() < temp)
	    {
	      myPriorityQueue.pop();
	      myPriorityQueue.push(temp);
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
void FA::printTopK()
{
  if(topKQuery.size() == 0)
    {
      cout << "No top-k query results" << endl;
      return;
    }
  cout << "The results for the top " << topK << " queries on " << dataSet.getDataSize()
       << " data items with " << dataSet.getListSize() << " lists by FA algorithm are:" << endl;
  cout << std::left << std::setw(20) << "Id" << std::left << std::setw(20) << "Overall Score" << endl;
  for(auto& oneItem: topKQuery)
    {
      cout << std::left <<std::setw(20) << oneItem.getId()
	   << std::left << std::setw(20) << oneItem.getOverallScore() << endl;
    }
}

// clear the FA class
void FA::clear()
{
  TopKAlgorithm::clear();
  topKQuery.clear();
  idMap.clear();
  seenAllList.clear();
}

// sum the local score in a vector
int FA::sumVector(const vector<int>& scoreVector) const
{
  int sum = 0;
  for(auto& localScore: scoreVector)
    {
      sum += localScore;
    }
  return sum;
}
