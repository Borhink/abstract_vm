#include <string>
#include <sstream>
#include <iostream>
#include "AbstractVM.class.hpp"

std::string test_mult_int8(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<char>("-128", Int8) * Operand<char>("1", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "1) -128 * 1 = -128 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("1", Int8) * Operand<char>("-128", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 1 * -128 = -128 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("-1", Int8) * Operand<char>("-128", Int8);
		std::cout << " ❌";
		ss << std::endl << "3) -1 * -128 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "3) -1 * -128 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-128", Int8) * Operand<char>("-1", Int8);
		std::cout << " ❌";
		ss << std::endl << "4) -128 * -1 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "4) -128 * -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("127", Int8) * Operand<char>("-1", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "5) 127 * -1 = -127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("-1", Int8) * Operand<char>("127", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 * 127 = -127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("127", Int8) * Operand<char>("1", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "7) 127 * 1 = 127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("1", Int8) * Operand<char>("127", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "8) 1 * 127 = 127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("100", Int8) * Operand<char>("10", Int8);
		std::cout << " ❌";
		ss << std::endl << "9) 100 * 10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "9) 100 * 10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("10", Int8) * Operand<char>("100", Int8);
		std::cout << " ❌";
		ss << std::endl << "10) 10 * 100 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "10) 10 * 100 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-100", Int8) * Operand<char>("10", Int8);
		std::cout << " ❌";
		ss << std::endl << "11) -100 * 10 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "11) -100 * 10 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-10", Int8) * Operand<char>("100", Int8);
		std::cout << " ❌";
		ss << std::endl << "12) -10 * 100 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "12) -10 * 100 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-100", Int8) * Operand<char>("-10", Int8);
		std::cout << " ❌";
		ss << std::endl << "13) -100 * -10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "13) -100 * -10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-10", Int8) * Operand<char>("-100", Int8);
		std::cout << " ❌";
		ss << std::endl << "14) -10 * -100 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "14) -10 * -100 = overflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}

std::string test_mult_int16(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<short>("-32768", Int16) * Operand<short>("1", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "1) -32768 * 1 = -32768 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("1", Int16) * Operand<short>("-32768", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 1 * -32768 = -32768 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("-1", Int16) * Operand<short>("-32768", Int16);
		std::cout << " ❌";
		ss << std::endl << "3) -1 * -32768 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "3) -1 * -32768 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-32768", Int16) * Operand<short>("-1", Int16);
		std::cout << " ❌";
		ss << std::endl << "4) -32768 * -1 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "4) -32768 * -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("32767", Int16) * Operand<short>("-1", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "5) 32767 * -1 = -32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("-1", Int16) * Operand<short>("32767", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 * 32767 = -32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("32767", Int16) * Operand<short>("1", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "7) 32767 * 1 = 32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("1", Int16) * Operand<short>("32767", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "8) 1 * 32767 = 32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("10000", Int16) * Operand<short>("10", Int16);
		std::cout << " ❌";
		ss << std::endl << "9) 10000 * 10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "9) 10000 * 10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("10", Int16) * Operand<short>("10000", Int16);
		std::cout << " ❌";
		ss << std::endl << "10) 10 * 10000 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "10) 10 * 10000 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-10000", Int16) * Operand<short>("10", Int16);
		std::cout << " ❌";
		ss << std::endl << "11) -10000 * 10 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "11) -10000 * 10 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-10", Int16) * Operand<short>("10000", Int16);
		std::cout << " ❌";
		ss << std::endl << "12) -10 * 10000 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "12) -10 * 10000 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-10000", Int16) * Operand<short>("-10", Int16);
		std::cout << " ❌";
		ss << std::endl << "13) -10000 * -10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "13) -10000 * -10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-10", Int16) * Operand<short>("-10000", Int16);
		std::cout << " ❌";
		ss << std::endl << "14) -10 * -10000 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "14) -10 * -10000 = overflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}

std::string test_mult_int32(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<int>("-2147483648", Int32) * Operand<int>("1", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "1) -2147483648 * 1 = -2147483648 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("1", Int32) * Operand<int>("-2147483648", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 1 * -2147483648 = -2147483648 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("-1", Int32) * Operand<int>("-2147483648", Int32);
		std::cout << " ❌";
		ss << std::endl << "3) -1 * -2147483648 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "3) -1 * -2147483648 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-2147483648", Int32) * Operand<int>("-1", Int32);
		std::cout << " ❌";
		ss << std::endl << "4) -2147483648 * -1 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "4) -2147483648 * -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("2147483647", Int32) * Operand<int>("-1", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "5) 2147483647 * -1 = -2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("-1", Int32) * Operand<int>("2147483647", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 * 2147483647 = -2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("2147483647", Int32) * Operand<int>("1", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "7) 2147483647 * 1 = 2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("1", Int32) * Operand<int>("2147483647", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "8) 1 * 2147483647 = 2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("1000000000", Int32) * Operand<int>("10", Int32);
		std::cout << " ❌";
		ss << std::endl << "9) 1000000000 * 10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "9) 1000000000 * 10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("10", Int32) * Operand<int>("1000000000", Int32);
		std::cout << " ❌";
		ss << std::endl << "10) 10 * 1000000000 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "10) 10 * 1000000000 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-1000000000", Int32) * Operand<int>("10", Int32);
		std::cout << " ❌";
		ss << std::endl << "11) -1000000000 * 10 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "11) -1000000000 * 10 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-10", Int32) * Operand<int>("1000000000", Int32);
		std::cout << " ❌";
		ss << std::endl << "12) -10 * 1000000000 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "12) -10 * 1000000000 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-1000000000", Int32) * Operand<int>("-10", Int32);
		std::cout << " ❌";
		ss << std::endl << "13) -1000000000 * -10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "13) -1000000000 * -10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-10", Int32) * Operand<int>("-1000000000", Int32);
		std::cout << " ❌";
		ss << std::endl << "14) -10 * -1000000000 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "14) -10 * -1000000000 = overflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}

std::string test_mult_float(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<float>("-340282346638528859811704183484516925440.0", Float) * Operand<float>("1", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "1) -340282346638528859811704183484516925440.0 * 1 = -340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("1", Float) * Operand<float>("-340282346638528859811704183484516925440.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 1 * -340282346638528859811704183484516925440.0 = -340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("-1", Float) * Operand<float>("-340282346638528859811704183484516925440.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -1 * -340282346638528859811704183484516925440.0 = 340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("-340282346638528859811704183484516925440.0", Float) * Operand<float>("-1", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -340282346638528859811704183484516925440.0 * -1 = 340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("340282346638528859811704183484516925440.0", Float) * Operand<float>("-1", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "5) 340282346638528859811704183484516925440.0 * -1 = -340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("-1", Float) * Operand<float>("340282346638528859811704183484516925440.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 * 340282346638528859811704183484516925440.0 = -340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("340282346638528859811704183484516925440.0", Float) * Operand<float>("1", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "7) 340282346638528859811704183484516925440.0 * 1 = 340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("1", Float) * Operand<float>("340282346638528859811704183484516925440.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "8) 1 * 340282346638528859811704183484516925440.0 = 340282346638528859811704183484516925440.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("100000000000000000000000000000000000000.0", Float) * Operand<float>("10", Float);
		std::cout << " ❌";
		ss << std::endl << "9) 100000000000000000000000000000000000000.0 * 10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "9) 100000000000000000000000000000000000000.0 * 10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("10", Float) * Operand<float>("100000000000000000000000000000000000000.0", Float);
		std::cout << " ❌";
		ss << std::endl << "10) 10 * 100000000000000000000000000000000000000.0 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "10) 10 * 100000000000000000000000000000000000000.0 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-100000000000000000000000000000000000000.0", Float) * Operand<float>("10", Float);
		std::cout << " ❌";
		ss << std::endl << "11) -100000000000000000000000000000000000000.0 * 10 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "11) -100000000000000000000000000000000000000.0 * 10 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-10", Float) * Operand<float>("100000000000000000000000000000000000000.0", Float);
		std::cout << " ❌";
		ss << std::endl << "12) -10 * 100000000000000000000000000000000000000.0 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "12) -10 * 100000000000000000000000000000000000000.0 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-100000000000000000000000000000000000000.0", Float) * Operand<float>("-10", Float);
		std::cout << " ❌";
		ss << std::endl << "13) -100000000000000000000000000000000000000.0 * -10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "13) -100000000000000000000000000000000000000.0 * -10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-10", Float) * Operand<float>("-100000000000000000000000000000000000000.0", Float);
		std::cout << " ❌";
		ss << std::endl << "14) -10 * -100000000000000000000000000000000000000.0 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "14) -10 * -100000000000000000000000000000000000000.0 = overflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}

std::string test_mult_double(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) * Operand<double>("1", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "1) -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 * 1 = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("1", Double) * Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "2) 1 * -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("-1", Double) * Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -1 * -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) * Operand<double>("-1", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 * -1 = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) * Operand<double>("-1", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "5) 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 * -1 = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("-1", Double) * Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 * 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) * Operand<double>("1", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "7) 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 * 1 = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("1", Double) * Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "8) 1 * 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double) * Operand<double>("10", Double);
		std::cout << " ❌";
		ss << std::endl << "9) 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * 10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "9) 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * 10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("10", Double) * Operand<double>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double);
		std::cout << " ❌";
		ss << std::endl << "10) 10 * 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "10) 10 * 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double) * Operand<double>("10", Double);
		std::cout << " ❌";
		ss << std::endl << "11) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * 10 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "11) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * 10 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-10", Double) * Operand<double>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double);
		std::cout << " ❌";
		ss << std::endl << "12) -10 * 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = underflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("underflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "12) -10 * 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double) * Operand<double>("-10", Double);
		std::cout << " ❌";
		ss << std::endl << "13) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * -10 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "13) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 * -10 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-10", Double) * Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", Double);
		std::cout << " ❌";
		ss << std::endl << "14) -10 * -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = overflow (you: " << res->toString() << ")";
		delete res;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("overflow"))
		{
			std::cout << " ✅";
			grade++;
		}
		else
		{
			std::cout << " ❌";
			ss << std::endl << "14) -10 * -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 = overflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}
