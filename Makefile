all: dataset.x bruteforce.x

dataset.x: DataItem.cpp DataSet.cpp DataSetTest.cpp Makefile
	g++ -std=c++11 -O3 -o dataset.x DataItem.cpp DataSet.cpp DataSetTest.cpp

bruteforce.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp Makefile
	g++ -std=c++11 -O3 -o bruteforce.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp

clean:
	rm -f *.o *.x core.*
