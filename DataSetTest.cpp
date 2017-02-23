#include "DataItem.h"
#include "DataSet.h"
#include <iostream>

using namespace std;

int main()
{
  // testing DataItem class
  DataItem d0;
  d0.print();
  DataItem d1(1, 20, 1, 1);
  d1.print();
  d0 = d1;
  d0.print();
  DataItem d2(2, 30, 3, 2);
  d2.print();
  d2.update(2, 40, 2, 6);
  d2.print();
  DataItem d3(3, -10);
  cout << "Data item id: " << d3.getId() << endl;
  cout << "Data item score: " << d3.getScore() << endl;
  cout << "Data item position: " << d3.getPosition() << endl;
  cout << "Data item list number: " << d3.getListNum() << endl;
  d3.setId(4);
  d3.setScore(1000);
  d3.setPosition(10);
  d3.setListNum(9);
  d3.print();
  cout << endl;

  // testing DataSet class
  DataSet s1;
  s1.print();
  DataSet s2 = s1;
  s2.print();
  vector<int> scores1{200, 150, -1};
  s2.insert(scores1);
  s2.print();
  vector<int> scores2{22, 24, 19};
  s2.insert(scores2);
  s2.print();
  s2.remove(1);
  s2.print();
  s2.remove(2);
  s2.remove(3);
  s2.print();
  s2.insert(scores2);
  s2.print();
  s2.remove(10);
  s2.remove(18);
  s2.print();
  s2.remove(15);
  s2.remove(16);
  s2.remove(17);
  s2.print();
  s2.remove(18);
  s2.print();
  vector<int> scores3 = s2.checkScore(4);
  cout << "the scores for data item 4 is: " << endl;
  for(auto score: scores3)
    {
      cout << score << " ";
    }
  cout << endl;
  vector<int> scores4 = s2.checkScore(18);
  cout << "the scores for data item 18 is: " << endl;
  for(auto score: scores4)
    {
      cout << score << " ";
    }
  cout << endl;

  cout << endl << endl << endl;
  DataSet s3 = s2;
  s3.print();
  vector<int> scores5{24, 1, 10};
  s3.update(6, scores5);
  s3.print();
  
  return 0;
}
