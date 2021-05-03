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

// machine controllers:

	// I would prefer to implement indices as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// application (abstraction):

	using v_appl_type = index_type(*)(index_type);

	struct VAppl
	{
		// registers:

			static constexpr index_type size		=  0;
			static constexpr index_type name		=  1;
			static constexpr index_type reg			=  2;
			static constexpr index_type op			=  3;
			static constexpr index_type arg			=  4;
			static constexpr index_type arg1		=  4;
			static constexpr index_type arg2		=  5;

		// dispatch:

			static constexpr index_type unary		=  0;
			static constexpr index_type binary		=  1;

		// procedures:

			static constexpr index_type length (v_appl_type i) { return i(size); }
			static constexpr index_type arity  (v_appl_type i) { return i(size) == 4 ? unary : binary; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr v_appl_type v_application = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// locus:

	using v_loc_type = depth_type(*)(index_type);

		// pack length is stored as the initial value.

	template<depth_type... Vs>
	constexpr v_loc_type v_locus = f_array<depth_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// controller:

	using v_ctr_type = index_type(*)(index_type);

	struct VCtr
	{
		// registers:

			static constexpr index_type size	=  0;

		// procedures:

			static constexpr index_type length (v_ctr_type c) { return c(size); }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr v_ctr_type v_controller = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// dispatch:

	constexpr index_type v_next_name(v_ctr_type c, pair_type p)
	{
		if (!bool(p[VInd::depth]))	return VM::pause;
		else 				return c(p[VInd::index]+1);
	}

	template<pair_type p>
	constexpr pair_type v_next_index = !bool(p[VInd::depth]) ? p : pair<p[VInd::depth]-1, p[VInd::index]+1>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// application:

		// inherits variadic application.

	using l_appl_type = v_appl_type;

	struct LAppl
	{
		// registers:

			static constexpr index_type size			=  VAppl::size;
			static constexpr index_type name			=  VAppl::name;
			static constexpr index_type reg				=  VAppl::reg;
			static constexpr index_type op				=  VAppl::op;
			static constexpr index_type arg				=  VAppl::arg;
			static constexpr index_type arg1			=  VAppl::arg1;
			static constexpr index_type arg2			=  VAppl::arg2;

		// dispatch:

			static constexpr index_type unary			=  VAppl::unary;
			static constexpr index_type binary			=  VAppl::binary;

		// procedures:

			static constexpr index_type (*length) (l_appl_type)	= VAppl::length;
			static constexpr index_type (*arity)  (l_appl_type)	= VAppl::arity;
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr l_appl_type l_application = v_application<Vs...>;

	// syntactic sugar:

		template<index_type Reg, index_type Op, index_type... Args>
		constexpr l_appl_type l_apply = l_application<LM::apply, Reg, Op, Args...>;

		template<index_type B>
		constexpr l_appl_type l_stop = l_application<LM::stop, B>;

/***********************************************************************************************************************/

// controller:

	using l_ctr_type = l_appl_type(*)(index_type);

	struct LCtr
	{
		// registers:

			static constexpr index_type size	=  0;

		// procedures:

			static constexpr index_type length (l_ctr_type c) { return c(size)(size); }
	};

		// pack length is stored as the initial value.

	template<l_appl_type... Vs>
	constexpr l_ctr_type l_controller = f_array<l_appl_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	constexpr index_type l_name(depth_type d, l_ctr_type c, index_type i)
	{
		if (!bool(d))	return LM::pause;
		else 		return c(i)(LAppl::name);
	}

	constexpr index_type l_next_name(depth_type d, l_ctr_type c, index_type i)
	{
		if (!bool(d))	return LM::pause;
		else 		return c(i+1)(LAppl::name);
	}

	constexpr index_type l_next_i(depth_type d, l_ctr_type c, index_type i)
	{
		if (!bool(d))	return i;
		else 		return i+1;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear:

/***********************************************************************************************************************/

// applications:

		// inherits variadic application.

	using nl_appl_type = v_appl_type;

	struct NLAppl
	{
		// registers:

			static constexpr index_type size			=  VAppl::size;
			static constexpr index_type name			=  VAppl::name;
			static constexpr index_type reg				=  VAppl::reg;
			static constexpr index_type op				=  VAppl::op;
			static constexpr index_type arg				=  VAppl::arg;
			static constexpr index_type arg1			=  VAppl::arg1;
			static constexpr index_type arg2			=  VAppl::arg2;

		// dispatch:

			static constexpr index_type unary			=  VAppl::unary;
			static constexpr index_type binary			=  VAppl::binary;

		// procedures:

			static constexpr index_type (*length) (nl_appl_type)	= VAppl::length;
			static constexpr index_type (*arity)  (nl_appl_type)	= VAppl::arity;
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr nl_appl_type nl_application = v_application<Vs...>;

	// syntactic sugar:

		template<index_type Op, index_type... Args>					// The 0 value is filler to
		constexpr nl_appl_type nl_test = nl_application<NLM::pred, 0, Op, Args...>;	// align with the NLAppl indices.

		template<index_type Reg>
		constexpr nl_appl_type nl_break = nl_application<NLM::stop, Reg>;

		template<index_type Reg, index_type Op, index_type... Args>
		constexpr nl_appl_type nl_apply = nl_application<NLM::appl, Reg, Op, Args...>;

/***********************************************************************************************************************/

// continuation passing functors:

	using nl_cont_type = nl_appl_type(*)(index_type);

	struct NLCont
	{
		// registers:

			static constexpr index_type size		=  0;
			static constexpr index_type name		=  1;
			static constexpr index_type appl		=  2;
			static constexpr index_type pred		=  2;
			static constexpr index_type appl1		=  3;
			static constexpr index_type appl2		=  4;

		// procedures:

			static constexpr index_type length (nl_cont_type l) { return l(size)(size); }
	};

		// pack length is stored as the initial value.

	template<nl_appl_type... Vs>
	constexpr nl_cont_type nl_continuation = f_array<nl_appl_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

	// syntactic sugar:

		template<nl_appl_type N>
		constexpr nl_cont_type nl_lift = nl_continuation<nl_application<NLM::lift>, N>;

		template<nl_appl_type P, nl_appl_type B, nl_appl_type N>
		constexpr nl_cont_type nl_stem = nl_continuation<nl_application<NLM::stem>, P, B, N>;

		template<nl_appl_type P, nl_appl_type N, nl_appl_type B>
		constexpr nl_cont_type nl_costem = nl_continuation<nl_application<NLM::costem>, P, N, B>;

		template<nl_appl_type P, nl_appl_type N1, nl_appl_type N2>
		constexpr nl_cont_type nl_distem = nl_continuation<nl_application<NLM::distem>, P, N1, N2>;

		template<nl_appl_type B>
		constexpr nl_cont_type nl_halt = nl_continuation<nl_application<NLM::halt>, B>;

		constexpr nl_cont_type nl_cycle = nl_continuation<nl_application<NLM::cycle>>;

/***********************************************************************************************************************/

// controller:

	using nl_ctr_type = nl_cont_type(*)(index_type);

	struct NLCtr
	{
		// registers:

			static constexpr index_type size	=  0;

		// procedures:

			static constexpr index_type length (nl_ctr_type c) { return c(size)(size)(size); }
	};

		// pack length is stored as the initial value.

	template<nl_cont_type... Vs>
	constexpr nl_ctr_type nl_controller = f_array
		<nl_cont_type, f_array<nl_appl_type, f_array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	// current:

		constexpr index_type nl_name(depth_type d, nl_ctr_type c, index_type i)
		{
			if (!bool(d)) return NLM::pause;
			else
			{
				index_type name = c(i)(NLCont::name)(NLAppl::name);

				if (name != NLM::cycle) return name;
				return c(1)(NLCont::name)(NLAppl::name);
			}
		}

		constexpr index_type nl_index(depth_type d, nl_ctr_type c, index_type i)
		{
			if (!bool(d)) return i;
			else
			{
				index_type name = c(i)(NLCont::name)(NLAppl::name);

				if (name != NLM::cycle) return i;
				return 1;
			}
		}

	// next:

		constexpr index_type nl_next_name(depth_type d, nl_ctr_type c, index_type i)
		{
			if (!bool(d)) return NLM::pause;
			else
			{
				index_type name = c(i+1)(NLCont::name)(NLAppl::name);

				if (name != NLM::cycle) return name;
				else return c(1)(NLCont::name)(NLAppl::name);
			}
		}

		constexpr index_type nl_next_i(depth_type d, nl_ctr_type c, index_type i)
		{
			if (!bool(d)) return i;
			else
			{
				index_type name = c(i+1)(NLCont::name)(NLAppl::name);

				if (name != NLM::cycle) return i+1;
				else return 1;
			}
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register:

/***********************************************************************************************************************/

// instructions:

	using r_inst_type = index_type(*)(index_type);

	struct RInst
	{
		// registers:

			static constexpr index_type size		=  0;
			static constexpr index_type name		=  1;
			static constexpr index_type value		=  2;

		// procedures:

			static constexpr index_type length (r_inst_type i) { return i(size); }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	constexpr r_inst_type r_instruction = f_array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// labels:

	using r_lbl_type = r_inst_type(*)(index_type);

	struct RLbl
	{
		// registers:

			static constexpr index_type size		=  0;
			static constexpr index_type first		=  1;

		// procedures:

			static constexpr index_type length (r_lbl_type l) { return l(size)(size) ; }
			static constexpr r_inst_type last  (r_lbl_type l) { return l(length(l))  ; }
	};

		// pack length is stored as the initial value.

	template<r_inst_type... Vs>
	constexpr r_lbl_type label = f_array<r_inst_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

	using r_ctr_type = r_lbl_type(*)(index_type);

	struct RCtr
	{
		// registers:

			static constexpr index_type size		=  0;

		// procedures:

			static constexpr index_type length   (r_ctr_type c) { return c(size)(size)(size)               ; }
			static constexpr r_lbl_type last     (r_ctr_type c) { return c(length(c))                      ; }
			static constexpr index_type reg_size (r_ctr_type c) { return RLbl::last(last(c))(RInst::value) ; }
	};

		// pack length is stored as the initial value.

	template<r_lbl_type... Vs>
	constexpr r_ctr_type controller = f_array
		<r_lbl_type, f_array<r_inst_type, f_array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	// Initializers require (l = 0, m = k) -> first instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/***********************************************************************************************************************/

/*
	template
	<
		auto pause_next  , auto branch_next , auto l_goto_next ,
		auto r_goto_next , auto label_next  , auto instr_next
	>
	constexpr auto r_next(depth_type d, contr_type c, index_type l, index_type m, index_type n, bool is_branch)
	{
		if	(!bool(d))				return pause_next  (c, l, m);
		else if (!bool(l))				return label_next  (c, l, m);
		else if (is_branch)				return branch_next (c, l, m);
		else if	(c(l)(m)(Instr::name) == MI::l_goto)	return l_goto_next (c, l, m);
		else if (c(l)(m)(Instr::name) == MI::r_goto)	return r_goto_next (c, n, m);
		else if (m == Label::length(c(l)))		return label_next  (c, l, m);
		else						return instr_next  (c, l, m);
	}
*/

/***********************************************************************************************************************/

// next c:

/*
	constexpr instr_type pause_i     (contr_type c, index_type l, index_type m) { return instruction<MI::pause, 1>; }
	constexpr instr_type branch_i    (contr_type c, index_type l, index_type m) { return c( c(l)(m)(Instr::value) )
													(Label::first); }
	constexpr instr_type (*l_goto_i) (contr_type c, index_type l, index_type m) = branch_i                          ;
	constexpr instr_type r_goto_i    (contr_type c, index_type l, index_type m) { return c(l)(Label::first);        }
	constexpr instr_type label_i     (contr_type c, index_type l, index_type m) { return c(l+1)(Label::first);      }
	constexpr instr_type instr_i     (contr_type c, index_type l, index_type m) { return c(l)(m+1);                 }

	constexpr instr_type r_next_i(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<pause_i, branch_i, l_goto_i, r_goto_i, label_i, instr_i>(d, c, l, m, n, is_br);
	}

	//

	constexpr index_type r_next_k(contr_type c, instr_type i)
	{
		if
		(	(i(Instr::name) == MI::l_assign )	||
			(i(Instr::name) == MI::r_assign )	||
			(i(Instr::name) == MI::u_apply  )	||
			(i(Instr::name) == MI::b_apply  )
		)						return i(Instr::value);
	//	else if
	//	(
	//		(i(Instr::name) == MI::save     )	||
	//		(i(Instr::name) == MI::restore  )
	//	)						return Ctr::reg_size(c);
		else						return 0;
	}
*/

/***********************************************************************************************************************/

// next l:

/*
	constexpr index_type pause_l      (contr_type c, index_type l, index_type m)	{ return l;                     }
	constexpr index_type branch_l     (contr_type c, index_type l, index_type m)	{ return c(l)(m)(Instr::value); }
	constexpr index_type (*l_goto_l)  (contr_type c, index_type l, index_type m)	= branch_l                      ;
	constexpr index_type (*r_goto_l)  (contr_type c, index_type l, index_type m)	= pause_l                       ;
	constexpr index_type label_l      (contr_type c, index_type l, index_type m)	{ return l+1;                   }
	constexpr index_type (*instr_l)   (contr_type c, index_type l, index_type m)	= pause_l                       ;

	//

	constexpr index_type r_next_l(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<pause_l, branch_l, l_goto_l, r_goto_l, label_l, instr_l>(d, c, l, m, n, is_br);
	}
*/

/***********************************************************************************************************************/

// next m:

/*
	constexpr index_type pause_m      (contr_type c, index_type l, index_type m)	{ return m;             }
	constexpr index_type branch_m     (contr_type c, index_type l, index_type m)	{ return Instr::name;   }
	constexpr index_type (*l_goto_m)  (contr_type c, index_type l, index_type m)	= branch_m              ;
	constexpr index_type (*r_goto_m)  (contr_type c, index_type l, index_type m)	= branch_m              ;
	constexpr index_type (*label_m)   (contr_type c, index_type l, index_type m)	= branch_m              ;
	constexpr index_type instr_m      (contr_type c, index_type l, index_type m)	{ return m+1;           }

	//

	constexpr index_type r_next_m(depth_type d,
		contr_type c, index_type l, index_type m, index_type n = 0, bool is_br = false)
	{
		return next<pause_m, branch_m, l_goto_m, r_goto_m, label_m, instr_m>(d, c, l, m, n, is_br);
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

