/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_near_linear_function_space.
**
** cpp_near_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_near_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_near_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#include<cstdio>

/***********************************************************************************************************************/

#include"include.h"

	using namespace meta_programming;
	using namespace machine_space;

#include"case-studies/0_lists.hpp"

/***********************************************************************************************************************/

	using utype = unsigned long long;
	using stype =   signed long long;

/***********************************************************************************************************************/

	using list_5 = auto_pack<3, add<int>, 9, 12, 0>;

	int main(int argc, char *argv[])
	{
		printf("%llu\n", r_factorial<utype(20)>);

		return 0;
	}

	//	printf("%llu\n", n_factorial<utype(5)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                120
//			                                
//			real	0m0.662s                real	0m0.002s
//			user	0m0.602s                user	0m0.001s
//			sys	0m0.060s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                120
//			                                
//			real	0m0.776s                real	0m0.001s
//			user	0m0.702s                user	0m0.001s
//			sys	0m0.057s                sys	0m0.000s

	//	printf("%llu\n", n_factorial<utype(20)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m1.066s                real	0m0.002s
//			user	0m0.938s                user	0m0.001s
//			sys	0m0.101s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m1.463s                real	0m0.001s
//			user	0m1.343s                user	0m0.001s
//			sys	0m0.100s                sys	0m0.000s

