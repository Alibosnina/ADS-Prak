#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"
using namespace std;

void print_menu()
{
    
    cout <<"=========================" << endl
        << " ADS-Praktikum 5: Graphen " << endl
        << "=========================" << endl
        << "1) Graph Einlesen" << endl
			<< "2) Tiefensuche" << endl
			<< "3) Breitensuche" << endl
			<< "4) MST nach Prim (Eingaben: Startknoten)" << endl
			<< "5) MST nach Kruskal" << endl
			<< "6) Kurzerste Wege nach Djikstra (Eingabe: Startknoten)" << endl
			<< "7) Ausgabe der Adjazenzliste" << endl
			<< "8) Kante loeschen" << endl
			<< "9) Kante hinzufuegen" << endl
			<< "10) Program beenden" << endl
			<< "Weiter mit beliebiger Eingabe ..." << endl
			<< "?>";
}


int main() {
	// Starte Unit-Tests
	Catch::Session().run();
	
	
	EdgeWeightedDigraph dGraph("graph1.txt");
	EdgeWeightedGraph Graph("graph1.txt");
	int eingabe ;
	

	

	do
	{
		print_menu();
		
		cin >> eingabe;

		if (eingabe == 1)
		{
			int lesen;
			
			cout << "Bitte waehlen Sie ein Graph aus: " << endl;
			cout << "	1.Graph" << endl
				 << "	2.Graph" << endl
				 << "	3.Graph" << endl
				 << "?>";
			cin >> lesen;
			

			if (lesen == 1)
			{
				dGraph = EdgeWeightedDigraph("graph1.txt");
				Graph = EdgeWeightedGraph("graph1.txt");
			}
			else if (lesen == 2)
			{
				dGraph = EdgeWeightedDigraph("graph2.txt");
				Graph = EdgeWeightedGraph("graph2.txt");
			}
			else if(lesen == 3)
			{
				dGraph = EdgeWeightedDigraph("graph3.txt");
				Graph = EdgeWeightedGraph("graph3.txt");
			}
			
		}

		
		
	
	if (eingabe == 2)
		{
			int start = 0;

			cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten : 0 " << endl;

			vector<bool> marked;
			vector<int> edgeTo;

			cout << "Besuchsreihenfolge:" << endl ;
			bool verbunden = Graphsearch::DFS(Graph, start, marked, edgeTo);
			
			cout << endl << endl << "EdgeTo_Array:" << endl;

			for (int i = 0; i < edgeTo.size(); i++)
			{
				cout << i << " -> " << edgeTo[i];
				if (i == start)
				{
					cout << " (Startknoten)";
				}
				cout << endl;
			}

			cout << endl << "Marked-Array:" << endl;
			for (int i = 0; i < marked.size(); i++)
			{
				cout << i << " -> ";
				if (marked[i])
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}

				if (i == start)
				{
					cout << " (Startknoten)";
				}
				cout << endl;
			}

			cout << endl << "Graph ist "; 

			if (!verbunden)
			{
				cout << "nicht ";
			}
			cout << "zusammenhaengend\n" << endl;
		}

		
	else if (eingabe == 3)
	{
		int start = 0;

			cout << "Breitensuche (Breadth-First-Search (DFS)) - Startknoten : ? ";
			cin >> start;

			vector<bool> marked;
			vector<int> edgeTo;

			cout << "Besuchsreihenfolge:" << endl ;
			bool verbunden = Graphsearch::BFS(Graph, start, marked, edgeTo);

			cout << endl << endl << "EdgeTo_Array:" << endl;
			for (int i = 0; i < edgeTo.size(); i++)
			{
				cout << i << " -> " << edgeTo[i];
				if (i == start)
				{
					cout << " (Startknoten)";
				}
				cout << endl;
			}
			cout << endl << "Marked-Array:" << endl;
			for (int i = 0; i < marked.size(); i++)
			{
				cout << i << " -> ";

				if (marked[i])
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}

				if (i == start)
				{
					cout << " (Startknoten)";
				}
				cout << endl;
			}
			cout << endl << "Graph ist ";
			if (!verbunden)
			{
				cout << "nicht ";
			}
			cout << "zusammenhaengend" << endl << endl;
	}

	


	else if (eingabe == 4)
	{
		int start = 0;
			cout << "Startknoten: ? ";
			cin >> start;
			cout << endl;

			cout << "Minimaler Spannbaum (MST) nach Prim: " << endl;
			PrimMST prim(Graph, start);

			cout << "Gewicht: " << prim.weight() << endl;
			cout << "Adjazenliste:" << endl;

			struct node
			{
				int w;
				double weight;
			};

			vector<vector<node>> ergebnis;
			ergebnis.resize(Graph.getV());

			for (Edge edge : prim.edges())
			{
				int v = edge.either();
				int w = edge.other(v);

				node p;
				p.w = w;
				p.weight = edge.weight();
				ergebnis[v].push_back(p);
			}

			for (int i = 0; i < ergebnis.size(); i++)
			{
				if (ergebnis[i].empty())
				{
					continue;
				}

				cout << i;
				for (int j = 0; j < ergebnis[i].size(); j++)
				{
					cout << " -> " << ergebnis[i][j].w << " [" << ergebnis[i][j].weight << "]";
				}
				cout << endl;
			}
			cout << endl;
		}
		
		
		
		
		else if (eingabe == 5)
		{
			cout << "Minimaler Spannbaum (MST) nach Kruskal: " << endl;
			KruskalMST kruskal(Graph);

			cout << "Gewicht: " << kruskal.weight() << endl;
			cout << "Adjazenliste:" << endl;

			struct node
			{
				double w;
				int weight;
			};

			vector<vector<node>> ergebnis;
			ergebnis.resize(Graph.getV());

			for (Edge edge : kruskal.edges())
			{
				int v = edge.either();
				int w = edge.other(v);

				node p;
				p.w = w;
				p.weight = edge.weight();
				ergebnis[v].push_back(p);
			}
			for (int i = 0; i < ergebnis.size(); i++)
			{
				if (ergebnis[i].empty())
				{
					continue;
				}

				cout << i;
				for (int j = 0; j < ergebnis[i].size(); j++)
				{
					cout << " -> " << ergebnis[i][j].w << " [" << ergebnis[i][j].weight << "]";
				}
				cout << endl;
			}
			cout << endl;
	}




	else if (eingabe == 6)
	{
		int start = 0;
			int ziel = 6;
			cout << "Startknoten: ? ";
			cin >> start;

			cout << "Zielknoten: ? ";
			cin >> ziel;

			DijkstraSP dijkstra(dGraph, start);
			vector<DirectedEdge> path = dijkstra.pathTo(ziel);


			cout << endl << "Gewichtete Kanten des Graphen: ";
			for (int i = 0; i < dGraph.getV(); i++)
			{
				cout << endl << i;

				for (DirectedEdge e : dGraph[i])
				{
					cout << "  -> " << e.to() << " [" << e.weight() << "]";
				}
			}

			cout << endl << "Kurzerster Weg (Djikstra):" << endl
				 << "Start:  " << start << endl
				 << "Ziel:   " << ziel << endl
				 << "Pfad:   " << start;

			for (DirectedEdge p : path)
			{
				cout << " [" << p.weight() << "] -> " << p.to();
			}
			cout << endl << "Kosten: " << dijkstra.distTo(ziel) << endl << endl;
	}


		//------------------------------------------------------------------------
		// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
		//------------------------------------------------------------------------
		else if (eingabe ==7)
		{
			
			for (int i = 0; i < Graph.getV(); i++)
			{
				cout << i;

				for (Edge e : Graph[i])
				{
					cout << "  -> " << e.other(i) << " [" << e.weight() << "]";
				}
				
				cout << endl;
			}
			cout << endl;	
			
		}

	else if (eingabe == 8)
	{
		int auswahl;
		cout << "Bitte waehlen Sie ein Graph aus: " << endl;
		cout << "	1 -Kante loeschen aus Graph\n"
			 << "	2 -Kante loeschen aus Digraph" << endl;

		cin>> auswahl;
		int		ein_knoten;  // ein Knoten der Kante
		int		andere_knoten;   // der andere Knoten der Kante
		double	gewicht;  // Kantengewicht
		
		cout << "Bitte ein Knoten der Kante eingeben: ";
		cin>>ein_knoten;
		cout << "Bitte der andere Knoten der Kante eingeben: ";
		cin>>andere_knoten;
		cout << "Bitte Kantengewicht eingeben: ";
		cin>>gewicht;
		
		
		
		if (auswahl == 1)
		{
			Edge e(ein_knoten , andere_knoten, gewicht);
			Graph.del_Edge(e);
		}
		else if (auswahl == 2)
		{
			DirectedEdge e(ein_knoten , andere_knoten, gewicht);
			dGraph.del_Edge(e);
		}

	}




	else if (eingabe == 9)
	{
		int auswahl;
		cout << "Bitte waehlen Sie ein Graph aus: " << endl;
		cout << "	1 -Kante hinzufuegen zum Graph\n"
			 << "	2 -Kante hinzufuegen zum Digraph" << endl;

		cin>> auswahl;

		int		ein_knoten;  // ein Knoten der Kante
		int		andere_knoten;   // der andere Knoten der Kante
		double	gewicht;  // Kantengewicht
		
		cout << "Bitte ein Knoten der hinzufuegende Kante eingeben: ";
		cin>>ein_knoten;
		cout << "Bitte der andere Knoten der hinzufuegende Kante eingeben: ";
		cin>>andere_knoten;
		cout << "Bitte Kantengewicht der hinzufuegende Kante eingeben: ";
		cin>>gewicht;
		
		if (auswahl == 1)
		{
			Edge e(ein_knoten , andere_knoten, gewicht);
			Graph.add(e);
		}
		else if (auswahl == 2)
		{
			DirectedEdge e(ein_knoten , andere_knoten, gewicht);
			dGraph.add(e);
		}
		
		
		

	}


	
	}while (eingabe !=10);

	system("PAUSE");
	return 0;
}












/*
Laufzeiten:

 - Dijkstra:	O(|E| + |V| log |V|)

 - KruskalMST:	O(E log E)

 - PrimMST:		Adjazenjsmatrix = O(v²) | Heap/Liste = O(V log V + E log V)



 Speicheraufwand:

  - Edges:				2 + 2 * E			(2)

  - Knoten:				2 + |V| + |E|		(3)

  - Adjazenzmatrix:		|V|²				(1)

  - Adjazenzliste:		|V| + |E|			(4)



  Ablauf:

  - Dijkstra:		Kürzester Weg von einem Start zum Endknoten. Besucht und Gewicht Update über wege.

  - KruskalMST:		MST vom Startknoten und wählt immer den günstigsten Pfad im Graph.

  - Prim:			MST vom Startknoten und nimmt den günstigsten Pfad zu einem Knoten. | Ohne Zyklen

*/