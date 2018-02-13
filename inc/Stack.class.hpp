/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:34 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/13 13:16:05 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <stack>
# include <algorithm>
# include <stdexcept>

template <typename T>
class Stack : public std::stack<T>
{

public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	typedef typename std::stack<T>::reference reference;

	Stack(void) {}
	Stack(Stack const &src) : std::stack<T>(src) {}
	~Stack(void) {}

	Stack &operator=(Stack const &rhs) { if (this != &rhs) {} }

	reference at(size_t n) { return (this->c.at(n)); }
	reference operator[](size_t n) { return (this->c[n]); }
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }

	const_iterator cbegin() { return (this->c.cbegin()); }
	const_iterator cend() { return (this->c.cend()); }
	const_reverse_iterator crbegin() { return (this->c.crbegin()); }
	const_reverse_iterator crend() { return (this->c.crend()); }
	void resize(size_t n) { this->c.resize(n); }
};

#endif
