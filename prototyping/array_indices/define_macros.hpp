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

// define macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto:

	#define _1_auto_Vs											\
														\
		auto   V1

	#define _2_auto_Vs											\
														\
		auto   V2

	#define _4_auto_Vs											\
														\
		auto   V3, auto   V4

	#define _8_auto_Vs											\
														\
		auto   V5, auto   V6, auto   V7, auto   V8

	#define _16_auto_Vs											\
														\
		auto   V9, auto  V10, auto  V11, auto  V12, auto  V13, auto  V14, auto  V15, auto  V16

	#define _32_auto_Vs											\
														\
		auto  V17, auto  V18, auto  V19, auto  V20, auto  V21, auto  V22, auto  V23, auto  V24,		\
		auto  V25, auto  V26, auto  V27, auto  V28, auto  V29, auto  V30, auto  V31, auto  V32

	#define _64_auto_Vs											\
														\
		auto  V33, auto  V34, auto  V35, auto  V36, auto  V37, auto  V38, auto  V39, auto  V40,		\
		auto  V41, auto  V42, auto  V43, auto  V44, auto  V45, auto  V46, auto  V47, auto  V48,		\
		auto  V49, auto  V50, auto  V51, auto  V52, auto  V53, auto  V54, auto  V55, auto  V56,		\
		auto  V57, auto  V58, auto  V59, auto  V60, auto  V61, auto  V62, auto  V63, auto  V64

	#define _128_auto_Vs											\
														\
		auto  V65, auto  V66, auto  V67, auto  V68, auto  V69, auto  V70, auto  V71, auto  V72,		\
		auto  V73, auto  V74, auto  V75, auto  V76, auto  V77, auto  V78, auto  V79, auto  V80,		\
		auto  V81, auto  V82, auto  V83, auto  V84, auto  V85, auto  V86, auto  V87, auto  V88,		\
		auto  V89, auto  V90, auto  V91, auto  V92, auto  V93, auto  V94, auto  V95, auto  V96,		\
		auto  V97, auto  V98, auto  V99, auto V100, auto V101, auto V102, auto V103, auto V104,		\
		auto V105, auto V106, auto V107, auto V108, auto V109, auto V110, auto V111, auto V112,		\
		auto V113, auto V114, auto V115, auto V116, auto V117, auto V118, auto V119, auto V120,		\
		auto V121, auto V122, auto V123, auto V124, auto V125, auto V126, auto V127, auto V128

	#define _256_auto_Vs											\
														\
		auto V129, auto V130, auto V131, auto V132, auto V133, auto V134, auto V135, auto V136,		\
		auto V137, auto V138, auto V139, auto V140, auto V141, auto V142, auto V143, auto V144,		\
		auto V145, auto V146, auto V147, auto V148, auto V149, auto V150, auto V151, auto V152,		\
		auto V153, auto V154, auto V155, auto V156, auto V157, auto V158, auto V159, auto V160,		\
		auto V161, auto V162, auto V163, auto V164, auto V165, auto V166, auto V167, auto V168,		\
		auto V169, auto V170, auto V171, auto V172, auto V173, auto V174, auto V175, auto V176,		\
		auto V177, auto V178, auto V179, auto V180, auto V181, auto V182, auto V183, auto V184,		\
		auto V185, auto V186, auto V187, auto V188, auto V189, auto V190, auto V191, auto V192,		\
														\
		auto V193, auto V194, auto V195, auto V196, auto V197, auto V198, auto V199, auto V200,		\
		auto V201, auto V202, auto V203, auto V204, auto V205, auto V206, auto V207, auto V208,		\
		auto V209, auto V210, auto V211, auto V212, auto V213, auto V214, auto V215, auto V216,		\
		auto V217, auto V218, auto V219, auto V220, auto V221, auto V222, auto V223, auto V224,		\
		auto V225, auto V226, auto V227, auto V228, auto V229, auto V230, auto V231, auto V232,		\
		auto V233, auto V234, auto V235, auto V236, auto V237, auto V238, auto V239, auto V240,		\
		auto V241, auto V242, auto V243, auto V244, auto V245, auto V246, auto V247, auto V248,		\
		auto V249, auto V250, auto V251, auto V252, auto V253, auto V254, auto V255, auto V256

	#define _512_auto_Vs											\
														\
		auto V257, auto V258, auto V259, auto V260, auto V261, auto V262, auto V263, auto V264,		\
		auto V265, auto V266, auto V267, auto V268, auto V269, auto V270, auto V271, auto V272,		\
		auto V273, auto V274, auto V275, auto V276, auto V277, auto V278, auto V279, auto V280,		\
		auto V281, auto V282, auto V283, auto V284, auto V285, auto V286, auto V287, auto V288,		\
		auto V289, auto V290, auto V291, auto V292, auto V293, auto V294, auto V295, auto V296,		\
		auto V297, auto V298, auto V299, auto V300, auto V301, auto V302, auto V303, auto V304,		\
		auto V305, auto V306, auto V307, auto V308, auto V309, auto V310, auto V311, auto V312,		\
		auto V313, auto V314, auto V315, auto V316, auto V317, auto V318, auto V319, auto V320,		\
														\
		auto V321, auto V322, auto V323, auto V324, auto V325, auto V326, auto V327, auto V328,		\
		auto V329, auto V330, auto V331, auto V332, auto V333, auto V334, auto V335, auto V336,		\
		auto V337, auto V338, auto V339, auto V340, auto V341, auto V342, auto V343, auto V344,		\
		auto V345, auto V346, auto V347, auto V348, auto V349, auto V350, auto V351, auto V352,		\
		auto V353, auto V354, auto V355, auto V356, auto V357, auto V358, auto V359, auto V360,		\
		auto V361, auto V362, auto V363, auto V364, auto V365, auto V366, auto V367, auto V368,		\
		auto V369, auto V370, auto V371, auto V372, auto V373, auto V374, auto V375, auto V376,		\
		auto V377, auto V378, auto V379, auto V380, auto V381, auto V382, auto V383, auto V384,		\
														\
		auto V385, auto V386, auto V387, auto V388, auto V389, auto V390, auto V391, auto V392,		\
		auto V393, auto V394, auto V395, auto V396, auto V397, auto V398, auto V399, auto V400,		\
		auto V401, auto V402, auto V403, auto V404, auto V405, auto V406, auto V407, auto V408,		\
		auto V409, auto V410, auto V411, auto V412, auto V413, auto V414, auto V415, auto V416,		\
		auto V417, auto V418, auto V419, auto V420, auto V421, auto V422, auto V423, auto V424,		\
		auto V425, auto V426, auto V427, auto V428, auto V429, auto V430, auto V431, auto V432,		\
		auto V433, auto V434, auto V435, auto V436, auto V437, auto V438, auto V439, auto V440,		\
		auto V441, auto V442, auto V443, auto V444, auto V445, auto V446, auto V447, auto V448,		\
														\
		auto V449, auto V450, auto V451, auto V452, auto V453, auto V454, auto V455, auto V456,		\
		auto V457, auto V458, auto V459, auto V460, auto V461, auto V462, auto V463, auto V464,		\
		auto V465, auto V466, auto V467, auto V468, auto V469, auto V470, auto V471, auto V472,		\
		auto V473, auto V474, auto V475, auto V476, auto V477, auto V478, auto V479, auto V480,		\
		auto V481, auto V482, auto V483, auto V484, auto V485, auto V486, auto V487, auto V488,		\
		auto V489, auto V490, auto V491, auto V492, auto V493, auto V494, auto V495, auto V496,		\
		auto V497, auto V498, auto V499, auto V500, auto V501, auto V502, auto V503, auto V504,		\
		auto V505, auto V506, auto V507, auto V508, auto V509, auto V510, auto V511, auto V512

/***********************************************************************************************************************/

// values:

	#define _1_Vs													\
															\
		  V1

	#define _2_Vs													\
															\
		  V2

	#define _4_Vs													\
															\
		  V3,   V4

	#define _8_Vs													\
															\
		  V5,   V6,   V7,   V8

	#define _16_Vs													\
															\
		  V9,  V10,  V11,  V12,  V13,  V14,  V15,  V16

	#define _32_Vs													\
															\
		 V17,  V18,  V19,  V20,  V21,  V22,  V23,  V24,  V25,  V26,  V27,  V28,  V29,  V30,  V31,  V32

	#define _64_Vs													\
															\
		 V33,  V34,  V35,  V36,  V37,  V38,  V39,  V40,  V41,  V42,  V43,  V44,  V45,  V46,  V47,  V48,		\
		 V49,  V50,  V51,  V52,  V53,  V54,  V55,  V56,  V57,  V58,  V59,  V60,  V61,  V62,  V63,  V64

	#define _128_Vs													\
															\
		 V65,  V66,  V67,  V68,  V69,  V70,  V71,  V72,  V73,  V74,  V75,  V76,  V77,  V78,  V79,  V80,		\
		 V81,  V82,  V83,  V84,  V85,  V86,  V87,  V88,  V89,  V90,  V91,  V92,  V93,  V94,  V95,  V96,		\
		 V97,  V98,  V99, V100, V101, V102, V103, V104, V105, V106, V107, V108, V109, V110, V111, V112,		\
		V113, V114, V115, V116, V117, V118, V119, V120, V121, V122, V123, V124, V125, V126, V127, V128

	#define _256_Vs													\
															\
		V129, V130, V131, V132, V133, V134, V135, V136, V137, V138, V139, V140, V141, V142, V143, V144,		\
		V145, V146, V147, V148, V149, V150, V151, V152, V153, V154, V155, V156, V157, V158, V159, V160,		\
		V161, V162, V163, V164, V165, V166, V167, V168, V169, V170, V171, V172, V173, V174, V175, V176,		\
		V177, V178, V179, V180, V181, V182, V183, V184, V185, V186, V187, V188, V189, V190, V191, V192,		\
															\
		V193, V194, V195, V196, V197, V198, V199, V200, V201, V202, V203, V204, V205, V206, V207, V208,		\
		V209, V210, V211, V212, V213, V214, V215, V216, V217, V218, V219, V220, V221, V222, V223, V224,		\
		V225, V226, V227, V228, V229, V230, V231, V232, V233, V234, V235, V236, V237, V238, V239, V240,		\
		V241, V242, V243, V244, V245, V246, V247, V248, V249, V250, V251, V252, V253, V254, V255, V256

	#define _512_Vs													\
															\
		V257, V258, V259, V260, V261, V262, V263, V264, V265, V266, V267, V268, V269, V270, V271, V272,		\
		V273, V274, V275, V276, V277, V278, V279, V280, V281, V282, V283, V284, V285, V286, V287, V288,		\
		V289, V290, V291, V292, V293, V294, V295, V296, V297, V298, V299, V300, V301, V302, V303, V304,		\
		V305, V306, V307, V308, V309, V310, V311, V312, V313, V314, V315, V316, V317, V318, V319, V320,		\
															\
		V321, V322, V323, V324, V325, V326, V327, V328, V329, V330, V331, V332, V333, V334, V335, V336,		\
		V337, V338, V339, V340, V341, V342, V343, V344, V345, V346, V347, V348, V349, V350, V351, V352,		\
		V353, V354, V355, V356, V357, V358, V359, V360, V361, V362, V363, V364, V365, V366, V367, V368,		\
		V369, V370, V371, V372, V373, V374, V375, V376, V377, V378, V379, V380, V381, V382, V383, V384,		\
															\
		V385, V386, V387, V388, V389, V390, V391, V392, V393, V394, V395, V396, V397, V398, V399, V400,		\
		V401, V402, V403, V404, V405, V406, V407, V408, V409, V410, V411, V412, V413, V414, V415, V416,		\
		V417, V418, V419, V420, V421, V422, V423, V424, V425, V426, V427, V428, V429, V430, V431, V432,		\
		V433, V434, V435, V436, V437, V438, V439, V440, V441, V442, V443, V444, V445, V446, V447, V448,		\
															\
		V449, V450, V451, V452, V453, V454, V455, V456, V457, V458, V459, V460, V461, V462, V463, V464,		\
		V465, V466, V467, V468, V469, V470, V471, V472, V473, V474, V475, V476, V477, V478, V479, V480,		\
		V481, V482, V483, V484, V485, V486, V487, V488, V489, V490, V491, V492, V493, V494, V495, V496,		\
		V497, V498, V499, V500, V501, V502, V503, V504, V505, V506, V507, V508, V509, V510, V511, V512

/***********************************************************************************************************************/

// optimizations (auto):

	#define _0_opt_auto_Vs

		// blank space.

	#define _1_opt_auto_Vs												\
															\
		auto V0,

	#define _2_opt_auto_Vs												\
															\
		auto V0, auto V1,

	#define _3_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2,

	#define _4_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3,

	#define _5_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4,

	#define _6_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5,

	#define _7_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6,

	#define _8_opt_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7,

/***********************************************************************************************************************/

// optimizations (values):

	#define _0_opt_Vs

		// blank space.

	#define _1_opt_Vs												\
															\
		V0,

	#define _2_opt_Vs												\
															\
		V0, V1,

	#define _3_opt_Vs												\
															\
		V0, V1, V2,

	#define _4_opt_Vs												\
															\
		V0, V1, V2, V3,

	#define _5_opt_Vs												\
															\
		V0, V1, V2, V3, V4,

	#define _6_opt_Vs												\
															\
		V0, V1, V2, V3, V4, V5,

	#define _7_opt_Vs												\
															\
		V0, V1, V2, V3, V4, V5, V6,

	#define _8_opt_Vs												\
															\
		V0, V1, V2, V3, V4, V5, V6, V7,

/***********************************************************************************************************************/

// fast tracking (auto):

	#define _1_fast_auto_Vs												\
															\
		_1_auto_Vs

	#define _2_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs

	#define _3_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs

	#define _4_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs

	#define _5_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs

	#define _6_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,						\
		_32_auto_Vs

	#define _7_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,						\
		_32_auto_Vs, _64_auto_Vs

	#define _8_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,						\
		_32_auto_Vs, _64_auto_Vs, _128_auto_Vs

	#define _9_fast_auto_Vs												\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,						\
		_32_auto_Vs, _64_auto_Vs, _128_auto_Vs, _256_auto_Vs

	#define _10_fast_auto_Vs											\
															\
		_1_auto_Vs, _2_auto_Vs, _4_auto_Vs, _8_auto_Vs, _16_auto_Vs,						\
		_32_auto_Vs, _64_auto_Vs, _128_auto_Vs, _256_auto_Vs, _512_auto_Vs

/***********************************************************************************************************************/

// fast tracking (values):

	#define _1_fast_Vs												\
															\
		_1_Vs

	#define _2_fast_Vs												\
															\
		_1_Vs, _2_Vs

	#define _3_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs

	#define _4_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs

	#define _5_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs

	#define _6_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,									\
		_32_Vs

	#define _7_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,									\
		_32_Vs, _64_Vs

	#define _8_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,									\
		_32_Vs, _64_Vs, _128_Vs

	#define _9_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,									\
		_32_Vs, _64_Vs, _128_Vs, _256_Vs

	#define _10_fast_Vs												\
															\
		_1_Vs, _2_Vs, _4_Vs, _8_Vs, _16_Vs,									\
		_32_Vs, _64_Vs, _128_Vs, _256_Vs, _512_Vs

/***********************************************************************************************************************/

// variadic pop:

	#define define_variadic_pop(P, N)										\
															\
		template<>												\
		struct variadic_pop<N>											\
		{													\
			template											\
			<												\
				/* stack: */										\
															\
					auto s, auto n,									\
															\
					_ ## N ## _fast_auto_Vs,							\
															\
					auto... Vs,									\
															\
				/* heap: */										\
															\
					typename CHeap, typename LHeap, typename RHeap					\
			>												\
			static constexpr auto result(CHeap ch, LHeap lh, RHeap rh)					\
			{												\
				constexpr auto next_n = n -_2_ ## P;							\
															\
				return variadic_pop<s(next_n)>::template result<s, next_n, Vs...>(ch, lh, rh);		\
			}												\
		}

/***********************************************************************************************************************/

// variadic push:

	#define define_variadic_push(P, N)										\
															\
		template<>												\
		struct variadic_push<N>											\
		{													\
			template											\
			<												\
				/* stack: */										\
															\
					auto s, auto n,									\
															\
					_ ## N ## _fast_auto_Vs,							\
															\
					auto... Vs,									\
															\
				/* heap: */										\
															\
					typename CHeap, typename LHeap, typename RHeap					\
			>												\
			static constexpr auto result(CHeap ch, LHeap lh, RHeap rh)					\
			{												\
				constexpr auto next_n = n -_2_ ## P;							\
															\
				return variadic_push<s(next_n)>::template result					\
				<											\
					s, next_n, Vs...,								\
															\
					_ ## N ## _fast_Vs								\
															\
				>(ch, lh, rh);										\
			}												\
		}

/***********************************************************************************************************************/

// variadic lheap:

	#define define_variadic_lheap(P, N)										\
															\
		template<>												\
		struct variadic_lheap<N>										\
		{													\
			template											\
			<												\
				/* stack: */										\
															\
					auto s, auto n,									\
															\
					_ ## N ## _fast_auto_Vs,							\
															\
					auto... Vs,									\
															\
				/* heap: */										\
															\
					auto... Ws, typename RHeap, typename CHeap					\
			>												\
			static constexpr auto result(void(*)(auto_pack<Ws...>*), RHeap rh, CHeap ch)			\
			{												\
				constexpr auto next_n = n -_2_ ## P;							\
															\
				return variadic_lheap<s(next_n)>::template result<s, next_n, Vs...>			\
				(											\
					U_pack_Vs									\
					<										\
						Ws...,									\
															\
						_ ## N ## _fast_Vs							\
															\
					>, rh, ch									\
				);											\
			}												\
		}

/***********************************************************************************************************************/

// variadic rheap:

	#define define_variadic_rheap(P, N)										\
															\
		template<>												\
		struct variadic_rheap<N>										\
		{													\
			template											\
			<												\
				/* stack: */										\
															\
					auto s, auto n,									\
															\
					_ ## N ## _fast_auto_Vs,							\
															\
					auto... Vs,									\
															\
				/* heap: */										\
															\
					typename LHeap, auto... Ws, typename CHeap					\
			>												\
			static constexpr auto result(LHeap lh, void(*)(auto_pack<Ws...>*), CHeap ch)			\
			{												\
				constexpr auto next_n = n -_2_ ## P;							\
															\
				return variadic_rheap<s(next_n)>::template result<s, next_n, Vs...>			\
				(											\
					lh, U_pack_Vs									\
					<										\
						Ws...,									\
															\
						_ ## N ## _fast_Vs							\
															\
					>, ch										\
				);											\
			}												\
		}

/***********************************************************************************************************************/

// pack at:

	#define define_pack_at(N)											\
															\
		template<>												\
		struct pack_at<N>											\
		{													\
			static constexpr index_type h = VCtr::length(pack_at_contr<VM::pack>)-1;			\
															\
			template<auto d, auto cont, _ ## N ## _opt_auto_Vs auto... Vs, auto... Ws>			\
			static constexpr auto result(void(*)(auto_pack<Ws...>*))					\
			{												\
				constexpr auto c = pack_at_contr<cont>;							\
				constexpr auto i = pair<d, h>;								\
															\
				return variadic_machine<v_next_name(c, i)>::template result				\
				<											\
					c, v_next_index<i>, pack_at_locus<N>, Ws..., Vs...				\
															\
				>(U_pack_Vs<>, U_pack_Vs<>);								\
			}												\
		}

/***********************************************************************************************************************/

// pack erase:

	#define define_pack_erase(N, S)											\
															\
		template<>												\
		struct pack_erase<N>											\
		{													\
			static constexpr index_type h = VCtr::length(pack_erase_contr<VM::pack>)-1;			\
															\
			template<auto d, auto cont, _ ## S ## _opt_auto_Vs auto... Vs, auto... Ws>			\
			static constexpr auto result(void(*)(auto_pack<Ws...>*))					\
			{												\
				constexpr auto c = pack_erase_contr<cont>;						\
				constexpr auto i = pair<d, h>;								\
															\
				return variadic_machine<v_next_name(c, i)>::template result				\
				<											\
					c, v_next_index<i>, pack_erase_locus<N>, Ws..., _ ## N ## _opt_Vs Vs...		\
															\
				>(U_pack_Vs<>, U_pack_Vs<>);								\
			}												\
		}

/***********************************************************************************************************************/

// pack insert:

	#define define_pack_insert(N)											\
															\
		template<>												\
		struct pack_insert<N>											\
		{													\
			static constexpr index_type h = VCtr::length(pack_insert_contr<VM::pack>)-1;			\
															\
			template<auto d, auto cont, _ ## N ## _opt_auto_Vs auto... Vs, auto V, auto... Ws>		\
			static constexpr auto result(void(*)(auto_pack<V>*), void(*)(auto_pack<Ws...>*))		\
			{												\
				constexpr auto c = pack_insert_contr<cont>;						\
				constexpr auto i = pair<d, h>;								\
															\
				return variadic_machine<v_next_name(c, i)>::template result				\
				<											\
					c, v_next_index<i>, pack_insert_locus<N>, Ws..., _ ## N ## _opt_Vs V, Vs...	\
															\
				>(U_pack_Vs<>, U_pack_Vs<>);								\
			}												\
		}

/***********************************************************************************************************************/

// pack replace:

	#define define_pack_replace(N, S)										\
															\
		template<>												\
		struct pack_replace<N>											\
		{													\
			static constexpr index_type h = VCtr::length(pack_replace_contr<VM::pack>)-1;			\
															\
			template<auto d, auto cont, _ ## S ## _opt_auto_Vs auto... Vs, auto V, auto... Ws>		\
			static constexpr auto result(void(*)(auto_pack<V>*), void(*)(auto_pack<Ws...>*))		\
			{												\
				constexpr auto c = pack_replace_contr<cont>;						\
				constexpr auto i = pair<d, h>;								\
															\
				return variadic_machine<v_next_name(c, i)>::template result				\
				<											\
					c, v_next_index<i>, pack_replace_locus<N>, Ws..., _ ## N ## _opt_Vs V, Vs...	\
															\
				>(U_pack_Vs<>, U_pack_Vs<>);								\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

