/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/14 14:16:07 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <stdexcept>
# include <algorithm>
# include <map>
# include <regex>
# include <ctype.h>
# include "Stack.class.hpp"
# include "IOperand.class.hpp"
# include "Operand.class.hpp"
# include "Exceptions.class.hpp"
# include "Factory.class.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define EOC "\033[0m"

class AbstractVM
{

public:

	typedef void (AbstractVM::*funcPtr2)(std::string const &);

	AbstractVM(void);
	AbstractVM(AbstractVM const &src);
	~AbstractVM(void);

	static std::map<std::string, funcPtr2> initInst(void);
	static std::map<std::string, funcPtr2> initTypes(void);

	AbstractVM &operator=(AbstractVM const &rhs);

	void run(char *path);

private:

	void clearStack(void);
	void purifyString(std::string &str) const;

	void parseInstruction(std::string line);
	void checkLine(std::string const &line);
	void Push(std::string const &line);
	void Pop(std::string const &line);
	void Dump(std::string const &line);
	void Assert(std::string const &line);
	void Add(std::string const &line);
	void Sub(std::string const &line);
	void Mul(std::string const &line);
	void Div(std::string const &line);
	void Mod(std::string const &line);
	void Print(std::string const &line);
	void Exit(std::string const &line);

	void parseArg(std::string const &line);
	void checkInteger(std::string const &value);
	void checkDecimal(std::string const &value);
	void parseInt8(std::string const &value);
	void parseInt16(std::string const &value);
	void parseInt32(std::string const &value);
	void parseFloat(std::string const &value);
	void parseDouble(std::string const &value);

	bool _run;
	bool _exit;
	bool _isFile;
	Stack<IOperand const*> *_operands;
	Factory _factory;

	static std::map<std::string, AbstractVM::funcPtr2> const _inst;
	static std::map<std::string, AbstractVM::funcPtr2> const _types;
};

#endif
