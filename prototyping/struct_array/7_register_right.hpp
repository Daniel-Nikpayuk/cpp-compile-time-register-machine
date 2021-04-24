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

// right:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// 2^0:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(0)>*))
	{
		constexpr depth_type nn		= n-_2_0;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^1:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(1)>*))
	{
		constexpr depth_type nn		= n-_2_1;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^2:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(2)>*))
	{
		constexpr depth_type nn		= n-_2_2;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^3:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(3)>*))
	{
		constexpr depth_type nn		= n-_2_3;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^4:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(4)>*))
	{
		constexpr depth_type nn		= n-_2_4;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^5:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,
		_32_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(5)>*))
	{
		constexpr depth_type nn		= n-_2_5;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^6:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,
		_32_auto_Rs, _64_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(6)>*))
	{
		constexpr depth_type nn		= n-_2_6;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^7:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,
		_32_auto_Rs, _64_auto_Rs, _128_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(7)>*))
	{
		constexpr depth_type nn		= n-_2_7;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^8:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,
		_32_auto_Rs, _64_auto_Rs, _128_auto_Rs, _256_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(8)>*))
	{
		constexpr depth_type nn		= n-_2_8;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/

// 2^9:

	template
	<
		auto d, auto c, auto l, auto m,
		auto k, auto dispatch, depth_type n,

		_1_auto_Rs, _2_auto_Rs, _4_auto_Rs, _8_auto_Rs, _16_auto_Rs,
		_32_auto_Rs, _64_auto_Rs, _128_auto_Rs, _256_auto_Rs, _512_auto_Rs,

		auto... Rs
	>
	constexpr auto machine(void(*)(auto_pack<MI::right, index_type(9)>*))
	{
		constexpr depth_type nn		= n-_2_9;
		constexpr index_type nk		= dispatch(nn);

		constexpr instr_type j		= next_i(d, c, l, m);
		constexpr index_type nl		= next_l(d, c, l, m);
		constexpr index_type nm		= next_m(d, c, l, m);

		return machine<d-1, c, nl, nm, nk, dispatch, nn, Rs...>(U_pair_VxV<j(1), next_k(c, j)>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<auto k, auto dispatch, depth_type n, template<auto...> class ListName, auto... Rs>
	constexpr auto list_at_cont(void(*)(ListName<Rs...>*))
	{
		return machine
			<cont, dispatch, pos, Rs...>(U_value_V<dispatch(pos)>);
	}

	template<typename List, depth_type pos>
	constexpr auto list_at = list_at_cont<get_dispatch(pos), pos>(U_type_T<List>);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

