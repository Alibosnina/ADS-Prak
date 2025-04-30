#include "KruskalMST.h"

/**
 * Erstellt einen MST zum Graph G mit dem Kruskal Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 */
KruskalMST::KruskalMST(EdgeWeightedGraph G)
{
	/*
	 * TODO
	 */
	this->treeID.assign(G.getV(), -1);

	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

	std::vector<Edge> edges = G.edges(); // liefert alle Kanten von G

	// Hier werden alle Kanten von G geliefert.
	for (int i = 0; i < edges.size(); i++)
	{
		pq.push(edges[i]);
	}

	// Anfangs ist jeder Knoten ein Baum für sich. Während zusammenfügung, achtet man auf Zyklen.
	for (int i = 0; i < G.getV(); i++)
	{
		treeID[i] = i;
	}

	while(!pq.empty())
	{
		Edge edg = pq.top();// Hole Kante mit geringstem Gewicht
		pq.pop(); // aus PQ

		int v = edg.either();
		int w = edg.other(v);

		// Wenn Knoten v und w zu unterschiedlichen Baumen gehort,
 		// konnen diese mit der Kante e ohne Zykel verbunden werden
		if (treeID[v] != treeID[w])
		{
			mst.push_back(edg); // Fuge Kante e zum MSP hinzu
			int treeid_w = treeID[w];
			for (int i = 0; i < G.getV(); i++) // BaumID von v und w
			{
				if (treeID[i] == treeid_w)// angleichen
				{
					treeID[i] = treeID[v];
				}
			}
		}
	}
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> KruskalMST::edges() const
{
	/*
	 * TODO
	 */
	return this->mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double KruskalMST::weight() const
{
	/*
	 * TODO
	 */
	double sum = 0.0;
	for (int i = 0; i < mst.size(); i++)
	{
		sum += mst[i].weight();
	}

	return sum;
}
