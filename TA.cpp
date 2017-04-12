#include <iostream>
#include <queue>
#include <iomanip>
#include "TA.h"

using namespace std;

TA::TA():TopKAlgorithm()
{
}

TA::TA(const DataSet& rhs_dataSet, const size_t& rhs_topK)
  :TopKAlgorithm(rhs_dataSet, rhs_topK)
{ 
}

TA::TA(const TA& rhs):TopKAlgorithm(rhs)
{
  topKQuery = rhs.topKQuery;
}

TA::TA(TA&& rhs):TopKAlgorithm(std::move(rhs))
{
  topKQuery = std::move(rhs.topKQuery);
}

TA& TA::operator=(const TA& rhs)
{
  if(this != &rhs)
    {
      TA copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

TA& TA::operator=(TA&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSet, rhs.dataSet);
      std::swap(topK, rhs.topK);
      std::swap(topKQuery, rhs.topKQuery);
    }
  return *this;
}

TA::~TA()
{
}


void TA::TASolution()
{
  size_t threshold = 0;
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }
  vector<vector<DataItem>> allLists = dataSet.getLists();
  priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> myPriorityQueue;
  for (int i = 0; i < dataSet.getDataSize(); i++)
  {
     for (int j =0; j < dataSet.getListSize(); j++)
     {
	   sequenceAccess += 1;
       DataItem tempDataItem = allLists[j][i];
       size_t tempId = tempDataItem.getId();
       threshold += tempDataItem.getScore();
       vector<int> allScore = dataSet.checkScore(tempId);
	   if(idTimes.count(tempId) == 0)
	   {
         DataOverallScore temp;
		 idTimes[tempId] = 1;
         temp.setId(tempId);
         temp.setOverallScore(sumVector(allScore));
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
     }
     if( myPriorityQueue.size() == topK && myPriorityQueue.top().getOverallScore() >= threshold)
       break;
     threshold = 0;
  }
  topKQuery.resize(topK);

  size_t index = topK - 1;
  while(!myPriorityQueue.empty())
  {
    topKQuery[index] = myPriorityQueue.top();
    myPriorityQueue.pop();
    index--;
  }

  randomAccess = sequenceAccess * (dataSet.getListSize() - 1);
  size_t cost = (size_t)log(dataSet.getDataSize());
  executionCost = sequenceAccess + cost * randomAccess;
}

void TA::clear()
{
  TopKAlgorithm::clear();
  topKQuery.clear();
}

