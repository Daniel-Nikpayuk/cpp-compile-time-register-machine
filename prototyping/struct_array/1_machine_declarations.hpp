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

// machine declarations:

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

	// constexpr variadic monad (design):

//		template
//		<
//			// stack:

//				auto d, auto c, auto l, auto i,
 
//				auto... Vs,

//			// heap:

//				auto... LHs, auto... RHs
//		>
//		constexpr auto variadic_machine
//		(
//			void(* name  )( auto_pack< VM::(((name))) > *),
//			void(* lheap )( auto_pack< LHs...         > *),
//			void(* rheap )( auto_pack< RHs...         > *)
//		)
//		{
//			constexpr auto next_name  = U_value_V< c(i+1) >;
//			constexpr auto next_lheap = U_pack_Vs< LHs... >; // It is assumed LHs..., RHs...
//			constexpr auto next_rheap = U_pack_Vs< RHs... >; // are mutated in some way here.

//			return variadic_machine<d-1, 1, l, i+1, Vs...>(next_name, next_lheap, next_rheap);
//		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumerations:

/***********************************************************************************************************************/

	struct VM // variadic machine
	{
		// stack -> stack:

			static constexpr index_type pop			=  0;
			static constexpr index_type push		=  1;

			static constexpr index_type first		=  2;
			static constexpr index_type rest		=  3;
			static constexpr index_type pack		=  4;
			static constexpr index_type dump		=  5;

		// stack -> heap:

			static constexpr index_type s_to_lh		=  6;
			static constexpr index_type s_to_rh		=  7;

		// heap -> stack:

			static constexpr index_type lh_to_sf		=  8;
			static constexpr index_type lh_to_sb		=  9;
			static constexpr index_type rh_to_sf		= 10;
			static constexpr index_type rh_to_sb		= 11;

		// heap -> heap:

			static constexpr index_type lh_to_rhf		= 12;
			static constexpr index_type lh_to_rhb		= 13;
			static constexpr index_type rh_to_lhf		= 14;
			static constexpr index_type rh_to_lhb		= 15;

		// auxiliary:

			static constexpr index_type fold		= 16;

		// compounds:

			static constexpr index_type erase		= 17;
			static constexpr index_type insert		= 18;
			static constexpr index_type replace		= 19;

		// trampolining:

			static constexpr index_type nl_machine		= 20;
			static constexpr index_type r_machine		= 21;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// declarations:

	// d  - depth
	// c  - controller
	// l  - locus
	// i  - index
	// Vs - values

/***********************************************************************************************************************/

// kernel:

	// pop:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::pop>*), LHeap, RHeap);

	// push:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::push>*), LHeap, RHeap);

/***********************************************************************************************************************/

// core:

	// first:

		template<auto d, auto c, auto l, auto i, auto V0, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::first>*), LHeap, RHeap);

	// rest:

		template<auto d, auto c, auto l, auto i, auto V0, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::rest>*), LHeap, RHeap);

	// pack:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::pack>*), LHeap, RHeap);

/***********************************************************************************************************************/

// stack -> heap:

	// lheap:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::s_to_lh>*), LHeap, RHeap);

	// rheap:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::s_to_rh>*), LHeap, RHeap);

/***********************************************************************************************************************/

// heap -> stack:

	// lheap front:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::lh_to_sf>*), void(*)(auto_pack<LHs...>*), RHeap);

	// lheap back:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::lh_to_sb>*), void(*)(auto_pack<LHs...>*), RHeap);

	// rheap front:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::rh_to_sf>*), LHeap, void(*)(auto_pack<RHs...>*));

	// rheap back:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::rh_to_sb>*), LHeap, void(*)(auto_pack<RHs...>*));

/***********************************************************************************************************************/

// heap -> heap:

	// to rheap front:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::lh_to_rhf>*),
			void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*));

	// to rheap back:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::lh_to_rhb>*),
			void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*));

	// to lheap front:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::rh_to_lhf>*),
			void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*));

	// to lheap back:

		template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, auto... RHs>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::rh_to_lhb>*),
			void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*));

/***********************************************************************************************************************/

// auxiliary:

	// fold:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::fold>*), LHeap, RHeap);

/***********************************************************************************************************************/

// compounds:

	// erase:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::erase>*), LHeap, RHeap);

	// insert:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::insert>*), LHeap, RHeap);

	// replace:

		template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::replace>*), LHeap, RHeap);

/***********************************************************************************************************************/

// trampolining:

	// near_linear_machine:

		template<auto d, auto vc, auto vl, auto vi,
			auto c, auto i, auto... Rs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::nl_machine>*), LHeap, RHeap);

	// register_machine:

		template<auto d, auto vc, auto vl, auto vi,
			auto c, auto l, auto m, auto... Rs, typename LHeap, typename RHeap>
		constexpr auto variadic_machine(void(*)(auto_pack<VM::r_machine>*), LHeap, RHeap);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear:

	// constexpr near linear monad (design):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumerations:

/***********************************************************************************************************************/

	struct NLM // near linear machine
	{
		// operations:

		static constexpr index_type pred		=  0;
		static constexpr index_type appl		=  1;
		static constexpr index_type stop		=  2;

		// continuations:

		static constexpr index_type lift		=  0;

		static constexpr index_type stem		=  1;
		static constexpr index_type costem		=  2;
		static constexpr index_type distem		=  3;

		static constexpr index_type halt		=  4;
		static constexpr index_type cycle		=  5;

		// trampolining:

		static constexpr index_type r_machine		=  6;

		// extensions:

		static constexpr index_type reg_size		=  7;
	};

	// operations:

		template<index_type Op, index_type... Args>					// The 0 value is filler to
		constexpr nl_appl_type nl_test = nl_application<NLM::pred, 0, Op, Args...>;	// align with the NLAppl indices.

		template<index_type Reg>
		constexpr nl_appl_type nl_break = nl_application<NLM::stop, Reg>;

		template<index_type Reg, index_type Op, index_type... Args>
		constexpr nl_appl_type nl_apply = nl_application<NLM::appl, Reg, Op, Args...>;

		template<index_type Reg, index_type Op, index_type... Args>
		constexpr nl_appl_type nl_next = nl_application<NLM::appl, Reg, Op, Args...>;

	// continuations:

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
/***********************************************************************************************************************/

// declarations:

	// d  - depth
	// c  - controller
	// i  - index
	// Vs - values

/***********************************************************************************************************************/

// kernel:

	// lift:

		template<auto d, auto c, auto i, auto... Rs>
		constexpr auto near_linear_machine(void(*)(auto_pack<NLM::lift>*));

	// stem:

		template<auto d, auto c, auto i, auto... Rs>
		constexpr auto near_linear_machine(void(*)(auto_pack<NLM::stem>*));

	// costem:

		template<auto d, auto c, auto i, auto... Rs>
		constexpr auto near_linear_machine(void(*)(auto_pack<NLM::costem>*));

	// distem:

		template<auto d, auto c, auto i, auto... Rs>
		constexpr auto near_linear_machine(void(*)(auto_pack<NLM::distem>*));

	// halt:

		// No need to declare ahead of time as this machine only occurs at the end of a controller.

	// cycle:

		// No need to declare ahead of time as this machine only occurs at the end of a controller.

/***********************************************************************************************************************/

// trampolining:

	// register_machine:

		template<auto d, auto nlc, auto nli, auto c, auto l, auto m, auto... Rs>
		constexpr auto near_linear_machine(void(*)(auto_pack<NLM::r_machine>*));

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumerations:

/***********************************************************************************************************************/

	struct RM // register machine
	{
		static constexpr index_type start		=  0;

		static constexpr index_type first		=  1;
		static constexpr index_type stop		=  2;

		static constexpr index_type dump		=  3;
		static constexpr index_type pause		=  4;

		static constexpr index_type drop		=  5;
		static constexpr index_type cache		=  6;

		static constexpr index_type pass		=  7;

		static constexpr index_type u_branch		=  8;
		static constexpr index_type b_branch		=  9;

		static constexpr index_type l_goto		= 10;
		static constexpr index_type r_goto		= 11;

		static constexpr index_type ll_call		= 12;
		static constexpr index_type lr_call		= 13;
		static constexpr index_type rl_call		= 14;
		static constexpr index_type rr_call		= 15;

		static constexpr index_type l_right		= 16;
		static constexpr index_type r_right		= 17;

		static constexpr index_type l_rotate		= 18;
		static constexpr index_type r_rotate		= 19;

		static constexpr index_type save		= 20;
		static constexpr index_type restore		= 21;

		static constexpr index_type l_assign		= 22;
		static constexpr index_type r_assign		= 23;

		static constexpr index_type u_apply		= 24;
		static constexpr index_type b_apply		= 25;

		static constexpr index_type _2_n_right		= 26;
		static constexpr index_type _2_n_rotate		= 27;

		static constexpr index_type r_size		= 28;
		static constexpr index_type r_min_size		= 29;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// declarations:

	// d  - depth
	// c  - controller
	// l  - label
	// m  - index
	// Vs - values

/***********************************************************************************************************************/

// kernel:

	// start:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::start>*), void(*)(auto_pack<d, c, l, m, Rs...>*));

	// first:

		template<auto d, auto c, auto l, auto m, auto R0, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::first>*), void(*)(auto_pack<index_type(0)>*));

	// stop:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::stop>*), void(*)(auto_pack<index_type(0)>*));

	// (alt) dump:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::dump>*), void(*)(auto_pack<index_type(0)>*));

	// (alt) pause:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::pause>*), void(*)(auto_pack<index_type(0)>*));

	// drop:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::drop>*), void(*)(auto_pack<index_type(0)>*));

	// cache:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::cache>*), void(*)(auto_pack<index_type(0)>*));

	// pass:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::pass>*), void(*)(auto_pack<index_type(0)>*));

/***********************************************************************************************************************/

// predicates:

	// branch:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::u_branch>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::b_branch>*), void(*)(auto_pack<index_type(0)>*));

/***********************************************************************************************************************/

// operators:

	// goto:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::l_goto>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::r_goto>*), void(*)(auto_pack<index_type(0)>*));

	// call:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::ll_call>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::lr_call>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::rl_call>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::rr_call>*), void(*)(auto_pack<index_type(0)>*));

	// right:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::l_right>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::r_right>*), void(*)(auto_pack<index_type(0)>*));

	// rotate:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::l_rotate>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::r_rotate>*), void(*)(auto_pack<index_type(0)>*));

	// save:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::save>*), void(*)(auto_pack<index_type(0)>*));

	// restore:

		template<auto d, auto c, auto l, auto m, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::restore>*), void(*)(auto_pack<index_type(0)>*));

	// l_assign:

	// r_assign:

	// apply_u:

	// apply_b:

	// _2_n_right:

/*
		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(0)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(1)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(2)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(3)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(4)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(5)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(6)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(7)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(8)>*));

		template<auto d, auto c, auto l, auto m, auto dispatch, auto pos, auto... Rs>
		constexpr auto register_machine(void(*)(auto_pack<RM::right>*), void(*)(auto_pack<index_type(9)>*));
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

