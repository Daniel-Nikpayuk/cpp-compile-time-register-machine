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

// experimental alternatives:

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

	void print_RI(size_type n)
	{
		printf("%s, ",	(n == RI::assign   ) ? "assign"   :
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
		print_next(1, fact_c, 1, 1, 0, true);	// assign  3 1
		print_next(1, fact_c, 1, 1);		// save    1 2
		print_next(1, fact_c, 1, 2);		// save    1 3
		print_next(1, fact_c, 1, 3);		// apply   1 4
		print_next(1, fact_c, 1, 4);		// assign  1 5
		print_next(1, fact_c, 1, 5);		// l_goto  1 6
		print_next(1, fact_c, 1, 6);		// branch  1 1
		printf("\n");

		print_next(1, fact_c, 2, 1);		// restore 2 2
		print_next(1, fact_c, 2, 2);		// apply   2 3
		print_next(1, fact_c, 2, 3);		// r_goto  2 4
		print_next(1, fact_c, 2, 4, 1);		// branch  1 1
		print_next(1, fact_c, 2, 4, 2);		// restore 2 1
		print_next(1, fact_c, 2, 4, 3);		// assign  3 1
		printf("\n");

		print_next(1, fact_c, 3, 1);		// r_goto  3 2
		print_next(1, fact_c, 3, 2, 1);		// branch  1 1
		print_next(1, fact_c, 3, 2, 2);		// restore 2 1
		print_next(1, fact_c, 3, 2, 3);		// assign  3 1
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

