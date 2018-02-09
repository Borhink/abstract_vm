/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:10:21 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/09 19:29:17 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
# define AVM_HPP

std::string test_add_int8(int &grade);
std::string test_add_int16(int &grade);
std::string test_add_int32(int &grade);
std::string test_add_float(int &grade);
std::string test_add_double(int &grade);

std::string test_sub_int8(int &grade);
std::string test_sub_int16(int &grade);
std::string test_sub_int32(int &grade);
std::string test_sub_float(int &grade);
std::string test_sub_double(int &grade);

std::string test_mult_int8(int &grade);
std::string test_mult_int16(int &grade);
std::string test_mult_int32(int &grade);
std::string test_mult_float(int &grade);
std::string test_mult_double(int &grade);

std::string test_div_int8(int &grade);
std::string test_div_int16(int &grade);
std::string test_div_int32(int &grade);
std::string test_div_float(int &grade);
std::string test_div_double(int &grade);

std::string test_mod_int8(int &grade);
std::string test_mod_int16(int &grade);
std::string test_mod_int32(int &grade);
std::string test_mod_float(int &grade);
std::string test_mod_double(int &grade);

void test_all(void);

#endif
