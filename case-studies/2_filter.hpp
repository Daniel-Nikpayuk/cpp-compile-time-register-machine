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

// filter:

	using namespace function_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear filter:

/***********************************************************************************************************************/

/*
	template
	<
		// registers:

			index_type n		= 0,

			index_type eq		= 1,
			index_type U_eq		= 2,
			index_type sub		= 3,

			index_type zero		= 4,
			index_type one		= 5,
			index_type id		= 6,

			index_type func		= 7
	>
	constexpr auto filter_contr = n_controller
	<
		n_stem <  n_test<eq, n, zero>        ,    n_pack           ,    n_apply<n, sub, n, one>  >,
		n_stem <  n_check<U_eq, func, id>    ,    n_erase<func>    ,    n_pass<>                 >,

		n_cycle
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register filter:

/***********************************************************************************************************************/

	template
	<
		// registers:

			index_type n		= 0,

			index_type eq		= 1,
			index_type cond		= 2,
			index_type sub		= 3,

			index_type c_0		= 4,
			index_type c_1		= 5,

			index_type val		= 6,

		// labels:

			index_type is_loop_end	= 1,
			index_type pop_value	= 2,
			index_type return_pack	= 3
	>
	constexpr auto r_filter_contr = r_controller
	<
		r_label // is loop end:
		<
			test       < eq          , n   , c_0       >,
			branch     < return_pack                   >,
			apply      < n           , sub , n   , c_1 >,
			check      < cond        , val             >,
			branch     < pop_value                     >,
			rotate_sn  < val                           >,
			goto_contr < is_loop_end                   >
		>,

		r_label // pop value:
		<
			erase      < val                         >,
			goto_contr < is_loop_end                 >
		>,

		r_label // return pack:
		<
			pop        < six >,

			pack       <     >
		>
	>;

/***********************************************************************************************************************/

	template<auto d, auto test_op, auto... Vs>
	constexpr auto f_r_filter()
	{
		constexpr depth_type n		= sizeof...(Vs);

		constexpr auto eq_op		= equal<depth_type>;
		constexpr auto sub_op		= subtract<depth_type>;

		constexpr depth_type c_0	= 0;
		constexpr depth_type c_1	= 1;

		constexpr index_type i		= one;
		constexpr index_type j		= zero;

		return machine_start
		<
			RD, r_filter_contr<>, d, i, j,
			n, eq_op, test_op, sub_op, c_0, c_1, Vs...
		>();
	}

	template<auto test_op, auto... Vs>
	constexpr auto r_filter = f_r_filter<500, test_op, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// application: function composition

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	constexpr void _id_() { }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// binary operator:

	struct S_do_compose
	{
		template<auto f, auto g>
		static constexpr out_type<g> result(in_type<f> x) { return g(f(x)); }
	};

	constexpr auto U_do_compose = U_type_T<S_do_compose>;

/***********************************************************************************************************************/

// binary operator:

	struct S_is_id
	{
		static constexpr auto pack_id = U_pack_Vs<_id_>;

		template<auto f>
		static constexpr bool result = V_is_equal_UxU(U_pack_Vs<f>, pack_id);
	};

	constexpr auto U_is_id = U_type_T<S_is_id>;

/***********************************************************************************************************************/

// (fast) do compose:

	template<auto d, auto... Vs>
	constexpr auto f_do_compose()
	{
		constexpr depth_type length = sizeof...(Vs);

		if constexpr (length == 0) return _id_;
		else
		{
			constexpr auto c	= p_controller
						<
							move_sn_to_h0<zero>,
							call<MN::roll_s0, zero>,
							stop<zero>
						>;
			constexpr auto i	= zero;
			constexpr auto j	= zero;

			return machine_start<PD, c, d, i, j, U_do_compose, length-1, Vs...>();
		}
	}

	template<auto... Vs>
	constexpr auto do_compose = f_do_compose<500, Vs...>();

/***********************************************************************************************************************/

// auto pack do compose:

	template<depth_type d, auto... Vs>
	constexpr auto f_auto_pack_do_compose(void(*)(auto_pack<Vs...>*))
	{
		return f_do_compose<d, Vs...>();
	}

/***********************************************************************************************************************/

	template<auto d, auto... fs>
	constexpr auto f_safe_do_compose()
	{
		return f_auto_pack_do_compose<d>(r_filter<U_is_id, fs...>);
	}

	template<auto... fs>
	constexpr auto safe_do_compose = f_safe_do_compose<500, fs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

