-- Creature_equip_template

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN('14720', '107574');

INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(14720,1,21580,0,0,18019),
(107574,1,12748,0,0,18019);

 -- Creature

DELETE FROM `creature` WHERE `guid` IN ('314277', '314300','314301','310903');
DELETE FROM `creature` WHERE `id` IN ('1747', '45253'); 

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `Phasemask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(310903,'14720','1','0','0','1','0','0','0','0','1','1664.72','-4345.48','26.279','3.60323','120','0','0','626703616','0','0','3','0','0','0'),
(314300,'107574','0','0','0','1','0','0','0','0','1','-8363.06','232.236','157.073','2.23402','120','0','0','655852800','0','0','3','0','0','0');

-- creature_template`

DELETE FROM `creature_template` WHERE `entry`=14720;
DELETE FROM `creature_template` WHERE `entry`=107574;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
('14720','0','0','0','0','0','14732','0','0','0','High Overlord Saurfang','','','','0','3','3','-1','0','0','1734','3','1.1','1.14286','1','1','0','2000','2000','1','1','1','32768','2099200','0','0','0','0','0','7','76','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','700000','750000','','0','3','1','1200','1','1','1','1','35','1','1','151','1','619397119','0','','22908'),
('107574','0','0','0','0','0','65199','0','0','0','King Anduin Wrynn','','King of Stormwind','','0','3','3','-1','0','0','1733','3','1','1.14286','1','1','0','2000','2000','1','1','2','32768','2099200','0','0','0','0','0','7','76','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','700000','750000','','0','3','1','1200','1','250','1','1','35','1','1','144','1','619397119','0','','22908');
