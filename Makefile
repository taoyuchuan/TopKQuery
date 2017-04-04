all: dataset.x bruteforce.x FA.x BPA.x compare.x

dataset.x: DataItem.cpp DataSet.cpp DataSetTest.cpp Makefile
	g++ -std=c++11 -O3 -o dataset.x DataItem.cpp DataSet.cpp DataSetTest.cpp

bruteforce.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp Makefile
	g++ -std=c++11 -O3 -o bruteforce.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp

FA.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp FA.cpp FATest.cpp Makefile
	g++ -std=c++11 -O3 -o FA.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp FA.cpp FATest.cpp

BPA.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA.cpp BPATest.cpp Makefile
	g++ -std=c++11 -O3 -o BPA.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA.cpp BPATest.cpp

compare.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp FA.cpp BPA.cpp compare.cpp Makefile
	g++ -std=c++11 -O3 -o compare.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp FA.cpp BPA.cpp compare.cpp

clean:
	rm -f *.o *.x core.*
