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

// define machine macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

/***********************************************************************************************************************/

	#define CONTR_PARAMS												\
															\
		typename n, auto c, auto d, auto i, auto j								\

/***********************************************************************************************************************/

	#define FIXED_HEAP_PARAMS											\
															\
		typename Heap0, typename Heap1

	#define FIXED_HEAP_SIG_ARGS											\
															\
		Heap0 H0, Heap1 H1

	#define FIXED_HEAP_ARGS												\
															\
		H0, H1

/***********************************************************************************************************************/

	#define MACHINE(N, C, D, I, J)	 										\
															\
		machine													\
		<													\
			N::next_name(C, D, I, J),									\
			N::next_note(C, D, I, J)									\
															\
		>::template result											\
		<													\
			N, C,												\
															\
			N::next_depth(D),										\
			N::next_index1(C, D, I, J),									\
			N::next_index2(C, D, I, J),									\
															\
			Vs...												\
		>

/***********************************************************************************************************************/

// pop (2^N):

	#define define_block_machine_pop(N)										\
															\
		template<>												\
		struct machine<MN::pop_2_n, N>										\
		{													\
			template<CONTR_PARAMS, _2_ ## N ## _auto_Vs, auto... Vs, typename... Heaps>			\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return MACHINE(n, c, d, i, j)(Hs...);							\
			}												\
		}

/***********************************************************************************************************************/

// push (2^N):

	#define define_block_machine_push(N)										\
															\
		template<>												\
		struct machine<MN::push_2_n, N>										\
		{													\
			template<CONTR_PARAMS, _2_ ## N ## _auto_Vs, auto... Vs, typename... Heaps>			\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					Vs..., _2_ ## N ## _Vs								\
															\
				>(Hs...);										\
			}												\
		}

/***********************************************************************************************************************/

// fold (2^N):

	#define define_block_machine_fold(N)										\
															\
		template<>												\
		struct machine<MN::fold_2_n, N>										\
		{													\
			template											\
			<												\
				CONTR_PARAMS, auto V, _2_ ## N ## _auto_Vs, auto... Vs,					\
				auto op, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_2_ ## N ## _ops  V,  _2_ ## N ## _op_Vs, Vs...					\
															\
				>(H0, Hs...);										\
			}												\
		}

/***********************************************************************************************************************/

// roll (2^N):

	#define define_block_machine_roll(N)										\
															\
		template<>												\
		struct machine<MN::roll_2_n, N>										\
		{													\
			template											\
			<												\
				CONTR_PARAMS, auto V, _2_ ## N ## _auto_Vs, auto... Vs,					\
				auto uact, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<uact>*), Heaps... Hs)				\
			{												\
				using act = T_type_U<uact>;								\
															\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_2_ ## N ## _acts  V,  _2_ ## N ## _act_Vs, Vs...				\
															\
				>(H0, Hs...);										\
			}												\
		}

/***********************************************************************************************************************/

// move stack to heap zero (2^N):

	#define define_block_machine_move_stack_to_heap_zero(N)								\
															\
		template<>												\
		struct machine<MN::move_2_n_s_to_h0, N>									\
		{													\
			template<CONTR_PARAMS, _2_ ## N ## _auto_Vs, auto... Vs, auto... Ws, typename... Heaps>		\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return MACHINE(n, c, d, i, j)(U_pack_Vs<Ws..., _2_ ## N ## _Vs>, Hs...);		\
			}												\
		}

/***********************************************************************************************************************/

// move stack to heap one (2^N):

	#define define_block_machine_move_stack_to_heap_one(N)								\
															\
		template<>												\
		struct machine<MN::move_2_n_s_to_h1, N>									\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _2_ ## N ## _auto_Vs, auto... Vs,						\
				typename Heap0, auto... Ws, typename... Heaps						\
			>												\
			static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)		\
			{												\
				return MACHINE(n, c, d, i, j)(H0, U_pack_Vs<Ws..., _2_ ## N ## _Vs>, Hs...);		\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// (fast) copy stack position to heap zero:

	#define define_permutatic_machine_copy_stack_position_to_heap_zero(S, N)					\
															\
		template<>												\
		struct machine<MN::copy_sn_to_h0, S>									\
		{													\
			template<CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs, auto... Ws, typename... Heaps>	\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## S ## _fast_Vs, Vs...							\
															\
				>(U_pack_Vs<Ws..., V ## N>, Hs...);							\
			}												\
		}

/***********************************************************************************************************************/

// (fast) move stack position to heap zero:

	#define define_permutatic_machine_move_stack_position_to_heap_zero(S, N, C)					\
															\
		template<>												\
		struct machine<MN::move_sn_to_h0, S>									\
		{													\
			template<CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs, auto... Ws, typename... Heaps>	\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  Vs...					\
															\
				>(U_pack_Vs<Ws..., V ## N>, Hs...);							\
			}												\
		}

/***********************************************************************************************************************/

// (fast) erase stack position:

	#define define_permutatic_machine_erase_stack_position(S, N, C)							\
															\
		template<>												\
		struct machine<MN::erase_sn, S>										\
		{													\
			template<CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs, typename... Heaps>			\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  Vs...					\
															\
				>(Hs...);										\
			}												\
		}

/***********************************************************************************************************************/

// (fast) rotate stack position:

	#define define_permutatic_machine_rotate_stack_position(S, N, C)						\
															\
		template<>												\
		struct machine<MN::rotate_sn, S>									\
		{													\
			template<CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs, typename... Heaps>			\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  Vs..., V ## N				\
															\
				>(Hs...);										\
			}												\
		}

/***********************************************************************************************************************/

// (fast) insert heap zero to stack position:

	#define define_permutatic_machine_insert_heap_zero_to_stack_position(S, N, C)					\
															\
		template<>												\
		struct machine<MN::insert_h0_to_sn, S>									\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _ ## N ## _fast_auto_Vs  _ ## C ## _comma  auto... Vs,			\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  Ws..., Vs...				\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// replace heap zero to stack position:

	#define define_permutatic_machine_replace_heap_zero_to_stack_position(S, N, C)					\
															\
		template<>												\
		struct machine<MN::replace_h0_to_sn, S>									\
		{													\
			template<CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs, auto... Ws, typename... Heaps>	\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  Ws..., Vs...				\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// unary apply replace heap zero to stack position:

	#define define_permutatic_machine_unary_apply_replace_heap_zero_to_stack_position(S, N, C)			\
															\
		template<>												\
		struct machine<MN::apply1_replace_h0_to_sn, S>								\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs,					\
				auto op, auto arg, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op, arg>*), Heaps... Hs)			\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  op(arg), Vs...				\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// binary apply replace heap zero to stack position:

	#define define_permutatic_machine_binary_apply_replace_heap_zero_to_stack_position(S, N, C)			\
															\
		template<>												\
		struct machine<MN::apply2_replace_h0_to_sn, S>								\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs,					\
				auto op, auto arg1, auto arg2, typename... Heaps					\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op, arg1, arg2>*), Heaps... Hs)		\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma  op(arg1, arg2), Vs...			\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// unary compel replace heap zero to stack position:

	#define define_permutatic_machine_unary_compel_replace_heap_zero_to_stack_position(S, N, C)			\
															\
		template<>												\
		struct machine<MN::compel1_replace_h0_to_sn, S>								\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs,					\
				auto act, auto arg, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<act, arg>*), Heaps... Hs)			\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma						\
															\
					T_type_U<act>::template result<arg>, Vs...					\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// binary compel replace heap zero to stack position:

	#define define_permutatic_machine_binary_compel_replace_heap_zero_to_stack_position(S, N, C)			\
															\
		template<>												\
		struct machine<MN::compel2_replace_h0_to_sn, S>								\
		{													\
			template											\
			<												\
				CONTR_PARAMS, _ ## S ## _fast_auto_Vs, auto... Vs,					\
				auto act, auto arg1, auto arg2, typename... Heaps					\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<act, arg1, arg2>*), Heaps... Hs)		\
			{												\
				return machine										\
				<											\
					n::next_name(c, d, i, j),							\
					n::next_note(c, d, i, j)							\
															\
				>::template result									\
				<											\
					n, c,										\
															\
					n::next_depth(d),								\
					n::next_index1(c, d, i, j),							\
					n::next_index2(c, d, i, j),							\
															\
					_ ## N ## _fast_Vs  _ ## C ## _comma						\
															\
					T_type_U<act>::template result<arg1, arg2>, Vs...				\
															\
				>(U_pack_Vs<>, Hs...);									\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

