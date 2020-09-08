/*
 *
 * Daniel Quezada
 * ordered_array.hpp
 * 8/30/2020
 *
 * This program creates a simple data struct that maintains a sorted array.
 * It should also allow the user to 'insert' and 'remove' int values as well
 * as support indexing certain elements.
 *
 * 
*/

#include <stdexcept> //for out_of_range
#pragma once

class ordered_array
{
public:
	/*
		Ctor
		Construct a new ordered_array with given capacity (max size).
		The size of a new ordered_array should be 0.
	*/
	ordered_array(int cap)
	{
		data = new int[cap];
		maxSz = cap;
		sz = 0;
	}

	/*
		destructor
	*/
	~ordered_array()
	{
		delete data;
	}

	/**
	********************************
				Methods
	********************************
	**/

	/*
		capacity()
		Returns the maximum size of array
	*/
	int capacity()
	{
		return maxSz;
	}

	/*
		size()
		Returns size (# of elements in the array)
	*/
	int size()
	{
		return sz;
	}

	/*
		exists(elem)
		Return true if elem is present at least once in the array.

		If e == -2147483648 then this returns false
		(This should never happen though because insert()
		should not allow -2147483648 into the array)

		This runs in 'n' time because the method only does one
		cycle through the array, checking if the element is present.

		Best Case  : O(1)
		Worst Case : O(n)
	*/
	bool exists(int elem)
	{
		for (int i = 0; i < sz; ++i) // ] O(n) linear
		{
			if (data[i] == elem) // ] O(1) constant
				return true;
		}

		return false;
	}

	/*
		remove(elem)
		Remove elem from array, if it exists. (If it does not exist, the 
		array should be unchanged.) If multiple copies of a e are present, only
		one should be removed.

		If e = -2147483648 then this does nothing (Again, this should never happen
		because insert() would not allow that int into the array)

		This will run in '2n' time because the method will have two loops that  will run through 
		the array once.The first searches for the first instance of element that is to be removed.
		Second loop starts at index of element to be removed (if it exists) and cycles through
		remainder of array moving all elements down by one.
	*/
	void remove(int elem)
	{
		if (sz != 0)
		{

			int i;
			for (i = 0; i < sz; ++i) // ] O(n) linear
			{
				if (data[i] == elem) // ] O(1) constant
				{
					break;
				}
			}

			//Move all element's index back one starting at x+1
			//to 'remove' the elem and then lower the size to reflect
			//new appropriate size.
			if (i < sz)
			{
				--sz;
				for (int j = i; j < sz; ++j) // ] O(n) linear
				{
					data[j] = data[j + 1]; // ] O(1) constant
				}
			}
		}
	}

	/*
		insert(elem)
		Insert e into the array. Note that it is OK to insert duplicates; if n
		copies of a value are inserted into the array then n copies should appear
		in the array.

		If size() == capacity() then this does nothing.

		If e == -2147483648 then this does nothing (i.e., -2147483648 is not a 
		valid value to insert).

		This also runs in 'n^2' time since there is a nested loop that both run
		in linear time. By multiplying the run time of both of these loops, we get 
		a method that runs in quadratic time.
	*/
	void insert(int elem)
	{
		if (elem == -2147483648)
		{
		} //Not a valid value; do nothing
		else if (sz == maxSz)
		{ //Can NO longer add any inputs (Do nothing)
		}
		else
		{ //Insert the input at the end of array
			data[sz] = elem;
			++sz;
		}

		//Bubble sort the array
		for (int j = 0; j < sz; ++j) // ] O(n) linear
		{
			for (int h = j + 1; h < sz; ++h) // ] O(n) linear
			{
				compareSort(data[j], data[h]);
			}
		}
	}

	/*
		compareSort(&first, &second)
		Bubble sort function which takes two inputs and orders them in 
		ascending order. If inputs match each other, the function should
		still swap them.

	*/
	void compareSort(int &first, int &second)
	{
		if (first >= second)
		{
			int temp = first;
			first = second;
			second = temp;
		}
	}

	/*
		at(i)
		Returns the value in the array at index i, which should be >= 0 and < 
		size().

		If i < 0 or i >= size(), then at(i) should throw a std::out_of_range
		exception. (This is what std::vector does in this sitution)

		Note that at() should *never* return -2147483648 (because insert() should
		never insert it).
	*/
	int at(int i)
	{
		if (i < 0 || i >= sz)
		{
			throw std::out_of_range("out_of_range error!");
		}
		else
		{
			return data[i];
		}
	}

private:
	int maxSz, sz;
	int *data = nullptr;
};