#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>
#include <math.h>

using namespace std;

class HashTable {
private:	
	int size;						
	int elements;					
	int collisionCount;				
	double threshold_rehashing;			
	int m_sondierMethode;				
	vector<int>* hashTable;				
	int hashValue(int item);			
	void rehashing();					
public:
	HashTable(int size, double threshold=0.6, int methode=2);
	~HashTable();								
	int insert(int item);						
	int at(int i);								
	int getCollisionCount();    			
	int getSize();					
	int getElements();				
	void print();					
};

// Helper Funktion:
int get_next_Prime(int a);			
int get_last_Prime(int a);		
#endif 