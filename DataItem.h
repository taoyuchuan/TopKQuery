/*
*/

#ifndef DataItem_H
#define DataItem_H

class DataItem
{  
  public:
	// Default constructor
    DataItem();
	// 
    DataItem(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum);
	DataItem(const size_t& rhs.id, const int& rhs.score)
    DataItem(const DateItem& rhs);
    DataItem(DataItem&& rhs);
    DataItem& operator=(const DataItem& rhs);
    DataItem& operator=(DataItem&& rhs);
    ~DataItem();
    size_t getId() const;
    size_t getScore() const;
    size_t getPosition() const;
    size_t getListNum() const;
    void setId(const size_t& rhs_id);
    void setScore(const int& rhs_score);
    void setPosition(const size_t& rhs_position);
    void setListNum(const size_t& rhs_listNum);
    void print() const;
    void update(const size_t& rhs_id, const int& rhs_score, const size_t& rhs_position, const size_t& rhs_listNum);
  
  private:
    size_t id;
    int score;
    size_t position;
    size_t listNum;
};

#endif
