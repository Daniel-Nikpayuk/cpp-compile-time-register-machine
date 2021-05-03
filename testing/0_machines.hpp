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

// testing:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace testing_space
{
	using namespace machine_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block machines:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// at:

	template<depth_type d, depth_type pos, auto... Vs>
	constexpr auto f_auto_pack_at(void(*)(auto_pack<Vs...>*))
	{
		return pack_at<d, pos, Vs...>;
	}

	template<typename List, depth_type pos, depth_type depth = 500>
	constexpr auto auto_pack_at = f_auto_pack_at<depth, pos>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic machines:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic machines:

/***********************************************************************************************************************/

// erase:

	template<depth_type d, index_type pos, auto... Vs>
	constexpr auto f_auto_pack_erase(void(*)(auto_pack<Vs...>*))
	{
		return pack_erase<d, pos, Vs...>;
	}

	template<typename List, index_type pos, depth_type depth = 500>
	constexpr auto auto_pack_erase = f_auto_pack_erase<depth, pos>(U_type_T<List>);

/***********************************************************************************************************************/

// insert:

	template<depth_type d, index_type pos, index_type obj, auto... Vs>
	constexpr auto f_auto_pack_insert(void(*)(auto_pack<Vs...>*))
	{
		return pack_insert<d, pos, obj, Vs...>;
	}

	template<typename List, index_type pos, index_type obj, depth_type depth = 500>
	constexpr auto auto_pack_insert = f_auto_pack_insert<depth, pos, obj>(U_type_T<List>);

/***********************************************************************************************************************/

// replace:

	template<depth_type d, index_type pos, index_type obj, auto... Vs>
	constexpr auto f_auto_pack_replace(void(*)(auto_pack<Vs...>*))
	{
		return pack_replace<d, pos, obj, Vs...>;
	}

	template<typename List, index_type pos, index_type obj, depth_type depth = 500>
	constexpr auto auto_pack_replace = f_auto_pack_replace<depth, pos, obj>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack apply1:

	template<auto d, auto pos, auto op, auto arg, auto... Vs>
	constexpr auto f_pack_apply1()
	{
		constexpr auto c = apply1_replace_contr<pos, op, arg, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto op, auto arg, auto... Vs>
	constexpr auto pack_apply1 = f_pack_apply1<d, pos, op, arg, Vs...>();

/***********************************************************************************************************************/

// apply1:

	template<depth_type d, index_type pos, index_type op, index_type arg, auto... Vs>
	constexpr auto f_auto_pack_apply1(void(*)(auto_pack<Vs...>*))
	{
		return pack_apply1<d, pos, op, arg, Vs...>;
	}

	template<typename List, index_type pos, index_type op, index_type arg, depth_type depth = 500>
	constexpr auto auto_pack_apply1 = f_auto_pack_apply1<depth, pos, op, arg>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack apply2:

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto f_pack_apply2()
	{
		constexpr auto c = apply2_replace_contr<pos, op, arg1, arg2, p_pack>;
		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<PD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto pack_apply2 = f_pack_apply2<d, pos, op, arg1, arg2, Vs...>();

/***********************************************************************************************************************/

// apply2:

	template<depth_type d, index_type pos, index_type op, index_type arg1, index_type arg2, auto... Vs>
	constexpr auto f_auto_pack_apply2(void(*)(auto_pack<Vs...>*))
	{
		return pack_apply2<d, pos, op, arg1, arg2, Vs...>;
	}

	template<typename List, index_type pos, index_type op, index_type arg1, index_type arg2, depth_type depth = 500>
	constexpr auto auto_pack_apply2 = f_auto_pack_apply2<depth, pos, op, arg1, arg2>(U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distributic machines:

/***********************************************************************************************************************/

// pack apply2:

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto f_pack_apply2_then_return()
	{
		constexpr auto c = call_contr
		<
			d_apply<pos, op, arg1, arg2>,
			d_stop<pos>
		>;

		constexpr auto i = zero;
		constexpr auto j = zero;

		return machine_start<DD, c, d, i, j, Vs...>();
	}

	template<auto d, auto pos, auto op, auto arg1, auto arg2, auto... Vs>
	constexpr auto pack_apply2_then_return = f_pack_apply2_then_return<d, pos, op, arg1, arg2, Vs...>();

/***********************************************************************************************************************/

// apply2:

	template<depth_type d, index_type pos, index_type op, index_type arg1, index_type arg2, auto... Vs>
	constexpr auto f_auto_pack_apply2_then_return(void(*)(auto_pack<Vs...>*))
	{
		return pack_apply2_then_return<d, pos, op, arg1, arg2, Vs...>;
	}

	template<typename List, index_type pos, index_type op, index_type arg1, index_type arg2, depth_type depth = 500>
	constexpr auto auto_pack_apply2_then_return = f_list_apply2_then_return<depth, pos, op, arg1, arg2>(U_type_T<List>);

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear machines:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register machines:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#endif

