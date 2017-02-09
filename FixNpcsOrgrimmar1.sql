DELETE FROM `creature` WHERE `id` IN ('62198','62445','65008','65071','66022','66437','68869','69333','70301','6466');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `Phasemask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,'62198','1','0','0','1','0','0','0','0','0','1738.7','-4405','36.6605','1.9183','300','0','0','30522','9470','0','0','0','0','0'), -- Omakka Wolfbrother
(@CGUID+1,'62445','1','0','0','1','0','0','0','0','0','2027.28','-4707.04','28.3234','2.67778','300','0','0','11494','0','0','0','0','0','0'), -- Ji Firepaw <Monk Trainer>
(@CGUID+2,'65008','1','0','0','1','0','0','0','0','0','2022.54','-4714.15','28.6681','2.67854','300','0','0','384','0','0','0','0','0','0'), -- Huojin Monk
(@CGUID+3,'65008','1','0','0','1','0','0','0','0','0','2019.85','-4712.88','28.7463','5.9026','300','0','0','384','0','0','0','0','0','0'), -- Huojin Monk
(@CGUID+4,'65071','1','0','0','1','0','0','0','0','0','2027.69','-4715.04','28.4222','4.44176','300','0','0','80','0','0','0','0','0','0'), -- Great Green Dragon Turtle
(@CGUID+5,'66022','1','0','0','1','0','0','0','0','0','2005.2','-4718.74','29.5988','0.770294','300','0','0','11494','0','0','0','0','0','0'), -- Turtlemaster Odai <Dragon Turtle Breeder>
(@CGUID+6,'66437','1','0','0','1','0','0','0','0','0','2012.99','-4703.37','28.7158','0.394088','300','0','0','7987','0','0','0','0','0','0'), -- Arcanist Xu <Horde Mage>
(@CGUID+7,'68869','1','0','0','1','0','0','0','0','0','2023.63','-4705.22','28.4903','2.67778','300','0','0','80','0','0','0','0','0','0'), -- Luo Luo
(@CGUID+8,'69333','1','0','0','1','0','0','0','0','0','2014.98','-4699.09','28.5985','5.97252','300','0','0','11494','0','0','0','0','0','0'), -- Disciple Jusi <Huojin Quartermaster>
(@CGUID+9,'70301','1','0','0','1','0','0','0','0','0','2001.61','-4715.03','29.6448','0.770294','300','0','0','11494','0','0','0','0','0','0'); -- Softpaws <Riding Trainer>


UPDATE `creature` SET id= '88701' WHERE id= '5603';
UPDATE `creature` SET id= '88702' WHERE id= '5597';
UPDATE `creature` SET id= '88703' WHERE id= '44874';
UPDATE `creature` SET id= '88704' WHERE id= '3324';
UPDATE `creature` SET id= '88705' WHERE id= '3326';
UPDATE `creature` SET id= '88706' WHERE id= '5815';


-- Npc_vendor

UPDATE `creature` SET `npcflag`=128 WHERE `id`=69333;
DELETE FROM `npc_vendor` WHERE `entry`=69333;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(69333, 2, 92070, 20, 0, 1, 0, 0, 0), 
(69333, 1, 83080, 20, 0, 1, 0, 0, 0); 