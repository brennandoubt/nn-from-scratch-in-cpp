all:

	g++ NeuralNetwork.h NeuralNetworkTests.cpp

run:
	./a.out
	#./nntests

try: all run