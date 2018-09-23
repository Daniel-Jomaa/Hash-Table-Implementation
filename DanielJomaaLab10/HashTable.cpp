
#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	tableSize = other.tableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];

	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i] = other.dataTable[i];
	}
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
{
	delete[] dataTable;

	dataTable = new BSTree<DataType, KeyType>[tableSize];

	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i] = other.dataTable[i];
	}

	return this;
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	delete [] dataTable;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{
	int hashIndex = (DataType::getIntVal(newDataItem.getKey())) % tableSize;

	dataTable[hashIndex].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	int hashIndex = DataType::getIntVal(deleteKey) % tableSize;

	return dataTable[hashIndex].remove(deleteKey);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	int hashIndex = DataType::getIntVal(searchKey) % tableSize;

	return dataTable[hashIndex].retrieve(searchKey, returnItem);

}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i].clear();
	}

}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	bool isempty = true;

	for (int i = 0; i < tableSize; i++)
	{
		if (!dataTable[i].isEmpty())
			isempty = false;
	}

	return isempty;
}

#include "show10.cpp"

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const
{
	int xbar = 0; // average number of keys chained off each index
	int xi = 0; //number of keys chained off an index
	int n = 0; //number of array entries in the table

	int sum = 0;
	int count = 0;

	//find the average number of keys
	for (int i = 0; i < tableSize; i++)
	{
		if (!dataTable[i].isEmpty()) {
			sum += dataTable[i].getCount();
			count++;
		}
	}
	xbar = sum / count;




}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
{
}
