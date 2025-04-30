#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold, int methode) 
{
	this->size = size; 
	threshold_rehashing = threshold;
	m_sondierMethode = methode;
	elements = 0;
	collisionCount = 0;

	hashTable = new vector<int>(size);
	for (int i = 0; i < size; i++)
	{
		(*hashTable)[i] = -1;
	}
}

HashTable::~HashTable()
{
	delete hashTable;
	hashTable = nullptr;
}

int get_next_prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_last_prime(int x)
{
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

int HashTable::hashValue(int item) 
{
	int i = 0;
	int hi_x = 0; 
	switch (m_sondierMethode)
	{
	case (1):
		
		hi_x = (item + i) % size;
		while ((*hashTable)[hi_x] != -1)
		{
			i++;
			collisionCount++;
			hi_x = (item + i) % size;
		}
		break;
	case (2):
		
		hi_x = (item + i * i) % size;
		while ((*hashTable)[hi_x] != -1)
		{
			i++;
			collisionCount++;
			hi_x = (item + i * i) % size;
		}
		break;
	case (3):
	{
		
		int R = get_last_prime(size);
		hi_x = (item + i * (R - item % R)) % size;
		while ((*hashTable)[hi_x] != -1)
		{
			i++;
			collisionCount++;
			R = get_last_prime(size);
			hi_x = (item + i * (R - item % R)) % size;
		}
		break;
	}
	default:
		break;
	}
	return hi_x;
}

void HashTable::rehashing()
{
	int m_alt = size;
	int m_neu = (2 * m_alt > 1000) ? 1000 : get_next_prime(2 * m_alt); 

	vector<int>* copy = new vector<int>(m_alt);
	for (int i = 0; i < m_alt; i++)
	{
		(*copy)[i] = (*hashTable)[i];
	}
	delete hashTable;
	collisionCount = 0; 
	elements = 0; 
	hashTable = new vector<int>(m_neu);
	size = m_neu;
	for (int i = 0; i < m_neu; i++)
	{
		(*hashTable)[i] = -1;
	}
	int temp = m_sondierMethode; 
	m_sondierMethode = 2; 
	for (int i = 0; i < m_alt; i++)
	{
		if ((*copy)[i] != -1) 
		{
			insert((*copy)[i]);
		}
	}
	m_sondierMethode = temp;
	delete copy;
}

int HashTable::insert(int item) 
{
	if (size != 0)
	{
		double beta = double(elements + 1) / double(size);
		if (beta >= threshold_rehashing) 
		{
			this->rehashing();
		}
	}
	int index = hashValue(item);
	(*hashTable)[index] = item;
	elements++;
	return index;
}


int HashTable::at(int i) 
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount() 
{
	return this->collisionCount;
}

int HashTable::getSize() 
{
	return this->size;
}

int HashTable::getElements() 
{
	return this->elements;
}
 
void HashTable::print()
{
	cout << "print hash Table:\n";

	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] -> " << this->at(i) << endl;
	}
}
