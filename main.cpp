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
#include"2_testing.hpp"
#include"3_samples.hpp"

	using namespace meta_programming;
	using namespace register_machine;
	using namespace testing;
	using namespace samples;

/***********************************************************************************************************************/

	using utype = unsigned long;
	using stype =   signed long;

/***********************************************************************************************************************/

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%d\n", RI::apply);
		printf("%d\n", RI::apply_2_1);

		return 0;
	}

