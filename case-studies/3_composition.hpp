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

// fibonacci:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) fibonacci:

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
	constexpr auto fib_contr = r_controller
	<
		r_label // fact loop:
		<
			r_test       < eq        , n          , c_1       >,
			r_branch     < base_case                          >,
			r_save       < cont                               >,
			r_save       < n                                  >,
			r_apply      < n         , sub        , n   , c_1 >,
			r_assign     < cont      , after_fact             >,
			r_goto_contr < fact_loop                          >
		>,

		r_label // after fact:
		<
			r_restore    < n                     >,
			r_restore    < cont                  >,
			r_apply      < val  , mult , n , val >,
			r_goto_regtr < cont                  >
		>,

		r_label // base case:
		<
			r_replace    < val  , c_1 >,
			r_goto_regtr < cont       >
		>,

		r_label // fact done:
		<
			r_stop     < val   >,
			r_reg_size < seven >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, depth_type d = 500>
	constexpr auto r_fibonacci = machine_start
	<
		RD, fib_contr<>, d, one, zero, decltype(n)(1), n,
		equal<decltype(n)>, subtract<decltype(n)>, multiply<decltype(n)>, decltype(n)(1), four
	>();

/***********************************************************************************************************************/

// perf:

	//	printf("%llu\n", r_fibonacci<utype(5)>);

	//	printf("%llu\n", r_fibonacci<utype(20)>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

