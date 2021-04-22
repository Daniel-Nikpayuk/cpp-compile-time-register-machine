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

#ifndef _1_VARIADIC_SPACE_HPP
#define _1_VARIADIC_SPACE_HPP

// variadic space:

	// Passing (copying) parameter packs is expensive, and shortens nesting depth lifespans. As such,
	// skipping over modular transitions is privileged when reasonable. See definition of "at" for example.

#include"machine-space/define_macros.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

	#include"machine-space/0_machine_controllers.hpp"
	#include"machine-space/1_machine_declarations.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - controller
	// l  - locus
	// i  - index
	// Vs - values

	#include"machine-space/2_variadic_pop.hpp"
	#include"machine-space/3_variadic_push.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

// start:

	template<auto d, auto c, auto l, auto... Vs>
	constexpr auto variadic_start()
	{
		constexpr index_type i		= 1;
		constexpr auto next_name	= U_value_V<c[i]>;

		return variadic_machine<d, c, l, i, Vs...>(next_name, U_pack_Vs<>, U_pack_Vs<>);
	}

/***********************************************************************************************************************/

// pause:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... LHs, auto... RHs>
	constexpr auto variadic_pause
	(
		void(*)( auto_pack<LHs...> *),
		void(*)( auto_pack<RHs...> *)
	)
	{
		constexpr auto next_lh	= U_pack_Vs<LHs...>;
		constexpr auto next_rh	= U_pack_Vs<RHs...>;

		return type_map<auto_pack<MH::variadic_machine, d, c, l, i, next_lh, next_rh, Vs...>*>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// core:

/***********************************************************************************************************************/

// first:

	template<auto d, auto c, auto l, auto i, auto V0, auto... Vs, typename LHeap, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*)( auto_pack<VM::first> *),
		LHeap lh, RHeap rh
	)
	{
		return V0;
	}

/***********************************************************************************************************************/

// rest:

	template<auto d, auto c, auto l, auto i, auto V0, auto... Vs, typename LHeap, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*)( auto_pack<VM::rest> *),
		LHeap lh, RHeap rh
	)
	{
		return type_map<auto_pack<Vs...>*>;
	}

/***********************************************************************************************************************/

// pack:

	template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*)( auto_pack<VM::pack> *),
		LHeap lh, RHeap rh
	)
	{
		return type_map<auto_pack<Vs...>*>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stack to heap:

	#include"machine-space/4_variadic_lheap.hpp"
	#include"machine-space/5_variadic_rheap.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// heap to stack:

/***********************************************************************************************************************/

// lheap front:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::lh_to_sf> *),
		void(* lh )( auto_pack<Ws...>        *),
		RHeap rh
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Ws..., Vs...>(next_name, U_pack_Vs<>, rh);
	}

/***********************************************************************************************************************/

// lheap back:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::lh_to_sb> *),
		void(* lh )( auto_pack<Ws...>        *),
		RHeap rh
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs..., Ws...>(next_name, U_pack_Vs<>, rh);
	}

/***********************************************************************************************************************/

// rheap front:

	template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, auto... Ws>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::rh_to_sf> *),
		LHeap lh,
		void(* rh )( auto_pack<Ws...>        *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Ws..., Vs...>(next_name, lh, U_pack_Vs<>);
	}

/***********************************************************************************************************************/

// rheap back:

	template<auto d, auto c, auto l, auto i, auto... Vs, typename LHeap, auto... Ws>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::rh_to_sb> *),
		LHeap lh,
		void(* rh )( auto_pack<Ws...>        *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs..., Ws...>(next_name, lh, U_pack_Vs<>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// heap to heap:

/***********************************************************************************************************************/

// to rheap front:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, auto... Xs>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::lh_to_rhf> *),
		void(* lh )( auto_pack<Ws...>         *),
		void(* rh )( auto_pack<Xs...>         *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;
		constexpr auto next_rh   = U_pack_Vs<Ws..., Xs...>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs...>(next_name, U_pack_Vs<>, next_rh);
	}

/***********************************************************************************************************************/

// to rheap back:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, auto... Xs>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::lh_to_rhb> *),
		void(* lh )( auto_pack<Ws...>         *),
		void(* rh )( auto_pack<Xs...>         *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;
		constexpr auto next_rh   = U_pack_Vs<Xs..., Ws...>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs...>(next_name, U_pack_Vs<>, next_rh);
	}

/***********************************************************************************************************************/

// to lheap front:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, auto... Xs>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::rh_to_lhf> *),
		void(* lh )( auto_pack<Ws...>         *),
		void(* rh )( auto_pack<Xs...>         *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;
		constexpr auto next_lh   = U_pack_Vs<Xs..., Ws...>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs...>(next_name, next_lh, U_pack_Vs<>);
	}

/***********************************************************************************************************************/

// to lheap back:

	template<auto d, auto c, auto l, auto i, auto... Vs, auto... Ws, auto... Xs>
	constexpr auto variadic_machine
	(
		void(*    )( auto_pack<VM::rh_to_lhb> *),
		void(* lh )( auto_pack<Ws...>         *),
		void(* rh )( auto_pack<Xs...>         *)
	)
	{
		constexpr auto next_name = U_value_V<c[i+1]>;
		constexpr auto next_lh   = U_pack_Vs<Ws..., Xs...>;

		if constexpr (!bool(d))

			return variadic_pause<d, c, l, i, Vs...>(lh, rh);
		else
			return variadic_machine<d-1, c, l, i+1, Vs...>(next_name, next_lh, U_pack_Vs<>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// at:

	template<index_type cont = VM::first>
	constexpr auto at_contr = v_controller<VM::pop, cont>;

	template<depth_type n>
	constexpr auto at_locus = v_locus<n>;

	template<depth_type d, depth_type n, auto... Vs>
	constexpr auto at = variadic_start<d, at_contr<>, at_locus<n>, Vs...>();

/***********************************************************************************************************************/

// erase (heap oriented):

	template<index_type cont = VM::pack>
	constexpr auto erase_contr = v_controller<VM::s_to_lh, VM::pop, VM::lh_to_sf, cont>;

	template<depth_type m, depth_type n>
	constexpr auto erase_locus = v_locus<m, n>;

	template<depth_type d, depth_type m, depth_type n, auto... Vs>
	constexpr auto erase = variadic_start<d, erase_contr<>, erase_locus<m, n>, Vs...>();

/***********************************************************************************************************************/

// insert (heap oriented):

	template<index_type cont = VM::pack>
	constexpr auto insert_contr = v_controller<VM::s_to_lh, VM::s_to_rh, VM::lh_to_sf, VM::rh_to_sf, cont>;

	template<depth_type m, depth_type n>
	constexpr auto insert_locus = v_locus<m, n>;

	template<depth_type d, depth_type m, depth_type n, auto... Vs>
	constexpr auto insert = variadic_start<d, insert_contr<>, insert_locus<m, n>, Vs...>();

/***********************************************************************************************************************/

// replace (heap oriented):

	template<index_type cont = VM::pack>
	constexpr auto replace_contr = v_controller<VM::s_to_lh, VM::s_to_rh, VM::pop, VM::lh_to_sf, VM::rh_to_sf, cont>;

	template<depth_type m, depth_type n>
	constexpr auto replace_locus = v_locus<m, n, m>;

	template<depth_type d, depth_type m, depth_type n, auto... Vs>
	constexpr auto replace = variadic_start<d, replace_contr<>, replace_locus<m, n>, Vs...>();

/***********************************************************************************************************************/

// fold:

//	#include"machine-space/5_variadic_fold.hpp"

/***********************************************************************************************************************/

// trampoline:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

	// undef macros should be included in the register space file instead.

#include"machine-space/undef_macros.hpp"

#endif

