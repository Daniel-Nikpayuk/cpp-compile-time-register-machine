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

	// restore, apply require 2 nesting depths. <-- the compilation error "between" suggests just one decrement.
	// n = 5
	// depth:

	// branch   1    - c 1 1 4 1 5 ... 
	// save     2    - c 1 2 4 1 5 ... 4
	// save     3    - c 1 3 4 1 5 ... 5 4
	// b_apply  4,5  - c 1 4 4 1 4 ... 5 4
	// assign   6    - c 1 5 2 1 4 ... 5 4
	// l_goto   7    - c 1 6 2 1 4 ... 5 4

	// branch   8    - c 1 1 2 1 4 ... 5 4
	// save     9    - c 1 2 2 1 4 ... 2 5 4
	// save    10    - c 1 3 2 1 4 ... 4 2 5 4
	// b_apply 11,12 - c 1 4 2 1 3 ... 4 2 5 4
	// assign  13    - c 1 5 2 1 3 ... 4 2 5 4
	// l_goto  14    - c 1 6 2 1 3 ... 4 2 5 4

/***********************************************************************************************************************/

	// n = 1
	// depth:

	// branch   1    - c 1 1 4 1 1 ... 
	// r_assign 2    - c 3 1 4 1 1 ... 
	// r_goto   3    - c 3 2 4 1 1 ... 

/***********************************************************************************************************************/


		int main(int argc, char *argv[])
		{
			constexpr auto n	= 5;
			constexpr auto result	= list_at1(factorial<n>);
		
			printf("factorial(%d): %d\n", n, result);

//				gcc compile time:		gcc run time:
//				                        	
//              		                     		factorial(5): 120
//              		                        	
//				real	0m1.283s        	real	0m0.002s
//				user	0m1.169s        	user	0m0.002s
//				sys	0m0.113s        	sys	0m0.000s
//				                        	
//				clang compile time:     	clang run time:
//				                        	
//              		                        	factorial(5): 120
//              		                        	
//				real	0m3.683s        	real	0m0.001s
//				user	0m3.384s        	user	0m0.002s
//				sys	0m0.109s        	sys	0m0.000s

			return 0;
		}

















	//	constexpr auto result = U_type_T<alt_list<5>>;

	//	printf("%s\n", V_is_auto_list_U(result) ? "true" : "false");
	//	printf("%s\n", V_is_alt_list_U(result) ? "true" : "false");

	//	printf("%d\n", factorial<5>);
