//Given an Iterator class interface with methods : next() and hasNext(), design and implement a PeekingIterator that support the peek() operation 
//-- it essentially peek() at the element that will be returned by the next call to next().

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		_isPeek = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!_isPeek)
		{
			_peekValue = Iterator::next();
		}
		_isPeek = true;
		return _peekValue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (!_isPeek)
		{
			return Iterator::next();
		}
		_isPeek = false;
		return _peekValue;
	}

	bool hasNext() const {
		return _isPeek || Iterator::hasNext();
	}

private:
	int _peekValue;
	bool _isPeek;
};

int main()
{
	vector<int> input = {1,2,3};

	system("pause");
	return 0;
}