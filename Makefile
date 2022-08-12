all:

	g++ NeuralNetwork.cpp NeuralNetworkTests.cpp -o nntests

run:

	./nntests

try: all run