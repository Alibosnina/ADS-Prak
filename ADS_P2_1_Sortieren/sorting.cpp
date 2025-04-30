#include "sorting.h"

namespace sorting
{
	//**************************
	// InsertionSort + QuickSort*
	//**************************
	void InsertQuickSort(vector<int>& a, int left, int right)
	{
		if (left < right)
		{

			if ((right - left + 1) < 350)//350 ist der ungefähre Crossover Point bei dem Insertion Sort schneller ist als Quicksort
			{
				InsertionSort(a, left, right + 1); //Plus 1, da Quicksort ja schon mit a.size()-1 aufgerufen wird und sonst im Insertion Sort nur bis < a.size()-1 iteriert wird
			}
			else
			{
				int index = partition(a, left, right);
				InsertQuickSort(a, left, index - 1);
				InsertQuickSort(a, index + 1, right);
			}
		}
	}

	//************
	// InsertionSort (keine Testcases dazu)
	//************
	void InsertionSort(vector<int>& a, int low, int n) // Angepasster Insertion Sort bei dem von low bis n sortiert wird
	{
		for (int i = low + 1; i < n; i++)
		{
			int tmp = a[i];
			int j = i - 1;
			while (j >= low && a[j] > tmp)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = tmp;
		}
	}

	//************
	// QuickSort *
	//************
	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left < right)
		{
			int q = partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}
	int partition(vector<int>& arr, int left, int right)
	{
		//Median von drei Zahlen berechnen
		int center = (left + right) / 2;
		if (arr[center] < arr[left]) {
			swap(arr[left], arr[center]);
		}
		if (arr[right] < arr[left]) {
			swap(arr[left], arr[right]);
		}
		if (arr[right] < arr[center]) {
			swap(arr[center], arr[right]);
		}
		int x = arr[center]; //pivot
		swap(arr[center], arr[right]);


		int i = left - 1;
		for (int j = left; j < right; j++)
		{
			if (arr[j] <= x) // j und i vertauschen wenn wert von j <= wert von pivot
			{
				i = i + 1;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[right]); // pivot hinter zuletzt getauschte Stelle
		return i + 1;
	}

	//************
	// MergeSort *
	//************
	void Merge(vector<int>& a, vector<int>& b, int low, int middle, int high)
	{
		int leftEnd = middle - 1;
		int tmpPos = low;
		int n = high - low + 1;
		while (low <= leftEnd && middle <= high)
		{
			if (a[low] <= a[middle])
			{ // Array b mit dem kleineren der beiden Elemente aus den Teilfolgen auffüllen
				b[tmpPos] = a[low];
				low++;
			}
			else
			{
				b[tmpPos] = a[middle];
				middle++;
			}
			tmpPos++;
		}
		while (low <= leftEnd)
		{							// Für den Fall dass die rechte Teillist zuerst fertig ist
			b[tmpPos++] = a[low++]; // Das geht weil erst übernommen wird und dann erhöht wird, wegen postfix Operator
		}
		while (middle <= high)
		{ // Für den Fall dass die linke Teilliste fertig ist
			b[tmpPos++] = a[middle++];
		}
		int i = high - n + 1; // Anfangsindex, man kann hier auch 0 nehmen und es besteht die Testcases, aber in der Vorlesung wurde mit dem hier stehenden gearbeitet
		while (i <= high) //Übertragen der Werte aus temp_array
		{
			a[i] = b[i];
			i++;
		}
	}

	void MergeSort(vector<int>& a, vector<int>& b, int low, int high)
	{
		if (low < high)
		{
			int middle = (low + high) * 0.5;
			MergeSort(a, b, low, middle);		// Linke Liste aufteilen
			MergeSort(a, b, middle + 1, high);	// Rechte Liste aufteilen
			Merge(a, b, low, middle + 1, high); // Liste wieder zusammenführen
		}
	}

	void natMerge(vector<int>& a, vector<int>& b, int leftStart, int rightStart, int end)
	{
		int left = leftStart;
		int right = rightStart;
		int tmp = leftStart;
		while (left < rightStart && right < end)
		{
			if (a[left] < a[right])
			{
				b[tmp++] = a[left++];
			}
			else
			{
				b[tmp++] = a[right++];
			}
		}
		while (left < rightStart)
		{
			b[tmp++] = a[left++];
		}
		while (right < end)
		{
			b[tmp++] = a[right++];
		}
		for (int i = leftStart; i < end; i++)
		{
			a[i] = b[i];
		}
	}

	void natMergeSort(vector<int>& a, vector<int>& b)
	{
		int numElements = a.size() - 1;
		vector<int> starts(numElements + 1, 0);

		int runCount = 0;
		starts[0] = 0;

		for (int i = 1; i <= numElements; i++) //Suche nach "Runs"
		{
			if (i == numElements || a[i] < a[i - 1]) 
			{
				starts[++runCount] = i; //Startpunkt einer bereits sortierten Teilfolge
			}
		}
		while (runCount > 1)
		{
			int newRunCount = 0;

			for (int i = 0; i < runCount - 1; i += 2)
			{
				natMerge(a, b, starts[i], starts[i + 1], starts[i + 2]); //(a,b,Anfang li vorsortierte Teilfolge, Anfang re vorsortierter Teilfolge, Ende);
				starts[newRunCount++] = starts[i];
			}

			if (runCount % 2 == 1) //ungrade Anzahl runCount
			{
				int lastStart = starts[runCount - 1];						 // runCount -1 da wenn wir run Nummer 5 wollen müssen wir auf Array Index 4 zugreifen
				copy(a.begin() + lastStart, a.end(), b.begin() + lastStart); // Kopiert von a.lastStart bis a.ende und zwar auf b.lastStart
				starts[newRunCount++] = lastStart;
			}
			starts[newRunCount] = numElements + 1; // Ich weiß nicht was alles nach dieser Line macht
			runCount = newRunCount;
		}
	}

	//************
	// Heapsort  *
	//************
	void heapify(vector<int>& a, int i, int n) // Das ist hier mit einem MaxHeap gelöst, da wir am Ende eine aufwärts sortierte Folge möchten
	{
		int tmp = a[i];
		int j = i;
		int child = 0;
		while ((2 * j + 1) < n) //2*j+1 == child von j
		{
			child = 2 * j + 1;
			if ((child != (n - 1)) && (a[child] < a[child + 1])) //falls li < re -> parent vergleich mit re
			{ // größer/kleiner ändern für MinHeap
				child = child + 1;
			}
			if (tmp < a[child]) //swap falls parent kleiner als child
			{ // größer/kleiner ändern für MinHeap
				swap(a[j], a[child]);
			}
			else
			{
				break;
			}
			j = child;
		}
		a[j] = tmp;
	}

	void HeapSort(vector<int>& a, int n)
	{
		int i = n * 0.5;
		while (i >= 0)
		{ // Erst einen MaxHeap aufbauen, also dass die Kinder jedes Knoten kleiner sind als die Eltern
			heapify(a, i, n);
			i--;
		}
		int j = n - 1;
		while (j >= 0)
		{
			swap(a[0], a[j]); // Wurzel mit letztem tauschen, da Wurzel ja bereits sortiert ist
			heapify(a, 0, j); 
			j--;			  // Letztes Element bei dem nächsten heapify Aufruf auslassen, da sortiert ist
		}
	}

	//************
	// Shellsort *
	//************
	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int>& a, int n)
	{
		int h = 1;
		while (2 * h + 1 < n) //max hibbardabstand finden
		{
			h = 2 * h + 1; // hibbard folge(1,3,7,9)
		}
		while (h > 0)
		{
			int i = h;
			while (i < n)
			{
				int tmp = a[i];
				int j = i;
				while (j >= h &&  a[j - h] > tmp) //li < re
				{
					a[j] = a[j - h];
					j = j - h; //abstand zurück
				}
				a[j] = tmp;
				i = i + 1;
			}
			h = (h - 1) * 0.5; //n#chst kleiner abstand
		}
	}

	void ShellSort_3n(vector<int>& a, int n)
	{	
		double drittel = 1.0 / 3.0;
		int h = 1;
		while (3 * h + 1 < n)
		{
			h = 3 * h + 1; // beste Abstandsfolge
		}
		while (h > 0)
		{
			int i = h;
			while (i < n)
			{
				int tmp = a[i];
				int j = i;
				while (j >= h && tmp < a[j - h])
				{
					a[j] = a[j - h];
					j = j - h;
				}
				a[j] = tmp;
				i = i + 1;
			}
			h = (h - 1) * drittel;
		}
	}

	void randomizeVector(vector<int>& array, int n)
	{
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}
}