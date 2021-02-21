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

	using size_type = unsigned char;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// f array:

	template<typename Type, Type... Vs>
	constexpr Type f_array(size_type pos)
	{
		constexpr Type array[] = { Vs... };

		return array[pos];
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

// register:

	struct RI
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

// instruction:

	using instr_type = size_type(*)(size_type);

		// pack length is stored as the initial value.

	template<size_type... Vs>
	constexpr instr_type instruction = f_array<size_type, sizeof...(Vs), Vs...>;

	constexpr size_type instr_length(instr_type i) { return i(0); }

/***********************************************************************************************************************/

// label:

	using label_type = instr_type(*)(size_type);

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	constexpr label_type label = f_array<instr_type, f_array<size_type, sizeof...(Vs)>, Vs...>;

	constexpr size_type label_length(label_type l) { return l(0)(0); }

/***********************************************************************************************************************/

// controller:

	using contr_type = label_type(*)(size_type);

		// pack length is stored as the initial value.

	template<label_type... Vs>
	constexpr contr_type controller = f_array
		<label_type, f_array<instr_type, f_array<size_type, sizeof...(Vs)>>, Vs...>;

	constexpr size_type contr_length(contr_type c)	{ return c(0)(0)(0); }
	constexpr size_type reg_size(contr_type c)	{ return c(contr_length(c))(1)(2); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller iteration:

	// Assumes the final controller label is the halt instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/***********************************************************************************************************************/

	template
	<
		auto stop_next   , auto pause_next   , auto branch_next ,
		auto l_goto_next , auto r_goto_next  , auto assign_next ,
		auto save_next   , auto restore_next , auto label_next  , auto instr_next
	>
	constexpr size_type next(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_branch = false)
	{
		if	(!bool(d))			return pause_next   (c, l, m);
		else if	(l == contr_length(c))		return stop_next    (c, l, m);
		else if (is_branch)			return branch_next  (c, l, m);
		else if	(c(l)(m)(1) == RI::l_goto)	return l_goto_next  (c, l, m);
		else if (c(l)(m)(1) == RI::r_goto)	return r_goto_next  (c, n, m);
		else if (c(l)(m)(1) == RI::assign)	return assign_next  (c, l, m);
		else if (c(l)(m)(1) == RI::save)	return save_next    (c, l, m);
		else if (c(l)(m)(1) == RI::restore)	return restore_next (c, l, m);
		else if (m == label_length(c(l)))	return label_next   (c, l, m);
		else					return instr_next   (c, l, m);
	}

/***********************************************************************************************************************/

// next c:

	constexpr size_type stop_c      (contr_type c, size_type l, size_type m) { return RI::stop;                  }
	constexpr size_type pause_c     (contr_type c, size_type l, size_type m) { return RI::pause;                 }
	constexpr size_type break_c     (contr_type c, size_type l, size_type m) { return c( c(l)(m)(2) )(1)(1);     }
	constexpr size_type (*l_goto_c) (contr_type c, size_type l, size_type m) = break_c;
	constexpr size_type r_goto_c    (contr_type c, size_type l, size_type m) { return c(l)(1)(1);                }

		// dispatch optimization requires RI enum consecutive constraint:

	constexpr size_type assign_c    (contr_type c, size_type l, size_type m) { return RI::assign  + c(l)(m)(2);  }
	constexpr size_type save_c      (contr_type c, size_type l, size_type m) { return RI::save    + reg_size(c); }
	constexpr size_type restore_c   (contr_type c, size_type l, size_type m) { return RI::restore + reg_size(c); }

	constexpr size_type label_c     (contr_type c, size_type l, size_type m) { return c(l+1)(1)(1);              }
	constexpr size_type instr_c     (contr_type c, size_type l, size_type m) { return c(l)(m+1)(1);              }

	constexpr size_type (*next_c)(size_type, contr_type, size_type, size_type, size_type, bool) = next
	<
		stop_c, pause_c, break_c, l_goto_c, r_goto_c,
		assign_c, save_c, restore_c, label_c, instr_c
	>;

/***********************************************************************************************************************/

// next l:

	constexpr size_type stop_l       (contr_type c, size_type l, size_type m)	{ return l;          }
	constexpr size_type (*pause_l)   (contr_type c, size_type l, size_type m)	= stop_l;
	constexpr size_type break_l      (contr_type c, size_type l, size_type m)	{ return c(l)(m)(2); }
	constexpr size_type (*l_goto_l)  (contr_type c, size_type l, size_type m)	= break_l;
	constexpr size_type (*r_goto_l)  (contr_type c, size_type l, size_type m)	= stop_l;
	constexpr size_type (*assign_l)  (contr_type c, size_type l, size_type m)	= stop_l;
	constexpr size_type (*save_l)    (contr_type c, size_type l, size_type m)	= stop_l;
	constexpr size_type (*restore_l) (contr_type c, size_type l, size_type m)	= stop_l;
	constexpr size_type label_l      (contr_type c, size_type l, size_type m)	{ return l+1;        }
	constexpr size_type (*instr_l)   (contr_type c, size_type l, size_type m)	= stop_l;

	constexpr size_type (*next_l)(size_type, contr_type, size_type, size_type, size_type, bool) = next
	<
		stop_l, pause_l, break_l, l_goto_l, r_goto_l,
		assign_l, save_l, restore_l, label_l, instr_l
	>;

/***********************************************************************************************************************/

// next m:

	constexpr size_type stop_m       (contr_type c, size_type l, size_type m)	{ return m;   }
	constexpr size_type (*pause_m)   (contr_type c, size_type l, size_type m)	= stop_m;
	constexpr size_type break_m      (contr_type c, size_type l, size_type m)	{ return 1;   }
	constexpr size_type (*l_goto_m)  (contr_type c, size_type l, size_type m)	= break_m;
	constexpr size_type (*r_goto_m)  (contr_type c, size_type l, size_type m)	= break_m;
	constexpr size_type (*assign_m)  (contr_type c, size_type l, size_type m)	= stop_m;
	constexpr size_type (*save_m)    (contr_type c, size_type l, size_type m)	= stop_m;
	constexpr size_type (*restore_m) (contr_type c, size_type l, size_type m)	= stop_m;
	constexpr size_type (*label_m)   (contr_type c, size_type l, size_type m)	= break_m;
	constexpr size_type instr_m      (contr_type c, size_type l, size_type m)	{ return m+1; }

	constexpr size_type (*next_m)(size_type, contr_type, size_type, size_type, size_type, bool) = next
	<
		stop_m, pause_m, break_m, l_goto_m, r_goto_m,
		assign_m, save_m, restore_m, label_m, instr_m
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machine:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

/***********************************************************************************************************************/

	// d  - depth
	// c  - control
	// l  - label index
	// m  - instruction index
	// Rs - registers

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::stop>*))
	{
		return type_map<auto_list<Rs...>>;
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::pause>*))
	{
		return type_map<alt_list<c, l, m, Rs...>>;
	}

	template<auto d, auto c, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::start>*))
	{
		return register_machine<d-1, c, 1, 1, Rs...>(U_value_V<c(1)(1)(1)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// branch:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::u_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr bool is_br		= test(a);

		return register_machine
			<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m, 0, is_br)>);
	}

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::b_branch>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto test		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<size_type, Rs...>(U_value_V<i(4)>);
		constexpr auto a2		= at<size_type, Rs...>(U_value_V<i(5)>);
		constexpr bool is_br		= test(a1, a2);

		return register_machine
			<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m, 0, is_br)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// l_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::l_goto>*))
	{
		return register_machine<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m)>);
	}

/***********************************************************************************************************************/

// r_goto:

	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::r_goto>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr auto r		= at<size_type, Rs...>(U_value_V<i(2)>);

		return register_machine
			<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m, r)>);
	}

/***********************************************************************************************************************/

// assign [0-15):

	#include"fast_track/A_assign.hpp"

/***********************************************************************************************************************/

// save [0-15):

	#include"fast_track/B_save.hpp"

/***********************************************************************************************************************/

// restore [0-15):

	#include"fast_track/C_restore.hpp"

/***********************************************************************************************************************/

// apply:

/*
	template<auto d, auto c, auto l, auto m, auto... Rs>
	constexpr auto register_machine(void(*)(auto_map<RI::apply>*))
	{
		constexpr instr_type i		= c(l)(m);
		constexpr size_type label	= at<size_type, Rs...>(U_value_V<i(2)>);
		constexpr auto test		= at<size_type, Rs...>(U_value_V<i(3)>);
		constexpr auto a1		= at<size_type, Rs...>(U_value_V<i(4)>);

		if constexpr (instr_length(i) == 4)
		{
			constexpr bool is_br	= test(a1);

			return register_machine
				<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m, 0, is_br)>);
		}
		else
		{
			constexpr auto a2	= at<size_type, Rs...>(U_value_V<i(5)>);
			constexpr bool is_br	= test(a1, a2);

			return register_machine
				<d-1, c, next_l(c, l, m), next_m(c, l, m), Rs...>(U_value_V<next_c(c, l, m, 0, is_br)>);
		}
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

