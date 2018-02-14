#include <string>
#include <iostream>
#include "avm.hpp"

static void test_add(int &grade)
{
	int add_grade = 0;

	std::cout << "================== Addition ==================" << std::endl;
	std::cout << "Int8   :" << test_add_int8(add_grade) << std::endl;
	std::cout << "Int16  :" << test_add_int16(add_grade) << std::endl;
	std::cout << "Int32  :" << test_add_int32(add_grade) << std::endl;
	std::cout << "Float  :" << test_add_float(add_grade) << std::endl;
	std::cout << "Double :" << test_add_double(add_grade) << std::endl;
	std::cout << "Grade  : " << add_grade << "/40" << std::endl;
	grade += add_grade;
}

static void test_sub(int &grade)
{
	int sub_grade = 0;

	std::cout << "================ Substraction ================" << std::endl;
	std::cout << "Int8   :" << test_sub_int8(sub_grade) << std::endl;
	std::cout << "Int16  :" << test_sub_int16(sub_grade) << std::endl;
	std::cout << "Int32  :" << test_sub_int32(sub_grade) << std::endl;
	std::cout << "Float  :" << test_sub_float(sub_grade) << std::endl;
	std::cout << "Double :" << test_sub_double(sub_grade) << std::endl;
	std::cout << "Grade  : " << sub_grade << "/30" << std::endl;
	grade += sub_grade;
}

static void test_mult(int &grade)
{
	int mult_grade = 0;

	std::cout << "=============== Multiplication ===============" << std::endl;
	std::cout << "Int8   :" << test_mult_int8(mult_grade) << std::endl;
	std::cout << "Int16  :" << test_mult_int16(mult_grade) << std::endl;
	std::cout << "Int32  :" << test_mult_int32(mult_grade) << std::endl;
	std::cout << "Float  :" << test_mult_float(mult_grade) << std::endl;
	std::cout << "Double :" << test_mult_double(mult_grade) << std::endl;
	std::cout << "Grade  : " << mult_grade << "/70" << std::endl;
	grade += mult_grade;
}

static void test_div(int &grade)
{
	int div_grade = 0;

	std::cout << "================== Division ==================" << std::endl;
	std::cout << "Int8   :" << test_div_int8(div_grade) << std::endl;
	std::cout << "Int16  :" << test_div_int16(div_grade) << std::endl;
	std::cout << "Int32  :" << test_div_int32(div_grade) << std::endl;
	std::cout << "Float  :" << test_div_float(div_grade) << std::endl;
	std::cout << "Double :" << test_div_double(div_grade) << std::endl;
	std::cout << "Grade  : " << div_grade << "/50" << std::endl;
	grade += div_grade;
}

static void test_mod(int &grade)
{
	int mod_grade = 0;

	std::cout << "=================== Modulo ===================" << std::endl;
	std::cout << "Int8   :" << test_mod_int8(mod_grade) << std::endl;
	std::cout << "Int16  :" << test_mod_int16(mod_grade) << std::endl;
	std::cout << "Int32  :" << test_mod_int32(mod_grade) << std::endl;
	std::cout << "Float  :" << test_mod_float(mod_grade) << std::endl;
	std::cout << "Double :" << test_mod_double(mod_grade) << std::endl;
	std::cout << "Grade  : " << mod_grade << "/10" << std::endl;
	grade += mod_grade;
}

void test_all(void)
{
	int grade = 0;

	test_add(grade);
	test_sub(grade);
	test_mult(grade);
	test_div(grade);
	test_mod(grade);
	std::cout << "==============================================" << std::endl;
	std::cout << "Final grade : " << grade << "/200" << std::endl;
	std::cout << "==============================================" << std::endl;
}
