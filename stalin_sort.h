#pragma once

#include <vector>
#include <list>
#include <forward_list>
#include <deque>

namespace 
{
	template <class STLCont>
	void __impl_stalin_sort(STLCont& con)
	{
		auto iter = con.begin();
		auto before = iter;
		iter++;
	
		while(iter!=con.end())
			if(*before > *iter)
			{
				iter = con.erase(iter);
				before = iter;
				before--;
			}
			else
				++before, ++iter;
	}
}

template <class T>
void stalin_sort(std::list<T>& li)
{
	__impl_stalin_sort(li);
}

template <class T>
void stalin_sort(std::vector<T>& vec)
{
	__impl_stalin_sort(vec);
}

template <class T>
void stalin_sort(std::forward_list<T>& li)
{
	auto iter = li.begin();
	auto after = iter;
	after++;
	
	while(after!=li.end())
		if(*iter > *after)
			after = li.erase_after(iter);
		else
			++after, ++iter;
}

template <class T>
void stalin_sort(std::deque<T>& li)
{
	__impl_stalin_sort(li);
}
