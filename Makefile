dataset.x: DataItem.cpp DataSet.cpp DataSetTest.cpp
	g++ -std=c++11 -o dataset.x DataItem.cpp DataSet.cpp DataSetTest.cpp

clean:
	rm -f *.o *.x core.*
