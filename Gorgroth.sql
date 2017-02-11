UPDATE `creature_template` SET `lootid`=110832, `minlevel`=110, `maxlevel`=110, `faction`=73 WHERE `entry`=110832;
DELETE FROM `creature_loot_template` WHERE ´entry´='110832';
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroudId`, `MinCount`, `MaxCount`, `Comment`)VALUES
('110832', '121747', '0', '29', '0', '1', '1', '0', '1'),
('110832', '138839', '0', '21', '0', '1', '1', '0', '1'),
('110832', '138991', '0', '2', '1', '1', '1', '0', '1'),
('110832', '141572', '0', '0.17', '0', '1', '1', '0', '1'),
('110832', '132204', '0', '77', '0', '1', '1', '0', '1'),
('110832', '132199', '0', '19', '0', '1', '1', '0', '1'),
('110832', '124437', '0', '10', '0', '1', '1', '1', '3'),
('110832', '132200', '0', '6', '0', '1', '1', '0', '1'); 

-- Spawn 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(482365+0, 110832, 1220, 7637, 7844, 15, '0', 0, 0, 0, 1014.625305, 5142.360352, 58.754696, 6.070705, 2700, 0, 0, 0, 0, 0, 0, 0, 0, 22290);

-- Health
UPDATE `creature` SET `curhealth`=1036424 WHERE `id`=110832;