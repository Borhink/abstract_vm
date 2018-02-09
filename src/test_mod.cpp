#include <string>
#include <sstream>
#include <iostream>
#include "AbstractVM.class.hpp"

std::string test_mod_int8(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<char>("100", Int8) % Operand<char>("0", Int8);
		std::cout << " ❌";
		ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Floating point exception"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("0", Int8) % Operand<char>("100", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 0 %% 100 = 0 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_mod_int16(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<short>("100", Int16) % Operand<short>("0", Int16);
		std::cout << " ❌";
		ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Floating point exception"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("0", Int16) % Operand<short>("100", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 0 %% 100 = 0 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_mod_int32(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<int>("100", Int32) % Operand<int>("0", Int32);
		std::cout << " ❌";
		ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Floating point exception"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "1) 100 %% 0 = Floating point exception (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("0", Int32) % Operand<int>("100", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 0 %% 100 = 0 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_mod_float(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<float>("100.0", Float) % Operand<float>("0", Float);
		std::cout << " ❌";
		ss << std::endl << "1) 100.0 %% 0 = Floating point exception (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Floating point exception"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "1) 100.0 %% 0 = Floating point exception (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("0", Float) % Operand<float>("100.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 0 %% 100.0 = 0 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_mod_double(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<double>("100.0", Double) % Operand<double>("0", Double);
		std::cout << " ❌";
		ss << std::endl << "1) 100.0 %% 0 = Floating point exception (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Floating point exception"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "1) 100.0 %% 0 = Floating point exception (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("0", Double) % Operand<double>("100.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 0 %% 100.0 = 0 (you: " << e.what() << ")";
	}
	return (ss.str());
}
