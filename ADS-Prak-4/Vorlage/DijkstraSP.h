#pragma once
#include <vector>
#include <queue>
#include <map>
#include "EdgeWeightedDigraph.h"
#include "PriorityQueue.h"

class DijkstraSP
{
private:
	std::map<int, DirectedEdge> edgeTo;	// nächste kante, die die geringsten nächten kosten zu s hat	 
	std::vector<double> distToVect;	// Gewicht der Pfade von s		
	Utils::PriorityQueue<int> pq;
	void relax(EdgeWeightedDigraph G, int v);	

public:
	DijkstraSP() {};
	DijkstraSP(EdgeWeightedDigraph G, int s);
	double distTo(int v) const;					// Abstaende vom Startvertex zu v
	bool hasPathTo(int v) const;				// ueberprueft die existens eines Pfades
	std::vector<DirectedEdge> pathTo(int v) ;	// Kanten des kuerzsesten Weges
};

