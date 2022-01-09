#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Graphe
{
private:
	map<int, vector<pair<int, int >>> matr;
	int sommets;
public:

	Graphe(int n);
	void insert(int s, int d, int dist);
	void Dijkstra(int s);
};

