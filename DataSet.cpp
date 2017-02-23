/***********************************************************
Implementation for all member functions for class DataSet
***********************************************************/

#include "DataSet.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// dafault constructor
// suppose the number of data item is 15 and the number of sorted lists is 3
DataSet::DataSet()
{
  dataSize = 15;
  listSize = 3;
  maxId = 15;
  
  DataItem dataitem1{1, 30, 1, 1};
  DataItem dataitem2{4, 28, 2, 1};
  DataItem dataitem3{9, 27, 3, 1};
  DataItem dataitem4{3, 26, 4, 1};
  DataItem dataitem5{7, 25, 5, 1};
  DataItem dataitem6{8, 23, 6, 1};
  DataItem dataitem7{5, 17, 7, 1};
  DataItem dataitem8{6, 14, 8, 1};
  DataItem dataitem9{2, 11, 9, 1};
  DataItem dataitem10{11, 10, 10, 1};
  DataItem dataitem11{10, 8, 11, 1};
  DataItem dataitem12{13, 6, 12, 1};
  DataItem dataitem13{12, 4, 13, 1};
  DataItem dataitem14{15, 2, 14, 1};
  DataItem dataitem15{14, 1, 15, 1};
  // use constructor to establish sorted list
  vector<DataItem> temp1{dataitem1, dataitem2, dataitem3, dataitem4, dataitem5, dataitem6, dataitem7,
      dataitem8, dataitem9, dataitem10, dataitem11, dataitem12, dataitem13, dataitem14, dataitem15};
  lists.push_back(temp1);

  dataitem1.update(2, 28, 1, 2);
  dataitem2.update(6, 27, 2, 2);
  dataitem3.update(7, 25, 3, 2);
  dataitem4.update(5, 24, 4, 2);
  dataitem5.update(9, 23, 5, 2);
  dataitem6.update(1, 21, 6, 2);
  dataitem7.update(8, 20, 7, 2);
  dataitem8.update(3, 14, 8, 2);
  dataitem9.update(4, 13, 9, 2);
  dataitem10.update(14, 12, 10, 2);
  dataitem11.update(10, 10, 11, 2);
  dataitem12.update(12, 8, 12, 2);
  dataitem13.update(11, 6, 13, 2);
  dataitem14.update(15, 4, 14, 2);
  dataitem15.update(13, 2, 15, 2);
  // use constructor to establish sorted list
  vector<DataItem> temp2{dataitem1, dataitem2, dataitem3, dataitem4, dataitem5, dataitem6, dataitem7,
      dataitem8, dataitem9, dataitem10, dataitem11, dataitem12, dataitem13, dataitem14, dataitem15};
  lists.push_back(temp2);

  dataitem1.update(3, 30, 1, 3);
  dataitem2.update(5, 29, 2, 3);
  dataitem3.update(8, 28, 3, 3);
  dataitem4.update(4, 25, 4, 3);
  dataitem5.update(2, 24, 5, 3);
  dataitem6.update(6, 19, 6, 3);
  dataitem7.update(13, 15, 7, 3);
  dataitem8.update(1, 14, 8, 3);
  dataitem9.update(9, 12, 9, 3);
  dataitem10.update(7, 11, 10, 3);
  dataitem11.update(10, 10, 11, 3);
  dataitem12.update(12, 8, 12, 3);
  dataitem13.update(11, 6, 13, 3);
  dataitem14.update(15, 4, 14, 3);
  dataitem15.update(14, 2, 15, 3);
  // user constructor to establish sorted list
  vector<DataItem> temp3{dataitem1, dataitem2, dataitem3, dataitem4, dataitem5, dataitem6, dataitem7,
      dataitem8, dataitem9, dataitem10, dataitem11, dataitem12, dataitem13, dataitem14, dataitem15};
  lists.push_back(temp3);
}

// constructor for randomly generated scores
// the number of data itme and sorted lists are provided
// the score of each data item in each list will be randomly generated
DataSet::DataSet(const size_t& rhs_dataSize, const size_t& rhs_listSize)
{
  dataSize = rhs_dataSize;
  listSize = rhs_listSize;
  maxId = rhs_dataSize;
  generateDataSet();
}

// copy constructor
DataSet::DataSet(const DataSet& rhs)
{
  dataSize = rhs.dataSize;
  listSize = rhs.listSize;
  maxId = rhs.maxId;
  lists = rhs.lists;
}

// move constructor
DataSet::DataSet(DataSet&& rhs)
{
  dataSize = std::move(rhs.dataSize);
  listSize = std::move(rhs.listSize);
  maxId = std::move(rhs.maxId);
  lists = std::move(rhs.lists);
}

// move assignment operator
DataSet& DataSet::operator=(DataSet&& rhs)
{
  if(this != &rhs)
    {
      std::swap(dataSize, rhs.dataSize);
      std::swap(listSize, rhs.listSize);
      std::swap(maxId, rhs.maxId);
      std::swap(lists, rhs.lists);
    }
  return *this;
}

// copy assignment operator
DataSet& DataSet::operator=(const DataSet& rhs)
{
  if(this != &rhs)
    {
      DataSet copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// destructor
DataSet::~DataSet()
{
}

// re-construct the data set
// number of data item and sorted list are provided
// scores of each data item in each list will be randomly generated
void DataSet::reInit(const size_t& rhs_dataSize, const size_t& rhs_listSize)
{
  clear();                        // clear the data set
  dataSize = rhs_dataSize;
  listSize = rhs_listSize;
  generateDataSet();              // regenerate data set
}

// return the number of data item
size_t DataSet::getDataSize() const
{
  return dataSize;
}

// return the number of sorted lists
size_t DataSet::getListSize() const
{
  return listSize;
}

// return the max id for data items in lists
size_t DataSet::getMaxId() const
{
  return maxId;
}

// return all the sorted lists
vector<vector<DataItem>> DataSet::getLists() const
{
  return lists;
}

// set the number of data item
void DataSet::setDataSize(const size_t& rhs_dataSize)
{
  if(rhs_dataSize > 0)
    {
      dataSize = rhs_dataSize;
    }
  else
    {
      cout << "Invalud data size" << endl;
      return;
    }
}

// set the number of sorted lists
void DataSet::setListSize(const size_t& rhs_listSize)
{
  if(rhs_listSize > 0)
    {
      listSize = rhs_listSize;
    }
  else
    {
      cout << "Invalid list size" << endl;
      return;
    }
}

// set the value of max id in lists
void DataSet::setMaxId(const size_t& rhs_maxId)
{
  if(rhs_maxId > 0)
    {
      maxId = rhs_maxId;
    }
  else
    {
      cout << "Invalid max id" << endl;
      return;
    }
}

// set the sorted lists
void DataSet::setLists(const vector<vector<DataItem>>& rhs_lists)
{
  if(rhs_lists.size() == 0 || rhs_lists[0].size() == 0)
    {
      cout << "Empty lists" << endl;
      return;
    }
  lists = rhs_lists;
}

// insert a dataitem in all sorted lists
// the id of the data item will automatically increased
// the scores of the data item in all lists will be given
// this functions calls the insertPosition() function to find the correct position to insert
// after insertion, the positions of data items after the inserted item will be increased by 1
void DataSet::insert(const vector<int>& scores)
{
  if(scores.size() != listSize)                 // number of scores mush match number of lists
    {
      cout << "Invalid input for scores" << endl;
      return;
    }
	
  for(int i=0; i<listSize; i++)
    {
      DataItem temp;                    // temporary data item
      temp.setId(maxId + 1);            // the new inserted id is always maxId + 1
      temp.setScore(scores[i]);
      // call insertPosition() function to find the correct position for insertion
      size_t myPosition = insertPosition(lists[i], scores[i]);
      temp.setPosition(myPosition + 1);
      temp.setListNum(i + 1);
      lists[i].insert(lists[i].begin() + myPosition, temp); // insert the data item

      // the for loop undate the position value for the data item after the insertion position
      for(size_t j=myPosition+1; j<lists[i].size(); j++)
	{
	  size_t temp = lists[i][j].getPosition();
	  lists[i][j].setPosition(temp + 1);
	}
    }
  dataSize += 1;                   // update dataSIze
  maxId += 1;                      // update maxId
}

// remove a data item from all lists
// the id of data item that will be removed is provided
// this function calls the findPosition() function to get the correct position to remove the item
// after removing the itme, the positions of the item after the removed item will be decreased by 1
void DataSet::remove(const size_t& rhs_id)
{
  if(rhs_id == 0)                           // validate the id
    {
      cout << "Invalid id" << endl;
      return;
    }
  
  for(auto& oneList: lists)
    {
      // call findPosition() function to get the correct position of the item that will be removed
      size_t myPosition = findPosition(oneList, rhs_id);
      if(myPosition == oneList.size())            // check is the provided id exist
        {
          cout << "non exist id" << endl;
          return;
        }
      oneList.erase(oneList.begin() + myPosition);     // remvoe the data item

      // for loop update the position value of the data item after the position of removed data item
      for(size_t j=myPosition; j<oneList.size(); j++)
	{
	  size_t temp = oneList[j].getPosition();
	  oneList[j].setPosition(temp - 1);
	}
    }
  dataSize -= 1;                   // update dataSize
  if(maxId == rhs_id)              // update maxId if necessary
    {
      maxId = findMaxId();
    }
}

// modify the score of a data item
// the id of the item will be updated is provided
// this function calls the findPosition() function to get the correct position to update the item
void DataSet::update(const size_t& rhs_id, const vector<int>& scores)
{
  if(scores.size() != listSize)            // number of scores must match number of sorted lists
    {
      cout << "Invalid input for scores" << endl;
      return;
    }
  
  for(int i=0; i<lists.size(); i++)
    {
      // call findPosition() function to get the correct position of a data item
      size_t myPosition = findPosition(lists[i], rhs_id);
      if(myPosition == lists[i].size())      // check if the id exist
	{
	  cout << "Non exist id" << endl;
	  return;
	}
      lists[i][myPosition].setScore(scores[i]);  // update the scores
      // after updating the score, need to rearrange the lists to maintaince the sorted property

      // if the score of the updated item is larger than that of the item before it 
      if(myPosition > 0 && lists[i][myPosition] > lists[i][myPosition-1])
	{
	  for(int j=myPosition; j>=1; j--)
	    {
	      // swap two data item if their socre is reversed
	      if(lists[i][j] > lists[i][j-1])
		{
		  // swap their positon value  before swapping the item
		  size_t positionLeft = lists[i][j].getPosition();
		  size_t positionRight = lists[i][j-1].getPosition();
		  lists[i][j].setPosition(positionRight);
		  lists[i][j-1].setPosition(positionLeft);
		  // swap the data item
		  std::swap(lists[i][j], lists[i][j-1]);
		}
	    }
	}
       // if the score of the updated item is smaller than that of the item after it 
      if(myPosition < lists[i].size() - 1 && lists[i][myPosition+1] > lists[i][myPosition])
	{
	  for(int j=myPosition; j<lists[i].size()-1; j++)
	    {
	      // swap two data item if their socre is reversed
	      if(lists[i][j+1] > lists[i][j])
		{
		  // swap their positon value  before swapping the item
		  int positionLeft = lists[i][j+1].getPosition();
		  int positionRight = lists[i][j].getPosition();
		  lists[i][j+1].setPosition(positionRight);
		  lists[i][j].setPosition(positionLeft);
		  // swap the data item
		  std::swap(lists[i][j], lists[i][j+1]);
		}
	    }
	}
    }
}

// returns all scores of a data item in all lists
// the id of the item will be searched is provided
// this function calls the findPosition() function to get the correct position to search the item
vector<int> DataSet::checkScore(const size_t& rhs_id) const
{
  vector<int> scores;
  if(rhs_id == 0)
    {
      cout << "Invalid id" << endl;
      return scores;
    }
  for(auto& oneList: lists)
    {
      // call findPosition() function to get the correct position of the data item
      size_t myPosition = findPosition(oneList, rhs_id);
      if(myPosition == oneList.size())
        {
          cout << "non exist id" << endl;
          return scores;
        }
      scores.push_back(oneList[myPosition].getScore());
    }
  return scores;
}

// print out all the contents in the data set
// the format is provided in this function and can be modified as required
void DataSet::print() const
{
  if(dataSize == 0 || listSize == 0)
    {
      cout << "Empty data set" << endl;
      return;
    }
  cout << "There are " << dataSize << " data items" << endl;
  cout << "The max id is " << maxId << endl;
  cout << "There are " << listSize << " lists" << endl << endl; 
  int counter = 1;
  for(auto& oneList: lists)
    {
      cout << "list " << counter++ << ":" << endl;
      for(auto& oneItem: oneList)
	{
	  cout << std::left << std::setw(6) << oneItem.getId() << " "
	       << std::left << std::setw(6) << oneItem.getScore() << " "
	       << std::left << std::setw(6) << oneItem.getPosition() << " "
	       << std::left << std::setw(6) << oneItem.getListNum() << endl;
	}
      cout << endl;
    }
}

// remove all content in data set
void DataSet::clear()
{
  lists.clear();
  dataSize = 0;
  listSize = 0;
  maxId = 0;
}

// core function to construct data set with randomly generated socres
// is uses the value from dataSize as number of data items and listSize as number of sorted lists 
void DataSet::generateDataSet()
{
  // provide implementation here
}

// returns the maximum id of the data item in all lists
size_t DataSet::findMaxId() const
{
  if(dataSize == 0 || listSize == 0)
    {
      cout << "Data set is empty";
      return 0;
    }
  size_t res = 0;
  for(auto& oneItem: lists[0])
    {
      if(oneItem.getId() > res)
	{
	  res = oneItem.getId();
	}
    }
  return res;
}

// returns the position of data item in a sorted list
size_t DataSet::findPosition(const vector<DataItem>& oneList, const size_t& rhs_id) const
{
  // if the id is non-exist, return the end positon of the list
  if(rhs_id == 0)
    {
      cout << "Invalid id" << endl;
      return oneList.size();
    }
  for(int i=0; i<oneList.size(); i++)
    {
      if(oneList[i].getId() == rhs_id)     // if found, return the index
	{
	  return i;
	}
    }
  return oneList.size();
}

// returns the correct position of the data item that will be inserted
// the inserted item should be inserted before this item of the returned index
size_t DataSet::insertPosition(const vector<DataItem>& oneList, const int& rhs_score) const
{
  if(oneList.size() == 0)            // if list is empty
    {
      cout << "empty list" << endl;
      return 0;
    }
  if(oneList.back().getScore() >= rhs_score)   // if the score is the smallest, return the end position of list
    {
      return oneList.size();
    }

  // binary search to get the correct postion for insertion
  size_t start = 0;
  size_t end = oneList.size() - 1;
  while(start < end)
    {
      size_t mid = start + (end - start) / 2;
      if(oneList[mid].getScore() >= rhs_score)
	{
	  start = mid + 1;
	}
      else
	{
	  end = mid;
	}
    }
  return start;
}
