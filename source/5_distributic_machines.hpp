/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of cpp_linear_function_space.
**
** cpp_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** cpp_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with cpp_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#ifndef _5_DISTRIBUTIC_MACHINES_HPP
#define _5_DISTRIBUTIC_MACHINES_HPP

// distributic machines:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace machine_space
{
	using namespace meta_programming;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomics:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// erase:

	template<>
	struct machine<MN::erase>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = erase_contr<n::pos(c, i, j)>; // single call
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// insert:

	template<>
	struct machine<MN::insert>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = insert_contr<n::pos(c, i, j), n::obj(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// replace:

	template<>
	struct machine<MN::replace>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = replace_contr<n::pos(c, i, j), n::obj(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary apply:

	template<>
	struct machine<MN::apply, MA::unary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= apply1_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j), n::arg(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary apply:

	template<>
	struct machine<MN::apply, MA::binary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= apply2_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j),
							n::arg1(c, i, j), n::arg2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary compel:

	template<>
	struct machine<MN::compel, MA::unary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= compel1_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j), n::arg(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary compel:

	template<>
	struct machine<MN::compel, MA::binary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= compel2_replace_contr // single call(s)
						<
							n::pos(c, i, j), n::op(c, i, j),
							n::arg1(c, i, j), n::arg2(c, i, j)
						>;
			constexpr auto un	= U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary test:

	template<>
	struct machine<MN::test, MA::unary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= apply1_replace_contr // single call(s)
						<
							zero, n::pred(c, i, j) + 1, n::input(c, i, j) + 1
						>;
			constexpr auto un	= U_type_T<n>;

			return machine
			<
				nn::next_name(nc, d, ni, nj),
				nn::next_note(nc, d, ni, nj)

			>::template result
			<
				nn, nc,

				nn::next_depth(d),
				nn::next_index1(nc, d, ni, nj),
				nn::next_index2(nc, d, ni, nj),

				false, Vs...

			>(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary test:

	template<>
	struct machine<MN::test, MA::binary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= apply2_replace_contr // single call(s)
						<
							zero, n::pred(c, i, j) + 1,
							n::input1(c, i, j) + 1, n::input2(c, i, j) + 1
						>;
			constexpr auto un	= U_type_T<n>;

			return machine
			<
				nn::next_name(nc, d, ni, nj),
				nn::next_note(nc, d, ni, nj)

			>::template result
			<
				nn, nc,

				nn::next_depth(d),
				nn::next_index1(nc, d, ni, nj),
				nn::next_index2(nc, d, ni, nj),

				false, Vs...

			>(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary check:

	template<>
	struct machine<MN::check, MA::unary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= compel1_replace_contr // single call(s)
						<
							zero, n::pred(c, i, j) + 1, n::input(c, i, j) + 1
						>;
			constexpr auto un	= U_type_T<n>;

			return machine
			<
				nn::next_name(nc, d, ni, nj),
				nn::next_note(nc, d, ni, nj)

			>::template result
			<
				nn, nc,

				nn::next_depth(d),
				nn::next_index1(nc, d, ni, nj),
				nn::next_index2(nc, d, ni, nj),

				false, Vs...

			>(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// binary check:

	template<>
	struct machine<MN::check, MA::binary>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc	= compel2_replace_contr // single call(s)
						<
							zero, n::pred(c, i, j) + 1,
							n::input1(c, i, j) + 1, n::input2(c, i, j) + 1
						>;
			constexpr auto un	= U_type_T<n>;

			return machine
			<
				nn::next_name(nc, d, ni, nj),
				nn::next_note(nc, d, ni, nj)

			>::template result
			<
				nn, nc,

				nn::next_depth(d),
				nn::next_index1(nc, d, ni, nj),
				nn::next_index2(nc, d, ni, nj),

				false, Vs...

			>(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// jump:

	template<>
	struct machine<MN::jump>
	{
		template<CONTR_PARAMS, bool V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto nd		= n::next_depth(d);

			constexpr auto ni		= n::next_index1(c, d, i, j);
			constexpr auto nj		= n::next_index2(c, d, i, j);

			if constexpr (V0) // if true we jump two instructions:
			{
				constexpr auto nni	= n::next_index1(c, d, ni, nj);
				constexpr auto nnj	= n::next_index2(c, d, ni, nj);

				return machine
				<
					n::next_name(c, d, nni, nnj),
					n::next_note(c, d, nni, nnj)

				>::template result
				<
					n, c,

					nd,
					n::next_index1(c, d, nni, nnj),
					n::next_index2(c, d, nni, nnj),

					Vs...

				>(Hs...);
			}
			else return machine
			<
				n::next_name(c, d, i, j),
				n::next_note(c, d, i, j)

			>::template result<n, c, nd, ni, nj, Vs...>(Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// application:

	// inherits from machine applications:

		using da_type	= ma_type;
		using DA	= MA;

		template<index_type... Vs>
		constexpr da_type d_application = m_application<Vs...>;

	// syntactic sugar:

		template<index_type Name, index_type Note, index_type... Args>
		constexpr da_type d_call = d_application<Name, Note, Args...>;

		constexpr da_type d_pack = d_application<MN::pack, zero>;

		template<index_type Pos>
		constexpr da_type d_stop = d_application<MN::stop, zero, Pos>;

		template<index_type note = zero>
		constexpr da_type d_pass = d_application<MN::pass, note>;

		//

		template<index_type Pos>
		constexpr da_type d_erase = d_application<MN::erase, zero, Pos>;

		template<index_type Pos, index_type Obj>
		constexpr da_type d_insert = d_application<MN::insert, zero, Pos, Obj>;

		template<index_type Pos, index_type Obj>
		constexpr da_type d_replace = d_application<MN::replace, zero, Pos, Obj>;

		//

		template<index_type Pos, index_type Op, index_type... Args>
		constexpr da_type d_apply = d_application<MN::apply, MA::arity(sizeof...(Args)), Pos, Op, Args...>;

		template<index_type Pos, index_type Op, index_type... Args>
		constexpr da_type d_compel = d_application<MN::compel, MA::arity(sizeof...(Args)), Pos, Op, Args...>;

		template<index_type Op, index_type... Args>
		constexpr da_type d_test = d_application<MN::test, MA::arity(sizeof...(Args)), Op, Args...>;

		template<index_type Op, index_type... Args>
		constexpr da_type d_check = d_application<MN::check, MA::arity(sizeof...(Args)), Op, Args...>;

		constexpr da_type d_jump = d_application<MN::jump, zero>;

/***********************************************************************************************************************/

// controller:

	using dc_type = da_type(*)(index_type);

	struct DC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type length (dc_type c) { return c(size)(DA::size); }
	};

		// pack length is stored as the initial value.

	template<da_type... Vs>
	constexpr dc_type d_controller = f_array<da_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct DD
	{
		// applications:

			static constexpr index_type size   (dc_type c, index_type i, index_type) { return c(i)(DA::size  ); }
			static constexpr index_type name   (dc_type c, index_type i, index_type) { return c(i)(DA::name  ); }
			static constexpr index_type note   (dc_type c, index_type i, index_type) { return c(i)(DA::note  ); }
			static constexpr index_type pos    (dc_type c, index_type i, index_type) { return c(i)(DA::pos   ); }

			static constexpr index_type obj    (dc_type c, index_type i, index_type) { return c(i)(DA::obj   ); }

			static constexpr index_type op     (dc_type c, index_type i, index_type) { return c(i)(DA::op    ); }
			static constexpr index_type arg    (dc_type c, index_type i, index_type) { return c(i)(DA::arg   ); }
			static constexpr index_type arg1   (dc_type c, index_type i, index_type) { return c(i)(DA::arg1  ); }
			static constexpr index_type arg2   (dc_type c, index_type i, index_type) { return c(i)(DA::arg2  ); }

			static constexpr index_type pred   (dc_type c, index_type i, index_type) { return c(i)(DA::pred  ); }
			static constexpr index_type input  (dc_type c, index_type i, index_type) { return c(i)(DA::input ); }
			static constexpr index_type input1 (dc_type c, index_type i, index_type) { return c(i)(DA::input1); }
			static constexpr index_type input2 (dc_type c, index_type i, index_type) { return c(i)(DA::input2); }

		// iterators:

			// name:

				static constexpr index_type next_name(dc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0)	return MN::pause;
					else 		return c(i+1)(DA::name);
				}

			// note:

				static constexpr index_type next_note(dc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0)	return zero;
					else		return c(i+1)(DA::note);
				}

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;

			// index1:

				static constexpr index_type next_index1(dc_type c, depth_type d, index_type i, index_type)
				{
					if (d == 0)	return i;
					else 		return i+1;
				}

			// index2:

				static constexpr index_type (*next_index2)(dc_type, depth_type, index_type, index_type) =
					MD::template default_next_index2<dc_type, depth_type, index_type, index_type>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// call:

	template<da_type appl, da_type cont = d_pass<>>
	constexpr auto call_contr = d_controller<appl, cont>;

/***********************************************************************************************************************/

// jump:

	template<da_type test, da_type ante, da_type conse, da_type cont = d_pass<>>
	constexpr auto jump_contr = d_controller<test, d_jump, ante, cont, conse, cont>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

