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

#ifndef _2_NEAR_LINEAR_SPACE_HPP
#define _2_NEAR_LINEAR_SPACE_HPP

// near linear space:

	// Passing (copying) parameter packs is expensive, and shortens nesting depth lifespans. As such,
	// skipping over modular transitions is privileged when reasonable. See definition of "at" for example.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - controller
	// i  - index
	// Vs - values

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

// start:

	template<auto d, auto c, auto... Rs>
	constexpr auto near_linear_start()
	{
		constexpr index_type i		= 1;
		constexpr auto next_name	= U_value_V<c[i][NLCont::name][NLAppl::name]>;

		return near_linear_machine<d, c, i, Rs...>(next_name);
	}

/***********************************************************************************************************************/

// pause:

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_pause()
	{
		return type_map<auto_pack<MH::near_linear_machine, d, c, i, Rs...>*>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// mutators:

	// These specialized near linear machines do not test against the nesting depth.

/***********************************************************************************************************************/

// erase:

/***********************************************************************************************************************/

// insert:

/***********************************************************************************************************************/

// replace:

	template<auto d, auto nlc, auto nli, auto n, auto val, auto... Rs>
	constexpr auto near_linear_replace()
	{
		constexpr auto c		= replace_contr<VM::nl_machine>;
		constexpr auto l		= replace_locus<1, n>;
		constexpr index_type i		= 1;

		constexpr auto next_name	= U_value_V<c[i]>;
		constexpr auto next_rh		= U_pack_Vs<nlc, nli>;

		return variadic_machine<d-1, c, l, i, val, Rs...>(next_name, U_pack_Vs<>, next_rh);
	}

/***********************************************************************************************************************/

// stop:

	template<auto d, auto c, auto i, auto oper, auto... Rs>
	constexpr auto near_linear_stop()
	{
		constexpr auto n = oper[NLAppl::reg];

		return variadic_start<d, at_contr<>, at_locus<n>, Rs...>();
	}

/***********************************************************************************************************************/

// apply:

	template<auto d, auto c, auto i, auto oper, auto... Rs>
	constexpr auto near_linear_apply()
	{
		constexpr auto reg		= oper[NLAppl::reg];
		constexpr auto op		= at<d, oper[NLAppl::op], Rs...>;

		if constexpr (NLAppl::is_unary(oper))
		{
			constexpr auto arg	= at<d, oper[NLAppl::arg], Rs...>;
			constexpr auto val	= op(arg);

			return near_linear_replace<d-1, c, i+1, reg, val, Rs...>();
		}
		else
		{
			constexpr auto arg1	= at<d, oper[NLAppl::arg1], Rs...>;
			constexpr auto arg2	= at<d, oper[NLAppl::arg2], Rs...>;
			constexpr auto val	= op(arg1, arg2);

			return near_linear_replace<d-1, c, i+1, reg, val, Rs...>();
		}
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - controller
	// i  - index
	// Vs - values

/***********************************************************************************************************************/

// lift:

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_machine
	(
		void(*)(auto_pack<NLM::lift>*)
	)
	{
		constexpr auto oper = c[i][NLCont::appl];

		if constexpr (!bool(d))

			return near_linear_pause<d, c, i, Rs...>();
		else
			return near_linear_apply<d-1, c, i, oper, Rs...>();
	}

/***********************************************************************************************************************/

// stem:

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_machine
	(
		void(*)(auto_pack<NLM::stem>*)
	)
	{
		constexpr auto cont		= c[i];
		constexpr auto pred_appl	= cont[NLCont::pred];
		constexpr auto break_appl	= cont[NLCont::appl1];
		constexpr auto next_appl	= cont[NLCont::appl2];

		constexpr auto pred		= at<d, pred_appl[NLAppl::op], Rs...>;

		if constexpr (!bool(d))
		{
			return near_linear_pause<d, c, i, Rs...>();
		}
		else if constexpr (NLAppl::is_unary(pred_appl))
		{
			constexpr auto arg	= at<d, pred_appl[NLAppl::arg], Rs...>;

			if constexpr (pred(arg))

				return near_linear_stop<d-1, c, i, break_appl, Rs...>();
			else
				return near_linear_apply<d-1, c, i, next_appl, Rs...>();
		}
		else
		{
			constexpr auto arg1	= at<d, pred_appl[NLAppl::arg1], Rs...>;
			constexpr auto arg2	= at<d, pred_appl[NLAppl::arg2], Rs...>;

			if constexpr (pred(arg1, arg2))

				return near_linear_stop<d-1, c, i, break_appl, Rs...>();
			else
				return near_linear_apply<d-1, c, i, next_appl, Rs...>();
		}
	}

/***********************************************************************************************************************/

// costem:

/***********************************************************************************************************************/

// distem:

/***********************************************************************************************************************/

// halt:

		// needs to mitigate against nesting depth.

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_machine
	(
		void(*)(auto_pack<NLM::halt>*)
	)
	{
		constexpr auto oper = c[i][NLCont::appl];

		return near_linear_stop<d, c, i, oper, Rs...>();
	}

/***********************************************************************************************************************/

// cycle:

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_machine
	(
		void(*)(auto_pack<NLM::cycle>*)
	)
	{
		constexpr index_type j		= 1;
		constexpr auto next_name	= U_value_V<c[j][NLCont::name][NLAppl::name]>;

		return near_linear_machine<d-1, c, j, Rs...>(next_name);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

	template<auto d, auto vc, auto vl, auto vi, auto c, auto i, auto... Rs, typename LHeap, typename RHeap>
	constexpr auto variadic_machine
	(
		void(*)( auto_pack<VM::nl_machine> *),
		LHeap, RHeap
	)
	{
		constexpr auto next_name = U_value_V<c[i][NLCont::name][NLAppl::name]>;

		if constexpr (!bool(d))

			return near_linear_pause<d, c, i, Rs...>();
		else
			return near_linear_machine<d, c, i, Rs...>(next_name);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

