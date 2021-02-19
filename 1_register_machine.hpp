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
		enum : size_type { assign = 0, test, branch, l_goto, r_goto, save, restore };
		enum : size_type
		{
			apply = restore + 1	,

			apply_2_0 = restore + 1	, apply_2_1	, apply_2_2	, apply_2_3	,
			apply_2_4		, apply_2_5	, apply_2_6	, apply_2_7	, apply_2_8
		};
	};

/***********************************************************************************************************************/

// template:

	struct TI
	{
		enum : size_type
		{
			stop = 0	, pause		, start		,

			replace_0	, replace_1	, replace_2	, replace_3	,
			replace_4	, replace_5	, replace_6	, replace_7	,

			dimension
		};
	};

/***********************************************************************************************************************/

// instruction:

	using instruction_type = size_type(*)(size_type);

		// pack length is stored as the initial value.

	template<size_type... Vs>
	constexpr instruction_type instruction = f_array<size_type, sizeof...(Vs), Vs...>;

	constexpr size_type instruction_length(instruction_type i) { return i(0); }

/***********************************************************************************************************************/

// label:

	using label_type = instruction_type(*)(size_type);

		// pack length is stored as the initial value.

	template<instruction_type... Vs>
	constexpr label_type label = f_array<instruction_type, f_array<size_type, sizeof...(Vs)>, Vs...>;

	constexpr size_type label_length(label_type l) { return l(0)(0); }

/***********************************************************************************************************************/

// controller:

	using contr_type = label_type(*)(size_type);

		// pack length is stored as the initial value.

	template<label_type... Vs>
	constexpr contr_type controller = f_array
		<label_type, f_array<instruction_type, f_array<size_type, sizeof...(Vs)>>, Vs...>;

	constexpr size_type controller_length(contr_type c) { return c(0)(0)(0); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// iterators:

		// assumes the final controller label is the halt instruction.

/***********************************************************************************************************************/

	template
	<
		auto stop_next, auto pause_next, auto branch_next,
		auto l_goto_next, auto r_goto_next, auto label_next, auto instr_next
	>
	constexpr size_type next(size_type d,
		contr_type c, size_type l, size_type m, size_type n = 0, bool is_branch = false)
	{
		if	(!bool(d))			return pause_next  (c, l, m);
		else if	(l == controller_length(c))	return stop_next   (c, l, m);
		else if (is_branch)			return branch_next (c, l, m);
		else if	(c(l)(m)(1) == RI::l_goto)	return l_goto_next (c, l, m);
		else if (c(l)(m)(1) == RI::r_goto)	return r_goto_next (c, n, m);
		else if (m == label_length(c(l)))	return label_next  (c, l, m);
		else					return instr_next  (c, l, m);
	}

/***********************************************************************************************************************/

// next c:

	constexpr size_type sn_c(contr_type c, size_type l, size_type m)	{ return TI::stop;		}
	constexpr size_type pn_c(contr_type c, size_type l, size_type m)	{ return TI::pause;		}
	constexpr size_type bn_c(contr_type c, size_type l, size_type m)	{ return c( c(l)(m)(5) )(1)(1);	}
	constexpr size_type lg_c(contr_type c, size_type l, size_type m)	{ return c( c(l)(m)(1) )(1)(1);	}
	constexpr size_type rg_c(contr_type c, size_type l, size_type m)	{ return c(l)(1)(1);		}
	constexpr size_type ln_c(contr_type c, size_type l, size_type m)	{ return c(l+1)(1)(1);		}
	constexpr size_type in_c(contr_type c, size_type l, size_type m)	{ return c(l)(m+1)(1);		}

	constexpr size_type (*next_c)(size_type, contr_type, size_type, size_type, size_type, bool) = next
		<pn_c, sn_c, bn_c, lg_c, rg_c, ln_c, in_c>;

/***********************************************************************************************************************/

// next l:

	constexpr size_type sn_l(contr_type c, size_type l, size_type m)	{ return l;		}
	constexpr size_type pn_l(contr_type c, size_type l, size_type m)	{ return l;		}
	constexpr size_type bn_l(contr_type c, size_type l, size_type m)	{ return c(l)(m)(5);	}
	constexpr size_type lg_l(contr_type c, size_type l, size_type m)	{ return c(l)(m)(1);	}
	constexpr size_type rg_l(contr_type c, size_type l, size_type m)	{ return l;		}
	constexpr size_type ln_l(contr_type c, size_type l, size_type m)	{ return l+1;		}
	constexpr size_type in_l(contr_type c, size_type l, size_type m)	{ return l;		}

	constexpr size_type (*next_l)(size_type, contr_type, size_type, size_type, size_type, bool) = next
		<pn_l, sn_l, bn_l, lg_l, rg_l, ln_l, in_l>;

/***********************************************************************************************************************/

// next m:

	constexpr size_type sn_m(contr_type c, size_type l, size_type m)	{ return m; }
	constexpr size_type pn_m(contr_type c, size_type l, size_type m)	{ return m; }
	constexpr size_type bn_m(contr_type c, size_type l, size_type m)	{ return 1; }
	constexpr size_type lg_m(contr_type c, size_type l, size_type m)	{ return 1; }
	constexpr size_type rg_m(contr_type c, size_type l, size_type m)	{ return 1; }
	constexpr size_type ln_m(contr_type c, size_type l, size_type m)	{ return 1; }
	constexpr size_type in_m(contr_type c, size_type l, size_type m)	{ return m+1; }

	constexpr size_type (*next_m)(size_type, contr_type, size_type, size_type, size_type, bool) = next
		<pn_m, sn_m, bn_m, lg_m, rg_m, ln_m, in_m>;

/***********************************************************************************************************************/

// instruction accessors:

/*
	constexpr size_type rm_replace(control_type control, size_type m, size_type n)
	{
		return control(label)(index)(1);
	}

	template<control_type control, size_type m, size_type n>
	using rm_op = T_type_U<control(label)(index)(0)>;

	template<control_type control, size_type m, size_type n>
	constexpr size_type rm_arg1 = control(label)(index)(1);

	template<control_type control, size_type m, size_type n>
	constexpr size_type rm_arg1 = control(label)(index)(2);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machine:

/***********************************************************************************************************************/

// apply:

/*
	template<typename Op, auto arg1, auto arg2>
	constexpr auto binary_apply = Op::template result<arg1, arg2>;
*/

/***********************************************************************************************************************/

// at:

/*
	template<size_type> struct at;

	template<>
	struct at<0>
	{
		template<auto R0, auto... Rs>
		static constexpr auto result = R0;
	};

	template<>
	struct at<1>
	{
		template<auto R0, auto R1, auto... Rs>
		static constexpr auto result = R1;
	};

	template<>
	struct at<2>
	{
		template<auto R0, auto R1, auto R2, auto... Rs>
		static constexpr auto result = R2;
	};

	template<>
	struct at<3>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto... Rs>
		static constexpr auto result = R3;
	};

	template<>
	struct at<4>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs>
		static constexpr auto result = R4;
	};

	template<>
	struct at<5>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs>
		static constexpr auto result = R5;
	};

	template<>
	struct at<6>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs>
		static constexpr auto result = R6;
	};

	template<>
	struct at<7>
	{
		template<auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs>
		static constexpr auto result = R7;
	};
*/

/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - control
	// m  - label index
	// n  - instruction index
	// Rs - registers

/*
	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::stop>))
	{
		return type_map<auto_list<Rs...>>;
	}

	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::pause>))
	{
		return type_map<alt_list<c, m, n, Rs...>>;
	}

	template<auto d, auto c, auto m, auto n, auto... Rs>
	constexpr auto register_machine(void(*)(auto_list<TI::start>))
	{
		return register_machine<d-1, c, m, n, Rs...>(U_value_V<next_c(d, c, m, n)>);
	}
*/

/***********************************************************************************************************************/

// replace:

/*
	template<>
	struct register_machine<TI::replace_0>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_1>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_2>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_3>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_4>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_5>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_6>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, R5, V, Rs...>;
	};

	template<>
	struct register_machine<TI::replace_7>
	{
		template
		<
			auto d, auto c, auto m, auto n, auto V,
			auto R0, auto R1, auto R2, auto R3, auto R4, auto R5, auto R6, auto R7, auto... Rs
		>
		using result = typename register_machine
		<
			rm_instruction(c, false, m, n)

		>::template result<d-1, c, m, n, R0, R1, R2, R3, R4, R5, R6, V, Rs...>;
	};
*/

/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// operators:

/*
	template<>
	struct register_machine<TI::binary_apply>
	{
		template<auto d, auto c, auto m, auto n, auto... Rs>
		using result = typename register_machine
		<
			rm_replace(c, m, n)

		>::template result
		<
			d-1, c, label(m), index(n),

			binary_apply
			<
				rm_op<c, label, index>,
				rm_arg1<c, label, index>,
				rm_arg2<c, label, index>
			>,

			Rs...
		>;
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

