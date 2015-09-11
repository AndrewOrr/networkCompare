#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Network.h"
#include<string>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main(){
	string file;
	file= "test1.csv";
	Network net(file);
	//net.build_connections("C:\\Users\\Andrew\\Documents\\Visual Studio 2013\\Projects\\NetworkCompare\\NetworkCompare\\test1.csv");
	net.build_connections("D:\\Downloads\\test2.csv");
	//net.build_connections("C:\\Users\\Andrew\\Documents\\Visual Studio 2013\\Projects\\NetworkCompare\\NetworkCompare");
//	net.print();
//	net.print();
	net.build();
	//cout << net.gini[1][1];
//	net.print();
	float **compare;
	compare = new float*[net.nodes + 1];
	for (int i = 1; i <= net.nodes; ++i){
		compare[i] = new float[net.nodes + 1];
		//::cout << i;
	}
	for (int m = 1; m <= net.nodes; m++){
		for (int y = 1; y <= net.nodes; y++){
			compare[m][y] = 0;
		}
	}
//	cout << net.nodes;
	for (int node1 = 1; node1 <= net.nodes; node1++){
		for (int node2 = 1; node2 <= net.nodes; node2++){
			compare[node1][node2] = net.gini[node1][node2] - net.gini[node1][node2];
		}
	}
	cout << compare[1][1];

	cout << "blahljalskdjflskjdflksdjf";

	system("Pause");
}
