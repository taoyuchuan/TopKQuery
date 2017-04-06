all: dataset.x bruteforce.x FA.x BPA.x BPA2.x compare.x TA.x

dataset.x: DataItem.cpp DataSet.cpp DataSetTest.cpp Makefile
	g++ -std=c++11 -O3 -o dataset.x DataItem.cpp DataSet.cpp DataSetTest.cpp

bruteforce.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp Makefile
	g++ -std=c++11 -O3 -o bruteforce.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp BruteForceTest.cpp

FA.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp FA.cpp FATest.cpp Makefile
	g++ -std=c++11 -O3 -o FA.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp FA.cpp FATest.cpp

TA.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp TA.cpp TATest.cpp Makefile
	g++ -std=c++11 -O3 -o TA.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp TA.cpp TATest.cpp

BPA.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA.cpp BPATest.cpp Makefile
	g++ -std=c++11 -O3 -o BPA.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA.cpp BPATest.cpp

BPA2.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA2.cpp BPA2Test.cpp Makefile
	g++ -std=c++11 -O3 -o BPA2.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BPA2.cpp BPA2Test.cpp

compare.x: DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp FA.cpp BPA.cpp BPA2.cpp compare.cpp TA.cpp Makefile
	g++ -std=c++11 -O3 -o compare.x DataItem.cpp DataSet.cpp DataOverallScore.cpp TopKAlgorithm.cpp BruteForce.cpp FA.cpp BPA.cpp BPA2.cpp compare.cpp TA.cpp

clean:
	rm -f *.o *.x core.*
