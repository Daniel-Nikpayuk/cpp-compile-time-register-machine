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

// struct array:

/***********************************************************************************************************************/

// (pair) factorial:

	template
	<
		// registers:

			index_type n		= 0,		// n    - 4
			index_type p		= 1,		// p    - 3

			index_type eq		= 2,		// eq   - 1
			index_type sub		= 3,		// sub  - 1
			index_type mult		= 4,		// mult - 1

			index_type zero		= 5,		// zero - 1
			index_type one		= 6		// one  - 1
	>
	constexpr auto pair_fact_contr = nl_controller
	<
		nl_stem  < nl_test<eq , n, zero>	, nl_break<p>	, nl_next<p, mult, n, p>	>,
		nl_lift  < nl_apply<n, sub, n, one>							>,

		nl_cycle
	>;

		// nl_pred - predicate operator
		// nl_oper - register operator
		// nl_ret  - return/break from the cycle.

	template<auto n, depth_type d = 500>
	constexpr auto nl_factorial = near_linear_start
	<
		d, pair_fact_contr<>, n, 1,
			equal<decltype(n)>, subtract<decltype(n)>, multiply<decltype(n)>, 0, 1
	>();

	printf("%llu\n", nl_factorial<utype(16)>);

/***********************************************************************************************************************/

		// f_array:						// s_array:

//			gcc compile time:	gcc run time:		//	gcc compile time:	gcc run time:
//			                                                //	                        
//			                        20922789888000          //	                        20922789888000
//			                                                //	                        
//			real	0m2.095s        real	0m0.002s        //	real	0m2.392s        real	0m0.002s
//			user	0m1.890s        user	0m0.002s        //	user	0m2.212s        user	0m0.000s
//			sys	0m0.149s        sys	0m0.000s        //	sys	0m0.179s        sys	0m0.001s
//			                                                //	                        
//			clang compile time:     clang run time:         //	clang compile time:     clang run time:
//			                                                //	                        
//			                        20922789888000          //	                        20922789888000
//			                                                //	                        
//			real	0m4.472s        real	0m0.002s        //	real	0m4.402s        real	0m0.002s
//			user	0m4.053s        user	0m0.001s        //	user	0m4.158s        user	0m0.002s
//			sys	0m0.257s        sys	0m0.000s        //	sys	0m0.150s        sys	0m0.000s

