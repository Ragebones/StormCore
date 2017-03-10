UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=73 WHERE `entry`=111110;
UPDATE `creature_template` SET `lootid`=111110 WHERE entry=111110;
DELETE FROM `creature_loot_template` WHERE `entry` = 111110;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(111110, 139549, 0, 100, 0, 1, 0, 1, 1, 'Guise of the Deathwalker');

-- Health

UPDATE `creature` SET `curhealth`=10392670 WHERE `id`=111110;