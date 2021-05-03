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

#ifndef _3_NEAR_LINEAR_SPACE_HPP
#define _3_NEAR_LINEAR_SPACE_HPP

// near linear space:

	// constexpr near linear monad (design):

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

// externals:

/***********************************************************************************************************************/

// start:

	template<auto d, auto c, auto... Rs>
	constexpr auto near_linear_start()
	{
		constexpr index_type i = 1;

		return near_linear_machine<nl_name(d, c, i)>::template result<d-1, c, i, Rs...>();
	}

/***********************************************************************************************************************/

// pause:

	template<auto c, auto i, auto... Rs>
	constexpr auto near_linear_pause()
	{
		return type_map<auto_pack<MH::near_linear_machine, c, i, Rs...>*>;
	}

/***********************************************************************************************************************/

// trampoline:

	template<auto d, typename T>
	constexpr auto near_linear_trampoline(T v) { return v; }

	template<auto d, auto c, auto i, auto... Rs>
	constexpr auto near_linear_trampoline(void(*)(auto_pack<MH::near_linear_machine, c, i, Rs...>*))
	{
		constexpr auto v = near_linear_machine<nl_name(d, c, i)>::template result
		<
			d, c, nl_index(d, c, i), Rs... // index update necessary ?
		>();

		return near_linear_trampoline<d>(v);
	}

/***********************************************************************************************************************/

// stop:

		// policy d ?

	template<auto d, auto c, auto i, auto appl, auto... Rs>
	constexpr auto near_linear_stop()
	{
		constexpr auto n = appl(NLAppl::reg);

		return variadic_at<d-1, n, Rs...>();
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - controller
	// i  - index
	// Rs - registers

/***********************************************************************************************************************/

// lift:

	template<>
	struct near_linear_machine<NLM::lift>
	{
		template<auto d, auto c, auto i, auto... Rs>
		static constexpr auto result()
		{
			constexpr auto appl = c(i)(NLCont::appl);

			if constexpr (!bool(d))

				return near_linear_pause<c, i, Rs...>();
			else
				return pack_apply<NLAppl::arity(appl)>::template result
				<
					d-1, VM::nl_machine, appl, Rs...

				>(U_pack_Vs<c, i+1>);
		}
	};

/***********************************************************************************************************************/

// stem:

	template<index_type> struct stem_predicate;

	// unary:

		template<>
		struct stem_predicate<NLAppl::unary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto break_appl, auto next_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg	= variadic_at<d-1, pred_appl(NLAppl::arg), Rs...>();

				if constexpr (pred(arg))

					return near_linear_stop<d-1, c, i, break_appl, Rs...>();
				else
					return pack_apply<NLAppl::arity(next_appl)>::template result
					<
						d-1, VM::nl_machine, next_appl, Rs...

					>(U_pack_Vs<c, i+1>);
			}
		};

	// binary:

		template<>
		struct stem_predicate<NLAppl::binary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto break_appl, auto next_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg1	= variadic_at<d-1, pred_appl(NLAppl::arg1), Rs...>();
				constexpr auto arg2	= variadic_at<d-1, pred_appl(NLAppl::arg2), Rs...>();

				if constexpr (pred(arg1, arg2))

					return near_linear_stop<d-1, c, i, break_appl, Rs...>();
				else
					return pack_apply<NLAppl::arity(next_appl)>::template result
					<
						d-1, VM::nl_machine, next_appl, Rs...

					>(U_pack_Vs<c, i+1>);
			}
		};

	template<>
	struct near_linear_machine<NLM::stem>
	{
		template<auto d, auto c, auto i, auto... Rs>
		static constexpr auto result()
		{
			constexpr auto cont		= c(i);
			constexpr auto pred_appl	= cont(NLCont::pred);
			constexpr auto break_appl	= cont(NLCont::appl1);
			constexpr auto next_appl	= cont(NLCont::appl2);

			if constexpr (!bool(d))

				return near_linear_pause<c, i, Rs...>();
			else
				return stem_predicate<NLAppl::arity(pred_appl)>::template result
				<
					d-1, c, i, pred_appl, break_appl, next_appl, Rs...
				>();
		}
	};

/***********************************************************************************************************************/

// costem:

	template<index_type> struct costem_predicate;

	// unary:

		template<>
		struct costem_predicate<NLAppl::unary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto next_appl, auto break_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg	= variadic_at<d-1, pred_appl(NLAppl::arg), Rs...>();

				if constexpr (pred(arg))

					return pack_apply<NLAppl::arity(next_appl)>::template result
					<
						d-1, VM::nl_machine, next_appl, Rs...

					>(U_pack_Vs<c, i+1>);
				else
					return near_linear_stop<d-1, c, i, break_appl, Rs...>();
			}
		};

	// binary:

		template<>
		struct costem_predicate<NLAppl::binary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto next_appl, auto break_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg1	= variadic_at<d-1, pred_appl(NLAppl::arg1), Rs...>();
				constexpr auto arg2	= variadic_at<d-1, pred_appl(NLAppl::arg2), Rs...>();

				if constexpr (pred(arg1, arg2))

					return pack_apply<NLAppl::arity(next_appl)>::template result
					<
						d-1, VM::nl_machine, next_appl, Rs...

					>(U_pack_Vs<c, i+1>);
				else
					return near_linear_stop<d-1, c, i, break_appl, Rs...>();
			}
		};

	template<>
	struct near_linear_machine<NLM::costem>
	{
		template<auto d, auto c, auto i, auto... Rs>
		static constexpr auto result()
		{
			constexpr auto cont		= c(i);
			constexpr auto pred_appl	= cont(NLCont::pred);
			constexpr auto next_appl	= cont(NLCont::appl1);
			constexpr auto break_appl	= cont(NLCont::appl2);

			if constexpr (!bool(d))

				return near_linear_pause<c, i, Rs...>();
			else
				return costem_predicate<NLAppl::arity(pred_appl)>::template result
				<
					d-1, c, i, pred_appl, next_appl, break_appl, Rs...
				>();
		}
	};

/***********************************************************************************************************************/

// distem:

	template<index_type> struct distem_predicate;

	// unary:

		template<>
		struct distem_predicate<NLAppl::unary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto next1_appl, auto next2_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg	= variadic_at<d-1, pred_appl(NLAppl::arg), Rs...>();

				if constexpr (pred(arg))

					return pack_apply<NLAppl::arity(next1_appl)>::template result
					<
						d-1, VM::nl_machine, next1_appl, Rs...

					>(U_pack_Vs<c, i+1>);
				else
					return pack_apply<NLAppl::arity(next2_appl)>::template result
					<
						d-1, VM::nl_machine, next2_appl, Rs...

					>(U_pack_Vs<c, i+1>);
			}
		};

	// binary:

		template<>
		struct distem_predicate<NLAppl::binary>
		{
			template<auto d, auto c, auto i, auto pred_appl, auto next1_appl, auto next2_appl, auto... Rs>
			static constexpr auto result()
			{
				constexpr auto pred	= variadic_at<d-1, pred_appl(NLAppl::op), Rs...>();
				constexpr auto arg1	= variadic_at<d-1, pred_appl(NLAppl::arg1), Rs...>();
				constexpr auto arg2	= variadic_at<d-1, pred_appl(NLAppl::arg2), Rs...>();

				if constexpr (pred(arg1, arg2))

					return pack_apply<NLAppl::arity(next1_appl)>::template result
					<
						d-1, VM::nl_machine, next1_appl, Rs...

					>(U_pack_Vs<c, i+1>);
				else
					return pack_apply<NLAppl::arity(next2_appl)>::template result
					<
						d-1, VM::nl_machine, next2_appl, Rs...

					>(U_pack_Vs<c, i+1>);
			}
		};

	template<>
	struct near_linear_machine<NLM::distem>
	{
		template<auto d, auto c, auto i, auto... Rs>
		static constexpr auto result()
		{
			constexpr auto cont		= c(i);
			constexpr auto pred_appl	= cont(NLCont::pred);
			constexpr auto next1_appl	= cont(NLCont::appl1);
			constexpr auto next2_appl	= cont(NLCont::appl2);

			if constexpr (!bool(d))

				return near_linear_pause<c, i, Rs...>();
			else
				return distem_predicate<NLAppl::arity(pred_appl)>::template result
				<
					d-1, c, i, pred_appl, next1_appl, next2_appl, Rs...
				>();
		}
	};

/***********************************************************************************************************************/

// halt:

		// policy d ?

	template<>
	struct near_linear_machine<NLM::halt>
	{
		template<auto d, auto c, auto i, auto... Rs>
		static constexpr auto result()
		{
			constexpr auto appl = c(i)(NLCont::appl);

			return near_linear_stop<d-1, c, i, appl, Rs...>();
		}
	};

/***********************************************************************************************************************/

// cycle:

	// optimization: refactored into the controller dispatches.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperability:

	template<>
	struct variadic_machine<VM::nl_machine>
	{
		template<auto vc, auto vi, auto vl, auto c, auto i, auto... Rs, typename LHeap, typename RHeap>
		static constexpr auto result(LHeap, RHeap)
		{
			constexpr depth_type d = vi[VInd::depth];

			return near_linear_machine<nl_name(d, c, i)>::template result
			<
				d-1, c, nl_index(d, c, i), Rs...
			>();
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

