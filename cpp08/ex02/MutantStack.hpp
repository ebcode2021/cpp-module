#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <stack>

template <class _Tp, class _Container = std::deque<_Tp> > class MutantStack;

template<typename T, typename Container>
class MutantStack : public std::stack<T, Container>
{
	public:
		// OCCF
		MutantStack(){};
		MutantStack(const MutantStack& m){*this = m;};
		MutantStack& operator=(const MutantStack& m)
		{
			if (this != &m)
				std::stack<T, Container>::operator=(m);
			return (*this);
		};
		~MutantStack(){};

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return (this->c.begin());
		};
		iterator end()
		{
			return (this->c.end());
		}
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		};
		reverse_iterator rend()
		{
			return (this->c.rend());
		};
		const_iterator cbegin()
		{
			return (this->c.cbegin());
		};
		const_iterator cend()
		{
			return (this->c.cend());
		}
		const_reverse_iterator crbegin()
		{
			return (this->c.crbegin());
		};
		const_reverse_iterator crend()
		{
			return (this->c.crend());
		};
		void	push_back(T t)
		{
			this->c.push_back(t);
		}
		T	back()
		{
			return (this->c.back());
		}
		void	pop_back()
		{
			this->c.pop_back();
		}
};


#endif