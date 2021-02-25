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

// register machine:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace register_machine
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	using depth_type = unsigned short;
	using index_type = unsigned char;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// f array:

	template<typename Type, Type... Vs>
	constexpr Type f_array(index_type pos)
	{
		constexpr Type array[] = { Vs... };

		return array[pos];
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine declarations:

	#include"subsource/A_machine.hpp"

/***********************************************************************************************************************/

// instruction:

	using instr_type = index_type(*)(index_type);

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr instr_type instruction = f_array<index_type, sizeof...(Vs), Vs...>;

	constexpr index_type instr_length(instr_type i) { return i(0); }

/***********************************************************************************************************************/

// label:

	using label_type = instr_type(*)(index_type);

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	constexpr label_type label = f_array<instr_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

	constexpr index_type label_length(label_type l) { return l(0)(0); }

/***********************************************************************************************************************/

// controller:

	using contr_type = label_type(*)(index_type);

		// pack length is stored as the initial value.

	template<label_type... Vs>
	constexpr contr_type controller = f_array
		<label_type, f_array<instr_type, f_array<index_type, sizeof...(Vs)>>, Vs...>;

	constexpr index_type contr_length(contr_type c)	{ return c(0)(0)(0); }

	//

	constexpr index_type reg_size(contr_type c)
	{
		label_type l = c(contr_length(c));

		return l(label_length(l))(2);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller iteration:

	// Assumes the final controller label is the halt instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/***********************************************************************************************************************/

	template
	<
		auto stop_next   , auto pause_next  , auto branch_next ,
		auto l_goto_next , auto r_goto_next , auto label_next  , auto instr_next
	>
	constexpr auto next(depth_type d, contr_type c, index_type l, index_type m, index_type n, bool is_branch)
	{
		if	(!bool(d))			return pause_next   (c, l, m);
		else if	(l == contr_length(c))		return stop_next    (c, l, m);
		else if (is_branch)			return branch_next  (c, l, m);
		else if	(c(l)(m)(1) == RI::l_goto)	return l_goto_next  (c, l, m);
		else if (c(l)(m)(1) == RI::r_goto)	return r_goto_next  (c, n, m);
		else if (m == label_length(c(l)))	return label_next   (c, l, m);
		else					return instr_next   (c, l, m);
	}

/***********************************************************************************************************************/

// next c:

	constexpr instr_type stop_i      (contr_type c, index_type l, index_type m) { return instruction<RI::stop>;  }
	constexpr instr_type pause_i     (contr_type c, index_type l, index_type m) { return instruction<RI::pause>; }
	constexpr instr_type branch_i    (contr_type c, index_type l, index_type m) { return c( c(l)(m)(2) )(1);     }
	constexpr instr_type (*l_goto_i) (contr_type c, index_type l, index_type m) = branch_i                       ;
	constexpr instr_type r_goto_i    (contr_type c, index_type l, index_type m) { return c(l)(1);                }
	constexpr instr_type label_i     (contr_type c, index_type l, index_type m) { return c(l+1)(1);              }
	constexpr instr_type instr_i     (contr_type c, index_type l, index_type m) { return c(l)(m+1);              }

	// dispatch optimization requires RI enum consecutive constraint:

	constexpr instr_type next_i(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<stop_i, pause_i,
			branch_i, l_goto_i, r_goto_i, label_i, instr_i>(d, c, l, m, n, is_br);
	}

	//

	constexpr index_type next_k(contr_type c, instr_type i)
	{
		if (i(1) == RI::l_assign)	return i(2);
		else if (i(1) == RI::r_assign)	return i(2);
		else if (i(1) == RI::save)	return reg_size(c);
		else if (i(1) == RI::restore)	return reg_size(c);
		else if (i(1) == RI::u_apply)	return i(2);
		else if (i(1) == RI::b_apply)	return i(2);
		else				return 0;
	}

/***********************************************************************************************************************/

// next l:

	constexpr index_type stop_l       (contr_type c, index_type l, index_type m)	{ return l;          }
	constexpr index_type (*pause_l)   (contr_type c, index_type l, index_type m)	= stop_l             ;
	constexpr index_type branch_l     (contr_type c, index_type l, index_type m)	{ return c(l)(m)(2); }
	constexpr index_type (*l_goto_l)  (contr_type c, index_type l, index_type m)	= branch_l           ;
	constexpr index_type (*r_goto_l)  (contr_type c, index_type l, index_type m)	= stop_l             ;
	constexpr index_type label_l      (contr_type c, index_type l, index_type m)	{ return l+1;        }
	constexpr index_type (*instr_l)   (contr_type c, index_type l, index_type m)	= stop_l             ;

	//

	constexpr index_type next_l(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<stop_l, pause_l,
			branch_l, l_goto_l, r_goto_l, label_l, instr_l>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/

// next m:

	constexpr index_type stop_m       (contr_type c, index_type l, index_type m)	{ return m;   }
	constexpr index_type (*pause_m)   (contr_type c, index_type l, index_type m)	= stop_m      ;
	constexpr index_type branch_m     (contr_type c, index_type l, index_type m)	{ return 1;   }
	constexpr index_type (*l_goto_m)  (contr_type c, index_type l, index_type m)	= branch_m    ;
	constexpr index_type (*r_goto_m)  (contr_type c, index_type l, index_type m)	= branch_m    ;
	constexpr index_type (*label_m)   (contr_type c, index_type l, index_type m)	= branch_m    ;
	constexpr index_type instr_m      (contr_type c, index_type l, index_type m)	{ return m+1; }

	//

	constexpr index_type next_m(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<stop_m, pause_m,
			branch_m, l_goto_m, r_goto_m, label_m, instr_m>(d, c, l, m, n, is_br);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machine:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - control
	// l  - label index
	// m  - instruction index
	// Rs - registers

/***********************************************************************************************************************/

// at [0-16):

	#include"subsource/B_at.hpp"

/***********************************************************************************************************************/

// core:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::stop, index_type(0)>*))
	{
		return type_map<auto_pack<Rs...>*>;
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::pause, index_type(0)>*))
	{
		return type_map<alt_pack<c, l, m, Rs...>*>;
	}

	template<auto d, auto c, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::start, index_type(0)>*))
	{
		constexpr instr_type j = c(1)(1);

		return machine<d-1, c, 1, 1, Rs...>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// branch:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::u_branch, index_type(0)>*))
	{
		constexpr instr_type i	= c(l)(m);
		constexpr auto test	= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a	= at<Rs...>(U_value_V<i(4)>);
		constexpr bool is_br	= test(a);
		constexpr instr_type j	= next_i(d, c, l, m, 0, is_br);

		return machine
			<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_pair_V<j(1), next_k(c, j)>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::b_branch, index_type(0)>*))
	{
		constexpr instr_type i	= c(l)(m);
		constexpr auto test	= at<Rs...>(U_value_V<i(3)>);
		constexpr auto a1	= at<Rs...>(U_value_V<i(4)>);
		constexpr auto a2	= at<Rs...>(U_value_V<i(5)>);
		constexpr bool is_br	= test(a1, a2);
		constexpr instr_type j	= next_i(d, c, l, m, 0, is_br);

		return machine
			<d-1, c, next_l(d, c, l, m, 0, is_br),
				next_m(d, c, l, m, 0, is_br), Rs...>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// l_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::l_goto, index_type(0)>*))
	{
		constexpr instr_type j = next_i(d, c, l, m);

		return machine<d-1, c, next_l(d, c, l, m), next_m(d, c, l, m), Rs...>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// r_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto machine(void(*)(auto_pack<RI::r_goto, index_type(0)>*))
	{
		constexpr auto r	= at<Rs...>(U_value_V<c(l)(m)(2)>);
		constexpr instr_type j	= next_i(d, c, l, m, r);

		return machine
			<d-1, c, next_l(d, c, l, m, r), next_m(d, c, l, m, r), Rs...>(U_pair_V<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// l_assign [0-16):

	#include"subsource/C_l_assign.hpp"

/***********************************************************************************************************************/

// r_assign [0-16):

	#include"subsource/D_r_assign.hpp"

/***********************************************************************************************************************/

// save [0-16):

	#include"subsource/E_save.hpp"

/***********************************************************************************************************************/

// restore [0-16):

	#include"subsource/F_replace.hpp"
	#include"subsource/G_restore.hpp"

/***********************************************************************************************************************/

// apply [0-16):

	#include"subsource/H_apply.hpp"

/***********************************************************************************************************************/

// trampoline:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

