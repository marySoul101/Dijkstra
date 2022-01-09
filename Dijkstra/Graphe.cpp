#include "Graphe.h"

Graphe::Graphe(int n)
{
	this->sommets = n;
}

void Graphe::insert(int s, int d, int dist)
{
	this->matr[s].push_back(make_pair(d, dist));
}

void Graphe::Dijkstra(int s)
{
	int* visited=new int[this->sommets];
	int* distances = new int[this->sommets];
	for (int i = 0; i < this->sommets; i++) {
		visited[i] = -1;
		distances[i]=50;
	}
	distances[s] = 0;
	priority_queue<pair<int, int>> Noeuds;
	Noeuds.push(make_pair(s, 0));
	while (!Noeuds.empty()) {
		int sommet = Noeuds.top().first;
		int distance = Noeuds.top().second;
		Noeuds.pop();
		
			vector<pair<int, int>> next = this->matr[sommet];
			for (auto it : next) {
				if (distance + it.second < distances[it.first]) {
					distances[it.first] = distance + it.second;
					visited[it.first] = sommet;
					Noeuds.push(make_pair(it.first, distances[it.first]));
				}
			}
		
	}
	int i = this->sommets-1;
	cout << "le plus court chemin dans l'ordre inverse \n";
	while (visited[i] != -1) {
		cout << i << "-->" << visited[i] << " (distance = " << distances[i] << ") " <<"\t";
		i = visited[i];
	} 
}
