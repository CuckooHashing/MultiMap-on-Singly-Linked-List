#pragma once

#include<vector>
#include<utility>
#include <iostream>



using namespace std;


typedef int TKey;

typedef int TValue;


class MultiMapIterator;
typedef std::pair<TKey, TValue> TElem;

struct Node {
	TElem info;
	Node *next;
};

class MultiMap
{

private:

	Node* head;
	Node* tail;



public:
	friend class MultiMapIterator;

	//constructor
	MultiMap();




	//adds a key value pair to the multimap

	void add(TKey c, TValue v);

	int getValueRange();

	//removes a key value pair from the multimap

	//returns true if the pair was removed (if it was in the multimap) and false otherwise

	bool remove(TKey c, TValue v);



	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty

	vector<TValue> search(TKey c) const;



	//returns the number of pairs from the multimap

	int size() const;



	//checks whether the multimap is empty

	bool isEmpty() const;



	//returns an iterator for the multimap

	MultiMapIterator iterator() const;



	//descturctor

	~MultiMap();





};


