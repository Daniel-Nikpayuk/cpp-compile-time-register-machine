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

// variadic fold:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call:

	template
	<
		// stack:

			auto s, auto n,

			auto... Vs,

		// heap:

			auto d, auto c, auto l, auto i,

			typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(0)> *),
		void(*)( auto_pack<d, c, l, i>    *),
		LHeap lh, RHeap rh
	)
	{
		constexpr auto next_name = U_value_V<c[i]>;

		return variadic_machine<d, c, l, i, Vs...>(next_name, lh, rh);
	}

/***********************************************************************************************************************/

// 2^0:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(1)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_0;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^1:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(2)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_1;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^2:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(3)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_2;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^3:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(4)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_3;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^4:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(5)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_4;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^5:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,
			_32_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(6)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_5;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,
			_32_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^6:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,
			_32_auto_Vs, _64_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(7)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_6;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,
			_32_Vs, _64_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^7:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,
			_32_auto_Vs, _64_auto_Vs, _128_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(8)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_7;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,
			_32_Vs, _64_Vs, _128_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^8:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,
			_32_auto_Vs, _64_auto_Vs, _128_auto_Vs, _256_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(9)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_8;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,
			_32_Vs, _64_Vs, _128_Vs, _256_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// 2^9:

	template
	<
		// stack:

			auto s, auto n,

			_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,
			_32_auto_Vs, _64_auto_Vs, _128_auto_Vs, _256_auto_Vs, _512_auto_Vs,

			auto... Vs,

		// heap:

			typename CHeap, typename LHeap, typename RHeap
	>
	constexpr auto variadic_fold
	(
		void(*)( auto_pack<index_type(10)> *),
		CHeap ch, LHeap lh, RHeap rh
	)
	{
		constexpr auto next_n    = n -_2_9;
		constexpr auto next_name = U_value_V<s(next_n)>;

		return variadic_fold
		<
			s, next_n, t,

			Vs...

			_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,
			_32_Vs, _64_Vs, _128_Vs, _256_Vs, _512_Vs

		>(next_name, ch, lh, rh);
	}

/***********************************************************************************************************************/

// pass:

	template
	<
		// stack:

			auto d, auto c, auto l, auto i,

			auto... Vs,

		// heap:

			typename LHeap, typename RHeap
	>
	constexpr auto variadic_machine
	(
		void(*)( auto_pack<VM::fold> *),
		LHeap lh, RHeap rh
	)
	{
		constexpr auto n         = l[i];
		constexpr auto s         = get_dispatch(n);
		constexpr auto next_name = U_value_V<s(n)>;

		constexpr auto ft_d      = fast_track_depth(n);

		if constexpr (d < ft_d)

			return variadic_machine<d, c, l, i, Vs...>(U_value_V<index_type(VM::dump)>, lh, rh);
		else
			return variadic_fold<s, n, Vs...>(next_name, U_pack_Vs<d-ft_d, c, l, i+1>, lh, rh);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

