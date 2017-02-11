-- [NPC] Helya -- http://www.wowhead.com/npc=96759
SET @CREATURE_ENTRY := 96759;

DELETE FROM `creature_text` WHERE `entry` = @CREATURE_ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@CREATURE_ENTRY, 0, 0, 'You ALL will regret trespassing in my realm.', 14, 0, 100, 0, 0, 54395, '102212', 'Helya Emerges'),
(@CREATURE_ENTRY, 1, 0, 'You have come far enough. Time to die.', 14, 0, 100, 0, 0, 54180, '102213', 'Helya Aggro'),
(@CREATURE_ENTRY, 2, 0, 'Embrace your fate, fools!', 14, 0, 50, 0, 0, 54391, '102228', 'Helya casts Taint of the sea'),
(@CREATURE_ENTRY, 2, 1, 'Your fate rains down!', 14, 0, 50, 0, 0, 54392, '102217', 'Helya casts Taint of the sea'),
(@CREATURE_ENTRY, 3, 0, 'You will pay for that.', 14, 0, 20, 0, 0, 54244, '102221', 'Helya looses tentacle'),
(@CREATURE_ENTRY, 3, 1, 'I am losing my patience.', 14, 0, 20, 0, 0, 54245, '102222', 'Helya looses tentacle'),
(@CREATURE_ENTRY, 3, 2, 'Odyn values these creatures?', 14, 0, 20, 0, 0, 54372, '102662', 'Helya looses tentacle'),
(@CREATURE_ENTRY, 3, 3, 'No! This is not possible!', 14, 0, 20, 0, 0, 54389, '102223', 'Helya looses tentacle'),
(@CREATURE_ENTRY, 3, 4, 'What manner of creatures ARE you??', 14, 0, 20, 0, 0, 54390, '102227', 'Helya looses tentacle'),
(@CREATURE_ENTRY, 4, 0, 'An eternity of agony awaits you.', 14, 0, 25, 0, 0, 54399, '102229', 'Helya casts Corrupted Bellow'),
(@CREATURE_ENTRY, 4, 1, 'I will drown you all like rats!', 14, 0, 25, 0, 0, 54400, '102218', 'Helya casts Corrupted Bellow'),
(@CREATURE_ENTRY, 4, 2, 'Hold still!', 14, 0, 25, 0, 0, 54401, '102219', 'Helya casts Corrupted Bellow'),
(@CREATURE_ENTRY, 4, 3, 'Stop squirming!', 14, 0, 25, 0, 0, 54402, '102220', 'Helya casts Corrupted Bellow'),
(@CREATURE_ENTRY, 5, 0, 'Begone to the next life.', 14, 0, 50, 0, 0, 54393, '102216', 'Helya kills player'),
(@CREATURE_ENTRY, 5, 1, 'Your soul will not find shelter here.', 14, 0, 50, 0, 0, 54394, '102215', 'Helya kills player'),
(@CREATURE_ENTRY, 6, 0, 'It is finished. I banish your weak, mortal souls forevermore.', 14, 0, 100, 0, 0, 54243, '102214', 'Helya wipes party'),
(@CREATURE_ENTRY, 7, 0, 'Do you think you have won? You have merely survived the storm... The seas are unstoppable.', 14, 0, 100, 0, 0, 54396, '102661', 'Helya defeated');
