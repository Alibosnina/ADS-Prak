#include <assert.h>
#include "DijkstraSP.h"
#include <cfloat>
#include <algorithm>


/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	/*
	 * TODO
	 */

	for (DirectedEdge edge : G[v])// adjazente Knoten zum Knoten v
	{
		int w = edge.to();
		if (distToVect[w] > distToVect[v] + edge.weight())
		{
			distToVect[w] = distToVect[v] + edge.weight();
			edgeTo[w] = edge;

			if (pq.contains(w))
			{
				pq.change(w, distToVect[w]);
			}
			else
			{
				pq.push(w, distToVect[w]);
			}
		}
	}
}


/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	/*
	 * TODO
	 */
	
	distToVect.assign(G.getV(), -1);

	for (int v = 0; v < G.getV(); v++)
	{
		distToVect[v] = DBL_MAX; // Wir wählen den größten wer der von Double aufgenommen werden kann, um bei günstigeren Wegen zu aktualisieren.
	}

	distToVect[s] = 0.0;
	pq.push(s, 0.0);

	while (!pq.empty())
	{
		int minknoten = pq.top().value;
		pq.pop();
		// Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
		relax(G, minknoten);
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect[v] != -1;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v) 
{
	/*
	 * TODO
	 */



	assert(("Es gibt keinen Pfad von s nach v!", this->hasPathTo(v)));
		//assert(("Vertex is out of bounds!", false));


	std::vector<DirectedEdge> path;
		DirectedEdge e = edgeTo[v];
		while (true)
		{
			path.push_back(e);
			if (edgeTo.count(e.from()) > 0)
			{
				e = edgeTo[e.from()];
			}
			else
			{
				break;
			}
		}

		std::reverse(path.begin(), path.end());

		return path;
	}


