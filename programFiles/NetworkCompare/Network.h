#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include<string>
#include <fstream>
#include "hungarian.h"

using namespace std;
class Network
{
	int WIDTH;
public:
	Network(string file);
	~Network();
	void print();
	void build();
	void build_connections(string filepath);
	void count(string filepath);
	void geniCalc(float *flowIn, int node, int timeStep, int startingNode);
	float flow();
	string fileNames;
	int size;
	ifstream indata;
	//ofstream outdata;
	string cell1;
	int nodes;
	int edges;
	int node1;
	int node2;
	float **fNet;
	int DURATION;
	float **gini;
	float *CDF;
private:
	double **cNet;
	float a;
	int	HEIGHT;
	//float** testA;
	FILE * pfile;
	int plentyWater = 0;

};

