/**************************************************************
Implementation for all member functions for class BPA2 algorithm
**************************************************************/

#include "BPA2.h"
#include <iostream>
#include <limits.h>
#include <set>

using namespace std;

// default constructor
// calls the base class default constructor to initialize data set
// default value for number of lists is 3
// default value for number of data item is 15
BPA2::BPA2():TopKAlgorithm()
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
BPA2::BPA2(const DataSet& rhs_dataSet, const size_t& rhs_topK)
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
BPA2::BPA2(const BPA2& rhs):TopKAlgorithm(rhs)
{
	topKQueue = rhs.topKQueue;
	bestPosition = rhs.bestPosition;
}

// move constructor
BPA2::BPA2(BPA2&& rhs):TopKAlgorithm(std::move(rhs))
{
  topKQueue = std::move(rhs.topKQueue);
  bestPosition = std::move(rhs.bestPosition);
}

// copy assignment operator
BPA2& BPA2::operator=(const BPA2& rhs)
{
  if(this != &rhs)
    {
      BPA2 copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
BPA2& BPA2::operator=(BPA2&& rhs)
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
BPA2::~BPA2()
{
}

// return the topK priority queue
priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> BPA2::getTopKQueue() const
{
	return topKQueue;
}

// return the best position data structure
vector<BP> BPA2::getBestPosition() const
{
	return bestPosition;
}

// set the top k priority queue
void BPA2::setTopKQueue(const priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> rhs_topKQueue)
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
void BPA2::setBestPosition(const vector<BP> rhs_bestPosition)
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

// the core function to perform the BPA2 algorithm for top-k query
// the top-K query result will be stored in topKQuery vector
// the result will contain the id and overall score of top-k data item
void BPA2::BPA2Solution()
{
  // check the input value is correct
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }

  // retrive the dataset for top-k query
  vector<vector<DataItem>> allLists = dataSet.getLists();
  set<size_t> seenId;

  int threshold = INT_MAX;  // threshold value, when reaches threshold, stop
  
  // while loop stops when the overall score of the data item on the top of priority is larger or equal than threshold
  while(topKQueue.empty() || topKQueue.top().getOverallScore() < threshold)
  {
    for(int i=0; i<allLists.size(); i++)
	{
      int bp = bestPosition[i].bp;
	  DataItem tempDataItem = allLists[i][bp+1];
	  size_t tempId = tempDataItem.getId();
	  int tempOverallScore = 0; 

	  if(seenId.count(tempId) == 0)
	  {
        // for loop update bitArray for best position and calculate the overall score of a data item
	    for(int k=0; k<allLists.size(); k++)       
	    {
	  	  size_t position = dataSet.findPosition2(k, tempId);  // call the find postion function
		  tempOverallScore += allLists[k][position].getScore();
		  bestPosition[k].bitArray[position] = true;
	    }
	 
	    // maintain a priority queue to store top k result so far
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
		while(bestPosition[l].bp < (int)(allLists[l].size() - 1) && bestPosition[l].bitArray[bestPosition[l].bp+1] == true)
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
}

// function to clear all private data member
void BPA2::clear()
{
  TopKAlgorithm::clear();
  bestPosition.clear();
  while(!topKQueue.empty())
  {
  	topKQueue.pop();
  }
}
