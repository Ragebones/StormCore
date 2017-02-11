-- [NPC] Harbaron -- http://www.wowhead.com/npc=96754
SET @CREATURE_ENTRY := 96754;

UPDATE creature_template SET faction = 14, minlevel = 110, maxlevel = 111, ScriptName = 'npc_shackled_servitor' WHERE entry = 98693;

DELETE FROM `creature_text` WHERE `entry` = @CREATURE_ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@CREATURE_ENTRY, 0, 0, 'The spirits grow hungry from the scent of blood.', 14, 0, 100, 0, 0, 54387, '102201', 'Harbaron - Introduction Text'),
(@CREATURE_ENTRY, 1, 0, 'New passengers... New souls. I will guide you to the depths of helheim for a small price: your flesh and blood.', 14, 0, 50, 0, 0, 54373, '102206', 'Harbaron - Entered Combat Text'),
(@CREATURE_ENTRY, 1, 1, 'All who enter Helheim must pay the blood price. Resist if you wish... In the end, I always get my payment!', 14, 0, 50, 0, 0, 54378, '102205', 'Harbaron - Entered Combat Text'),
(@CREATURE_ENTRY, 2, 0, 'The flesh burdens the soul. A nuisance that must be flayed from your bones!', 14, 0, 25, 0, 0, 54384, '102198', 'Harbaron - Casts spell Cosmic Scythe'),
(@CREATURE_ENTRY, 3, 0, 'Spirits! Sweep these mortals into the tides!', 14, 0, 25, 0, 0, 54385, '102199', 'Harbaron - Casts spell Fragment'),
(@CREATURE_ENTRY, 3, 1, 'If I cannot bleed the payment from you, the spirits will!', 14, 0, 25, 0, 0, 54386, '102200', 'Harbaron - Casts spell Fragment'),
(@CREATURE_ENTRY, 4, 0, 'Arise, servitor! Claim our blood debt!', 14, 0, 25, 0, 0, 54388, '102202', 'Harbaron - Casts spell Shackled Servitor'),
(@CREATURE_ENTRY, 5, 0, 'Bend and break, your soul I\'ll take!', 14, 0, 16.5, 0, 0, 54374, '102197', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 5, 1, 'You see now the weakness in your mortal shell?', 14, 0, 16.5, 0, 0, 54375, '102196', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 5, 2, 'No one rides for free!', 14, 0, 16.5, 0, 0, 54380, '102659', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 5, 3, 'As I said... I always get my payment!', 14, 0, 16.5, 0, 0, 54381, '102207', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 5, 4, 'Another blood debt claimed... Another soul cast into the abyss.', 14, 0, 16.5, 0, 0, 54382, '102208', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 5, 5, 'Everyone must pay the blood price!', 14, 0, 16.5, 0, 0, 54383, '102209', 'Harbaron - Kills Player'),
(@CREATURE_ENTRY, 6, 0, 'Life... death... I am but one ripple in the eternal ebb and flow...', 14, 0, 33, 0, 0, 54376, '102660', 'Harbaron - Combat Ended, Creature Dead'),
(@CREATURE_ENTRY, 6, 1, 'Now... it is I who must pay... the blood price...', 14, 0, 33, 0, 0, 54377, '102210', 'Harbaron - Combat Ended, Creature Dead'),
(@CREATURE_ENTRY, 6, 2, 'Helya will make you pay... In the end, everyone pays...', 14, 0, 33, 0, 0, 54379, '102211', 'Harbaron - Combat Ended, Creature Dead');