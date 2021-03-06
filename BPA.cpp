/**************************************************************
Implementation for all member functions for class BPA algorithm
**************************************************************/

#include "BPA.h"
#include <iostream>
#include <limits.h>

using namespace std;

// default constructor
// calls the base class default constructor to initialize data set
// default value for number of lists is 3
// default value for number of data item is 15
BPA::BPA():TopKAlgorithm()
{
	// initialize the best position data structure
	bestPosition.resize(3);     // default size of number of lists is 3, so resize the best position vector as 3
	for(auto& bpItem: bestPosition)
	  {
		bpItem.bp = -1;
		bpItem.bitArray.resize(15, false);  // default size of number of data item is 15
	  }
}

// constructor
// call base class constructor
// data set and topK is provided as the parameter
BPA::BPA(const DataSet& rhs_dataSet, const size_t& rhs_topK)
  :TopKAlgorithm(rhs_dataSet, rhs_topK)
{ 
	// initialize best position data structure
	bestPosition.resize(dataSet.getListSize());
	for(auto& bpItem: bestPosition)
	  {
		bpItem.bp = -1;
		bpItem.bitArray.resize(dataSet.getDataSize(), false);
	  }
}

// copy constructor
BPA::BPA(const BPA& rhs):TopKAlgorithm(rhs)
{
	topKQueue = rhs.topKQueue;
	bestPosition = rhs.bestPosition;
}

// move constructor
BPA::BPA(BPA&& rhs):TopKAlgorithm(std::move(rhs))
{
  topKQueue = std::move(rhs.topKQueue);
  bestPosition = std::move(rhs.bestPosition);
}

// copy assignment operator
BPA& BPA::operator=(const BPA& rhs)
{
  if(this != &rhs)
    {
      BPA copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
BPA& BPA::operator=(BPA&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSet, rhs.dataSet);
      std::swap(topK, rhs.topK);
      std::swap(topKQuery, rhs.topKQuery);
      std::swap(topKQueue, rhs.topKQueue);
      std::swap(bestPosition, rhs.bestPosition);
    }
  return *this;
}

// destructor
BPA::~BPA()
{
}

// return the topK priority queue
priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> BPA::getTopKQueue() const
{
	return topKQueue;
}

// return the best position data structure
vector<BP> BPA::getBestPosition() const
{
	return bestPosition;
}

// return the seen data item so far
set<size_t> BPA::getSeenDataItem() const
{
	return seenDataItem;
}


// set the top k priority queue
void BPA::setTopKQueue(const priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> rhs_topKQueue)
{
	if(!rhs_topKQueue.empty())
	  {
		topKQueue = rhs_topKQueue;			
	  }
	else
	  {
	  	cout << "Invalid topK queue" << endl;
		return;
	  }
}

// set the best position data structure
void BPA::setBestPosition(const vector<BP> rhs_bestPosition)
  {
  	if(!rhs_bestPosition.empty())
	  {
		bestPosition = rhs_bestPosition;	
	  }
	else
	  {
	  	cout << "Invalid value of best position data structure" << endl;
		return;
	  }
  }

// set the seen data item set
void BPA::setSeenDataItem(const set<size_t> rhs_seenDataItem)
{
  	if(!rhs_seenDataItem.empty())
	  {
		seenDataItem = rhs_seenDataItem;	
	  }
	else
	  {
	  	cout << "Invalid value of seen data item set" << endl;
		return;
	  }
}

// the core function to perform the BPA algorithm for top-k query
// the top-K query result will be stored in topKQuery vector
// the result will contain the id and overall score of top-k data item
void BPA::BPASolution()
{
  // check the input value is correct
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }

  // retrive the dataset for top-k query
  vector<vector<DataItem>> allLists = dataSet.getLists();

  int threshold = INT_MAX;  // threshold value, when reaches threshold, stop
  int j = 0;  // counter for second index
  
  // while loop stops when the overall score of the data item on the top of priority is larger or equal than threshold
  while(topKQueue.empty() || topKQueue.top().getOverallScore() < threshold)
  {
    for(int i=0; i<allLists.size(); i++)
	{
	  sequenceAccess += 1;
	  DataItem tempDataItem = allLists[i][j];
	  size_t tempId = tempDataItem.getId();
	  int tempOverallScore = 0; 
	  // for loop update bitArray for best position and calculate the overall score of a data item
	  for(int k=0; k<allLists.size(); k++)       
	    {
	  	  size_t position = dataSet.findPosition2(k, tempId);  // call the find postion function
		  tempOverallScore += allLists[k][position].getScore();
		  bestPosition[k].bitArray[position] = true;
	    }
	 
	  // maintain a priority queue to store top k result so far
	  if(seenDataItem.count(tempId) == 0)             // check if the data item has already been seen
		{
		  seenDataItem.insert(tempId);                 // insert the id into set
	      DataOverallScore tempDataOverallScore;
	      tempDataOverallScore.setId(tempId);
	      tempDataOverallScore.setOverallScore(tempOverallScore);
	  	  if(topKQueue.size() < topK)
	      {
	  	    topKQueue.push(tempDataOverallScore);
	      }
	  	  else
	      {
	  	    if(topKQueue.top() < tempDataOverallScore)
		    {
			  topKQueue.pop();
			  topKQueue.push(tempDataOverallScore);
		    } 
	      }  
	    }
	}
	// calculate best positions on all lists
	for(int l=0; l<allLists.size(); l++)
	{
		while(bestPosition[l].bp < (int)(allLists[l].size()-1) && bestPosition[l].bitArray[bestPosition[l].bp+1] == true)
		{
			bestPosition[l].bp += 1;
		}
	}
 
	// calculate threshold based on all the best positions
	int tempThreshold = 0;
	for(int l=0; l<allLists.size(); l++)
	{
		tempThreshold += allLists[l][bestPosition[l].bp].getScore();
	}
	threshold = tempThreshold;

	// increase the counter
    j++;                                       
  }

  // resize the topKQuery vector
  topKQuery.resize(topK);

  // store the top-k query result in topKQuery vector
  size_t index = topK - 1;
  while(!topKQueue.empty())
    {
      topKQuery[index] = topKQueue.top();
      topKQueue.pop();
      index--;
    }

  randomAccess = sequenceAccess * (dataSet.getListSize() - 1);
  size_t cost = (size_t)log(dataSet.getDataSize());
  executionCost = sequenceAccess + cost * randomAccess;
}

// function to clear all private data member
void BPA::clear()
{
  TopKAlgorithm::clear();
  bestPosition.clear();
  while(!topKQueue.empty())
  {
  	topKQueue.pop();
  }
}
