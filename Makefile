dataset.x: DataItem.cpp DataSet.cpp DataSetTest.cpp Makefile
	g++ -std=c++11 -O3 -o dataset.x DataItem.cpp DataSet.cpp DataSetTest.cpp

clean:
	rm -f *.o *.x core.*
