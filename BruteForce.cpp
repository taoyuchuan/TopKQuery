/*************************************************************
Implementation for all member functions for class BruteForce
*************************************************************/

#include <BruteForce.h>

// default constructor
// calls the default constructor of class DataSet to initialize data set
// default value for top K is defined as 3
BruteForce::BruteForce()
{
	DataSet();
	topK = 3;
	bruteForceSolution();
}

// constructor
// data set and topK is provided as the parameter
BruteForce::BruteForce(const DataSet& rhs_dataSet, const size_t& rhs_topK)
{
	if(rhs_dataSet.dataSize < rhs_topK)
	{
		cout << "Incorrect value of topK";
		return;
	}
	dataSet = rhs_dataSet;
	topK = rhs_topK;
	bruteForceSolution();
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
		std::swap(*this, rhs);
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
	return *this
}

// destructor
BruteForce::~BruteForce()
{
}

// re-construct the data set and topK
// new data set and topK value are provided
void BruteForce::reInit(const DataSet& rhs_dataSet, const size_t& rhs_topK)
{
	if(rhs_dataSet.dataSize < rhs_topK)
	{
		cout << "Incorrect value of topK";
		return;
	}
	clear();
	dataSet = rhs_dataSet;
	topK = rhs_topK;
	bruteForceSolution();
}

// return the inside data set
DataSet& BruteForce::getDataSet() const
{
	return dataSet;
}

// return the value of topK
size_t BruteForce::getTopK() const
{
	return topK;
}

// return top k query result
vector<DataItem>& BruteForce::getTopKQuery() const
{
	return topKQuery;
}