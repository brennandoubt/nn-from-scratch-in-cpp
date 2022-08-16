all:

	g++-11 NeuralNetwork.h NeuralNetworkTests.cpp

run:
	./a.out
	#./nntests

try: all run