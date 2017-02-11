-- [NPC] Ymiron, The Fallen King -- http://www.wowhead.com/npc=96756
SET @CREATURE_ENTRY := 96756;

UPDATE creature_template SET minlevel = 112, maxlevel = 112, ScriptName = 'npc_bane_skeleton', VerifiedBuild = 2322, faction = 14 WHERE entry = 98246;

DELETE FROM `creature_text` WHERE `entry` = @CREATURE_ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@CREATURE_ENTRY, 0, 0, 'Another drop in the sea of souls!', 14, 0, 100, 0, 0, 54367, '102185', 'Ymiron, the Fallen King drains souls from initiates'),
(@CREATURE_ENTRY, 1, 0, 'Mortals... Your wretched kind murdered MY people... destroyed MY kingdom! Long have I waited for a chance to repay what was done to me!', 14, 0, 50, 0, 0, 54370, '102189', 'Ymiron, the Fallen King Aggro'),
(@CREATURE_ENTRY, 1, 1, 'Mortals... Your wretched kind murdered MY people... destroyed MY kingdom! Now you, too, will know what it feels like to lose EVERYTHING!', 14, 0, 50, 0, 0, 54371, '102190', 'Ymiron, the Fallen King Aggro'),
(@CREATURE_ENTRY, 2, 0, 'The shadows of the underworld bend to me!', 14, 0, 50, 0, 0, 54357, '102171', 'Ymiron, the Fallen King Casts Bane'),
(@CREATURE_ENTRY, 3, 0, 'The shadows of Helheim cut deeper than steel!', 14, 0, 50, 0, 0, 54358, '102173', 'Ymiron, the Fallen King Casts Arise, Fallen'),
(@CREATURE_ENTRY, 4, 0, 'COWER BEFORE ME!', 14, 0, 33, 0, 0, 54359, '102174', 'Ymiron, the Fallen King Casts Screams of the Dead'),
(@CREATURE_ENTRY, 4, 1, 'FLEE, COWARDS!', 14, 0, 33, 0, 0, 54360, '102175', 'Ymiron, the Fallen King Casts Screams of the Dead'),
(@CREATURE_ENTRY, 4, 2, 'CRAVEN MAGGOTS!', 14, 0, 33, 0, 0, 54361, '102176', 'Ymiron, the Fallen King Casts Screams of the Dead'),
(@CREATURE_ENTRY, 5, 0, 'Know the bitter chill of death as I have!', 14, 0, 50, 0, 0, 54362, '102177', 'Ymiron, the Fallen King Casts Winds of Northrend'),
(@CREATURE_ENTRY, 5, 1, 'The winds of the frozen north still howl in these veins!', 14, 0, 50, 0, 0, 54364, '102178', 'Ymiron, the Fallen King Casts Winds of Northrend'),
(@CREATURE_ENTRY, 6, 0, 'Vengeance!', 14, 0, 50, 0, 0, 54368, '102186', 'Ymiron, the Fallen King Kills Player'),
(@CREATURE_ENTRY, 6, 1, 'PAYBACK!', 14, 0, 50, 0, 0, 54369, '102187', 'Ymiron, the Fallen King Kills Player'),
(@CREATURE_ENTRY, 7, 0, 'You have not won... The Naglfar comes... for you...', 14, 0, 33, 0, 0, 54363, '102180', 'Ymiron, the Fallen King Killed'),
(@CREATURE_ENTRY, 7, 1, 'You have not won... You have only... secured your own doom...', 14, 0, 33, 0, 0, 54365, '102181', 'Ymiron, the Fallen King Killed'),
(@CREATURE_ENTRY, 7, 2, 'Not... again... HARBARON! CAST THEIR SOULS INTO THE TIDES!', 14, 0, 33, 0, 0, 54366, '102182', 'Ymiron, the Fallen King Killed');

