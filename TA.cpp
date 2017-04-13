/**************************************************************
Implementation for all member functions for class FA algorithm
**************************************************************/

#include <iostream>
#include <queue>
#include <iomanip>
#include "TA.h"

using namespace std;


// default constructor
// calls the base class default constructor to initialize data set
// default value for top K is defined as 3
TA::TA():TopKAlgorithm()
{
}

// constructor
// call base class constructor
// data set and topK is provided as the parameter
TA::TA(const DataSet& rhs_dataSet, const size_t& rhs_topK)
  :TopKAlgorithm(rhs_dataSet, rhs_topK)
{ 
}

//copy constructor
TA::TA(const TA& rhs):TopKAlgorithm(rhs)
{
  topKQuery = rhs.topKQuery;
}

//move constructor
TA::TA(TA&& rhs):TopKAlgorithm(std::move(rhs))
{
  topKQuery = std::move(rhs.topKQuery);
}

//copy assignemnt constructor
TA& TA::operator=(const TA& rhs)
{
  if(this != &rhs)
    {
      TA copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

//move assignment consctor
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

//destructor
TA::~TA()
{
}

// return the times of data items seen in all lists
unordered_map<size_t, size_t> TA::getIdTimes() const
{
  return idTimes;
}

// set the value of idTimes
void TA::setIdTimes(const unordered_map<size_t, size_t>& rhs_idTimes)
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

// the core function to perform the FA algorithm for top-k query
// the top-K query result will be stored in topKQuery vector
// the result will contain the id and overall score of top-k data item
void TA::TASolution()
{
  size_t threshold = 0;
  //check the input value
  if(dataSet.getDataSize() <= 0 || topK <= 0)
    {
      cout << "Invalid data set or invalid topK value" << endl;
      return;
    }
  vector<vector<DataItem>> allLists = dataSet.getLists();
  priority_queue<DataOverallScore, vector<DataOverallScore>, greater<DataOverallScore>> myPriorityQueue;
  //do the sequencial accesses to all the lists
  for (int i = 0; i < dataSet.getDataSize(); i++)
  {
     //do the parallel accesses to all the lists
     for (int j =0; j < dataSet.getListSize(); j++)
     {
      sequenceAccess += 1;
       DataItem tempDataItem = allLists[j][i];
       size_t tempId = tempDataItem.getId();
       threshold += tempDataItem.getScore();
      //access all the other lists to get all the local scores of this data item
       vector<int> allScore = dataSet.checkScore(tempId);
       //if this data item is first time seen
	   if(idTimes.count(tempId) == 0)
	   {
	//calculate its overall score and compare with the "top" in PriorityQueue
	//to decide if push or not
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
     //stop when priorityQueue is full and the smallest value in prioirtyQueue is smaller than or equal to the threashold
     if( myPriorityQueue.size() == topK && myPriorityQueue.top().getOverallScore() >= threshold)
       break;
     threshold = 0;
  }

 // store the result to topKQuery
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

//clear the TA class
void TA::clear()
{
  TopKAlgorithm::clear();
  topKQuery.clear();
  idTimes.clear();
}

