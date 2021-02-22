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

// testing:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace testing
{
	using namespace samples;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// temporary list operators:

/***********************************************************************************************************************/

	template<template<auto...> class ListName, auto V0, auto V1, auto... Vs>
	constexpr auto list_at1(void(*)(ListName<V0, V1, Vs...>*))
	{
		return V1;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// experimental alternatives:

/***********************************************************************************************************************/

	struct RI_v1
	{
		enum : size_type
		{
			stop = 0   , pause      , start      , u_branch   ,
			b_branch   , l_goto     , r_goto     , assign     ,
			save       , restore    , u_apply    , b_apply    ,

		// dispatch optimizations require these to be consecutive:

			assign_0   , assign_1   , assign_2   , assign_3   ,
			assign_4   , assign_5   , assign_6   , assign_7   ,
			assign_8   , assign_9   , assign_10  , assign_11  ,
			assign_12  , assign_13  , assign_14  , assign_15  ,

		// dispatch optimizations require these to be consecutive:

			save_0     , save_1     , save_2     , save_3     ,
			save_4     , save_5     , save_6     , save_7     ,
			save_8     , save_9     , save_10    , save_11    ,
			save_12    , save_13    , save_14    , save_15    ,

		// dispatch optimizations require these to be consecutive:

			replace_0  , replace_1  , replace_2  , replace_3  ,
			replace_4  , replace_5  , replace_6  , replace_7  ,
			replace_8  , replace_9  , replace_10 , replace_11 ,
			replace_12 , replace_13 , replace_14 , replace_15 ,

		// dispatch optimizations require these to be consecutive:

			restore_0  , restore_1  , restore_2  , restore_3  ,
			restore_4  , restore_5  , restore_6  , restore_7  ,
			restore_8  , restore_9  , restore_10 , restore_11 ,
			restore_12 , restore_13 , restore_14 , restore_15 ,

			r_size
		};

		enum : size_type
		{
			fold = r_size + 1     ,
			fold_2_0 = r_size + 1 , fold_2_1 , fold_2_2 , fold_2_3 , fold_2_4 ,
			fold_2_5              , fold_2_6 , fold_2_7 , fold_2_8 , fold_2_9
		};
	};

/***********************************************************************************************************************/

// next (alternate version):

	template
	<
		auto stop_next, auto pause_next, auto branch_next,
		auto l_goto_next, auto r_goto_next, auto label_next, auto instr_next
	>
	constexpr size_type next_v1(size_type d, contr_type c, size_type l, size_type m, size_type n = 0, bool is_branch = false)
	{
		bool d_break		= !bool(d);
		bool c_break		= !d_break && (l == contr_length(c));
		bool l_break		= !d_break && !c_break && (m == label_length(c(l)));
		bool is_l_goto		= !d_break && !c_break && !l_break && (c(l)(m)(1) == RI::l_goto);
		bool is_r_goto		= !d_break && !c_break && !l_break && (c(l)(m)(1) == RI::r_goto);

		return (d_break ? pause_next			:
			c_break ? stop_next			:
			l_break ?

				(is_branch ? branch_next	:
				 is_l_goto ? l_goto_next	:
				 is_r_goto ? r_goto_next	:
					       label_next)	:

				(is_branch ? branch_next	:
				 is_l_goto ? l_goto_next	:
				 is_r_goto ? r_goto_next	:
					       instr_next))	(c, l, m, n);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// printing:

/***********************************************************************************************************************/

// register instruction:

	void print_RI(size_type n)
	{
		printf("%s, ",	(n == RI::l_assign ) ? "l_assign" :
				(n == RI::r_assign ) ? "r_assign" :
				(n == RI::u_branch ) ? "u_branch" :
				(n == RI::b_branch ) ? "b_branch" :
				(n == RI::l_goto   ) ? "l_goto"   :
				(n == RI::r_goto   ) ? "r_goto"   :
				(n == RI::save     ) ? "save"     :
				(n == RI::restore  ) ? "restore"  :
				(n == RI::u_apply  ) ? "u_apply"  : "b_apply");
	}

	void print_next(size_type d, contr_type c, size_type l, size_type m, size_type n = 0, bool is_branch = false)
	{
		print_RI(next_c(d, c, l, m, n, is_branch));
		printf("%u, %u\n", next_l(d, c, l, m, n, is_branch), next_m(d, c, l, m, n, is_branch));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// next:

	void test_next()
	{
		print_next(1, fact_contr, 1, 1, 0, true);	// assign  3 1
		print_next(1, fact_contr, 1, 1);		// save    1 2
		print_next(1, fact_contr, 1, 2);		// save    1 3
		print_next(1, fact_contr, 1, 3);		// apply   1 4
		print_next(1, fact_contr, 1, 4);		// assign  1 5
		print_next(1, fact_contr, 1, 5);		// l_goto  1 6
		print_next(1, fact_contr, 1, 6);		// branch  1 1
		printf("\n");

		print_next(1, fact_contr, 2, 1);		// restore 2 2
		print_next(1, fact_contr, 2, 2);		// apply   2 3
		print_next(1, fact_contr, 2, 3);		// r_goto  2 4
		print_next(1, fact_contr, 2, 4, 1);		// branch  1 1
		print_next(1, fact_contr, 2, 4, 2);		// restore 2 1
		print_next(1, fact_contr, 2, 4, 3);		// assign  3 1
		printf("\n");

		print_next(1, fact_contr, 3, 1);		// r_goto  3 2
		print_next(1, fact_contr, 3, 2, 1);		// branch  1 1
		print_next(1, fact_contr, 3, 2, 2);		// restore 2 1
		print_next(1, fact_contr, 3, 2, 3);		// assign  3 1
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

