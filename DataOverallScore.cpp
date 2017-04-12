#include "DataOverallScore.h"
#include <iostream>

using namespace std;

// default constructor
DataOverallScore::DataOverallScore()
{
  id = 0;
  overallScore = 0;
}

// constructor with two parameters provided
// one for id, one for overall score
DataOverallScore::DataOverallScore(const size_t rhs_id, const int rhs_overallScore)
{
	if(rhs_id < 0 || rhs_overallScore < 0)
	{
		cout << "Invalid value for id or overall score" << endl;
		return;
	}

	id = rhs_id;
	overallScore = rhs_overallScore;
}

// copy constuctor
DataOverallScore::DataOverallScore(const DataOverallScore& rhs)
{
	id = rhs.id;
	overallScore = rhs.overallScore;
}

// move constructor
DataOverallScore::DataOverallScore(DataOverallScore&& rhs)
{
	id = std::move(rhs.id);
	overallScore = std::move(rhs.overallScore);
}

// copy assignment operator
DataOverallScore& DataOverallScore::operator=(const DataOverallScore& rhs)
{
	if(this != &rhs)
	{
		DataOverallScore copy = rhs;
		std::swap(*this, copy);
	}
	return *this;
}

// move assignment operator
DataOverallScore& DataOverallScore::operator=(DataOverallScore&& rhs)
{
	if(this != &rhs)
	{
		std::swap(id, rhs.id);
		std::swap(overallScore, rhs.overallScore);
	}
}

DataOverallScore::~DataOverallScore()
{
}

// return the id of data item
size_t DataOverallScore::getId() const
{
  return id;
}

// return the overall score of data item
int DataOverallScore::getOverallScore() const
{
  return overallScore;
}

// set the id of a data item
void DataOverallScore::setId(const size_t rhs_id)
{
  if(rhs_id > 0)
    {
      id = rhs_id;
    }
  else
    {
      cout << "Invalid value for id" << endl;
      return;
    }
}

void DataOverallScore::setOverallScore(const int rhs_overallScore)
{
  if(rhs_overallScore > 0)
    {
      overallScore = rhs_overallScore;
    }
  else
    {
      cout << "Invalid value for overallScore" << endl;
      return;
    }
}

// overload < rison operator for DataOverallScore 
// the comparison is first based on overall score
// if overall score is the same, the one with smaller id is considered as larger
bool DataOverallScore::operator<(const DataOverallScore& rhs) const
{
  if(overallScore < rhs.overallScore)
    {
      return true;
    }
  else if(overallScore == rhs.overallScore)
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

// overload > comparison operator
bool DataOverallScore::operator>(const DataOverallScore& rhs) const
{
  return !(*this < rhs);
}

// clear function
void DataOverallScore::clear()
{
	id = 0;
	overallScore = 0;
}
