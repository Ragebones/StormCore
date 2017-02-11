-- [Markus Hjolbruk]
-- http://es.wowhead.com/npc=112226

DELETE FROM `npc_vendor` WHERE `entry`=112226;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(112226, 10, 128833, 20, 0, 1, 0, 0, 22950), 
(112226, 9, 128834, 20, 0, 1, 0, 0, 22950), 
(112226, 8, 128840, 20, 0, 1, 0, 0, 22950), 
(112226, 7, 128841, 20, 0, 1, 0, 0, 22950), 
(112226, 6, 128842, 20, 0, 1, 0, 0, 22950), 
(112226, 5, 138290, 20, 0, 1, 0, 0, 22950), 
(112226, 4, 138292, 20, 0, 1, 0, 0, 22950), 
(112226, 3, 128839, 20, 0, 1, 0, 0, 22950), 
(112226, 2, 128853, 20, 0, 1, 0, 0, 22950), 
(112226, 1, 138285, 20, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=112226;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=112226;


-- Administrador Dayton <Tabernero>	
-- http://es.wowhead.com/npc=98112

DELETE FROM `npc_vendor` WHERE `entry`=98112;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(98112, 26, 38682, 200, 0, 1, 0, 0, 22950), 
(98112, 25, 128764, 20, 0, 1, 0, 0, 22950), 
(98112, 24, 128835, 20, 0, 1, 0, 0, 22950), 
(98112, 23, 128838, 20, 0, 1, 0, 0, 22950), 
(98112, 22, 138290, 20, 0, 1, 0, 0, 22950), 
(98112, 21, 138292, 20, 0, 1, 0, 0, 22950), 
(98112, 20, 128763, 20, 0, 1, 0, 0, 22950), 
(98112, 19, 128836, 20, 0, 1, 0, 0, 22950), 
(98112, 18, 128837, 20, 0, 1, 0, 0, 22950), 
(98112, 17, 128853, 20, 0, 1, 0, 0, 22950), 
(98112, 16, 138285, 20, 0, 1, 0, 0, 22950), 
(98112, 15, 138977, 20, 0, 1, 0, 0, 22950), 
(98112, 14, 138293, 1, 0, 1, 0, 0, 22950), 
(98112, 13, 90146, 200, 0, 1, 0, 0, 22950), 
(98112, 12, 128833, 20, 0, 1, 0, 0, 22950), 
(98112, 11, 20815, 1, 0, 1, 0, 0, 22950), 
(98112, 10, 164670, 20, 0, 1, 0, 0, 22950), 
(98112, 9, 6217, 1, 0, 1, 0, 0, 22950), 
(98112, 8, 4470, 200, 0, 1, 0, 0, 22950), 
(98112, 7, 2901, 1, 0, 1, 0, 0, 22950), 
(98112, 6, 7005, 1, 0, 1, 0, 0, 22950), 
(98112, 5, 85663, 1, 0, 1, 0, 0, 22950), 
(98112, 4, 3371, 200, 0, 1, 0, 0, 22950), 
(98112, 3, 5956, 1, 0, 1, 0, 0, 22950), 
(98112, 2, 6256, 1, 0, 1, 0, 0, 22950), 
(98112, 1, 39505, 1, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=98112;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=98112;

-- Elliot Theodric <Tabernero>
-- http://es.wowhead.com/npc=98106

DELETE FROM `npc_vendor` WHERE `entry`=98106;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(98106, 26, 38682, 200, 0, 1, 0, 0, 22950), 
(98106, 25, 128764, 20, 0, 1, 0, 0, 22950), 
(98106, 24, 128835, 20, 0, 1, 0, 0, 22950), 
(98106, 23, 128838, 20, 0, 1, 0, 0, 22950), 
(98106, 22, 138290, 20, 0, 1, 0, 0, 22950), 
(98106, 21, 138292, 20, 0, 1, 0, 0, 22950), 
(98106, 20, 128763, 20, 0, 1, 0, 0, 22950), 
(98106, 19, 128836, 20, 0, 1, 0, 0, 22950), 
(98106, 18, 128837, 20, 0, 1, 0, 0, 22950), 
(98106, 17, 128853, 20, 0, 1, 0, 0, 22950), 
(98106, 16, 138285, 20, 0, 1, 0, 0, 22950), 
(98106, 15, 138977, 20, 0, 1, 0, 0, 22950), 
(98106, 14, 138293, 1, 0, 1, 0, 0, 22950), 
(98106, 13, 90146, 200, 0, 1, 0, 0, 22950), 
(98106, 12, 128833, 20, 0, 1, 0, 0, 22950), 
(98106, 11, 20815, 1, 0, 1, 0, 0, 22950), 
(98106, 10, 164670, 20, 0, 1, 0, 0, 22950), 
(98106, 9, 6217, 1, 0, 1, 0, 0, 22950), 
(98106, 8, 4470, 200, 0, 1, 0, 0, 22950), 
(98106, 7, 2901, 1, 0, 1, 0, 0, 22950), 
(98106, 6, 7005, 1, 0, 1, 0, 0, 22950), 
(98106, 5, 85663, 1, 0, 1, 0, 0, 22950), 
(98106, 4, 3371, 200, 0, 1, 0, 0, 22950), 
(98106, 3, 5956, 1, 0, 1, 0, 0, 22950), 
(98106, 2, 6256, 1, 0, 1, 0, 0, 22950), 
(98106, 1, 39505, 1, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=98106;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=98106;

-- Maribeth <Tabernera>
-- http://es.wowhead.com/npc=113515

DELETE FROM `npc_vendor` WHERE `entry`=113515;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(113515, 25, 138292, 20, 0, 1, 0, 0, 22950), 
(113515, 24, 140286, 20, 0, 1, 0, 0, 22950),
(113515, 23, 140299, 20, 0, 1, 0, 0, 22950),
(113515, 22, 140301, 20, 0, 1, 0, 0, 22950),
(113515, 21, 140631, 20, 0, 1, 0, 0, 22950),
(113515, 20, 141208, 20, 0, 1, 0, 0, 22950),
(113515, 19, 128853, 20, 0, 1, 0, 0, 22950),
(113515, 18, 127037, 200, 0, 1, 0, 0, 22950),
(113515, 17, 127681, 200, 0, 1, 0, 0, 22950),
(113515, 16, 38426, 200, 0, 1, 0, 0, 22950),
(113515, 15, 4342, 200, 0, 1, 0, 0, 22950),
(113515, 14, 10290, 200, 0, 1, 0, 0, 22950),
(113515, 13, 14341, 200, 0, 1, 0, 0, 22950),
(113515, 12, 2325, 200, 0, 1, 0, 0, 22950),
(113515, 11, 8343, 200, 0, 1, 0, 0, 22950),
(113515, 10, 6261, 200, 0, 1, 0, 0, 22950),
(113515, 9, 4291, 200, 0, 1, 0, 0, 22950),
(113515, 8, 4340, 200, 0, 1, 0, 0, 22950),
(113515, 7, 4341, 200, 0, 1, 0, 0, 22950),
(113515, 6, 2321, 200, 0, 1, 0, 0, 22950),
(113515, 5, 2605, 200, 0, 1, 0, 0, 22950),
(113515, 4, 2604, 200, 0, 1, 0, 0, 22950),
(113515, 3, 6260, 200, 0, 1, 0, 0, 22950),
(113515, 2, 2320, 200, 0, 1, 0, 0, 22950),
(113515, 1, 2324, 200, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=113515;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=113515;

-- Riala la Vig�a del Hogar <Tabernero>
-- http://es.wowhead.com/npc=103796

DELETE FROM `npc_vendor` WHERE `entry`=103796;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(103796, 26, 38682, 200, 0, 1, 0, 0, 22950), 
(103796, 25, 128764, 20, 0, 1, 0, 0, 22950), 
(103796, 24, 128835, 20, 0, 1, 0, 0, 22950), 
(103796, 23, 128838, 20, 0, 1, 0, 0, 22950), 
(103796, 22, 138290, 20, 0, 1, 0, 0, 22950), 
(103796, 21, 138292, 20, 0, 1, 0, 0, 22950), 
(103796, 20, 128763, 20, 0, 1, 0, 0, 22950), 
(103796, 19, 128836, 20, 0, 1, 0, 0, 22950), 
(103796, 18, 128837, 20, 0, 1, 0, 0, 22950), 
(103796, 17, 128853, 20, 0, 1, 0, 0, 22950), 
(103796, 16, 138285, 20, 0, 1, 0, 0, 22950), 
(103796, 15, 138977, 20, 0, 1, 0, 0, 22950), 
(103796, 14, 138293, 1, 0, 1, 0, 0, 22950), 
(103796, 13, 90146, 200, 0, 1, 0, 0, 22950), 
(103796, 12, 128833, 20, 0, 1, 0, 0, 22950), 
(103796, 11, 20815, 1, 0, 1, 0, 0, 22950), 
(103796, 10, 164670, 20, 0, 1, 0, 0, 22950), 
(103796, 9, 6217, 1, 0, 1, 0, 0, 22950), 
(103796, 8, 4470, 200, 0, 1, 0, 0, 22950), 
(103796, 7, 2901, 1, 0, 1, 0, 0, 22950), 
(103796, 6, 7005, 1, 0, 1, 0, 0, 22950), 
(103796, 5, 85663, 1, 0, 1, 0, 0, 22950), 
(103796, 4, 3371, 200, 0, 1, 0, 0, 22950), 
(103796, 3, 5956, 1, 0, 1, 0, 0, 22950), 
(103796, 2, 6256, 1, 0, 1, 0, 0, 22950), 
(103796, 1, 39505, 1, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=103796;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=103796;

-- Intendente Ricard
-- http://es.wowhead.com/npc=91535

DELETE FROM `npc_vendor` WHERE `entry`=91535;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(91535, 11, 128833, 20, 0, 1, 0, 0, 22950), 
(91535, 10, 128834, 20, 0, 1, 0, 0, 22950), 
(91535, 9, 128835, 20, 0, 1, 0, 0, 22950), 
(91535, 8, 128840, 20, 0, 1, 0, 0, 22950), 
(91535, 7, 128841, 20, 0, 1, 0, 0, 22950), 
(91535, 6, 128842, 20, 0, 1, 0, 0, 22950), 
(91535, 5, 138292, 20, 0, 1, 0, 0, 22950), 
(91535, 4, 128836, 20, 0, 1, 0, 0, 22950), 
(91535, 3, 128853, 20, 0, 1, 0, 0, 22950), 
(91535, 2, 138977, 20, 0, 1, 0, 0, 22950), 
(91535, 1, 128839, 20, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=91535;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=91535;

-- Fola U�asevera <Tabernero> *
-- http://es.wowhead.com/npc=100746

DELETE FROM `npc_vendor` WHERE `entry`=100746;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(100746, 16, 128833, 20, 0, 1, 0, 0, 22950), 
(100746, 15, 128834, 20, 0, 1, 0, 0, 22950), 
(100746, 14, 128835, 20, 0, 1, 0, 0, 22950), 
(100746, 13, 128840, 20, 0, 1, 0, 0, 22950), 
(100746, 12, 128841, 20, 0, 1, 0, 0, 22950), 
(100746, 11, 128842, 20, 0, 1, 0, 0, 22950), 
(100746, 10, 138292, 20, 0, 1, 0, 0, 22950), 
(100746, 9, 128836, 20, 0, 1, 0, 0, 22950), 
(100746, 8, 128853, 20, 0, 1, 0, 0, 22950), 
(100746, 7, 138977, 20, 0, 1, 0, 0, 22950), 
(100746, 6, 128839, 20, 0, 1, 0, 0, 22950),
(100746, 5, 128844, 20, 0, 1, 0, 0, 22950),
(100746, 4, 128849, 20, 0, 1, 0, 0, 22950),
(100746, 3, 128761, 10, 0, 1, 0, 0, 22950), 
(100746, 2, 128763, 20, 0, 1, 0, 0, 22950),
(100746, 1, 128837, 20, 0, 1, 0, 0, 22950),

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=100746;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=100746;

-- Tabernero Boorand Ventollano <Tabernero>
-- http://es.wowhead.com/npc=104802

DELETE FROM `npc_vendor` WHERE `entry`=104802;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(104802, 12, 8766, 20, 0, 1, 0, 0, 22950), 
(104802, 11, 8953, 20, 0, 1, 0, 0, 22950), 
(104802, 10, 1645, 20, 0, 1, 0, 0, 22950), 
(104802, 9, 4602, 20, 0, 1, 0, 0, 22950), 
(104802, 8, 1708, 20, 0, 1, 0, 0, 22950), 
(104802, 7, 4539, 20, 0, 1, 0, 0, 22950), 
(104802, 6, 1205, 20, 0, 1, 0, 0, 22950), 
(104802, 5, 4538, 20, 0, 1, 0, 0, 22950), 
(104802, 4, 1179, 20, 0, 1, 0, 0, 22950), 
(104802, 3, 4537, 20, 0, 1, 0, 0, 22950), 
(104802, 2, 159, 20, 0, 1, 0, 0, 22950), 
(104802, 1, 4536, 20, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=104802;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=104802;

-- Nalysse Albapena <Ayudante de c�mara del Rey>
-- http://es.wowhead.com/npc=109372 

DELETE FROM `npc_vendor` WHERE `entry`=109372;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(109372, 11, 128833, 20, 0, 1, 0, 0, 22950), 
(109372, 10, 128834, 20, 0, 1, 0, 0, 22950), 
(109372, 9, 128835, 20, 0, 1, 0, 0, 22950), 
(109372, 8, 128840, 20, 0, 1, 0, 0, 22950), 
(109372, 7, 128841, 20, 0, 1, 0, 0, 22950), 
(109372, 6, 128842, 20, 0, 1, 0, 0, 22950), 
(109372, 5, 138292, 20, 0, 1, 0, 0, 22950), 
(109372, 4, 128836, 20, 0, 1, 0, 0, 22950), 
(109372, 3, 128853, 20, 0, 1, 0, 0, 22950), 
(109372, 2, 138977, 20, 0, 1, 0, 0, 22950), 
(109372, 1, 128839, 20, 0, 1, 0, 0, 22950);

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=109372;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=109372;

-- Filrich <Custodio, proveedor y director de alojamiento de la Academia> *
-- http://es.wowhead.com/npc=109377

DELETE FROM `npc_vendor` WHERE `entry`=109377;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(109377, 7, 128764, 20, 0, 1, 0, 0, 22950), 
(109377, 6, 128835, 20, 0, 1, 0, 0, 22950), 
(109377, 5, 138292, 20, 0, 1, 0, 0, 22950), 
(109377, 4, 128763, 20, 0, 1, 0, 0, 22950), 
(109377, 3, 128836, 20, 0, 1, 0, 0, 22950), 
(109377, 2, 128853, 20, 0, 1, 0, 0, 22950), 
(109377, 1, 138977, 20, 0, 1, 0, 0, 22950);


UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=109377;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=109377;

-- Taberneros Listos!


