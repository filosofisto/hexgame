//
// Created by eduardo on 11/4/17.
//

#include "HexGraph.h"

HexGraph::HexGraph()
{
    build_graph();
}

HexGraph::~HexGraph()
{
    if (graph != nullptr)
        delete graph;
}

void HexGraph::build_graph()
{
    graph = new Graph(121);

    //------------------------------------------
    //Line 0
    //------------------------------------------
    // (0, *)
    graph->add_edge(0,1,0);
    graph->add_edge(0,11,0);

    //1
    graph->add_edge(1,2,0);
    graph->add_edge(1,11,0);
    graph->add_edge(1,12,0);

    //2
    graph->add_edge(2,3,0);
    graph->add_edge(2,12,0);
    graph->add_edge(2,13,0);

    //3
    graph->add_edge(3,4,0);
    graph->add_edge(3,13,0);
    graph->add_edge(3,14,0);

    //4
    graph->add_edge(4,5,0);
    graph->add_edge(4,14,0);
    graph->add_edge(4,15,0);

    //9
    graph->add_edge(9,10,0);
    graph->add_edge(9,19,0);
    graph->add_edge(9,20,0);

    //10
    graph->add_edge(10,20,0);
    graph->add_edge(10,21,0);

    //------------------------------------------
    //Line 1
    //------------------------------------------
    //11
    graph->add_edge(11, 12, 0);
    graph->add_edge(11, 22, 0);
    //12
    graph->add_edge(12, 13, 0);
    graph->add_edge(12, 22, 0);
    graph->add_edge(12, 23, 0);
    //13
    graph->add_edge(13, 14, 0);
    graph->add_edge(13, 23, 0);
    graph->add_edge(13, 24, 0);
    //14
    graph->add_edge(14, 15, 0);
    graph->add_edge(14, 24, 0);
    graph->add_edge(14, 25, 0);
    //15
    graph->add_edge(15, 16, 0);
    graph->add_edge(15, 25, 0);
    graph->add_edge(15, 26, 0);
    //16
    graph->add_edge(16, 17, 0);
    graph->add_edge(16, 26, 0);
    graph->add_edge(16, 27, 0);
    //17
    graph->add_edge(17, 18, 0);
    graph->add_edge(17, 27, 0);
    graph->add_edge(17, 28, 0);
    //18
    graph->add_edge(18, 19, 0);
    graph->add_edge(18, 28, 0);
    graph->add_edge(18, 29, 0);
    //19
    graph->add_edge(19, 20, 0);
    graph->add_edge(19, 29, 0);
    graph->add_edge(19, 30, 0);
    //20
    graph->add_edge(20, 21, 0);
    graph->add_edge(20, 30, 0);
    graph->add_edge(20, 31, 0);
    //21
    graph->add_edge(21, 31, 0);
    graph->add_edge(21, 32, 0);
    //------------------------------------------
    //Line 2
    //------------------------------------------
    //22
    graph->add_edge(22, 23, 0);
    graph->add_edge(22, 33, 0);
    //23
    graph->add_edge(23, 24, 0);
    graph->add_edge(23, 33, 0);
    graph->add_edge(23, 34, 0);
    //24
    graph->add_edge(24, 25, 0);
    graph->add_edge(24, 34, 0);
    graph->add_edge(24, 35, 0);
    //25
    graph->add_edge(25, 26, 0);
    graph->add_edge(25, 35, 0);
    graph->add_edge(25, 36, 0);
    //26
    graph->add_edge(26, 27, 0);
    graph->add_edge(26, 36, 0);
    graph->add_edge(26, 37, 0);
    //27
    graph->add_edge(27, 28, 0);
    graph->add_edge(27, 37, 0);
    graph->add_edge(27, 38, 0);
    //28
    graph->add_edge(28, 29, 0);
    graph->add_edge(28, 38, 0);
    graph->add_edge(28, 39, 0);
    //29
    graph->add_edge(29, 30, 0);
    graph->add_edge(29, 39, 0);
    graph->add_edge(29, 40, 0);
    //30
    graph->add_edge(30, 31, 0);
    graph->add_edge(30, 40, 0);
    graph->add_edge(30, 41, 0);
    //31
    graph->add_edge(31, 32, 0);
    graph->add_edge(31, 41, 0);
    graph->add_edge(31, 42, 0);
    //32
    graph->add_edge(32, 43, 0);
    graph->add_edge(32, 44, 0);
    //------------------------------------------
    //Line 3
    //------------------------------------------
    //33
    graph->add_edge(33, 34, 0);
    graph->add_edge(33, 44, 0);
    //34
    graph->add_edge(34, 35, 0);
    graph->add_edge(34, 44, 0);
    graph->add_edge(34, 45, 0);
    //35
    graph->add_edge(35, 36, 0);
    graph->add_edge(35, 45, 0);
    graph->add_edge(35, 46, 0);
    //36
    graph->add_edge(36, 37, 0);
    graph->add_edge(36, 46, 0);
    graph->add_edge(36, 47, 0);
    //37
    graph->add_edge(37, 38, 0);
    graph->add_edge(37, 47, 0);
    graph->add_edge(37, 48, 0);
    //38
    graph->add_edge(38, 39, 0);
    graph->add_edge(38, 48, 0);
    graph->add_edge(38, 49, 0);
    //39
    graph->add_edge(39, 40, 0);
    graph->add_edge(39, 49, 0);
    graph->add_edge(39, 50, 0);
    //40
    graph->add_edge(40, 41, 0);
    graph->add_edge(40, 50, 0);
    graph->add_edge(40, 51, 0);
    //41
    graph->add_edge(41, 42, 0);
    graph->add_edge(41, 51, 0);
    graph->add_edge(41, 52, 0);
    //42
    graph->add_edge(42, 43, 0);
    graph->add_edge(42, 52, 0);
    graph->add_edge(42, 53, 0);
    //43
    graph->add_edge(43, 53, 0);
    graph->add_edge(43, 54, 0);
    //------------------------------------------
    //Line 4
    //------------------------------------------
    //44
    graph->add_edge(44, 45, 0);
    graph->add_edge(44, 55, 0);
    //45
    graph->add_edge(45, 46, 0);
    graph->add_edge(45, 55, 0);
    graph->add_edge(45, 56, 0);
    //46
    graph->add_edge(46, 47, 0);
    graph->add_edge(46, 56, 0);
    graph->add_edge(46, 57, 0);
    //47
    graph->add_edge(47, 48, 0);
    graph->add_edge(47, 57, 0);
    graph->add_edge(47, 58, 0);
    //48
    graph->add_edge(48, 49, 0);
    graph->add_edge(48, 58, 0);
    graph->add_edge(48, 59, 0);
    //49
    graph->add_edge(49, 50, 0);
    graph->add_edge(49, 59, 0);
    graph->add_edge(49, 60, 0);
    //50
    graph->add_edge(50, 51, 0);
    graph->add_edge(50, 60, 0);
    graph->add_edge(50, 61, 0);
    //51
    graph->add_edge(51, 52, 0);
    graph->add_edge(51, 61, 0);
    graph->add_edge(51, 62, 0);
    //52
    graph->add_edge(52, 53, 0);
    graph->add_edge(52, 62, 0);
    graph->add_edge(52, 63, 0);
    //53
    graph->add_edge(53, 54, 0);
    graph->add_edge(53, 63, 0);
    graph->add_edge(53, 64, 0);
    //54
    graph->add_edge(54, 64, 0);
    graph->add_edge(54, 65, 0);
    //------------------------------------------
    //Line 5
    //------------------------------------------
    //55
    graph->add_edge(55, 56, 0);
    graph->add_edge(55, 66, 0);
    //56
    graph->add_edge(56, 57, 0);
    graph->add_edge(56, 66, 0);
    graph->add_edge(56, 67, 0);
    //57
    graph->add_edge(57, 58, 0);
    graph->add_edge(57, 67, 0);
    graph->add_edge(57, 68, 0);
    //58
    graph->add_edge(58, 59, 0);
    graph->add_edge(58, 68, 0);
    graph->add_edge(58, 69, 0);
    //59
    graph->add_edge(59, 60, 0);
    graph->add_edge(59, 69, 0);
    graph->add_edge(59, 70, 0);
    //60
    graph->add_edge(60, 61, 0);
    graph->add_edge(60, 70, 0);
    graph->add_edge(60, 71, 0);
    //61
    graph->add_edge(61, 62, 0);
    graph->add_edge(61, 71, 0);
    graph->add_edge(61, 72, 0);
    //62
    graph->add_edge(62, 63, 0);
    graph->add_edge(62, 72, 0);
    graph->add_edge(62, 73, 0);
    //63
    graph->add_edge(63, 64, 0);
    graph->add_edge(63, 73, 0);
    graph->add_edge(63, 74, 0);
    //64
    graph->add_edge(64, 65, 0);
    graph->add_edge(64, 74, 0);
    graph->add_edge(64, 75, 0);
    //65
    graph->add_edge(65, 75, 0);
    graph->add_edge(65, 76, 0);
    //------------------------------------------
    //Line 6
    //------------------------------------------
    //66
    graph->add_edge(66, 67, 0);
    graph->add_edge(66, 77, 0);
    //67
    graph->add_edge(67, 68, 0);
    graph->add_edge(67, 77, 0);
    graph->add_edge(67, 78, 0);
    //68
    graph->add_edge(68, 69, 0);
    graph->add_edge(68, 78, 0);
    graph->add_edge(68, 79, 0);
    //69
    graph->add_edge(69, 70, 0);
    graph->add_edge(69, 79, 0);
    graph->add_edge(69, 80, 0);
    //70
    graph->add_edge(70, 71, 0);
    graph->add_edge(70, 80, 0);
    graph->add_edge(70, 81, 0);
    //71
    graph->add_edge(71, 72, 0);
    graph->add_edge(71, 81, 0);
    graph->add_edge(71, 82, 0);
    //72
    graph->add_edge(72, 73, 0);
    graph->add_edge(72, 82, 0);
    graph->add_edge(72, 83, 0);
    //73
    graph->add_edge(73, 74, 0);
    graph->add_edge(73, 83, 0);
    graph->add_edge(73, 84, 0);
    //74
    graph->add_edge(74, 75, 0);
    graph->add_edge(74, 84, 0);
    graph->add_edge(74, 85, 0);
    //75
    graph->add_edge(75, 76, 0);
    graph->add_edge(75, 85, 0);
    graph->add_edge(75, 86, 0);
    //76
    graph->add_edge(76, 86, 0);
    graph->add_edge(76, 87, 0);
    //------------------------------------------
    //Line 7
    //------------------------------------------
    //77
    graph->add_edge(77, 78, 0);
    graph->add_edge(77, 88, 0);
    //78
    graph->add_edge(78, 79, 0);
    graph->add_edge(78, 88, 0);
    graph->add_edge(78, 89, 0);
    //79
    graph->add_edge(79, 80, 0);
    graph->add_edge(79, 89, 0);
    graph->add_edge(79, 90, 0);
    //80
    graph->add_edge(80, 81, 0);
    graph->add_edge(80, 90, 0);
    graph->add_edge(80, 91, 0);
    //81
    graph->add_edge(81, 82, 0);
    graph->add_edge(81, 91, 0);
    graph->add_edge(81, 92, 0);
    //82
    graph->add_edge(82, 83, 0);
    graph->add_edge(82, 92, 0);
    graph->add_edge(82, 93, 0);
    //83
    graph->add_edge(83, 84, 0);
    graph->add_edge(83, 93, 0);
    graph->add_edge(83, 94, 0);
    //84
    graph->add_edge(84, 85, 0);
    graph->add_edge(84, 94, 0);
    graph->add_edge(84, 95, 0);
    //85
    graph->add_edge(85, 86, 0);
    graph->add_edge(85, 95, 0);
    graph->add_edge(85, 96, 0);
    //86
    graph->add_edge(86, 87, 0);
    graph->add_edge(86, 96, 0);
    graph->add_edge(86, 97, 0);
    //87
    graph->add_edge(87, 97, 0);
    graph->add_edge(87, 98, 0);
    //------------------------------------------
    //Line 8
    //------------------------------------------
    //88
    graph->add_edge(88, 89, 0);
    graph->add_edge(88, 99, 0);
    //89
    graph->add_edge(89, 90, 0);
    graph->add_edge(89, 99, 0);
    graph->add_edge(89, 100, 0);
    //90
    graph->add_edge(90, 91, 0);
    graph->add_edge(90, 100, 0);
    graph->add_edge(90, 101, 0);
    //91
    graph->add_edge(91, 92, 0);
    graph->add_edge(91, 101, 0);
    graph->add_edge(91, 102, 0);
    //92
    graph->add_edge(92, 93, 0);
    graph->add_edge(92, 102, 0);
    graph->add_edge(92, 103, 0);
    //93
    graph->add_edge(93, 94, 0);
    graph->add_edge(93, 103, 0);
    graph->add_edge(93, 104, 0);
    //94
    graph->add_edge(94, 95, 0);
    graph->add_edge(94, 104, 0);
    graph->add_edge(94, 105, 0);
    //95
    graph->add_edge(95, 96, 0);
    graph->add_edge(95, 105, 0);
    graph->add_edge(95, 106, 0);
    //96
    graph->add_edge(96, 97, 0);
    graph->add_edge(96, 106, 0);
    graph->add_edge(96, 107, 0);
    //97
    graph->add_edge(97, 98, 0);
    graph->add_edge(97, 107, 0);
    graph->add_edge(97, 108, 0);
    //98
    graph->add_edge(98, 108, 0);
    graph->add_edge(98, 109, 0);
    //------------------------------------------
    //Line 9
    //------------------------------------------
    //99
    graph->add_edge(99, 100, 0);
    graph->add_edge(99, 110, 0);
    //100
    graph->add_edge(100, 101, 0);
    graph->add_edge(100, 110, 0);
    graph->add_edge(100, 111, 0);
    //101
    graph->add_edge(101, 102, 0);
    graph->add_edge(101, 111, 0);
    graph->add_edge(101, 112, 0);
    //102
    graph->add_edge(102, 103, 0);
    graph->add_edge(102, 112, 0);
    graph->add_edge(102, 113, 0);
    //103
    graph->add_edge(103, 104, 0);
    graph->add_edge(103, 113, 0);
    graph->add_edge(103, 114, 0);
    //104
    graph->add_edge(104, 105, 0);
    graph->add_edge(104, 114, 0);
    graph->add_edge(104, 115, 0);
    //105
    graph->add_edge(105, 106, 0);
    graph->add_edge(105, 115, 0);
    graph->add_edge(105, 116, 0);
    //106
    graph->add_edge(106, 107, 0);
    graph->add_edge(106, 116, 0);
    graph->add_edge(106, 117, 0);
    //107
    graph->add_edge(107, 108, 0);
    graph->add_edge(107, 117, 0);
    graph->add_edge(107, 118, 0);
    //108
    graph->add_edge(108, 109, 0);
    graph->add_edge(108, 118, 0);
    graph->add_edge(108, 119, 0);
    //109
    graph->add_edge(109, 119, 0);
    graph->add_edge(109, 120, 0);
    //------------------------------------------
    //Line 10
    //------------------------------------------
    graph->add_edge(110, 111, 0);
    graph->add_edge(111, 112, 0);
    graph->add_edge(112, 113, 0);
    graph->add_edge(113, 114, 0);
    graph->add_edge(114, 115, 0);
    graph->add_edge(115, 116, 0);
    graph->add_edge(116, 117, 0);
    graph->add_edge(117, 118, 0);
    graph->add_edge(118, 119, 0);
    graph->add_edge(119, 120, 0);
}

