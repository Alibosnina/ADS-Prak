#include "PrimMST.h"


/**
 * Erstellt einen MST zum Graph G mit dem Prim Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  s		Startknoten
 */
PrimMST::PrimMST(EdgeWeightedGraph G, int s)
{
	/*
	 * TODO
	 */
	this->marked.assign(G.getV(), false);

	this->visit(G, s); // Beginnen beim Startknoten.

	while (!this->pq.empty())
	{
		Edge edg = pq.top(); // Hole Kante mit geringstem Gewicht
		pq.pop(); // aus PQ

		int v = edg.either();
		int w = edg.other(v);
		// Überspringen, falls beide Knoten im Baum markiert sind
		if (this->marked[v] && this->marked[w])  // Zykel-Detektion
		{
			continue;
		}

		mst.push_back(edg);// Fuge Kante e zum MSP hinzu
		 // Knoten v oder w zum MSP hinzufugen
		if (!this->marked[v])
		{
			visit(G, v);
		}

		if (!this->marked[w])
		{
			visit(G, w);
		}
	}
}

/**
 * Markiert Knoten v im Graph G als markiert und fuegt alle Nachbarn zur pq hinzu
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  v		Knoten im Graph G
 */
void PrimMST::visit(EdgeWeightedGraph G, int v)
{
	/*
	 * TODO
	 */
	this->marked[v] = true; // Markiere Knoten v als besucht
	std::vector<Edge> edges = G[v];

	for (int i = 0; i < edges.size(); i++)
	{
		//alle Kanten von v zu (noch nicht besuchten) Knoten in die PQ ablege 
		if (!marked[edges[i].other(v)])
		{
			pq.push(edges[i]);
		}
	}
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> PrimMST::edges() const
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
double PrimMST::weight() const
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
