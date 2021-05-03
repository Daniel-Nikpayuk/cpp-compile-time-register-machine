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

#ifndef _1_VARIADIC_SPACE_HPP
#define _1_VARIADIC_SPACE_HPP

// variadic space:

	// constexpr variadic monad (design):

		// Passing (copying) parameter packs is expensive, and shortens nesting depth lifespans. As such,
		// skipping over modular transitions is privileged when reasonable. See definition of "at" for example.

//		template<>
//		struct variadic_machine<VM::(((name)))>
//		{
//			template
//			<
//				// stack:

//					auto c, auto i, auto l,

//					auto... Vs,

//				// heap:

//					auto... LHs, auto... RHs
//			>
//			static constexpr auto result
//			(
//				void(* lheap )( auto_pack< LHs... > *),
//				void(* rheap )( auto_pack< RHs... > *)
//			)
//			{
//				constexpr auto next_lheap = U_pack_Vs< LHs... >; // It is assumed LHs..., RHs...
//				constexpr auto next_rheap = U_pack_Vs< RHs... >; // are mutated in some way here.

//				return variadic_machine<v_next_name(c, i)>::template result
//				<
//					c, v_next_index<i>, l, Vs...

//				>(next_lheap, next_rheap);
//			}
//		};

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

	#include"machine-space/0_machine_declarations.hpp"
	#include"machine-space/1_machine_controllers.hpp"

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// externals:

/***********************************************************************************************************************/

// start:

		// switch positions of d, c.

	template<auto d, auto c, auto l, auto... Vs>
	constexpr auto variadic_start()
	{
		constexpr pair_type i = pair<d, 0>; // assumes v_next will increment i.

		return variadic_machine<v_next_name(c, i)>::template result
		<
			c, v_next_index<i>, l, Vs...

		>(U_pack_Vs<>, U_pack_Vs<>);
	}

/***********************************************************************************************************************/

// pause:

	template<auto c, auto i, auto l, auto... Vs, auto... LHs, auto... RHs>
	constexpr auto variadic_pause(void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*))
	{
		constexpr auto nlh = U_pack_Vs<LHs...>;
		constexpr auto nrh = U_pack_Vs<RHs...>;

		return type_map<auto_pack<MH::variadic_machine, c, i(VInd::index), l, nlh, nrh, Vs...>*>;
	}

/***********************************************************************************************************************/

// trampoline:

	template<auto d, typename T>
	constexpr auto variadic_trampoline(T v) { return v; }

/*
	template<auto d, auto cont, auto appl, auto rh, auto... Vs>
	constexpr auto variadic_trampoline(void(*)(auto_pack<Vappl::unary, cont, appl, rh, Rs...>*))
	{
		constexpr auto v = variadic_machine<v_next_name(c, i)>::template result<d, c, i, l, Vs...>(lh, rh);

		return pack_apply<d>(v);
	}
*/

	template<auto d, auto c, auto h, auto l, auto lh, auto rh, auto... Vs>
	constexpr auto variadic_trampoline(void(*)(auto_pack<MH::variadic_machine, c, h, l, lh, rh, Vs...>*))
	{
		constexpr auto i = pair<d, h>;
		constexpr auto v = variadic_machine<v_next_name(c, i)>::template result<c, i, l, Vs...>(lh, rh);

		return variadic_trampoline<d>(v);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

	// d  - depth
	// c  - controller
	// l  - locus
	// i  - index
	// Vs - values

/***********************************************************************************************************************/

// pause:

	template<>
	struct variadic_machine<VM::pause>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... LHs, auto... RHs>
		static constexpr auto result(void(*)(auto_pack<LHs...>*), void(*)(auto_pack<RHs...>*))
		{
			constexpr auto nlh = U_pack_Vs<LHs...>;
			constexpr auto nrh = U_pack_Vs<RHs...>;

			return type_map<auto_pack<MH::variadic_machine, c, i(VInd::index), l, nlh, nrh, Vs...>*>;
		}
	};

/***********************************************************************************************************************/

// first:

	template<>
	struct variadic_machine<VM::first>
	{
		template<auto c, auto i, auto l, auto V0, auto... Vs, typename LHeap, typename RHeap>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			return V0;
		}
	};

/***********************************************************************************************************************/

// rest:

	template<>
	struct variadic_machine<VM::rest>
	{
		template<auto c, auto i, auto l, auto V0, auto... Vs, typename LHeap, typename RHeap>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			return type_map<auto_pack<Vs...>*>;
		}
	};

/***********************************************************************************************************************/

// pack:

	template<>
	struct variadic_machine<VM::pack>
	{
		template<auto c, auto i, auto l, auto... Vs, typename LHeap, typename RHeap>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			return type_map<auto_pack<Vs...>*>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fast tracking:

/***********************************************************************************************************************/

// pop:

	template<index_type> struct variadic_pop;

	// call:

	template<>
	struct variadic_pop<zero>
	{
		template
		<
			// stack:

				auto s, auto n,

				auto... Vs,

			// heap:

				auto c, auto i, auto l,

				typename LHeap, typename RHeap
		>
		static constexpr auto result(void(*)(auto_pack<c, i, l>*), LHeap lh, RHeap rh)
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(lh, rh);
		}
	};

	// 2^N:

	define_variadic_pop(0,  1);
	define_variadic_pop(1,  2);
	define_variadic_pop(2,  3);
	define_variadic_pop(3,  4);
	define_variadic_pop(4,  5);
	define_variadic_pop(5,  6);
	define_variadic_pop(6,  7);
	define_variadic_pop(7,  8);
	define_variadic_pop(8,  9);
	define_variadic_pop(9, 10);

	// pass:

	template<>
	struct variadic_machine<VM::pop>
	{
		template
		<
			// stack:

				auto c, auto i, auto l,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap
		>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			constexpr auto d         = i(VInd::depth);
			constexpr auto h         = i(VInd::index);

			constexpr auto n         = l(h);
			constexpr auto s         = get_dispatch(n);
			constexpr auto ft_d      = fast_track_depth(n);

			if constexpr (d < ft_d)

				return variadic_pause<c, i, l, Vs...>(lh, rh);
			else
				return variadic_pop<s(n)>::template result
				<
					s, n, Vs...

				>(U_pack_Vs<c, pair<d+1-ft_d, h>, l>, lh, rh);
		}
	};

/***********************************************************************************************************************/

// push:

	template<index_type> struct variadic_push;

	// call:

	template<>
	struct variadic_push<zero>
	{
		template
		<
			// stack:

				auto s, auto n,

				auto... Vs,

			// heap:

				auto c, auto i, auto l,

				typename LHeap, typename RHeap
		>
		static constexpr auto result(void(*)(auto_pack<c, i, l>*), LHeap lh, RHeap rh)
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(lh, rh);
		}
	};

	// 2^N:

	define_variadic_push(0,  1);
	define_variadic_push(1,  2);
	define_variadic_push(2,  3);
	define_variadic_push(3,  4);
	define_variadic_push(4,  5);
	define_variadic_push(5,  6);
	define_variadic_push(6,  7);
	define_variadic_push(7,  8);
	define_variadic_push(8,  9);
	define_variadic_push(9, 10);

	// pass:

	template<>
	struct variadic_machine<VM::push>
	{
		template
		<
			// stack:

				auto c, auto i, auto l,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap
		>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			constexpr auto d         = i(VInd::depth);
			constexpr auto h         = i(VInd::index);

			constexpr auto n         = l(h);
			constexpr auto s         = get_dispatch(n);
			constexpr auto ft_d      = fast_track_depth(n);

			if constexpr (d < ft_d)

				return variadic_pause<c, i, l, Vs...>(lh, rh);
			else
				return variadic_push<s(n)>::template result
				<
					s, n, Vs...

				>(U_pack_Vs<c, pair<d+1-ft_d, h>, l>, lh, rh);
		}
	};

/***********************************************************************************************************************/

// stack to lheap:

	template<index_type> struct variadic_lheap;

	// call:

	template<>
	struct variadic_lheap<zero>
	{
		template
		<
			// stack:

				auto s, auto n,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap,

				auto c, auto i, auto l
		>
		static constexpr auto result(LHeap lh, RHeap rh, void(*)(auto_pack<c, i, l>*))
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(lh, rh);
		}
	};

	// 2^N:

	define_variadic_lheap(0,  1);
	define_variadic_lheap(1,  2);
	define_variadic_lheap(2,  3);
	define_variadic_lheap(3,  4);
	define_variadic_lheap(4,  5);
	define_variadic_lheap(5,  6);
	define_variadic_lheap(6,  7);
	define_variadic_lheap(7,  8);
	define_variadic_lheap(8,  9);
	define_variadic_lheap(9, 10);

	// pass:

	template<>
	struct variadic_machine<VM::s_to_lh>
	{
		template
		<
			// stack:

				auto c, auto i, auto l,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap
		>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			constexpr auto d         = i(VInd::depth);
			constexpr auto h         = i(VInd::index);

			constexpr auto n         = l(h);
			constexpr auto s         = get_dispatch(n);
			constexpr auto ft_d      = fast_track_depth(n);

			if constexpr (d < ft_d)

				return variadic_pause<c, i, l, Vs...>(lh, rh);
			else
				return variadic_lheap<s(n)>::template result
				<
					s, n, Vs...

				>(lh, rh, U_pack_Vs<c, pair<d+1-ft_d, h>, l>);
		}
	};

/***********************************************************************************************************************/

// stack to rheap:

	template<index_type> struct variadic_rheap;

	// call:

	template<>
	struct variadic_rheap<zero>
	{
		template
		<
			// stack:

				auto s, auto n,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap,

				auto c, auto i, auto l
		>
		static constexpr auto result(LHeap lh, RHeap rh, void(*)(auto_pack<c, i, l>*))
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(lh, rh);
		}
	};

	// 2^N:

	define_variadic_rheap(0,  1);
	define_variadic_rheap(1,  2);
	define_variadic_rheap(2,  3);
	define_variadic_rheap(3,  4);
	define_variadic_rheap(4,  5);
	define_variadic_rheap(5,  6);
	define_variadic_rheap(6,  7);
	define_variadic_rheap(7,  8);
	define_variadic_rheap(8,  9);
	define_variadic_rheap(9, 10);

	// pass:

	template<>
	struct variadic_machine<VM::s_to_rh>
	{
		template
		<
			// stack:

				auto c, auto i, auto l,

				auto... Vs,

			// heap:

				typename LHeap, typename RHeap
		>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			constexpr auto d         = i(VInd::depth);
			constexpr auto h         = i(VInd::index);

			constexpr auto n         = l(h);
			constexpr auto s         = get_dispatch(n);
			constexpr auto ft_d      = fast_track_depth(n);

			if constexpr (d < ft_d)

				return variadic_pause<c, i, l, Vs...>(lh, rh);
			else
				return variadic_rheap<s(n)>::template result
				<
					s, n, Vs...

				>(lh, rh, U_pack_Vs<c, pair<d+1-ft_d, h>, l>);
		}
	};

/***********************************************************************************************************************/

// lheap to front stack:

	template<>
	struct variadic_machine<VM::lh_to_sf>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, typename RHeap>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), RHeap rh)
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Ws..., Vs...

			>(U_pack_Vs<>, rh);
		}
	};

/***********************************************************************************************************************/

// lheap to back stack:

	template<>
	struct variadic_machine<VM::lh_to_sb>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, typename RHeap>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), RHeap rh)
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs..., Ws...

			>(U_pack_Vs<>, rh);
		}
	};

/***********************************************************************************************************************/

// rheap to front stack:

	template<>
	struct variadic_machine<VM::rh_to_sf>
	{
		template<auto c, auto i, auto l, auto... Vs, typename LHeap, auto... Ws>
		static constexpr auto result(LHeap lh, void(*rh)(auto_pack<Ws...>*))
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Ws..., Vs...

			>(lh, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/

// rheap to back stack:

	template<>
	struct variadic_machine<VM::rh_to_sb>
	{
		template<auto c, auto i, auto l, auto... Vs, typename LHeap, auto... Ws>
		static constexpr auto result(LHeap lh, void(*rh)(auto_pack<Ws...>*))
		{
			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs..., Ws...

			>(lh, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/

// lheap to rheap front:

	template<>
	struct variadic_machine<VM::lh_to_rhf>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, auto... Xs>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), void(*rh)(auto_pack<Xs...>*))
		{
			constexpr auto nrh = U_pack_Vs<Ws..., Xs...>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(U_pack_Vs<>, nrh);
		}
	};

/***********************************************************************************************************************/

// lheap to rheap back:

	template<>
	struct variadic_machine<VM::lh_to_rhb>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, auto... Xs>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), void(*rh)(auto_pack<Xs...>*))
		{
			constexpr auto nrh = U_pack_Vs<Xs..., Ws...>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(U_pack_Vs<>, nrh);
		}
	};

/***********************************************************************************************************************/

// rheap to lheap front:

	template<>
	struct variadic_machine<VM::rh_to_lhf>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, auto... Xs>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), void(*rh)(auto_pack<Xs...>*))
		{
			constexpr auto nlh = U_pack_Vs<Xs..., Ws...>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(nlh, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/

// rheap to lheap back:

	template<>
	struct variadic_machine<VM::rh_to_lhb>
	{
		template<auto c, auto i, auto l, auto... Vs, auto... Ws, auto... Xs>
		static constexpr auto result(void(*lh)(auto_pack<Ws...>*), void(*rh)(auto_pack<Xs...>*))
		{
			constexpr auto nlh = U_pack_Vs<Ws..., Xs...>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, l, Vs...

			>(nlh, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// selectors:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// at:

/***********************************************************************************************************************/

// controller:

	template<index_type cont>
	constexpr auto pack_at_contr = v_controller<VM::pop, cont>;

	template<depth_type n>
	constexpr auto pack_at_locus = v_locus<n>;

	template<index_type...> struct pack_at;

/***********************************************************************************************************************/

// optimizations:

	define_pack_at(0);
	define_pack_at(1);
	define_pack_at(2);
	define_pack_at(3);
	define_pack_at(4);
	define_pack_at(5);
	define_pack_at(6);
	define_pack_at(7);

/***********************************************************************************************************************/

// otherwise:

	template<>
	struct pack_at<>
	{
		static constexpr index_type h = 0;

		template<auto d, auto cont, auto n, auto... Vs, typename RHeap>
		static constexpr auto result(RHeap rh)
		{
			constexpr auto c = pack_at_contr<cont>;
			constexpr auto i = pair<d, h>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, pack_at_locus<n>, Vs...

			>(U_pack_Vs<>, rh);
		}
	};

/***********************************************************************************************************************/

// variadic:

		// delegate d ?

	template<auto d, auto n, auto... Vs>
	constexpr auto variadic_at()
	{
		if constexpr (!bool(d))		return U_value_V<VAppl::binary>;
		else if constexpr (n < eight)	return pack_at<n>::template result<d-1, VM::first, Vs...>(U_pack_Vs<>);
		else				return pack_at<>::template result<d-1, VM::first, n, Vs...>(U_pack_Vs<>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// mutators:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// erase (heap oriented):

/***********************************************************************************************************************/

// controller:

	template<index_type cont>
	constexpr auto pack_erase_contr = v_controller<VM::s_to_lh, VM::pop, VM::lh_to_sf, cont>;

	template<depth_type n>
	constexpr auto pack_erase_locus = v_locus<n, one>;

	template<index_type...> struct pack_erase;

/***********************************************************************************************************************/

// optimizations:

	define_pack_erase(0, 1);
	define_pack_erase(1, 2);
	define_pack_erase(2, 3);
	define_pack_erase(3, 4);
	define_pack_erase(4, 5);
	define_pack_erase(5, 6);
	define_pack_erase(6, 7);
	define_pack_erase(7, 8);

/***********************************************************************************************************************/

// otherwise:

	template<>
	struct pack_erase<>
	{
		static constexpr index_type h = 0;

		template<auto d, auto cont, auto n, auto... Vs>
		static constexpr auto result()
		{
			constexpr auto c = pack_erase_contr<cont>;
			constexpr auto i = pair<d, h>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, pack_erase_locus<n>, Vs...

			>(U_pack_Vs<>, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// insert (heap oriented):

/***********************************************************************************************************************/

	template<index_type cont>
	constexpr auto pack_insert_contr = v_controller<VM::s_to_rh, VM::lh_to_sf, VM::rh_to_sf, cont>;

	template<depth_type n>
	constexpr auto pack_insert_locus = v_locus<n>;

	template<index_type...> struct pack_insert;

/***********************************************************************************************************************/

// optimizations:

	define_pack_insert(0);
	define_pack_insert(1);
	define_pack_insert(2);
	define_pack_insert(3);
	define_pack_insert(4);
	define_pack_insert(5);
	define_pack_insert(6);
	define_pack_insert(7);

/***********************************************************************************************************************/

// otherwise:

	template<>
	struct pack_insert<>
	{
		static constexpr index_type h = 0;

		template<auto d, auto cont, auto n, auto... Vs>
		static constexpr auto result()
		{
			constexpr auto c = pack_insert_contr<cont>;
			constexpr auto i = pair<d, h>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, pack_insert_locus<n>, Vs...

			>(U_pack_Vs<>, U_pack_Vs<>);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// replace (heap oriented):

/***********************************************************************************************************************/

	template<index_type cont>
	constexpr auto pack_replace_contr = v_controller<VM::s_to_rh, VM::pop, VM::lh_to_sf, VM::rh_to_sf, cont>;

	template<depth_type n>
	constexpr auto pack_replace_locus = v_locus<n, 1>;

	template<index_type...> struct pack_replace;

/***********************************************************************************************************************/

// optimizations:

	define_pack_replace(0, 1);
	define_pack_replace(1, 2);
	define_pack_replace(2, 3);
	define_pack_replace(3, 4);
	define_pack_replace(4, 5);
	define_pack_replace(5, 6);
	define_pack_replace(6, 7);
	define_pack_replace(7, 8);

/***********************************************************************************************************************/

// otherwise:

	template<>
	struct pack_replace<>
	{
		static constexpr index_type h = 0;

		template<auto d, auto cont, auto n, auto... Vs, typename LHeap, typename RHeap>
		static constexpr auto result(LHeap lh, RHeap rh)
		{
			constexpr auto c = pack_replace_contr<cont>;
			constexpr auto i = pair<d, h>;

			return variadic_machine<v_next_name(c, i)>::template result
			<
				c, v_next_index<i>, pack_replace_locus<n>, Vs...

			>(lh, rh);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// apply:

	template<index_type> struct pack_apply;

/***********************************************************************************************************************/

// unary:

	template<>
	struct pack_apply<VAppl::unary>
	{
		template<auto d, auto cont, auto appl, auto... Rs, auto... RHs>
		static constexpr auto result(void(*rh)(auto_pack<RHs...>*))
		{
			if constexpr (!bool(d)) return U_pack_Vs<VAppl::unary, cont, appl, U_pack_Vs<RHs...>, Rs...>;

			constexpr auto reg	= appl(VAppl::reg);
			constexpr auto op	= variadic_at<d-1, appl(VAppl::op), Rs...>();
			constexpr auto arg	= variadic_at<d-1, appl(VAppl::arg), Rs...>();
			constexpr auto lh	= U_value_V<op(arg)>;

			if constexpr (reg < eight)

				return pack_replace<reg>::template result<d-1, cont, Rs...>(lh, rh);
			else
				return pack_replace<>::template result<d-1, cont, reg, Rs...>(lh, rh);
		}
	};

/***********************************************************************************************************************/

// binary:

		// maybe delegate the nesting depth to any machine that uses this.

	template<>
	struct pack_apply<VAppl::binary>
	{
		template<auto d, auto cont, auto appl, auto... Rs, auto... RHs>
		static constexpr auto result(void(*rh)(auto_pack<RHs...>*))
		{
			if constexpr (!bool(d)) return U_pack_Vs<VAppl::unary, cont, appl, U_pack_Vs<RHs...>, Rs...>;

			constexpr auto reg	= appl(VAppl::reg);
			constexpr auto op	= variadic_at<d-1, appl(VAppl::op), Rs...>();
			constexpr auto arg1	= variadic_at<d-1, appl(VAppl::arg1), Rs...>();
			constexpr auto arg2	= variadic_at<d-1, appl(VAppl::arg2), Rs...>();
			constexpr auto lh	= U_value_V<op(arg1, arg2)>;

			if constexpr (reg < eight)

				return pack_replace<reg>::template result<d-1, cont, Rs...>(lh, rh);
			else
				return pack_replace<>::template result<d-1, cont, reg, Rs...>(lh, rh);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

#include"machine-space/undef_macros.hpp"

#endif

