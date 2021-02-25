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

	// 1. still need to decide on a depth decrement policy.
	// 2. still need to add register macros.

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		constexpr auto n	= 5;
		constexpr auto result	= factorial<n>;

		printf("factorial(%d): %d\n", n, result);

//			gcc compile time:		gcc run time:
//			                        	
//      		                     		factorial(5): 120
//      		                        	
//			real	0m1.283s        	real	0m0.002s
//			user	0m1.169s        	user	0m0.002s
//			sys	0m0.113s        	sys	0m0.000s
//			                        	
//			clang compile time:     	clang run time:
//			                        	
//      		                        	factorial(5): 120
//      		                        	
//			real	0m3.683s        	real	0m0.001s
//			user	0m3.384s        	user	0m0.002s
//			sys	0m0.109s        	sys	0m0.000s

		return 0;
	}

