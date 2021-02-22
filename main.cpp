/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_compile_time_register_machine.
**
** cpp_compile_time_register_machine is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_compile_time_register_machine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_compile_time_register_machine.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#include<cstdio>

/***********************************************************************************************************************/

#include"0_meta_programming.hpp"
#include"1_register_machine.hpp"
#include"2_samples.hpp"
#include"3_testing.hpp"

	using namespace meta_programming;
	using namespace register_machine;
	using namespace samples;
	using namespace testing;

/***********************************************************************************************************************/

	using utype = unsigned long;
	using stype =   signed long;

/***********************************************************************************************************************/

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		constexpr auto result = factorial<1>; // currently returns an alt list.
	//	printf(result);

	//	constexpr auto result = U_type_T<alt_list<5>>;

		printf("%s\n", V_is_auto_list_U(result) ? "true" : "false");
		printf("%s\n", V_is_alt_list_U(result) ? "true" : "false");

	//	printf("%d\n", factorial<5>);

		return 0;
	}

