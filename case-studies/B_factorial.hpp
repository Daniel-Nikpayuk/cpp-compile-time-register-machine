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

// factorial:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template
	<
		// registers:

			index_type val		= 0,
			index_type n		= 1,
			index_type eq		= 2,
			index_type sub		= 3,
			index_type mult		= 4,
			index_type c_1		= 5,
			index_type cont		= 6,

		// labels:

			index_type fact_loop	= 1,
			index_type after_fact	= 2,
			index_type base_case	= 3,
			index_type fact_done	= 4
	>
	constexpr auto fact_contr = controller
	<
		label // fact loop:
		<
			instruction < MI::b_branch , base_case , eq         , n , c_1 >,
			instruction < MI::save     , cont                             >,
			instruction < MI::save     , n                                >,
			instruction < MI::b_apply  , n         , sub        , n , c_1 >,
			instruction < MI::l_assign , cont      , after_fact           >,
			instruction < MI::l_goto   , fact_loop                        >
		>,

		label // after fact:
		<
			instruction < MI::restore  , n                     >,
			instruction < MI::restore  , cont                  >,
			instruction < MI::b_apply  , val  , mult , n , val >,
			instruction < MI::r_goto   , cont                  >
		>,

		label // base case:
		<
			instruction < MI::r_assign , val  , c_1 >,
			instruction < MI::r_goto   , cont       >
		>,

		label // fact done:
		<
			instruction < MI::at     , 6 >,
			instruction < MI::r_size , 7 >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, depth_type depth = 500>
	constexpr auto factorial = start
	<
		depth, fact_contr<>, 4, 1, n,
		equal<decltype(n)>, subtract<decltype(n)>, multiply<decltype(n)>, 1

	>(U_pair_V<MI::start, index_type(0)>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear pair factorial:

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

	// constexpr only:					// hybrid pop:

//		gcc compile time:	gcc run time:		//	gcc compile time:	gcc run time:
//		                                                //	                        
//		                        20922789888000          //	                        20922789888000
//		                                                //	                        
//		real	0m2.387s        real	0m0.001s        //	real	0m2.165s        real	0m0.002s
//		user	0m2.226s        user	0m0.001s        //	user	0m1.935s        user	0m0.000s
//		sys	0m0.155s        sys	0m0.000s        //	sys	0m0.170s        sys	0m0.002s
//		                                                //	                        
//		clang compile time:     clang run time:         //	clang compile time:     clang run time:
//		                                                //	                        
//		                        20922789888000          //	                        20922789888000
//		                                                //	                        
//		real	0m5.064s        real	0m0.001s        //	real	0m4.810s        real	0m0.002s
//		user	0m4.668s        user	0m0.000s        //	user	0m4.348s        user	0m0.002s
//		sys	0m0.228s        sys	0m0.001s        //	sys	0m0.280s        sys	0m0.000s

	// hybrid variadic (all):				// hybrid all:

//		gcc compile time:	gcc run time:		//	gcc compile time:	gcc run time:
//		                                                //	                        
//		                        20922789888000          //	                        20922789888000
//		                                                //	                        
//		real	0m1.997s        real	0m0.002s        //	real	0m1.093s        real	0m0.002s
//		user	0m1.803s        user	0m0.001s        //	user	0m0.992s        user	0m0.001s
//		sys	0m0.159s        sys	0m0.000s        //	sys	0m0.101s        sys	0m0.000s
//		                                                //	                        
//		clang compile time:     clang run time:         //	clang compile time:     clang run time:
//		                                                //	                        
//		                        20922789888000          //	                        20922789888000
//		                                                //	                        
//		real	0m3.600s        real	0m0.002s        //	real	0m1.506s        real	0m0.001s
//		user	0m3.408s        user	0m0.000s        //	user	0m1.366s        user	0m0.001s
//		sys	0m0.167s        sys	0m0.002s        //	sys	0m0.112s        sys	0m0.000s

	// factorial(16):

		// replace optimization:				// at optimization:

//			gcc compile time:	gcc run time:		//	gcc compile time:	gcc run time:
//			                                                //	                        
//			                        20922789888000          //	                        20922789888000
//			                                                //	                        
//			real	0m0.838s        real	0m0.002s        //	real	0m0.590s        real	0m0.002s
//			user	0m0.761s        user	0m0.001s        //	user	0m0.510s        user	0m0.002s
//			sys	0m0.079s        sys	0m0.000s        //	sys	0m0.081s        sys	0m0.000s
//			                                                //	                        
//			clang compile time:     clang run time:         //	clang compile time:     clang run time:
//			                                                //	                        
//			                        20922789888000          //	                        20922789888000
//			                                                //	                        
//			real	0m1.137s        real	0m0.002s        //	real	0m0.836s        real	0m0.002s
//			user	0m1.049s        user	0m0.002s        //	user	0m0.727s        user	0m0.002s
//			sys	0m0.070s        sys	0m0.000s        //	sys	0m0.090s        sys	0m0.000s


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

