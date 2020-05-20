#include "MultiMapIterator.h"



MultiMapIterator::MultiMapIterator(const Container& c, Node* current): c{ c }, current{ current }
{//theta 1
}


MultiMapIterator::~MultiMapIterator()
{//theta 1
}

void MultiMapIterator::first()
{//theta 1
	this->current = c.head;
}


bool MultiMapIterator::valid() const
{//complexity is theta 1
	if (this->current == NULL)
		return false;
	return true;
}

TElem MultiMapIterator::getCurrent() const
{//complexity is theta 1
	TElem thing(this->current->info.first, this->current->info.second);
	return thing;
}


void MultiMapIterator::next()
{//complexity is theta 1
	if (this->valid())
	{
		this->current = this->current->next;
	}
	else
		throw std::exception();
}
