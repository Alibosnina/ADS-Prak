#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>
#include <queue>

namespace Graphsearch {
	
	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen G,
		* ab dem Knoten v aus und markiert alle besuchten
		* Knoten in marked.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]	 G			Graph
		* \param[in]	 v			Startknoten
		* \param[in/out] marked		Bereits besuchte Knoten
		* \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
		*/
	void DFS_recursive(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo)
	{
		/*
		 * TODO
		 */
		std::cout << " -> " << v;
		
		marked[v] = true;
		
		for (Edge w : G.getAdj(v))	// Für jeden Loop, speichert er das Objekt v aus der adjazensliste in w.
		{
			if (marked[w.other(v)] == false)
			{
				edgeTo[w.other(v)] = v;
				DFS_recursive(G, w.other(v), marked, edgeTo);
			}
		}
	}


	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		* Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
		*
		* \param[in]  G			Graph
		* \param[out] marked	Bereits besuchte Knoten
		* \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
		* \param[in]  v			Startknoten
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/

	bool DFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO
		 */

		edgeTo.assign(G.getV(),-1);
		marked.assign(G.getV(), false);
	
		DFS_recursive(G, v, marked, edgeTo);

		// überprüfung ob Graph zusamenhangend
		for (int i = 0; i < G.getV(); i++)
		{
			if (marked[i] == false)
			{
				return false;
			}
		}
		
		return true;
	}

	/**
		* Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]  G			Graph
		* \param[in]  v			Startknoten
		* \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
		* \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool BFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO:
		 */
		std::queue<int> q;
		q.push(v);

		edgeTo.assign(G.getV(), -1);
		marked.assign(G.getV(), false);

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (marked[x] == true)
			{
				continue;
			}

			std::cout << " -> " << x;
			
			marked[x] = true;

			for (Edge w : G[x])
			{
				if (marked[w.other(x)] == false)
				{
					if (edgeTo[w.other(x)] == -1)
					{
						edgeTo[w.other(x)] = x;
					}
					q.push(w.other(x));
				}
			}
		}
		// überprüfung ob Graph zusamenhangend
		for (int i = 0; i < G.getV(); i++)
		{
			if (marked[i] == false)
			{
				return false;
			}
		}
		
		return true;
	}
}
