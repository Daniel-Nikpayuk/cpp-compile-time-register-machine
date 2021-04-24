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

#ifndef _7_REGISTER_MACHINES_HPP
#define _7_REGISTER_MACHINES_HPP

// register machines:

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

// halters:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// assign:

	template<>
	struct machine<MN::assign>
	{
		using nn			= VD;
		static constexpr auto nc	= replace_h0_to_sn_contr<>;
		static constexpr auto ni	= zero;

		template
		<
			CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heaps... Hs)
		{
			constexpr auto nj = replace_h0_to_sn_locus<n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)
				(U_pack_Vs<Ws..., n::obj(c, i, j)>, H1, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (dispatch):

/***********************************************************************************************************************/

// branch:

	template<>
	struct machine<MN::branch>
	{
		template<CONTR_PARAMS, bool V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto ni = V0 ? n::pos(c, i, j) : i;
			constexpr auto nj = V0 ? zero : j;

			return MACHINE(n, c, d, ni, nj)(Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// operators:

/***********************************************************************************************************************/

// go to stack zero (optimized):

	template<>
	struct machine<MN::go_to_s0>
	{
		static constexpr auto nj = zero;

		template
		<
			CONTR_PARAMS, auto V0, auto... Vs,
			FIXED_HEAP_PARAMS, auto un, auto nc, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, void(*)(auto_pack<un, nc>*), Heaps... Hs)
		{
			using nn		= T_type_U<un>;
			constexpr auto ni	= V0;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, Hs...);
		}
	};

/***********************************************************************************************************************/

// go to (optimized):

	template<>
	struct machine<MN::go_to, MD::regtr>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;
		static constexpr auto pass	= p_call<MN::go_to_s0, zero>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto nc = insert_contr<zero, n::pos(c, i, j), pass>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c>, Hs...);
		}
	};

/***********************************************************************************************************************/

// save:

	template<>
	struct machine<MN::save>
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
			constexpr auto nc = insert_contr<n::reg_size(c, i, j), n::pos(c, i, j)>; // single call(s)
			constexpr auto un = U_type_T<n>;

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/

// restore:

	template<>
	struct machine<MN::restore>
	{
		using nn			= PD;
		static constexpr auto ni	= zero;
		static constexpr auto nj	= zero;

		template<depth_type pos, depth_type obj, pa_type cont = p_pass<>>
		static constexpr auto restore = p_controller
		<
			p_move_sn_to_h0<obj>,
			p_replace_h0_to_sn<pos>,

			cont
		>;

		template
		<
			CONTR_PARAMS, auto... Vs,
			FIXED_HEAP_PARAMS, typename... Heaps
		>
		static constexpr auto result(FIXED_HEAP_SIG_ARGS, Heaps... Hs)
		{
			constexpr auto un = U_type_T<n>;
			constexpr auto nc = restore<n::pos(c, i, j), n::reg_size(c, i, j)>; // single call(s)

			return MACHINE(nn, nc, d, ni, nj)(FIXED_HEAP_ARGS, U_pack_Vs<un, c, i, j>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// applications:

	// inherits from machine applications:

		using ra_type	= ma_type;
		using RA	= MA;

		template<index_type Name, index_type Note, index_type... Vs>
		constexpr ra_type r_application = m_application<Name, Note, Vs...>;

	// syntactic sugar:

		constexpr ra_type r_dump = m_application<MN::dump, zero>;
		constexpr ra_type r_pack = m_application<MN::pack, zero>;

		template<index_type Op, index_type... Args>
		constexpr ra_type r_test = m_application<MN::test, MA::arity(sizeof...(Args)), Op, Args...>;

		template<index_type Pos, index_type Op, index_type... Args>
		constexpr ra_type r_apply = m_application<MN::apply, MA::arity(sizeof...(Args)), Pos, Op, Args...>;

		template<index_type Pos, index_type Obj>
		constexpr ra_type r_replace = m_application<MN::replace, zero, Pos, Obj>;

		template<index_type Pos, index_type Obj>
		constexpr ra_type r_assign = m_application<MN::assign, zero, Pos, Obj>;

		template<index_type Pos>
		constexpr ra_type r_branch = m_application<MN::branch, zero, Pos>;

		template<index_type Pos>
		constexpr ra_type r_save = m_application<MN::save, zero, Pos>;

		template<index_type Pos>
		constexpr ra_type r_restore = m_application<MN::restore, zero, Pos>;

		template<index_type Pos>
		constexpr ra_type r_goto_contr = m_application<MN::go_to, MD::contr, Pos>;

		template<index_type Pos>
		constexpr ra_type r_goto_regtr = m_application<MN::go_to, MD::regtr, Pos>;

		template<index_type Pos>
		constexpr ra_type r_stop = m_application<MN::stop, zero, Pos>;

		template<index_type Num>
		constexpr ra_type r_reg_size = m_application<MN::reg_size, zero, Num>;

/***********************************************************************************************************************/

// labels:

	using rl_type = ra_type(*)(index_type);

	struct RL
	{
		// members:

			static constexpr index_type size 	= 0;
			static constexpr index_type first	= 1;

		// procedures:

			static constexpr index_type	length(rl_type l)	{ return l(size)(RA::size) ; }
			static constexpr ra_type	last(rl_type l)		{ return l(length(l))  ; }
	};

		// pack length is stored as the initial value.

	template<ra_type... Vs>
	constexpr rl_type r_label = f_array<ra_type, f_array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

	using rc_type = rl_type(*)(index_type);

	struct RC
	{
		// members:

			static constexpr index_type size = 0;

		// procedures:

			static constexpr index_type	length   (rc_type c) { return c(size)(RL::size)(RA::size); }
			static constexpr rl_type	last     (rc_type c) { return c(length(c)); }
			static constexpr index_type	reg_size (rc_type c) { return RL::last(last(c))(RA::pos) ; }
	};

		// pack length is stored as the initial value.

	template<rl_type... Vs>
	constexpr rc_type r_controller = f_array
		<rl_type, f_array<ra_type, f_array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/

// dispatch:

	// Initializers require (l = 0, m = k) -> first instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

	struct RD
	{
		// applications:

			static constexpr index_type size   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::size  ); }
			static constexpr index_type name   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::name  ); }
			static constexpr index_type note   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::note  ); }
			static constexpr index_type pos    (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::pos   ); }

			static constexpr index_type obj    (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::obj   ); }

			static constexpr index_type op     (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::op    ); }
			static constexpr index_type arg    (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::arg   ); }
			static constexpr index_type arg1   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::arg1  ); }
			static constexpr index_type arg2   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::arg2  ); }

			static constexpr index_type test   (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::test  ); }
			static constexpr index_type input  (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::input ); }
			static constexpr index_type input1 (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::input1); }
			static constexpr index_type input2 (rc_type c, index_type i, index_type j) { return c(i)(j)(RA::input2); }

			static constexpr index_type reg_size (rc_type c, index_type, index_type)   { return RC::reg_size(c); }

		// iterators:

			// basics:

				static constexpr index_type basic_next_index1(rc_type c, index_type i, index_type j)
				{
					return i + bool(j == RL::length(c(i)));	// j == last : return i+1.
										// j != last : return i.
				}

				static constexpr index_type basic_next_index2(rc_type c, index_type i, index_type j)
				{
					return (j == RL::length(c(i))) ? one : j+1;	// j == last : return one.
											// j != last : return j+1.
				}

			// index1:

				static constexpr index_type next_index1(rc_type c, depth_type d, index_type i, index_type j)
				{
					if (d == 0) return i;

					index_type ni	= basic_next_index1(c, i, j);
					index_type nj	= basic_next_index2(c, i, j);
					index_type name	= c(ni)(nj)(RA::name);
					index_type note	= c(ni)(nj)(RA::note);

					if (name == MN::go_to && note == MD::contr)	return c(ni)(nj)(RA::pos);
					else 						return ni;
				}

			// index2:

				static constexpr index_type next_index2(rc_type c, depth_type d, index_type i, index_type j)
				{
					if (d == 0) return j;

					index_type ni	= basic_next_index1(c, i, j);
					index_type nj	= basic_next_index2(c, i, j);
					index_type name	= c(ni)(nj)(RA::name);
					index_type note	= c(ni)(nj)(RA::note);

					if (name == MN::go_to && note == MD::contr)	return one;
					else						return nj;
				}

			// name:

				static constexpr index_type next_name(rc_type c, depth_type d, index_type i, index_type j)
				{
					if (d == 0) return MN::pause;

					index_type ni = next_index1(c, d, i, j);
					index_type nj = next_index2(c, d, i, j);

					return c(ni)(nj)(RA::name);
				}

			// note:

				static constexpr index_type next_note(rc_type c, depth_type d, index_type i, index_type j)
				{
					if (d == 0) return zero;

					index_type ni = next_index1(c, d, i, j);
					index_type nj = next_index2(c, d, i, j);

					return c(ni)(nj)(RA::note);
				}

			// depth:

				static constexpr depth_type (*next_depth)(depth_type) =
					MD::template default_next_depth<depth_type>;
	};

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

