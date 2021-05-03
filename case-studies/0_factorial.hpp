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

// factorial:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear (pair) factorial:

/***********************************************************************************************************************/

	template
	<
		// registers:

			index_type n		= 0,
			index_type p		= 1,

			index_type eq		= 2,
			index_type sub		= 3,
			index_type mult		= 4,

			index_type zero		= 5,
			index_type one		= 6
	>
	constexpr auto pair_fact_contr = n_controller
	<
		n_stem  < test<eq, n, zero>     , _break<p> , apply<p, mult, n, p> >,
		n_lift  < apply<n, sub, n, one>                                    >,

		n_cycle
	>;

	template<auto n, auto d>
	constexpr auto f_n_factorial()
	{
		using n_type = decltype(n);

		constexpr n_type p		= 1;
		constexpr auto eq_op		= equal<n_type>;
		constexpr auto sub_op		= subtract<n_type>;
		constexpr auto mult_op		= multiply<n_type>;
		constexpr n_type c_0		= 0;
		constexpr n_type c_1		= 1;

		constexpr index_type i		= zero;
		constexpr index_type j		= zero;

		return machine_start
		<
			ND, pair_fact_contr<>, d, i, j,
			n, p, eq_op, sub_op, mult_op, c_0, c_1
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto n_factorial = f_n_factorial<n, d>();

/***********************************************************************************************************************/

// perf:

//		printf("%llu\n", n_factorial<utype(5)>);

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

//		printf("%llu\n", n_factorial<utype(20)>);

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

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) factorial:

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
	constexpr auto fact_contr = r_controller
	<
		r_label // fact loop:
		<
			test       < eq        , n          , c_1       >,
			branch     < base_case                          >,
			save       < cont                               >,
			save       < n                                  >,
			apply      < n         , sub        , n   , c_1 >,
			assign     < cont      , after_fact             >,
			goto_contr < fact_loop                          >
		>,

		r_label // after fact:
		<
			restore    < n                     >,
			restore    < cont                  >,
			apply      < val  , mult , n , val >,
			goto_regtr < cont                  >
		>,

		r_label // base case:
		<
			replace    < val  , c_1 >,
			goto_regtr < cont       >
		>,

		r_label // fact done:
		<
			stop       < val   >,
			reg_size   < seven >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, auto d>
	constexpr auto f_r_factorial()
	{
		using n_type = decltype(n);

		constexpr n_type val		= 1;
		constexpr auto eq_op		= equal<n_type>;
		constexpr auto sub_op		= subtract<n_type>;
		constexpr auto mult_op		= multiply<n_type>;
		constexpr n_type c_1		= 1;
		constexpr index_type cont	= 4;

		constexpr index_type i		= one;
		constexpr index_type j		= zero;

		return machine_start
		<
			RD, fact_contr<>, d, i, j,
			val, n, eq_op, sub_op, mult_op, c_1, cont
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto r_factorial = f_r_factorial<n, d>();

/***********************************************************************************************************************/

// perf:

//		printf("%llu\n", r_factorial<utype(5)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                120
//			                                
//			real	0m0.893s                real	0m0.002s
//			user	0m0.809s                user	0m0.000s
//			sys	0m0.085s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                120
//			                                
//			real	0m1.134s                real	0m0.001s
//			user	0m1.036s                user	0m0.001s
//			sys	0m0.081s                sys	0m0.000s

//		printf("%llu\n", r_factorial<utype(20)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m2.177s                real	0m0.002s
//			user	0m2.050s                user	0m0.000s
//			sys	0m0.125s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m3.405s                real	0m0.002s
//			user	0m3.252s                user	0m0.002s
//			sys	0m0.130s                sys	0m0.000s

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

