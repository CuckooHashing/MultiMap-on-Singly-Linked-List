#include "MultiMap.h"
#include "MultiMapIterator.h"



MultiMap::MultiMap()
{
	this->head = NULL;
	this->tail = NULL;
}

void MultiMap::add(TKey c, TValue v)
{//theta 1
	if (this->head != NULL)
	{
		TElem e (c, v);
		Node* node = new Node;
		node->info = e;
		node->next = NULL;
		this->tail->next = node;
		this->tail = node;
	}
	else
	{
		TElem e(c, v);
		Node* node = new Node;
		node->info = e;
		node->next = NULL;
		this->head = node;
		this->tail = node;
	}
}

int MultiMap::getValueRange()
{
	if (this->isEmpty())
		return -1;
	int max, min;
	max = this->head->info.second;
	min = this->head->info.second;
	Node *i = this->head;
	while (i != NULL)
	{
		if (i->info.second > max)
			max = i->info.second;
		if (i->info.second < min)
			min = i->info.second;
		i = i->next;
	}
	return max - min;
}

bool MultiMap::remove(TKey c, TValue v)
{//complexity is O(n)
	int s = 0;
	Node *i = this->head;
	bool oke = false;
	if (this->head == NULL)
		return false;
	if ((this->head->info.first == c) && (this->head->info.second == v))
	{
		this->head = this->head->next;
		return true;
	}
	while ((i != NULL) && (i->next != NULL))
	{
		if ((i->next->info.first == c) && (i->next->info.second == v))
		{
			i->next = i->next->next;
			oke = true;
		}
		s++;
		i = i->next;
	}

	return oke;
}

vector<TValue> MultiMap::search(TKey c) const
{//complexity is theta(n)
	std::vector<TValue> found;
	Node *i = this->head;
	while (i != NULL)
	{
		if (i->info.first == c)
		{
			found.push_back(i->info.second);
		}
		i = i->next;
	}
	return found;
}

int MultiMap::size() const
{//complexity is theta n
	int s = 0;
	Node *i = this->head;
	while (i != NULL)
	{
		s++;
		i = i->next;
	}
	return s;
}

bool MultiMap::isEmpty() const
{//complexity is theta 1
	if (this->head == NULL)
		return true;
	return false;
}

MultiMapIterator MultiMap::iterator() const
{//complexity is theta 1
	return MultiMapIterator(*this, this->head);
}


MultiMap::~MultiMap()
{
}
