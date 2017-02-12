/*
20:06:56.855 -- engage
20:07:13.126 -- burning arrows 1
20:07:16.620 -- burning arrows 2
20:07:46.791-- burning arrows 3
*/

SET @CGUID := 460000;

UPDATE `instance_template` SET `script`= 'instance_iron_docks' WHERE `map`= 1195;

-- Dreadfang and Fleshrender Nok'Gar
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 16, `scriptname`= 'boss_fleshrender_nokgar' WHERE `entry`= 81305; -- Fleshrender Nok'Gar
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 16, `unit_flags`= 32768, `unit_flags2`= 4261888, `vehicleId`= 3654, `ScriptName`= 'boss_dreadfang' WHERE `entry`= 81297; -- Dreadfang

-- Skulloc
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `vehicleId`= 3808, `scriptname`= 'boss_skulloc' WHERE `entry`= 83612; -- 3808 1631
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `unit_flags`= 33554496, `unit_flags2`= 1073874944, `flags_extra`= 0 WHERE `entry` IN (84109, 84030);
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 2048, `flags_extra`= 128, `InhabitType`= 4 WHERE `entry` = 84464;
-- Koramar
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `scriptname`= 'boss_koramar' WHERE `entry`= 83613;
-- Zoggosh
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `scriptname`= 'boss_zoggosh' WHERE `entry`= 83616;
-- Blackhands Might Cannon
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `vehicleId`= 3789, `unit_flags`= 33554496, `unit_flags2`= 1073741824 WHERE `entry`= 84215;

-- Grimrail Enforcers
-- Ability Sequencer
UPDATE `creature_template` SET `unit_flags` = 33554432, `flags_extra`= 128, `scriptname` = 'npc_ability_sequencer' WHERE `entry`= 82184;
-- Ahriok
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 16, `scriptname`= 'boss_ahriok_dugru' WHERE `entry`= 80816;
-- Makogg
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 16, `scriptname`= 'boss_makogg_emberblade' WHERE `entry`= 80805;
-- Neesa
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 16, `scriptname`= 'boss_neesa_nox' WHERE `entry`= 80808;


-- Train
UPDATE `creature_template` SET `minlevel`= 100, `maxlevel`= 100, `faction`= 35, `unit_flags`= 33554496, `unit_flags2`= 1073741824, `InhabitType`= 4, `flags_extra`=128 WHERE `entry` IN (83747, 83671, 83682, 83676, 83778, 83672);
-- Engine
UPDATE `creature_template` SET `minlevel`= 100, `maxlevel`= 100, `faction`= 35, `unit_flags`= 33554496, `unit_flags2`= 1073741824, `vehicleId`= 3734, `InhabitType`=4, `scriptname`= 'npc_iron_docks_engine' WHERE `entry`= 83673;
-- Flatbed
UPDATE `creature_template` SET `vehicleId`= 3732 WHERE `entry`= 83676;

UPDATE `creature_template` SET `vehicleId`= 0 WHERE `entry`= 83778;
UPDATE `creature_template` SET `vehicleId`= 3735 WHERE `entry`= 83672; -- Enforder Troop Transport

-- Orgron Laborer
UPDATE `creature_template` SET `minlevel`= 101, `maxlevel`= 101, `faction`= 16, `unit_flags`= 333024, `unit_flags2`= 71305216 WHERE `entry`= 83775;


DELETE FROM `creature_text` WHERE `entry` IN (83612, 83613, 83616, 80816, 80805, 80808, 81305);
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
-- Skulloc
(83612, 0, 0, '%s prepares a |cFFFF0404|Hspell:168148|h[Cannon Barrage]|h|r! Get behind cover to survive!', 41, 0, 100, 0, 0, 0, '90484', 'Skulloc - Cannon Barrage'),
-- Koramar
(83613, 0, 0, 'Calm yourself, Zoggosh. We will do no such thing. If these weaklings are so eager to die, then we should oblige.', 14, 0, 100, 603, 0, 43899, '85906', 'Koramar to Player'),
(83613, 1, 0, 'Zoggosh, do not question my authority. This isn\'t just ANY gronn. This is Skulloc, Son of Gruul. The blood of a champion courses through his veins. I\'m not concerned with these... paltry whelps.', 14, 0, 100, 603, 0, 43900, '85907', 'Koramar to Player'),
(83613, 2, 0, 'And what exactly do you think they\'re going to do with orcish iron? Fall on it and die, probably. I\'m not worried in the least.', 14, 0, 100, 603, 0, 43901, '85908', 'Koramar to Player'),
(83613, 3, 0, 'Hah. Would you look at that. Maybe I... underestimated them. Zoggosh! Prepare Skulloc! Let them have a taste of what he has to offer.', 14, 0, 100, 6, 0, 43902, '85909', 'Koramar to Player'),
(83613, 4, 0, 'FIRE... FIRE! AIM, THEN FIRE!', 14, 0, 100, 6, 0, 43903, '85910', 'Koramar to Player'),
(83613, 5, 0, 'What is wrong with you?! Keep firing you oaf!', 14, 0, 100, 603, 0, 43904, '85911', 'Koramar to Player'),
(83613, 6, 0, 'Argghhhh! Forget it! They\'ll never make it past the tracks. Makogg, Ahri\'ok - front and center! There\'s some new meat for you to tenderize.', 14, 0, 100, 1, 0, 43905, '85912', 'Koramar to Player'),

(83613, 9, 0, 'I\'m not playing these games anymore. Bring in the saberon and we\'ll be done with it.', 14, 0, 100, 603, 0, 43908, '85915', 'Koramar to Player'),
(83613, 10, 0, 'Put a muzzle on it.', 14, 0, 100, 1, 0, 43909, '85916', 'Koramar to Player'),
(83613, 11, 0, 'I didn\'t mean the cat.', 14, 0, 100, 1, 0, 43910, '85917', 'Koramar to Player'),

-- Zoggosh
(83616, 0, 0, 'Sir, they\'ve breached the gates! Nok\'gar... He\'s dead!! We should pick up anchor and set sail for Talador right now!', 14, 0, 100, 603, 0, 44047, '85924', 'Zoggosh to Player'),
(83616, 1, 0, 'But sir, this is the last of the gronn that we have! Blackhand will have our hides if we show up empty handed!', 14, 0, 100, 603, 0, 44048, '85925', 'Zoggosh to Player'),
(83616, 2, 0, 'Yessir!', 14, 0, 100, 603, 0, 44049, '85926', 'Zoggosh to Player'),
(83616, 3, 0, 'Sir! They\'re tampering with the Iron Stars!', 14, 0, 100, 603, 0, 44050, '85927', 'Zoggosh to Player'),
(83616, 4, 0, 'Igniting the cannons, sir!', 14, 0, 100, 6, 0, 44051, '85928', 'Zoggosh to Player'),
(83616, 5, 0, 'Sir, he\'s out of ammunition! I\'m reloading, I\'m reloading!', 14, 0, 100, 603, 0, 44052, '85929', 'Zoggosh to Player'),

(83616, 8, 0, 'Captain, they\'re almost here! What do we do now?!', 14, 0, 100, 603, 0, 44054, '85932', 'Zoggosh to Player'),
(83616, 9, 0, 'Uhhh... Are you sure you want to let that thing out of its cage? I don\'t think we have fed it since we found it.', 14, 0, 100, 6, 0, 44055, '85933', 'Zoggosh to Player'),
(83616, 10, 0, 'Good idea, sir!', 14, 0, 100, 603, 0, 44056, '85934', 'Zoggosh to Player'),

-- Ahriok
(80816, 0, 0, 'Right away, captain! It will be my pleasure.', 14, 0, 100, 0, 0, 44691, '85470', ''),

-- Makogg
(80805, 0, 0, 'Hah. Ditto.', 14, 0, 100, 0, 0, 45800, '85475', ''),

-- Neesa
(80808, 0, 0, 'Ooooh! Is there killin\' ta be done? Lemme at\'em!', 14, 0, 100, 603, 0, 46128, '85941', ''),

-- Fleshrender Nok'Gar
(81305, 0, 0, 'Warsong arrows sing from the sky! They\'ll be the last thing you hear as I crush your skull.', 14, 0, 100, 396, 0, 46059, '85406', 'Fleshrender Nok\'Gar Aggro'),
(81305, 1, 0, 'Revel in the slaughter!', 14, 0, 100, 396, 0, 46060, '85412', 'Fleshrender Nok\'Gar Burning Slay 1'),
(81305, 1, 1, 'My blade thirsts for more.', 14, 0, 100, 396, 0, 46061, '85413', 'Fleshrender Nok\'Gar Burning Slay 2'),
(81305, 2, 0, 'Let them have it!', 14, 0, 100, 396, 0, 46062, '85408', 'Fleshrender Nok\'Gar Arrow Barrage'),
(81305, 3, 0, 'Start the funeral pyres!', 14, 0, 100, 396, 0, 46057, '85407', 'Fleshrender Nok\'Gar Burning Arrows'),
(81305, 4, 0, 'That\'s it? You barely drew blood!', 14, 0, 100, 396, 0, 46063, '85409', 'Fleshrender Nok\'Gar Provocation'),
(81305, 4, 1, 'Terror overwhelms you, death is near.', 14, 0, 100, 396, 0, 46064, '85411', 'Fleshrender Nok\'Gar Provocation'),
(81305, 5, 1, '|TInterface\\Icons\\ability_warrior_rampage.blp:20|t %s begins to cast |cFFFF0000|Hspell:164426|h[Reckless Provocation]|h|r!', 41, 0, 100, 0, 0, 0, '85407', 'Fleshrender Nok\'Gar Announce Provocation'),
(81305, 6, 0, 'You will burn with me.', 14, 0, 100, 0, 0, 46058, '85414', 'Fleshrender Nok\'Gar Death'),
(81305, 7, 0, 'A death worthy of a warrior!', 14, 0, 100, 0, 0, 46065, '85410', 'Fleshrender Nok\'Gar Dreadfang Death');

UPDATE `creature_text` SET `TextRange`= 2 WHERE `entry` IN (83613, 83616);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (168227, 168929, 168129, 169131, 168390, 168541, 168514, 168537);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(168227, 'spell_skulloc_gronn_smash'),
(168929, 'spell_skulloc_cannon_barrage_channel_aura'),
(168129, 'spell_skulloc_cannon_barrage_cannon_aura'),
(169131, 'spell_skulloc_backdraft_dummy'),
(168390, 'spell_skulloc_cannon_barrage_aoe'),
(168541, 'spell_skulloc_cannon_barrage_aoe_npc'),
(168514, 'spell_skulloc_cannon_barrage_aoe_2'),
(168537, 'spell_skulloc_cannon_barrage_cannon_aura_2');


REPLACE INTO `spell_target_position`(`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(168167, 2, 1195, 6857.7, -990.11, 23.3);

DELETE FROM `creature` WHERE `id` IN (84109, 84030, 83676, 83682, 83676, 83778, 83676, 83775, 83776, 86565, 84109, 84030, 83777);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 83673;
REPLACE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(83612, 84109, 0, 1, 'Skulloc - Cannon', 7, 0),
(83612, 84030, 1, 1, 'Skulloc - Cannon', 7, 0);

DELETE FROM `vehicle_accessory` WHERE `guid` IN (@CGUID+98, @CGUID+117);
REPLACE INTO `vehicle_accessory` (`guid`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(@CGUID+98, 83682, 8, 1, 'Engine - Troop Transport Seat 6', 7, 0),
(@CGUID+98, 83682, 7, 1, 'Engine - Troop Transport Seat 5', 7, 0),
(@CGUID+98, 83676, 6, 1, 'Engine - Troop Transport Seat 4', 7, 0),
(@CGUID+98, 83682, 5, 1, 'Engine - Troop Transport Seat 3', 7, 0),
(@CGUID+98, 83676, 4, 1, 'Engine - Troop Transport Seat 2', 7, 0),
(@CGUID+98, 83778, 3, 1, 'Engine - Troop Transport Seat 1', 7, 0),

(@CGUID+117, 83672, 3, 1, 'Engine - Troop Transport Seat 1', 7, 0),
(@CGUID+117, 83676, 4, 1, 'Engine - Troop Transport Seat 2', 7, 0),
(@CGUID+117, 83682, 5, 1, 'Engine - Troop Transport Seat 3', 7, 0);


REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(83612, 77901, 1),
(83673, 46598, 1),
(83676, 46598, 1);

DELETE FROM `conditions` WHERE `SourceEntry` IN (169131, 168511, 168541);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 7, 169131, 0, 0, 31, 0, 3, 84464, 0, 0, 0, '', 'Backdraft target Backdraft'),
(13, 1, 168511, 0, 0, 31, 0, 3, 84109, 0, 0, 0, '', 'Cannon Barrage - Hit Cannons'),
(13, 2, 168511, 0, 0, 31, 0, 3, 84030, 0, 0, 0, '', 'Cannon Barrage - Hit Cannons'),

(13, 1, 168541, 0, 0, 31, 0, 3, 86526, 0, 0, 0, '', 'Cannon Barrage - Hit Gromkar Deckhand'),
(13, 1, 168541, 1, 0, 31, 0, 3, 84109, 0, 0, 0, '', 'Cannon Barrage - Hit Gromkar Chainmaster'),

(13, 2, 168541, 1, 0, 31, 0, 3, 83578, 0, 0, 0, '', 'Cannon Barrage - Hit Orgron Laborer');

DELETE FROM `areatrigger_scripts` WHERE `Scriptname`= 'at_iron_docks_gauntlet_2';

REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(10145, 'at_iron_docks_gauntlet_2'),
(10296, 'at_iron_docks_gauntlet_3'),
(10156, 'at_iron_docks_gauntlet_4'),
(10314, 'at_iron_docks_gauntlet_5'),
(10154, 'at_iron_docks_oshir_intro');

