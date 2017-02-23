/********************************
Implementation of DataItem class
********************************/

#include "DataItem.h"
#include <limits.h>
#include <iostream>

using namespace std;

// default constructor
// no actual data item is created
DataItem::DataItem()
{
  id = 0;
  score = INT_MIN;
  position = 0;
  listNum = 0;
}

// constructor with all parameters provided
// the provided will be validated before construct the data item
DataItem::DataItem(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum)
{
  if(rhs_id == 0 || rhs_score <= INT_MIN || rhs_score >= INT_MAX || rhs_position == 0 || rhs_listNum == 0)
    {
      cout << "Invalid input for data item" << endl;
      return;
    }
  id = rhs_id;
  score = rhs_score;
  position = rhs_position;
  listNum = rhs_listNum;
}

// constructor with only two parameters provided
// if calling this constructor, the position and listNum will be set as 0
// other assignment for position and listNum is required to constructor a valid data item
DataItem::DataItem(const size_t& rhs_id, const int& rhs_score)
{
  if(rhs_id == 0 || rhs_score <= INT_MIN || rhs_score >= INT_MAX)
    {
      cout << "Invalid input for data item" << endl;
      return;
    }
  id = rhs_id;
  score = rhs_score;
  position = 0;
  listNum = 0;
}

// copy constructor
DataItem::DataItem(const DataItem& rhs)
{
  id = rhs.id;
  score = rhs.score;
  position = rhs.position;
  listNum = rhs.listNum;
}

// move constructor
DataItem::DataItem(DataItem&& rhs)
{
  id = std::move(rhs.id);
  score = std::move(rhs.score);
  position = std::move(rhs.position);
  listNum = std::move(rhs.listNum);
}

// copy assignment operator
DataItem& DataItem::operator=(const DataItem& rhs)
{
  if(this != &rhs)
    {
      DataItem copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

// move assignment operator
DataItem& DataItem::operator=(DataItem&& rhs)
{
  if(this != &rhs)
    {
      std::swap(id, rhs.id);
      std::swap(score, rhs.score);
      std::swap(position, rhs.position);
      std::swap(listNum, rhs.listNum);
    }
  return *this;
}

// destructor
DataItem::~DataItem()
{
}

// return the id of a data item
size_t DataItem::getId() const
{
  return id;
}

// return the score of a data item
int DataItem::getScore() const
{
  return score;
}

// return the position of a data item in a list
size_t DataItem::getPosition() const
{
  return position;
}

// return the list number of a data item
size_t DataItem::getListNum() const
{
  return listNum;
}

// set the id of a data item
void DataItem::setId(const size_t& rhs_id)
{
  if(rhs_id > 0)
    {
      id = rhs_id;
    }
  else
    {
      cout << "Invalid id" << endl;
      return;
    }
}

// set the score of a data item
void DataItem::setScore(const int& rhs_score)
{
  if(rhs_score > INT_MIN && rhs_score < INT_MAX)
    {
      score = rhs_score;
    }
  else
    {
      cout << "Invalid score" << endl;
      return;
    }
}

// set the position of a data item in a list
void DataItem::setPosition(const size_t& rhs_position)
{
  if(rhs_position > 0)
    {
      position = rhs_position;
    }
  else
    {
      cout << "Invalid position" << endl;
      return;
    }
}

// set the list number of a data item
void DataItem::setListNum(const size_t& rhs_listNum)
{
  if(rhs_listNum > 0)
    {
      listNum = rhs_listNum;
    }
  else
    {
      cout << "Invalid list number" << endl;
      return;
    }
}

// print function
// print out the information of a data item in a specific format
void DataItem::print() const
{
  if(id == 0 || score == INT_MIN || position == 0 || listNum == 0)
    {
      cout << "No Valid Data Item" << endl;
      return;
    }
  cout << "The data item is: data item " << id << endl;
  cout << "data item id: " << id << endl;
  cout << "data item score: " << score << endl;
  cout << "data item position: " << position << endl;
  cout << "data item listNum: " << listNum << endl;
}

// update the information of a data item
// provided value will be validated before update
void DataItem::update(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum)
{
  if(rhs_id == 0 || rhs_score <= INT_MIN || rhs_score >= INT_MAX || rhs_position == 0 || rhs_listNum == 0)
    {
      cout << "Invalid input for data item" << endl;
      return;
    }
  id = rhs_id;
  score = rhs_score;
  position = rhs_position;
  listNum = rhs_listNum;
}

// overload < operator
// if the socre is the same, the smaller id will be considered as larger item
bool DataItem::operator<(const DataItem& rhs) const
{
  if(score < rhs.score)
    {
      return true;
    }
  else if(score == rhs.score)        // if score is the same, smaller id is larger
    {
      if(id > rhs.id)
	{
	  return true;
	}
    }
  else
    {
      return false;
    }
}

// overload > operator 
bool DataItem::operator>(const DataItem& rhs) const
{
  return !(*this < rhs);
}
