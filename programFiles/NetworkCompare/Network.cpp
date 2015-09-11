#define _CRT_SECURE_NO_DEPRECATE
#include "Network.h"
#include<string>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <regex>
#include "hungarian.h"
#include <stdio.h>
#include <windows.h>
using namespace std;
float **gini;
int nodes;
Network::Network(string file){
	//define all important variables
	double **network; //define the starting array
	int node1 = 0;
	int node2 = 0;
	int numFiles = 1;
	int edges = 0;
	nodes = 0;
	double **cNet;
	int DURATION = 2;
	

	/*
	double **cNet;
	//int Network::WIDTH = 4;
	//	int HEIGHT = 2991;
	ofstream outdata;
	ifstream in2;
	string baseFile = "C:\\Users\\Andrew\\Documents\\Visual Studio 2013\\Projects\\NetworkCompare\\NetworkCompare\\";
	int numFiles = 1;
	in2.open("C:\\Users\\Andrew\\Documents\\Visual Studio 2013\\Projects\\NetworkCompare\\NetworkCompare\\files.txt");
	for (int file = 0; file < numFiles; file++){
	string filePath;
	string fileName;
	in2 >> fileName;
	//std::cout << fileName;
	ifstream indata;
	filePath = baseFile + fileName;
	indata.open(filePath);
	regex integer("[_[:alnum:]][[:digit:]]+,[_[:alnum:]][[:digit:]]+");
	int edges = 0;
	int nodes = 0;
	for (int i = 0; i < 10000; i++){
	string cell1;
	indata >> cell1;
	string estring1 = "";
	string estring2 = "";
	if (regex_match(cell1, integer)){
	edges++;
	for (int j = 0; j < (cell1.length()); j++){
	int mid = cell1.find(",");
	if (j < mid){
	if (cell1[j] != 'a'){
	estring1 = estring1 + cell1[j];
	}

	}

	else{
	if (cell1[j + 1] != 'a'){
	estring2 = estring2 + cell1[j + 1];
	}
	}
	}
	if (atoi(estring2.c_str()) > nodes){
	nodes = atoi(estring2.c_str());
	}
	if (atoi(estring1.c_str()) > nodes){
	nodes = atoi(estring1.c_str());
	}
	}
	else{
	break;
	}
	}
	//std::cout << nodes;
	cNet = new double*[nodes];
	for (int i = 1; i <= nodes; ++i){
	cNet[i] = new double[nodes];
	//::cout << i;
	}

	for (int m = 1; m <= nodes; m++){
	for (int y = 1; y <= nodes; y++){
	cNet[m][y] = 0;
	}
	}
	indata.clear();
	indata.seekg(0, ios::beg);

	for (int i = 0; i < edges; i++){
	string cell1;
	indata >> cell1;
	string estring1 = "";
	string estring2 = "";
	if (regex_match(cell1, integer)){
	int mid = cell1.find(",");
	int node1;
	int node2;
	for (int j = 0; j < (cell1.length()); j++){

	if (j < mid){
	if (cell1[j] != 'a'){
	estring1 = estring1 + cell1[j];
	}

	}

	else{
	if (cell1[j + 1] != 'a'){
	estring2 = estring2 + cell1[j + 1];
	}
	}
	}
	//cout << cell1[mid-1];


	/*
	std::cout << typeid(atoi(estring2.c_str())).name();
	std::cout << "\n";

	cNet[atoi(estring2.c_str())][atoi(estring1.c_str())] = 1;
	//std::cout << cNet[atoi(estring2.c_str())][atoi(estring1.c_str())];
	}
	else{
	std::cout << "no";
	}

	}
	//	std::cout << cNet[nodes-1][nodes-1];


	for (int m = 1; m <= nodes; m++){
	std::cout << "\n";
	for (int y = 1; y <= nodes; y++){
	std::cout << "\t";
	std::cout << cNet[m][y];
	}
	}
	}
	in2.clear();
	in2.close();

	}
	*/
}

	Network::~Network()
	{
	}
	void Network::print()
	{
		//std::cout << WIDTH;
		//std::cout << nodes;
		//std::cout << edges;
		for (int m = 1; m <= nodes; m++){
			std::cout << "\n";
			for (int y = 1; y <= nodes; y++){
				std::cout << " ";
				std::cout << cNet[m][y];
			}
		}
		
		
		
		return;
	}
	void Network::build_connections(string filepath){
		regex integer("[_[:alnum:]][[:digit:]]+,[_[:alnum:]][[:digit:]]+");
		string filePath = filepath; // full file-path
		count(filepath);
		/*
		gini = new float*[DURATION+1];
		for (int i = 1; i <= DURATION; ++i){
			cNet[i] = new double[nodes + 1];
			//::cout << i;
		}
		for (int m = 1; m <= DURATION; m++){
			for (int y = 1; y <= nodes; y++){
				gini[m][y] = 0;
			}
		}
		
		*/
		cNet = new double*[nodes+1];
	for (int i = 1; i <= nodes; ++i){
		cNet[i] = new double[nodes+1];
		//::cout << i;
	}
	for (int m = 1; m <= nodes; m++){
		for (int y = 1; y <= nodes; y++){
			cNet[m][y]=0;
		}
	}
	indata.open(filePath);
	indata.clear();
	indata.seekg(0, ios::beg);

	for (int i = 0; i < edges; i++){
		string cell1; 
		indata >> cell1;
		string estring1 = "";
		string estring2 = "";
		if (regex_match(cell1, integer)){
			int mid = cell1.find(",");
			int node1;
			int node2;
			for (int j = 0; j<(cell1.length()) ; j++){
				
				if (j<mid){
					if (cell1[j] != 'a'){
						estring1 = estring1 + cell1[j];
					}
					
				}
				
				else{
					if (cell1[j+1] != 'a'){
						estring2 = estring2 + cell1[j+1];
					}
				}
			}
			cNet[atoi(estring1.c_str())][atoi(estring2.c_str())] = 1;
			//Currently for directed, add another fir un-directed 
			//cNet[atoi(estring1.c_str())][atoi(estring2.c_str())] = 1;
		}
	}
	indata.close();
	
	/*
			for (int m = 1; m <= nodes; m++){
		std::cout << "\n";
		for (int y = 1; y <= nodes; y++){
			std::cout << " ";
			std::cout << cNet[m][y];
		}
	}
	*/
		
	}
	void Network::count(string filepath)//count finds the number of nodes and the number of edges
	{
		regex integer("[_[:alnum:]][[:digit:]]+,[_[:alnum:]][[:digit:]]+");
		ofstream outdata;//define nan instream
		string filePath = filepath; // full file-path
		//	ifstream in2;//define filename input
		int numFiles = 1;//need to know how many files we want. Not sure if we want this. 
		ifstream indata; //this will hold our input data
		indata.open(filePath);


		//this code currently works. This finds the largest node... yada yada
		for (int i = 0; i < 100000; i++){
			string cell1;
			indata >> cell1;
			string estring1 = "";
			string estring2 = "";
			if (regex_match(cell1, integer)){
				edges++;
				for (int j = 0; j < (cell1.length()); j++){
					int mid = cell1.find(",");
					if (j < mid){
						if (cell1[j] != 'a'){
							estring1 = estring1 + cell1[j];
						}

					}

					else{
						if (cell1[j + 1] != 'a'){
							estring2 = estring2 + cell1[j + 1];
						}
					}
				}
				if (atoi(estring2.c_str()) > nodes){
					nodes = atoi(estring2.c_str());
				}
				if (atoi(estring1.c_str()) > nodes){
					nodes = atoi(estring1.c_str());
				}
			}
			else{
				break;
			}
		}
		indata.close();
		/*
		FILE * pFile;
		//list of filenames

		//Construct Path String

		//this doesn't seem to work.
		string test;
		fileName = "test.text";
		filePath = baseFile + fileName; //combine filename and path
		const char * charFile = filePath.c_str();
		std::cout << charFile;
		pFile = fopen("C:\\Users\\Andrew\\Documents\\Visual Studio 2013\\Projects\\NetworkCompare\\NetworkCompare\\testing.txt", "r");
		if (pFile != 0){
		fscanf(pfile, "%c\n", &test);
		}
		fclose(pFile);
		*/
		//fclose(pFile);
		//(pFile, "a%d,a%d", node1, node2);
		//fprint
		//std::cout << node1;
		//std::cout << "\n";
	}
	void Network::build()
	{
		int DURATION = 2;
		int plentyWater = 0;
		gini = new float*[nodes + 1];
		for (int i = 1; i <= nodes; ++i){
			gini[i] = new float[DURATION + 1];
			//::cout << i;
		}
		for (int m = 1; m <= nodes; m++){
			for (int y = 1; y <= DURATION; y++){
				gini[m][y] = 0;
			}
		}

		//define some nice flow arrays to be used later!
		//int startingNode = 0;
		float *flowIn = new float[nodes+1];
		float *flowOut = new float[nodes + 1];
		float *flowNet = new float[nodes + 1];
		float *totEdges = new float[nodes + 1];
		float *flowInNew = new float[nodes + 1];
		float *current = new float[nodes + 1];
		//make sure they aren't filled with crap
		for (int i = 1; i <= nodes; i++){
			flowIn[i] = 0.0;
			flowInNew[i] = 0.0;
			flowOut[i] = 0.0;
			flowNet[i] = 0.0;
			totEdges[i] = 0.0;
			current[i] = 0.0;
		}

		for (int node = 1; node <= nodes; node++){
			for (int connectedNode = 1; connectedNode <= nodes; connectedNode++){
				totEdges[node] = cNet[node][connectedNode] + totEdges[node];
			}
		}
		

		for (int startingNode = 1; startingNode <= (nodes); startingNode++){
			current[startingNode] = 10.0;
			//For each duration
			//std::cout << " __________________________________________________________________ ";
			//std::cout << "\n";
			//std::cout << "Starting Node: ";
			//std::cout << startingNode;
			//std::cout << "\n";
			//Now we have a loop to go through each timestep
			for (int timeStep = 1; timeStep <= DURATION; ++timeStep){
				//flow changes when there is inflow. If flow of node!=0 then we check to see if the flow out is 0....? Not sure how this works. 
				//flow out = edgeweight if edgeweights<flowin

				//each time we start a timestep we want to have a clean slate for everything but current. Current will be used to calculate flowout later on. 

				for (int i = 1; i <= nodes; i++){
					flowInNew[i] = 0.0;
					flowOut[i] = 0.0;
					flowNet[i] = 0.0;
				}
				//current[startingNode] = 10.0;
				plentyWater = 0;
				//for every node, calculate the flow
				for (int node = 1; node <= nodes; node++){
					plentyWater = 0;
					//if the node has water, shown in current[node] then  it will produce some outflow

					if (current[node] != 0){

						//we can only have 2 kinds of flow. Either there is more edgeweight than water in the node or there is more water coming in than out. 

						if (current[node] >= totEdges[node]){

							plentyWater = 1;

							//in the case that we have enough water to quench all edges the outflow of the node is equal to the edge weights.

							flowOut[node] = totEdges[node];

							//we will then see a change in the total amount of water inside of the node.

							current[node] = current[node] - flowOut[node];
						}

						//in the case that there is not enough water to quench the edges but there is SOME water the total outflow of the node will be equal all the water in the node and the node will be emptied

						else{

							flowOut[node] = current[node];
							current[node] = 0;
						}//end of if else has water for flowout

						//at this point we have updated all outflow and adjusted current to reflect it. We now need to find where that water goes to and add it to the correct node

						//we go through each node and check the edge weight between it and the node we are on

						for (int connectedNode = 1; connectedNode <= nodes; connectedNode++){
							if (plentyWater == 1){

								flowInNew[connectedNode] = cNet[node][connectedNode] * 1.0 + flowInNew[connectedNode] * 1.0;

							}

							//if this is not the case then the inflow is equal to the total outflow of the node multiplied by the ratio of the relevant node edge and the total edges at a node
							else{
								flowInNew[connectedNode] = (flowOut[node] / totEdges[node])*cNet[node][connectedNode] * 1.0 + flowInNew[connectedNode] * 1.0;
								//std::cout << flowInNew[connectedNode];
							}
						}
					}	
	
				}//end of flow calculation for each node

				// we need to combine accounts for the system
				for (int node = 1; node <= nodes; node++){

					//we  have already accounted for the loss of flow to calculate the total outflow, we just need to add new inflow to get this going

					current[node] = current[node] + flowInNew[node];
					flowIn[node] = flowIn[node] + flowInNew[node];
					//cout << flowIn[node];
					////cout << "\t";
					geniCalc(flowIn, node, timeStep, startingNode);
					//cout << " ";
				//	cout << current[node];
				}
			//	cout << "\n";
			}//End of Timestep

			for (int i = 1; i <= nodes; i++){
				flowIn[i] = 0.0;
				flowInNew[i] = 0.0;
				flowOut[i] = 0.0;
				flowNet[i] = 0.0;
				totEdges[i] = 0.0;
				current[i] = 0.0;
			}
		}//end of node changing

		/*
			cout << "GINI";
		for (int m = 1; m <= nodes; m++){
			std::cout << "\n";
			for (int y = 1; y <= DURATION; y++){
				std::cout << " ";
				std::cout << gini[m][y];
			}
		}
		
		*/

		
		/*
		for (int y = 1; y <= nodes; y++){
			std::cout << " ";
			std::cout << flowIn[y];
		}
		*/
		


		delete[] flowIn;
		delete[] flowOut;
		delete[] flowNet;
		delete[] totEdges;
		delete[] flowInNew;
		delete[] current;
	}
	void Network::geniCalc(float *flowIn, int n, int timeStep, int startingNode)
	{

		//cout << timeStep;
		std::sort(flowIn+1, flowIn + n +1);


		float *CDF = new float[n + 1];
		float G = 0;
		for (int i = 0; i <= n; i++){
			CDF[i] = 0.0;
		}
	
		for (int node = 0; node <= n ; node++){
			if (node == 0){
				CDF[node] = 0;

				//G = G + CDF[node];
			}
			else if (node == 1){
				CDF[node] = flowIn[node];
				G = G + CDF[node];
			}
			else if (node == n){
				CDF[node] = (CDF[node - 1] + flowIn[node]) / 2;
				G = G + CDF[node];
			}
			else{
				CDF[node] = CDF[node - 1] + flowIn[node];
				G = G + CDF[node];
			}
		}
		
		
		gini[startingNode][timeStep] = 1 - (G / n) /(1 +(0.5*(2 * CDF[n])));
		//cout << gini[startingNode][timeStep];
		//cout << "\n";
		delete[] CDF;

	}
	float Network::flow()
	{
		float a = 0;
		return a;
	}
