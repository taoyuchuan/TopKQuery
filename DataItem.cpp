#inlcude <DataItem.h>
#include <limits.h>

DataItem::DataItem()
{
  id = 0;
  score = INT_MIN;
  position = 0;
  listNum = 0;
}

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

DataItem::DataItem(const size_t& rhs.id, const int& rhs.score)
{
	if(rhs_id == 0 || rhs_score <= INT_MIN || rhs_score >= INT_MAX)
	  {
		cout << "Invalid input for data item" << endl;
		return;
	  }
	id = rhs.id;
	score = rhs.score;
	position = 0;
	listNum = 0;
}

DataItem::DataItem(const DataItem& rhs)
{
  id = rhs.id;
  score = rhs.score;
  position = rhs.position;
  listNum = rhs.listNum;
}

DataItem::DataItem(DataItem&& rhs)
{
  id = std::move(rhs.id);
  score = std::move(rhs.score);
  position = std::move(rhs.position);
  listNum = std::move(rhs.listNum);
}

DataItem& DataItem::operator=(const DataItem& rhs)
{
  if(this != &rhs)
    {
      DataItem copy = rhs;
      std::swap(*this, copy);
    }
  return *this;
}

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

DataItem::~DataItem()
{
}

size_t DataItem::getId() const
{
  return id;
}

int DataItem::getScore() const
{
  return score;
}

size_t DataItem::getPosition() const
{
  return position;
}

size_t DataItem::getListNum() const
{
  return listNum;
}

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

void DataItem::setScore(const int& rhs_score)
{
  if(rhs_score > INT_MIN && rhs_score < INT_MAX)
    {
      score = rhs.score;
    }
  else
    {
	  cout << "Invalid score" << endl;
	  return;
    }
}

void DataItem::setPosition(const size_t& rhs_position)
{
  if(rhs_position > 0)
    {
      position = rhs.position;
    }
  else
	{
	  cout << "Invalid position" << endl;
	  return;
	}
}

void DataItem::setListNum(const size_t& rhs_listNum)
{
  if(rhs_listNum > 0)
    {
      listNum = rhs.listNum;
    }
  else
	{
	  cout << "Invalid list number" << endl;
	  return;
	}
}

void DataItem::print() const
{
  if(id == 0 || score == INT_MIN || position == 0 || listNum == 0)
    {
      cout << "No Valid Data Item" << endl;
      return;
    }
  cout << "The data item is: " << endl;
  cout << "data item id: " << id << endl;
  cout << "data item score: " << score << endl;
  cout << "data item position: " << position << endl;
  cout << "data item listNum: " << listNum << endl;
}

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
