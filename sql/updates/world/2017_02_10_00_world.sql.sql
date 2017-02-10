DELETE FROM `creature_equip_template` WHERE (`CreatureID`=103810 AND `ID`=1) OR (`CreatureID`=113270 AND `ID`=1) OR (`CreatureID`=107484 AND `ID`=1) OR (`CreatureID`=107483 AND `ID`=1) OR (`CreatureID`=96401 AND `ID`=2) OR (`CreatureID`=96401 AND `ID`=1) OR (`CreatureID`=114559 AND `ID`=1) OR (`CreatureID`=112577 AND `ID`=1) OR (`CreatureID`=107494 AND `ID`=1) OR (`CreatureID`=96586 AND `ID`=1) OR (`CreatureID`=114558 AND `ID`=1) OR (`CreatureID`=96679 AND `ID`=1) OR (`CreatureID`=96572 AND `ID`=1) OR (`CreatureID`=112392 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(103810, 1, 83019, 0, 0), -- 103810
(113270, 1, 2703, 0, 0), -- Doncella escudera
(107484, 1, 137174, 137266, 0), -- 107484
(107483, 1, 137263, 137264, 0), -- 107483
(96401, 2, 137176, 0, 0), -- Aspirante Valarjar
(96401, 1, 137174, 137264, 0), -- Aspirante Valarjar
(114559, 1, 137263, 137264, 0), -- 114559
(112577, 1, 140747, 0, 0), -- 112577
(107494, 1, 137262, 0, 0), -- Maestra de arena Val'kyr
(96586, 1, 7956, 0, 0), -- 96586
(114558, 1, 137263, 140748, 0), -- 114558
(96679, 1, 140345, 0, 0), -- 96679
(96572, 1, 137174, 140748, 0), -- Valarjar Tronaforjado
(112392, 1, 140747, 0, 0); -- 112392

UPDATE `creature_template` SET `npcflag`=4, `faction`=35 WHERE `entry`=112392;

DELETE FROM `npc_vendor` WHERE (`entry`=112392 AND `item`=140985 AND `ExtendedCost`=6102 AND `type`=1) OR (`entry`=112392 AND `item`=140946 AND `ExtendedCost`=6101 AND `type`=1) OR (`entry`=112392 AND `item`=140984 AND `ExtendedCost`=5952 AND `type`=1) OR (`entry`=112392 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139687 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139682 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139681 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139685 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139688 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139684 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=140537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=112392 AND `item`=140557 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=112392 AND `item`=140559 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(112392, 14, 140985, 0, 6102, 1, 0, 0, 23420), -- Refuerzo para armadura superior de señor de la batalla
(112392, 13, 140946, 0, 6101, 1, 0, 0, 23420), -- Refuerzo para armadura de señor de la batalla
(112392, 12, 140984, 0, 5952, 1, 0, 0, 23420), -- Refuerzo para armadura inferior de señor de la batalla
(112392, 11, 139686, 0, 6125, 1, 0, 0, 23420), -- Espaldares de señor de la batalla
(112392, 10, 139687, 0, 6125, 1, 43138, 0, 23420), -- Faja de señor de la batalla
(112392, 9, 139682, 0, 6125, 1, 43054, 0, 23420), -- Botas de guerra de señor de la batalla
(112392, 8, 139681, 0, 6125, 1, 43118, 0, 23420), -- Peto de señor de la batalla
(112392, 7, 139685, 0, 6125, 1, 43111, 0, 23420), -- Quijotes de señor de la batalla
(112392, 6, 139683, 0, 6125, 1, 0, 0, 23420), -- Guanteletes de señor de la batalla
(112392, 5, 139688, 0, 6125, 1, 43117, 0, 23420), -- Guardamuñecas de señor de la batalla
(112392, 4, 139684, 0, 6125, 1, 43119, 0, 23420), -- Gran yelmo de señor de la batalla
(112392, 3, 140537, 0, 0, 1, 45032, 0, 23420), -- Baluarte del Bastión Celestial
(112392, 2, 140557, 0, 0, 1, 45032, 0, 23420), -- Hoja rauda del Bastión Celestial
(112392, 1, 140559, 0, 0, 1, 45032, 0, 23420); -- Mandoble del Bastión Celestial