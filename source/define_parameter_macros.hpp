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

// define parameter macros:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// preamble:

	#define _0_comma												\
															\
		// blank space.

	#define _1_comma												\
															\
		,

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// upper auto:

	#define _upper_1_auto_Vs											\
															\
		auto   V0

	#define _upper_2_auto_Vs											\
															\
		auto   V1

	#define _upper_4_auto_Vs											\
															\
		auto   V2, auto   V3

	#define _upper_8_auto_Vs											\
															\
		auto   V4, auto   V5, auto   V6, auto   V7

	#define _upper_16_auto_Vs											\
															\
		auto   V8, auto   V9, auto  V10, auto  V11, auto  V12, auto  V13, auto  V14, auto  V15

	#define _upper_32_auto_Vs											\
															\
		auto  V16, auto  V17, auto  V18, auto  V19, auto  V20, auto  V21, auto  V22, auto  V23,			\
		auto  V24, auto  V25, auto  V26, auto  V27, auto  V28, auto  V29, auto  V30, auto  V31

	#define _upper_64_auto_Vs											\
															\
		auto  V32, auto  V33, auto  V34, auto  V35, auto  V36, auto  V37, auto  V38, auto  V39,			\
		auto  V40, auto  V41, auto  V42, auto  V43, auto  V44, auto  V45, auto  V46, auto  V47,			\
		auto  V48, auto  V49, auto  V50, auto  V51, auto  V52, auto  V53, auto  V54, auto  V55,			\
		auto  V56, auto  V57, auto  V58, auto  V59, auto  V60, auto  V61, auto  V62, auto  V63

	#define _upper_128_auto_Vs											\
															\
		auto  V64, auto  V65, auto  V66, auto  V67, auto  V68, auto  V69, auto  V70, auto  V71,			\
		auto  V72, auto  V73, auto  V74, auto  V75, auto  V76, auto  V77, auto  V78, auto  V79,			\
		auto  V80, auto  V81, auto  V82, auto  V83, auto  V84, auto  V85, auto  V86, auto  V87,			\
		auto  V88, auto  V89, auto  V90, auto  V91, auto  V92, auto  V93, auto  V94, auto  V95,			\
		auto  V96, auto  V97, auto  V98, auto  V99, auto V100, auto V101, auto V102, auto V103,			\
		auto V104, auto V105, auto V106, auto V107, auto V108, auto V109, auto V110, auto V111,			\
		auto V112, auto V113, auto V114, auto V115, auto V116, auto V117, auto V118, auto V119,			\
		auto V120, auto V121, auto V122, auto V123, auto V124, auto V125, auto V126, auto V127

	#define _upper_256_auto_Vs											\
															\
		auto V128, auto V129, auto V130, auto V131, auto V132, auto V133, auto V134, auto V135,			\
		auto V136, auto V137, auto V138, auto V139, auto V140, auto V141, auto V142, auto V143,			\
		auto V144, auto V145, auto V146, auto V147, auto V148, auto V149, auto V150, auto V151,			\
		auto V152, auto V153, auto V154, auto V155, auto V156, auto V157, auto V158, auto V159,			\
		auto V160, auto V161, auto V162, auto V163, auto V164, auto V165, auto V166, auto V167,			\
		auto V168, auto V169, auto V170, auto V171, auto V172, auto V173, auto V174, auto V175,			\
		auto V176, auto V177, auto V178, auto V179, auto V180, auto V181, auto V182, auto V183,			\
		auto V184, auto V185, auto V186, auto V187, auto V188, auto V189, auto V190, auto V191,			\
															\
		auto V192, auto V193, auto V194, auto V195, auto V196, auto V197, auto V198, auto V199,			\
		auto V200, auto V201, auto V202, auto V203, auto V204, auto V205, auto V206, auto V207,			\
		auto V208, auto V209, auto V210, auto V211, auto V212, auto V213, auto V214, auto V215,			\
		auto V216, auto V217, auto V218, auto V219, auto V220, auto V221, auto V222, auto V223,			\
		auto V224, auto V225, auto V226, auto V227, auto V228, auto V229, auto V230, auto V231,			\
		auto V232, auto V233, auto V234, auto V235, auto V236, auto V237, auto V238, auto V239,			\
		auto V240, auto V241, auto V242, auto V243, auto V244, auto V245, auto V246, auto V247,			\
		auto V248, auto V249, auto V250, auto V251, auto V252, auto V253, auto V254, auto V255

	#define _upper_512_auto_Vs											\
															\
		auto V256, auto V257, auto V258, auto V259, auto V260, auto V261, auto V262, auto V263,			\
		auto V264, auto V265, auto V266, auto V267, auto V268, auto V269, auto V270, auto V271,			\
		auto V272, auto V273, auto V274, auto V275, auto V276, auto V277, auto V278, auto V279,			\
		auto V280, auto V281, auto V282, auto V283, auto V284, auto V285, auto V286, auto V287,			\
		auto V288, auto V289, auto V290, auto V291, auto V292, auto V293, auto V294, auto V295,			\
		auto V296, auto V297, auto V298, auto V299, auto V300, auto V301, auto V302, auto V303,			\
		auto V304, auto V305, auto V306, auto V307, auto V308, auto V309, auto V310, auto V311,			\
		auto V312, auto V313, auto V314, auto V315, auto V316, auto V317, auto V318, auto V319,			\
															\
		auto V320, auto V321, auto V322, auto V323, auto V324, auto V325, auto V326, auto V327,			\
		auto V328, auto V329, auto V330, auto V331, auto V332, auto V333, auto V334, auto V335,			\
		auto V336, auto V337, auto V338, auto V339, auto V340, auto V341, auto V342, auto V343,			\
		auto V344, auto V345, auto V346, auto V347, auto V348, auto V349, auto V350, auto V351,			\
		auto V352, auto V353, auto V354, auto V355, auto V356, auto V357, auto V358, auto V359,			\
		auto V360, auto V361, auto V362, auto V363, auto V364, auto V365, auto V366, auto V367,			\
		auto V368, auto V369, auto V370, auto V371, auto V372, auto V373, auto V374, auto V375,			\
		auto V376, auto V377, auto V378, auto V379, auto V380, auto V381, auto V382, auto V383,			\
															\
		auto V384, auto V385, auto V386, auto V387, auto V388, auto V389, auto V390, auto V391,			\
		auto V392, auto V393, auto V394, auto V395, auto V396, auto V397, auto V398, auto V399,			\
		auto V400, auto V401, auto V402, auto V403, auto V404, auto V405, auto V406, auto V407,			\
		auto V408, auto V409, auto V410, auto V411, auto V412, auto V413, auto V414, auto V415,			\
		auto V416, auto V417, auto V418, auto V419, auto V420, auto V421, auto V422, auto V423,			\
		auto V424, auto V425, auto V426, auto V427, auto V428, auto V429, auto V430, auto V431,			\
		auto V432, auto V433, auto V434, auto V435, auto V436, auto V437, auto V438, auto V439,			\
		auto V440, auto V441, auto V442, auto V443, auto V444, auto V445, auto V446, auto V447,			\
															\
		auto V448, auto V449, auto V450, auto V451, auto V452, auto V453, auto V454, auto V455,			\
		auto V456, auto V457, auto V458, auto V459, auto V460, auto V461, auto V462, auto V463,			\
		auto V464, auto V465, auto V466, auto V467, auto V468, auto V469, auto V470, auto V471,			\
		auto V472, auto V473, auto V474, auto V475, auto V476, auto V477, auto V478, auto V479,			\
		auto V480, auto V481, auto V482, auto V483, auto V484, auto V485, auto V486, auto V487,			\
		auto V488, auto V489, auto V490, auto V491, auto V492, auto V493, auto V494, auto V495,			\
		auto V496, auto V497, auto V498, auto V499, auto V500, auto V501, auto V502, auto V503,			\
		auto V504, auto V505, auto V506, auto V507, auto V508, auto V509, auto V510, auto V511

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// upper values:

	#define _upper_1_Vs												\
															\
		  V0

	#define _upper_2_Vs												\
															\
		  V1

	#define _upper_4_Vs												\
															\
		  V2,   V3

	#define _upper_8_Vs												\
															\
		  V4,   V5,   V6,   V7

	#define _upper_16_Vs												\
															\
		  V8,   V9,  V10,  V11,  V12,  V13,  V14,  V15

	#define _upper_32_Vs												\
															\
		 V16,  V17,  V18,  V19,  V20,  V21,  V22,  V23,  V24,  V25,  V26,  V27,  V28,  V29,  V30,  V31

	#define _upper_64_Vs												\
															\
		 V32,  V33,  V34,  V35,  V36,  V37,  V38,  V39,  V40,  V41,  V42,  V43,  V44,  V45,  V46,  V47,		\
		 V48,  V49,  V50,  V51,  V52,  V53,  V54,  V55,  V56,  V57,  V58,  V59,  V60,  V61,  V62,  V63

	#define _upper_128_Vs												\
															\
		 V64,  V65,  V66,  V67,  V68,  V69,  V70,  V71,  V72,  V73,  V74,  V75,  V76,  V77,  V78,  V79,		\
		 V80,  V81,  V82,  V83,  V84,  V85,  V86,  V87,  V88,  V89,  V90,  V91,  V92,  V93,  V94,  V95,		\
		 V96,  V97,  V98,  V99, V100, V101, V102, V103, V104, V105, V106, V107, V108, V109, V110, V111,		\
		V112, V113, V114, V115, V116, V117, V118, V119, V120, V121, V122, V123, V124, V125, V126, V127

	#define _upper_256_Vs												\
															\
		V128, V129, V130, V131, V132, V133, V134, V135, V136, V137, V138, V139, V140, V141, V142, V143,		\
		V144, V145, V146, V147, V148, V149, V150, V151, V152, V153, V154, V155, V156, V157, V158, V159,		\
		V160, V161, V162, V163, V164, V165, V166, V167, V168, V169, V170, V171, V172, V173, V174, V175,		\
		V176, V177, V178, V179, V180, V181, V182, V183, V184, V185, V186, V187, V188, V189, V190, V191,		\
															\
		V192, V193, V194, V195, V196, V197, V198, V199, V200, V201, V202, V203, V204, V205, V206, V207,		\
		V208, V209, V210, V211, V212, V213, V214, V215, V216, V217, V218, V219, V220, V221, V222, V223,		\
		V224, V225, V226, V227, V228, V229, V230, V231, V232, V233, V234, V235, V236, V237, V238, V239,		\
		V240, V241, V242, V243, V244, V245, V246, V247, V248, V249, V250, V251, V252, V253, V254, V255

	#define _upper_512_Vs												\
															\
		V256, V257, V258, V259, V260, V261, V262, V263, V264, V265, V266, V267, V268, V269, V270, V271,		\
		V272, V273, V274, V275, V276, V277, V278, V279, V280, V281, V282, V283, V284, V285, V286, V287,		\
		V288, V289, V290, V291, V292, V293, V294, V295, V296, V297, V298, V299, V300, V301, V302, V303,		\
		V304, V305, V306, V307, V308, V309, V310, V311, V312, V313, V314, V315, V316, V317, V318, V319,		\
															\
		V320, V321, V322, V323, V324, V325, V326, V327, V328, V329, V330, V331, V332, V333, V334, V335,		\
		V336, V337, V338, V339, V340, V341, V342, V343, V344, V345, V346, V347, V348, V349, V350, V351,		\
		V352, V353, V354, V355, V356, V357, V358, V359, V360, V361, V362, V363, V364, V365, V366, V367,		\
		V368, V369, V370, V371, V372, V373, V374, V375, V376, V377, V378, V379, V380, V381, V382, V383,		\
															\
		V384, V385, V386, V387, V388, V389, V390, V391, V392, V393, V394, V395, V396, V397, V398, V399,		\
		V400, V401, V402, V403, V404, V405, V406, V407, V408, V409, V410, V411, V412, V413, V414, V415,		\
		V416, V417, V418, V419, V420, V421, V422, V423, V424, V425, V426, V427, V428, V429, V430, V431,		\
		V432, V433, V434, V435, V436, V437, V438, V439, V440, V441, V442, V443, V444, V445, V446, V447,		\
															\
		V448, V449, V450, V451, V452, V453, V454, V455, V456, V457, V458, V459, V460, V461, V462, V463,		\
		V464, V465, V466, V467, V468, V469, V470, V471, V472, V473, V474, V475, V476, V477, V478, V479,		\
		V480, V481, V482, V483, V484, V485, V486, V487, V488, V489, V490, V491, V492, V493, V494, V495,		\
		V496, V497, V498, V499, V500, V501, V502, V503, V504, V505, V506, V507, V508, V509, V510, V511

/***********************************************************************************************************************/

// upper operation values:

	#define _upper_1_op_Vs												\
															\
		  V0)

	#define _upper_2_op_Vs												\
															\
		  V1)

	#define _upper_4_op_Vs												\
															\
		  V2),   V3)

	#define _upper_8_op_Vs												\
															\
		  V4),   V5),   V6),   V7)

	#define _upper_16_op_Vs												\
															\
		  V8),   V9),  V10),  V11),  V12),  V13),  V14),  V15)

	#define _upper_32_op_Vs												\
															\
		 V16),  V17),  V18),  V19),  V20),  V21),  V22),  V23),							\
		 V24),  V25),  V26),  V27),  V28),  V29),  V30),  V31)

	#define _upper_64_op_Vs												\
															\
		 V32),  V33),  V34),  V35),  V36),  V37),  V38),  V39),							\
		 V40),  V41),  V42),  V43),  V44),  V45),  V46),  V47),							\
		 V48),  V49),  V50),  V51),  V52),  V53),  V54),  V55),							\
		 V56),  V57),  V58),  V59),  V60),  V61),  V62),  V63)

	#define _upper_128_op_Vs											\
															\
		 V64),  V65),  V66),  V67),  V68),  V69),  V70),  V71),							\
		 V72),  V73),  V74),  V75),  V76),  V77),  V78),  V79),							\
		 V80),  V81),  V82),  V83),  V84),  V85),  V86),  V87),							\
		 V88),  V89),  V90),  V91),  V92),  V93),  V94),  V95),							\
		 V96),  V97),  V98),  V99), V100), V101), V102), V103),							\
		V104), V105), V106), V107), V108), V109), V110), V111),							\
		V112), V113), V114), V115), V116), V117), V118), V119),							\
		V120), V121), V122), V123), V124), V125), V126), V127)

	#define _upper_256_op_Vs											\
															\
		V128), V129), V130), V131), V132), V133), V134), V135),							\
		V136), V137), V138), V139), V140), V141), V142), V143),							\
		V144), V145), V146), V147), V148), V149), V150), V151),							\
		V152), V153), V154), V155), V156), V157), V158), V159),							\
		V160), V161), V162), V163), V164), V165), V166), V167),							\
		V168), V169), V170), V171), V172), V173), V174), V175),							\
		V176), V177), V178), V179), V180), V181), V182), V183),							\
		V184), V185), V186), V187), V188), V189), V190), V191),							\
															\
		V192), V193), V194), V195), V196), V197), V198), V199),							\
		V200), V201), V202), V203), V204), V205), V206), V207),							\
		V208), V209), V210), V211), V212), V213), V214), V215),							\
		V216), V217), V218), V219), V220), V221), V222), V223),							\
		V224), V225), V226), V227), V228), V229), V230), V231),							\
		V232), V233), V234), V235), V236), V237), V238), V239),							\
		V240), V241), V242), V243), V244), V245), V246), V247),							\
		V248), V249), V250), V251), V252), V253), V254), V255)

	#define _upper_512_op_Vs											\
															\
		V256), V257), V258), V259), V260), V261), V262), V263),							\
		V264), V265), V266), V267), V268), V269), V270), V271),							\
		V272), V273), V274), V275), V276), V277), V278), V279),							\
		V280), V281), V282), V283), V284), V285), V286), V287),							\
		V288), V289), V290), V291), V292), V293), V294), V295),							\
		V296), V297), V298), V299), V300), V301), V302), V303),							\
		V304), V305), V306), V307), V308), V309), V310), V311),							\
		V312), V313), V314), V315), V316), V317), V318), V319),							\
															\
		V320), V321), V322), V323), V324), V325), V326), V327),							\
		V328), V329), V330), V331), V332), V333), V334), V335),							\
		V336), V337), V338), V339), V340), V341), V342), V343),							\
		V344), V345), V346), V347), V348), V349), V350), V351),							\
		V352), V353), V354), V355), V356), V357), V358), V359),							\
		V360), V361), V362), V363), V364), V365), V366), V367),							\
		V368), V369), V370), V371), V372), V373), V374), V375),							\
		V376), V377), V378), V379), V380), V381), V382), V383),							\
															\
		V384), V385), V386), V387), V388), V389), V390), V391),							\
		V392), V393), V394), V395), V396), V397), V398), V399),							\
		V400), V401), V402), V403), V404), V405), V406), V407),							\
		V408), V409), V410), V411), V412), V413), V414), V415),							\
		V416), V417), V418), V419), V420), V421), V422), V423),							\
		V424), V425), V426), V427), V428), V429), V430), V431),							\
		V432), V433), V434), V435), V436), V437), V438), V439),							\
		V440), V441), V442), V443), V444), V445), V446), V447),							\
															\
		V448), V449), V450), V451), V452), V453), V454), V455),							\
		V456), V457), V458), V459), V460), V461), V462), V463),							\
		V464), V465), V466), V467), V468), V469), V470), V471),							\
		V472), V473), V474), V475), V476), V477), V478), V479),							\
		V480), V481), V482), V483), V484), V485), V486), V487),							\
		V488), V489), V490), V491), V492), V493), V494), V495),							\
		V496), V497), V498), V499), V500), V501), V502), V503),							\
		V504), V505), V506), V507), V508), V509), V510), V511)

/***********************************************************************************************************************/

// upper action values:

	#define _upper_1_act_Vs												\
															\
		  V0>

	#define _upper_2_act_Vs												\
															\
		  V1>

	#define _upper_4_act_Vs												\
															\
		  V2>,   V3>

	#define _upper_8_act_Vs												\
															\
		  V4>,   V5>,   V6>,   V7>

	#define _upper_16_act_Vs											\
															\
		  V8>,   V9>,  V10>,  V11>,  V12>,  V13>,  V14>,  V15>

	#define _upper_32_act_Vs											\
															\
		 V16>,  V17>,  V18>,  V19>,  V20>,  V21>,  V22>,  V23>,							\
		 V24>,  V25>,  V26>,  V27>,  V28>,  V29>,  V30>,  V31>

	#define _upper_64_act_Vs											\
															\
		 V32>,  V33>,  V34>,  V35>,  V36>,  V37>,  V38>,  V39>,							\
		 V40>,  V41>,  V42>,  V43>,  V44>,  V45>,  V46>,  V47>,							\
		 V48>,  V49>,  V50>,  V51>,  V52>,  V53>,  V54>,  V55>,							\
		 V56>,  V57>,  V58>,  V59>,  V60>,  V61>,  V62>,  V63>

	#define _upper_128_act_Vs											\
															\
		 V64>,  V65>,  V66>,  V67>,  V68>,  V69>,  V70>,  V71>,							\
		 V72>,  V73>,  V74>,  V75>,  V76>,  V77>,  V78>,  V79>,							\
		 V80>,  V81>,  V82>,  V83>,  V84>,  V85>,  V86>,  V87>,							\
		 V88>,  V89>,  V90>,  V91>,  V92>,  V93>,  V94>,  V95>,							\
		 V96>,  V97>,  V98>,  V99>, V100>, V101>, V102>, V103>,							\
		V104>, V105>, V106>, V107>, V108>, V109>, V110>, V111>,							\
		V112>, V113>, V114>, V115>, V116>, V117>, V118>, V119>,							\
		V120>, V121>, V122>, V123>, V124>, V125>, V126>, V127>

	#define _upper_256_act_Vs											\
															\
		V128>, V129>, V130>, V131>, V132>, V133>, V134>, V135>,							\
		V136>, V137>, V138>, V139>, V140>, V141>, V142>, V143>,							\
		V144>, V145>, V146>, V147>, V148>, V149>, V150>, V151>,							\
		V152>, V153>, V154>, V155>, V156>, V157>, V158>, V159>,							\
		V160>, V161>, V162>, V163>, V164>, V165>, V166>, V167>,							\
		V168>, V169>, V170>, V171>, V172>, V173>, V174>, V175>,							\
		V176>, V177>, V178>, V179>, V180>, V181>, V182>, V183>,							\
		V184>, V185>, V186>, V187>, V188>, V189>, V190>, V191>,							\
															\
		V192>, V193>, V194>, V195>, V196>, V197>, V198>, V199>,							\
		V200>, V201>, V202>, V203>, V204>, V205>, V206>, V207>,							\
		V208>, V209>, V210>, V211>, V212>, V213>, V214>, V215>,							\
		V216>, V217>, V218>, V219>, V220>, V221>, V222>, V223>,							\
		V224>, V225>, V226>, V227>, V228>, V229>, V230>, V231>,							\
		V232>, V233>, V234>, V235>, V236>, V237>, V238>, V239>,							\
		V240>, V241>, V242>, V243>, V244>, V245>, V246>, V247>,							\
		V248>, V249>, V250>, V251>, V252>, V253>, V254>, V255>

	#define _upper_512_act_Vs											\
															\
		V256>, V257>, V258>, V259>, V260>, V261>, V262>, V263>,							\
		V264>, V265>, V266>, V267>, V268>, V269>, V270>, V271>,							\
		V272>, V273>, V274>, V275>, V276>, V277>, V278>, V279>,							\
		V280>, V281>, V282>, V283>, V284>, V285>, V286>, V287>,							\
		V288>, V289>, V290>, V291>, V292>, V293>, V294>, V295>,							\
		V296>, V297>, V298>, V299>, V300>, V301>, V302>, V303>,							\
		V304>, V305>, V306>, V307>, V308>, V309>, V310>, V311>,							\
		V312>, V313>, V314>, V315>, V316>, V317>, V318>, V319>,							\
															\
		V320>, V321>, V322>, V323>, V324>, V325>, V326>, V327>,							\
		V328>, V329>, V330>, V331>, V332>, V333>, V334>, V335>,							\
		V336>, V337>, V338>, V339>, V340>, V341>, V342>, V343>,							\
		V344>, V345>, V346>, V347>, V348>, V349>, V350>, V351>,							\
		V352>, V353>, V354>, V355>, V356>, V357>, V358>, V359>,							\
		V360>, V361>, V362>, V363>, V364>, V365>, V366>, V367>,							\
		V368>, V369>, V370>, V371>, V372>, V373>, V374>, V375>,							\
		V376>, V377>, V378>, V379>, V380>, V381>, V382>, V383>,							\
															\
		V384>, V385>, V386>, V387>, V388>, V389>, V390>, V391>,							\
		V392>, V393>, V394>, V395>, V396>, V397>, V398>, V399>,							\
		V400>, V401>, V402>, V403>, V404>, V405>, V406>, V407>,							\
		V408>, V409>, V410>, V411>, V412>, V413>, V414>, V415>,							\
		V416>, V417>, V418>, V419>, V420>, V421>, V422>, V423>,							\
		V424>, V425>, V426>, V427>, V428>, V429>, V430>, V431>,							\
		V432>, V433>, V434>, V435>, V436>, V437>, V438>, V439>,							\
		V440>, V441>, V442>, V443>, V444>, V445>, V446>, V447>,							\
															\
		V448>, V449>, V450>, V451>, V452>, V453>, V454>, V455>,							\
		V456>, V457>, V458>, V459>, V460>, V461>, V462>, V463>,							\
		V464>, V465>, V466>, V467>, V468>, V469>, V470>, V471>,							\
		V472>, V473>, V474>, V475>, V476>, V477>, V478>, V479>,							\
		V480>, V481>, V482>, V483>, V484>, V485>, V486>, V487>,							\
		V488>, V489>, V490>, V491>, V492>, V493>, V494>, V495>,							\
		V496>, V497>, V498>, V499>, V500>, V501>, V502>, V503>,							\
		V504>, V505>, V506>, V507>, V508>, V509>, V510>, V511>

/***********************************************************************************************************************/

// upper array values:

	#define _upper_1_arr_Vs												\
															\
		  arr[i+0]

	#define _upper_2_arr_Vs												\
															\
		  arr[i+1]

	#define _upper_4_arr_Vs												\
															\
		  arr[i+2],   arr[i+3]

	#define _upper_8_arr_Vs												\
															\
		  arr[i+4],   arr[i+5],   arr[i+6],   arr[i+7]

	#define _upper_16_arr_Vs											\
															\
		  arr[i+8],   arr[i+9],  arr[i+10],  arr[i+11],  arr[i+12],  arr[i+13],  arr[i+14],  arr[i+15]

	#define _upper_32_arr_Vs											\
															\
		 arr[i+16],  arr[i+17],  arr[i+18],  arr[i+19],  arr[i+20],  arr[i+21],  arr[i+22],  arr[i+23],		\
		 arr[i+24],  arr[i+25],  arr[i+26],  arr[i+27],  arr[i+28],  arr[i+29],  arr[i+30],  arr[i+31]

	#define _upper_64_arr_Vs											\
															\
		 arr[i+32],  arr[i+33],  arr[i+34],  arr[i+35],  arr[i+36],  arr[i+37],  arr[i+38],  arr[i+39],		\
		 arr[i+40],  arr[i+41],  arr[i+42],  arr[i+43],  arr[i+44],  arr[i+45],  arr[i+46],  arr[i+47],		\
		 arr[i+48],  arr[i+49],  arr[i+50],  arr[i+51],  arr[i+52],  arr[i+53],  arr[i+54],  arr[i+55],		\
		 arr[i+56],  arr[i+57],  arr[i+58],  arr[i+59],  arr[i+60],  arr[i+61],  arr[i+62],  arr[i+63]

	#define _upper_128_arr_Vs											\
															\
		 arr[i+64],  arr[i+65],  arr[i+66],  arr[i+67],  arr[i+68],  arr[i+69],  arr[i+70],  arr[i+71],		\
		 arr[i+72],  arr[i+73],  arr[i+74],  arr[i+75],  arr[i+76],  arr[i+77],  arr[i+78],  arr[i+79],		\
		 arr[i+80],  arr[i+81],  arr[i+82],  arr[i+83],  arr[i+84],  arr[i+85],  arr[i+86],  arr[i+87],		\
		 arr[i+88],  arr[i+89],  arr[i+90],  arr[i+91],  arr[i+92],  arr[i+93],  arr[i+94],  arr[i+95],		\
		 arr[i+96],  arr[i+97],  arr[i+98],  arr[i+99], arr[i+100], arr[i+101], arr[i+102], arr[i+103],		\
		arr[i+104], arr[i+105], arr[i+106], arr[i+107], arr[i+108], arr[i+109], arr[i+110], arr[i+111],		\
		arr[i+112], arr[i+113], arr[i+114], arr[i+115], arr[i+116], arr[i+117], arr[i+118], arr[i+119],		\
		arr[i+120], arr[i+121], arr[i+122], arr[i+123], arr[i+124], arr[i+125], arr[i+126], arr[i+127]

	#define _upper_256_arr_Vs											\
															\
		arr[i+128], arr[i+129], arr[i+130], arr[i+131], arr[i+132], arr[i+133], arr[i+134], arr[i+135],		\
		arr[i+136], arr[i+137], arr[i+138], arr[i+139], arr[i+140], arr[i+141], arr[i+142], arr[i+143],		\
		arr[i+144], arr[i+145], arr[i+146], arr[i+147], arr[i+148], arr[i+149], arr[i+150], arr[i+151],		\
		arr[i+152], arr[i+153], arr[i+154], arr[i+155], arr[i+156], arr[i+157], arr[i+158], arr[i+159],		\
		arr[i+160], arr[i+161], arr[i+162], arr[i+163], arr[i+164], arr[i+165], arr[i+166], arr[i+167],		\
		arr[i+168], arr[i+169], arr[i+170], arr[i+171], arr[i+172], arr[i+173], arr[i+174], arr[i+175],		\
		arr[i+176], arr[i+177], arr[i+178], arr[i+179], arr[i+180], arr[i+181], arr[i+182], arr[i+183],		\
		arr[i+184], arr[i+185], arr[i+186], arr[i+187], arr[i+188], arr[i+189], arr[i+190], arr[i+191],		\
															\
		arr[i+192], arr[i+193], arr[i+194], arr[i+195], arr[i+196], arr[i+197], arr[i+198], arr[i+199],		\
		arr[i+200], arr[i+201], arr[i+202], arr[i+203], arr[i+204], arr[i+205], arr[i+206], arr[i+207],		\
		arr[i+208], arr[i+209], arr[i+210], arr[i+211], arr[i+212], arr[i+213], arr[i+214], arr[i+215],		\
		arr[i+216], arr[i+217], arr[i+218], arr[i+219], arr[i+220], arr[i+221], arr[i+222], arr[i+223],		\
		arr[i+224], arr[i+225], arr[i+226], arr[i+227], arr[i+228], arr[i+229], arr[i+230], arr[i+231],		\
		arr[i+232], arr[i+233], arr[i+234], arr[i+235], arr[i+236], arr[i+237], arr[i+238], arr[i+239],		\
		arr[i+240], arr[i+241], arr[i+242], arr[i+243], arr[i+244], arr[i+245], arr[i+246], arr[i+247],		\
		arr[i+248], arr[i+249], arr[i+250], arr[i+251], arr[i+252], arr[i+253], arr[i+254], arr[i+255]

	#define _upper_512_arr_Vs											\
															\
		arr[i+256], arr[i+257], arr[i+258], arr[i+259], arr[i+260], arr[i+261], arr[i+262], arr[i+263],		\
		arr[i+264], arr[i+265], arr[i+266], arr[i+267], arr[i+268], arr[i+269], arr[i+270], arr[i+271],		\
		arr[i+272], arr[i+273], arr[i+274], arr[i+275], arr[i+276], arr[i+277], arr[i+278], arr[i+279],		\
		arr[i+280], arr[i+281], arr[i+282], arr[i+283], arr[i+284], arr[i+285], arr[i+286], arr[i+287],		\
		arr[i+288], arr[i+289], arr[i+290], arr[i+291], arr[i+292], arr[i+293], arr[i+294], arr[i+295],		\
		arr[i+296], arr[i+297], arr[i+298], arr[i+299], arr[i+300], arr[i+301], arr[i+302], arr[i+303],		\
		arr[i+304], arr[i+305], arr[i+306], arr[i+307], arr[i+308], arr[i+309], arr[i+310], arr[i+311],		\
		arr[i+312], arr[i+313], arr[i+314], arr[i+315], arr[i+316], arr[i+317], arr[i+318], arr[i+319],		\
															\
		arr[i+320], arr[i+321], arr[i+322], arr[i+323], arr[i+324], arr[i+325], arr[i+326], arr[i+327],		\
		arr[i+328], arr[i+329], arr[i+330], arr[i+331], arr[i+332], arr[i+333], arr[i+334], arr[i+335],		\
		arr[i+336], arr[i+337], arr[i+338], arr[i+339], arr[i+340], arr[i+341], arr[i+342], arr[i+343],		\
		arr[i+344], arr[i+345], arr[i+346], arr[i+347], arr[i+348], arr[i+349], arr[i+350], arr[i+351],		\
		arr[i+352], arr[i+353], arr[i+354], arr[i+355], arr[i+356], arr[i+357], arr[i+358], arr[i+359],		\
		arr[i+360], arr[i+361], arr[i+362], arr[i+363], arr[i+364], arr[i+365], arr[i+366], arr[i+367],		\
		arr[i+368], arr[i+369], arr[i+370], arr[i+371], arr[i+372], arr[i+373], arr[i+374], arr[i+375],		\
		arr[i+376], arr[i+377], arr[i+378], arr[i+379], arr[i+380], arr[i+381], arr[i+382], arr[i+383],		\
															\
		arr[i+384], arr[i+385], arr[i+386], arr[i+387], arr[i+388], arr[i+389], arr[i+390], arr[i+391],		\
		arr[i+392], arr[i+393], arr[i+394], arr[i+395], arr[i+396], arr[i+397], arr[i+398], arr[i+399],		\
		arr[i+400], arr[i+401], arr[i+402], arr[i+403], arr[i+404], arr[i+405], arr[i+406], arr[i+407],		\
		arr[i+408], arr[i+409], arr[i+410], arr[i+411], arr[i+412], arr[i+413], arr[i+414], arr[i+415],		\
		arr[i+416], arr[i+417], arr[i+418], arr[i+419], arr[i+420], arr[i+421], arr[i+422], arr[i+423],		\
		arr[i+424], arr[i+425], arr[i+426], arr[i+427], arr[i+428], arr[i+429], arr[i+430], arr[i+431],		\
		arr[i+432], arr[i+433], arr[i+434], arr[i+435], arr[i+436], arr[i+437], arr[i+438], arr[i+439],		\
		arr[i+440], arr[i+441], arr[i+442], arr[i+443], arr[i+444], arr[i+445], arr[i+446], arr[i+447],		\
															\
		arr[i+448], arr[i+449], arr[i+450], arr[i+451], arr[i+452], arr[i+453], arr[i+454], arr[i+455],		\
		arr[i+456], arr[i+457], arr[i+458], arr[i+459], arr[i+460], arr[i+461], arr[i+462], arr[i+463],		\
		arr[i+464], arr[i+465], arr[i+466], arr[i+467], arr[i+468], arr[i+469], arr[i+470], arr[i+471],		\
		arr[i+472], arr[i+473], arr[i+474], arr[i+475], arr[i+476], arr[i+477], arr[i+478], arr[i+479],		\
		arr[i+480], arr[i+481], arr[i+482], arr[i+483], arr[i+484], arr[i+485], arr[i+486], arr[i+487],		\
		arr[i+488], arr[i+489], arr[i+490], arr[i+491], arr[i+492], arr[i+493], arr[i+494], arr[i+495],		\
		arr[i+496], arr[i+497], arr[i+498], arr[i+499], arr[i+500], arr[i+501], arr[i+502], arr[i+503],		\
		arr[i+504], arr[i+505], arr[i+506], arr[i+507], arr[i+508], arr[i+509], arr[i+510], arr[i+511]

/***********************************************************************************************************************/

// block auto:

	#define _2_0_auto_Vs												\
															\
		_upper_1_auto_Vs

	#define _2_1_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs

	#define _2_2_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs

	#define _2_3_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs

	#define _2_4_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs

	#define _2_5_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs,		\
		_upper_32_auto_Vs

	#define _2_6_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs,		\
		_upper_32_auto_Vs, _upper_64_auto_Vs

	#define _2_7_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs,		\
		_upper_32_auto_Vs, _upper_64_auto_Vs, _upper_128_auto_Vs

	#define _2_8_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs,		\
		_upper_32_auto_Vs, _upper_64_auto_Vs, _upper_128_auto_Vs, _upper_256_auto_Vs

	#define _2_9_auto_Vs												\
															\
		_upper_1_auto_Vs, _upper_2_auto_Vs, _upper_4_auto_Vs, _upper_8_auto_Vs, _upper_16_auto_Vs,		\
		_upper_32_auto_Vs, _upper_64_auto_Vs, _upper_128_auto_Vs, _upper_256_auto_Vs, _upper_512_auto_Vs

/***********************************************************************************************************************/

// block values:

	#define _2_0_Vs													\
															\
		_upper_1_Vs

	#define _2_1_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs

	#define _2_2_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs

	#define _2_3_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs

	#define _2_4_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs

	#define _2_5_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs,					\
		_upper_32_Vs

	#define _2_6_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs,					\
		_upper_32_Vs, _upper_64_Vs

	#define _2_7_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs,					\
		_upper_32_Vs, _upper_64_Vs, _upper_128_Vs

	#define _2_8_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs,					\
		_upper_32_Vs, _upper_64_Vs, _upper_128_Vs, _upper_256_Vs

	#define _2_9_Vs													\
															\
		_upper_1_Vs, _upper_2_Vs, _upper_4_Vs, _upper_8_Vs, _upper_16_Vs,					\
		_upper_32_Vs, _upper_64_Vs, _upper_128_Vs, _upper_256_Vs, _upper_512_Vs

/***********************************************************************************************************************/

// block operations:

	#define _2_0_ops												\
															\
		op(

	#define _2_1_ops												\
															\
		_2_0_ops _2_0_ops

	#define _2_2_ops												\
															\
		_2_1_ops _2_1_ops

	#define _2_3_ops												\
															\
		_2_2_ops _2_2_ops

	#define _2_4_ops												\
															\
		_2_3_ops _2_3_ops

	#define _2_5_ops												\
															\
		_2_4_ops _2_4_ops

	#define _2_6_ops												\
															\
		_2_5_ops _2_5_ops

	#define _2_7_ops												\
															\
		_2_6_ops _2_6_ops

	#define _2_8_ops												\
															\
		_2_7_ops _2_7_ops

	#define _2_9_ops												\
															\
		_2_8_ops _2_8_ops

/***********************************************************************************************************************/

// block actions:

	#define _2_0_acts												\
															\
		act::template result<

	#define _2_1_acts												\
															\
		_2_0_acts _2_0_acts

	#define _2_2_acts												\
															\
		_2_1_acts _2_1_acts

	#define _2_3_acts												\
															\
		_2_2_acts _2_2_acts

	#define _2_4_acts												\
															\
		_2_3_acts _2_3_acts

	#define _2_5_acts												\
															\
		_2_4_acts _2_4_acts

	#define _2_6_acts												\
															\
		_2_5_acts _2_5_acts

	#define _2_7_acts												\
															\
		_2_6_acts _2_6_acts

	#define _2_8_acts												\
															\
		_2_7_acts _2_7_acts

	#define _2_9_acts												\
															\
		_2_8_acts _2_8_acts

/***********************************************************************************************************************/

// block operation values:

	#define _2_0_op_Vs												\
															\
		_upper_1_op_Vs

	#define _2_1_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs

	#define _2_2_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs

	#define _2_3_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs

	#define _2_4_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs

	#define _2_5_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs,			\
		_upper_32_op_Vs

	#define _2_6_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs,			\
		_upper_32_op_Vs, _upper_64_op_Vs

	#define _2_7_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs,			\
		_upper_32_op_Vs, _upper_64_op_Vs, _upper_128_op_Vs

	#define _2_8_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs,			\
		_upper_32_op_Vs, _upper_64_op_Vs, _upper_128_op_Vs, _upper_256_op_Vs

	#define _2_9_op_Vs												\
															\
		_upper_1_op_Vs, _upper_2_op_Vs, _upper_4_op_Vs, _upper_8_op_Vs, _upper_16_op_Vs,			\
		_upper_32_op_Vs, _upper_64_op_Vs, _upper_128_op_Vs, _upper_256_op_Vs, _upper_512_op_Vs

/***********************************************************************************************************************/

// block action values:

	#define _2_0_act_Vs												\
															\
		_upper_1_act_Vs

	#define _2_1_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs

	#define _2_2_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs

	#define _2_3_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs

	#define _2_4_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs

	#define _2_5_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs,			\
		_upper_32_act_Vs

	#define _2_6_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs,			\
		_upper_32_act_Vs, _upper_64_act_Vs

	#define _2_7_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs,			\
		_upper_32_act_Vs, _upper_64_act_Vs, _upper_128_act_Vs

	#define _2_8_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs,			\
		_upper_32_act_Vs, _upper_64_act_Vs, _upper_128_act_Vs, _upper_256_act_Vs

	#define _2_9_act_Vs												\
															\
		_upper_1_act_Vs, _upper_2_act_Vs, _upper_4_act_Vs, _upper_8_act_Vs, _upper_16_act_Vs,			\
		_upper_32_act_Vs, _upper_64_act_Vs, _upper_128_act_Vs, _upper_256_act_Vs, _upper_512_act_Vs

/***********************************************************************************************************************/

// block array values:

	#define _2_0_arr_Vs												\
															\
		_upper_1_arr_Vs

	#define _2_1_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs

	#define _2_2_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs

	#define _2_3_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs

	#define _2_4_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs

	#define _2_5_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs,			\
		_upper_32_arr_Vs

	#define _2_6_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs,			\
		_upper_32_arr_Vs, _upper_64_arr_Vs

	#define _2_7_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs,			\
		_upper_32_arr_Vs, _upper_64_arr_Vs, _upper_128_arr_Vs

	#define _2_8_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs,			\
		_upper_32_arr_Vs, _upper_64_arr_Vs, _upper_128_arr_Vs, _upper_256_arr_Vs

	#define _2_9_arr_Vs												\
															\
		_upper_1_arr_Vs, _upper_2_arr_Vs, _upper_4_arr_Vs, _upper_8_arr_Vs, _upper_16_arr_Vs,			\
		_upper_32_arr_Vs, _upper_64_arr_Vs, _upper_128_arr_Vs, _upper_256_arr_Vs, _upper_512_arr_Vs

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// fast auto:

	#define _0_fast_auto_Vs

		// blank space.

	#define _1_fast_auto_Vs												\
															\
		auto V0

	#define _2_fast_auto_Vs												\
															\
		auto V0, auto V1

	#define _3_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2

	#define _4_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3

	#define _5_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4

	#define _6_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5

	#define _7_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6

	#define _8_fast_auto_Vs												\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7

/***********************************************************************************************************************/

// fast values:

	#define _0_fast_Vs

		// blank space.

	#define _1_fast_Vs												\
															\
		V0

	#define _2_fast_Vs												\
															\
		V0, V1

	#define _3_fast_Vs												\
															\
		V0, V1, V2

	#define _4_fast_Vs												\
															\
		V0, V1, V2, V3

	#define _5_fast_Vs												\
															\
		V0, V1, V2, V3, V4

	#define _6_fast_Vs												\
															\
		V0, V1, V2, V3, V4, V5

	#define _7_fast_Vs												\
															\
		V0, V1, V2, V3, V4, V5, V6

	#define _8_fast_Vs												\
															\
		V0, V1, V2, V3, V4, V5, V6, V7

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

