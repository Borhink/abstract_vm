/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/11 19:24:49 by qhonore          ###   ########.fr       */
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

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define EOC "\033[0m"

class AbstractVM
{

public:

	typedef IOperand const *(AbstractVM::*funcPtr1)(std::string const &) const;
	typedef void (AbstractVM::*funcPtr2)(std::string const &);

	AbstractVM(void);
	AbstractVM(AbstractVM const &src);
	~AbstractVM(void);

	static std::map<std::string, funcPtr2> initInst(void);
	static std::map<std::string, funcPtr2> initTypes(void);

	AbstractVM &operator=(AbstractVM const &rhs);

	void run(char *path);

	IOperand const *createOperand(eOperandType type, std::string const &value) const;
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;

private:
	void purifyString(std::string &str) const;

	void parseInstruction(std::string line);
	void parsePush(std::string const &line);
	void parsePop(std::string const &line);
	void parseDump(std::string const &line);
	void parseAssert(std::string const &line);
	void parseAdd(std::string const &line);
	void parseSub(std::string const &line);
	void parseMul(std::string const &line);
	void parseDiv(std::string const &line);
	void parseMod(std::string const &line);
	void parsePrint(std::string const &line);
	void parseExit(std::string const &line);

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
	Stack<IOperand*> *_operands;

	static funcPtr1 const _create[5];
	static std::map<std::string, AbstractVM::funcPtr2> const _inst;
	static std::map<std::string, AbstractVM::funcPtr2> const _types;
};

#endif
