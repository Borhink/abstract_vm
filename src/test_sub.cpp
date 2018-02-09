#include <string>
#include <sstream>
#include <iostream>
#include "AbstractVM.class.hpp"

std::string test_sub_int8(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<char>("-128", Int8) - Operand<char>("1", Int8);
		std::cout << " ❌";
		ss << std::endl << "1) -128 - 1 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "1) -128 - 1 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("1", Int8) - Operand<char>("-128", Int8);
		std::cout << " ❌";
		ss << std::endl << "2) 1 - -128 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "2) 1 - -128 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-1", Int8) - Operand<char>("-128", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -1 - -128 = 127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("-128", Int8) - Operand<char>("-1", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -128 - -1 = -127 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<char>("127", Int8) - Operand<char>("-1", Int8);
		std::cout << " ❌";
		ss << std::endl << "5) 127 - -1 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "5) 127 - -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<char>("-1", Int8) - Operand<char>("127", Int8);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 - 127 = -128 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_sub_int16(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<short>("-32768", Int16) - Operand<short>("1", Int16);
		std::cout << " ❌";
		ss << std::endl << "1) -32768 - 1 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "1) -32768 - 1 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("1", Int16) - Operand<short>("-32768", Int16);
		std::cout << " ❌";
		ss << std::endl << "2) 1 - -32768 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "2) 1 - -32768 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-1", Int16) - Operand<short>("-32768", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -1 - -32768 = 32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("-32768", Int16) - Operand<short>("-1", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -32768 - -1 = -32767 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<short>("32767", Int16) - Operand<short>("-1", Int16);
		std::cout << " ❌";
		ss << std::endl << "5) 32767 - -1 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "5) 32767 - -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<short>("-1", Int16) - Operand<short>("32767", Int16);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 - 32767 = -32768 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_sub_int32(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<int>("-2147483648", Int32) - Operand<int>("1", Int32);
		std::cout << " ❌";
		ss << std::endl << "1) -2147483648 - 1 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "1) -2147483648 - 1 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("1", Int32) - Operand<int>("-2147483648", Int32);
		std::cout << " ❌";
		ss << std::endl << "2) 1 - -2147483648 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "2) 1 - -2147483648 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-1", Int32) - Operand<int>("-2147483648", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -1 - -2147483648 = 2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("-2147483648", Int32) - Operand<int>("-1", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -2147483648 - -1 = -2147483647 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<int>("2147483647", Int32) - Operand<int>("-1", Int32);
		std::cout << " ❌";
		ss << std::endl << "5) 2147483647 - -1 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "5) 2147483647 - -1 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<int>("-1", Int32) - Operand<int>("2147483647", Int32);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "6) -1 - 2147483647 = -2147483648 (you: " << e.what() << ")";
	}
	return (ss.str());
}

std::string test_sub_float(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<float>("-340282346638528859811704183484516925440.0", Float) - Operand<float>("100000000000000000000000000000000000000", Float);
		std::cout << " ❌";
		ss << std::endl << "1) -340282346638528859811704183484516925440.0 - 100000000000000000000000000000000000000 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "1) -340282346638528859811704183484516925440.0 - 100000000000000000000000000000000000000 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("100000000000000000000000000000000000000", Float) - Operand<float>("-340282346638528859811704183484516925440.0", Float);
		std::cout << " ❌";
		ss << std::endl << "2) 100000000000000000000000000000000000000 - -340282346638528859811704183484516925440.0 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "2) 100000000000000000000000000000000000000 - -340282346638528859811704183484516925440.0 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-100000000000000000000000000000000000000", Float) - Operand<float>("-340282346638528859811704183484516925440.0", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -100000000000000000000000000000000000000 - -340282346638528859811704183484516925440.0 = 2.40282e+38 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("-340282346638528859811704183484516925440.0", Float) - Operand<float>("-100000000000000000000000000000000000000", Float);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -340282346638528859811704183484516925440.0 - -100000000000000000000000000000000000000 = -2.40282e+38 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<float>("340282346638528859811704183484516925440.0", Float) - Operand<float>("-100000000000000000000000000000000000000", Float);
		std::cout << " ❌";
		ss << std::endl << "5) 340282346638528859811704183484516925440.0 - -100000000000000000000000000000000000000 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "5) 340282346638528859811704183484516925440.0 - -100000000000000000000000000000000000000 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<float>("-100000000000000000000000000000000000000", Float) - Operand<float>("340282346638528859811704183484516925440.0", Float);
		std::cout << " ❌";
		ss << std::endl << "6) -100000000000000000000000000000000000000 - 340282346638528859811704183484516925440.0 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "6) -100000000000000000000000000000000000000 - 340282346638528859811704183484516925440.0 = underflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}

std::string test_sub_double(int &grade)
{
	std::stringstream ss;

	try
	{
		IOperand const *res = Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) - Operand<double>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double);
		std::cout << " ❌";
		ss << std::endl << "1) -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 - 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "1) -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 - 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 = underflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double) - Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ❌";
		ss << std::endl << "2) 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 - -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "2) 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 - -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double) - Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "3) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 - -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = 7.97693e+307 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) - Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double);
		std::cout << " ✅";
		grade++;
		delete res;
	}
	catch (std::exception &e)
	{
		std::cout << " ❌";
		ss << std::endl << "4) -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 - -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 = -7.97693e+307 (you: " << e.what() << ")";
	}

	try
	{
		IOperand const *res = Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double) - Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double);
		std::cout << " ❌";
		ss << std::endl << "5) 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 - -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 = overflow (you: " << res->toString() << ")";
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
			ss << std::endl << "5) 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 - -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 = overflow (you: " << e.what() << ")";
		}
	}

	try
	{
		IOperand const *res = Operand<double>("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", Double) - Operand<double>("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", Double);
		std::cout << " ❌";
		ss << std::endl << "6) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 - 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = underflow (you: " << res->toString() << ")";
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
			ss << std::endl << "6) -100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 - 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0 = underflow (you: " << e.what() << ")";
		}
	}
	return (ss.str());
}
