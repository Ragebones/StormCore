SET @CGUID := 1330829;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 105507, 1220, 0, 0, 3, 0, 0, 0, -831.425, 4255.36, 746.178, 1.54849, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- 105507
DELETE FROM creature_template WHERE `entry`=105507 LIMIT 1;
INSERT INTO creature_template (entry, modelid1, NAME, gossip_menu_id, minlevel, maxlevel, faction, npcflag, AIName) VALUES (105507, 73300, "Danica the Reclaimer", 19489, 110, 110, 35, 1, "SmartAI");
DELETE FROM `gossip_menu` WHERE (`entry`=19489 AND `text_id`=28791);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(19489, 28791); -- 105507
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=19489 AND `id`=1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(19489, 1, 0, 'Take me to the Halls of Valor.',  0,  1,  1,  0,  0, 0, 0, '',  0);
DELETE FROM `world`.`smart_scripts` WHERE (`entryorguid`=105507 AND `source_type`=0);
INSERT INTO `world`.`smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('105507', '0', '1', '0', '62', '0', '100', '0', '19489', '1', '0', '0', '62', '1479', '0', '0', '0', '0', '0', '7', '0', '0', '0', '1082.99', '7229.33', '98.2015', '3.55833', 'skyhold');