/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk
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

//	int main(int argc, char *argv[]) { return 0; }

/************************************************************************************/

#include"include_source.hpp"

	using namespace machine_space;

#include"case-studies/2_filter.hpp"

/************************************************************************************/

	using utype = unsigned long long;
	using stype =   signed long long;

/************************************************************************************/
/************************************************************************************/

// (naive) factorial:

/************************************************************************************/

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

/************************************************************************************/

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

/************************************************************************************/
/************************************************************************************/

// (naive) fibonacci:

/************************************************************************************/

	template
	<
		// registers:

			index_type val		= 0,
			index_type n		= 1,
			index_type less_than	= 2,
			index_type add		= 3,
			index_type sub		= 4,
			index_type c_1		= 5,
			index_type c_2		= 6,
			index_type cont		= 7,

		// labels:

			index_type fib_loop		= 1,
			index_type after_fib_n_1	= 2,
			index_type after_fib_n_2	= 3,
			index_type immediate_answer	= 4,
			index_type fib_done		= 5
	>
	constexpr auto fib_contr = r_controller
	<
		r_label // fib loop:
		<
			test       < less_than        , n          , c_2       >,
			branch     < immediate_answer                          >,
			save       < cont                                      >,
			assign     < cont             , after_fib_n_1          >,
			save       < n                                         >,
			apply      < n                , sub        , n   , c_1 >,
			goto_contr < fib_loop                                  >
		>,

		r_label // after fib n 1:
		<
			restore    < n                     >,
			restore    < cont                  >,
			apply      < n    , sub , n , c_2  >,
			save       < cont                  >,
			assign     < cont , after_fib_n_2  >,
			save       < val                   >,
			goto_contr < fib_loop              >
		>,

		r_label // after fib n 2:
		<
			replace    < n    , val           >,
			restore    < val                  >,
			restore    < cont                 >,
			apply      < val  , add , val , n >,
			goto_regtr < cont                 >
		>,

		r_label // immediate answer:
		<
			replace    < val  , n >,
			goto_regtr < cont     >
		>,

		r_label // fib done:
		<
			stop       < val       >,
			reg_size   < eight     >
		>
	>;

/************************************************************************************/

	template<auto n, auto d>
	constexpr auto f_r_fibonacci()
	{
		using n_type = decltype(n);

		constexpr n_type val		= 1;
		constexpr auto lt_op		= less_than<n_type>;
		constexpr auto add_op		= add<n_type>;
		constexpr auto sub_op		= subtract<n_type>;
		constexpr n_type c_1		= 1;
		constexpr n_type c_2		= 2;
		constexpr index_type cont	= 5;

		constexpr index_type i		= one;
		constexpr index_type j		= zero;

		return machine_start
		<
			RD, fib_contr<>, d, i, j,
			val, n, lt_op, add_op, sub_op, c_1, c_2, cont
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto r_fibonacci = f_r_fibonacci<n, d>();

/************************************************************************************/
/************************************************************************************/

// filter then compose:

/************************************************************************************/

	template<typename T>
	constexpr T square(T x) { return x*x; }

	//

	constexpr auto func_1	= do_compose // 2 x^4 + 1
				<
					square<int>,
					square<int>,
					multiply_by<int, 2>,
					add_by<int, 1>
				>;

	constexpr auto func_2	= safe_do_compose // (3(x + 1))^2
				<
					add_by<int, 1>,
					multiply_by<int, 3>,
					_id_,
					square<int>
				>;

/************************************************************************************/
/************************************************************************************/

	template<utype n>
	void print_factorial() { printf("factorial(%llu): %llu\n", n, r_factorial<n>); }

	template<utype n>
	void print_fibonacci() { printf("fibonacci(%llu): %llu\n", n, r_fibonacci<n>); }

	void print_func_1(utype n) { printf("2x^4+1(%llu): %d\n", n, func_1(n)); }
	void print_func_2(utype n) { printf("(3(x+1))^2(%llu): %d\n", n, func_2(n)); }

/************************************************************************************/
/************************************************************************************/

	int main(int argc, char *argv[])
	{
		// factorial:

		//	0  1  2  3  4   5    6    7      8       9        10       
		//	1  1  2  6  24  120  720  5,040  40,320  362,880  3,628,800

		//	print_factorial<5>();

		// fibonacci:

		//	0  1  2  3  4   5    6    7      8       9        10       
		//	0  1  1  2  3   5    8    13     21      34       55

		//	print_fibonacci<5>();

		// compositions:

		//	print_func_1(5);
		//	print_func_2(5);

			return 0;
	}

