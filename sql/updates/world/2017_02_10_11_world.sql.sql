SET @CGUID := 1369140;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+108;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+1, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper
(@CGUID+2, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+3, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+4, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+5, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Slaver
(@CGUID+6, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Slaver
(@CGUID+7, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+8, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+9, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+10, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Slaver
(@CGUID+11, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+12, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+13, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+14, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+15, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+16, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+17, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+18, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+19, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+20, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+21, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Captured Shieldmaiden
(@CGUID+22, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+23, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+24, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+25, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+26, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+27, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+28, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+29, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+30, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+31, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+32, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+33, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper
(@CGUID+34, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+35, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Slaver
(@CGUID+36, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Captured Runecarver
(@CGUID+37, 0, 0, 50331648, 1, 3, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Dive
(@CGUID+38, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+39, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper 
(@CGUID+40, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+41, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+42, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+43, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+44, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+45, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Ymiron, the Fallen King
(@CGUID+46, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+47, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+48, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+49, 0, 0, 8, 1, 3, 0, 0, 0, ''), -- Runecarver Slave 
(@CGUID+50, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Cursed Falke 
(@CGUID+51, 0, 0, 50331648, 1, 3, 0, 0, 0, '191889'), -- Cursed Falke , 191889 - Dive
(@CGUID+52, 0, 0, 0, 1, 3, 0, 0, 0, '203605'), -- Night Watch Mariner - 203605 - Fencing
(@CGUID+53, 0, 0, 50331648, 1, 3, 0, 0, 0, '191889'), -- Cursed Falke , 191889 - Dive
(@CGUID+54, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Mistmender - 199514 - Torrent of Souls
(@CGUID+55, 0, 0, 0, 1, 3, 0, 0, 0, '145953'), -- Shroud Hound , 145953 - Cosmetic - Sleep Zzz
(@CGUID+56, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+57, 0, 0, 0, 1, 3, 0, 0, 0, '195219 197227 42459'), -- Seacursed Swiftblade , 195219 - Eye Patch, 197227 - Kneeling, 42459 - Dual Wield
(@CGUID+58, 0, 0, 50331648, 1, 3, 0, 0, 0, '191889'), -- Cursed Falke , 191889 - Dive
(@CGUID+59, 0, 0, 0, 0, 3, 0, 0, 0, ''), -- Seacursed Mistmender 
(@CGUID+60, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Waterlogged Soul Guard 
(@CGUID+61, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Shroud Hound 
(@CGUID+62, 0, 0, 0, 0, 3, 0, 0, 0, ''), -- Harbaron 
(@CGUID+63, 0, 0, 0, 1, 3, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade , 195219 - Eye Patch, 42459 - Dual Wield
(@CGUID+64, 0, 0, 0, 1, 3, 0, 0, 0, '194583'), -- The Grimewalker , 194583 - Bone Hammer
(@CGUID+65, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Shroud Hound 
(@CGUID+66, 0, 0, 50331648, 1, 3, 0, 0, 0, '191889'), -- Cursed Falke , 191889 - Dive
(@CGUID+67, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Waterlogged Soul Guard 
(@CGUID+68, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper 
(@CGUID+69, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Shroud Hound 
(@CGUID+70, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Swiftblade
(@CGUID+71, 0, 0, 0, 1, 3, 0, 0, 0, '145953'), -- Shroud Hound , 145953 - Cosmetic - Sleep Zzz
(@CGUID+72, 0, 0, 0, 1, 3, 0, 0, 0, '203038'), -- Fallen Shieldmaiden , 203038 - Fallen Vrykul
(@CGUID+73, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+74, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+75, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+76, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Swiftblade
(@CGUID+77, 0, 0, 0, 1, 3, 0, 0, 0, '145953'), -- Shroud Hound , 145953 - Cosmetic - Sleep Zzz
(@CGUID+78, 0, 0, 0, 1, 3, 0, 0, 0, '42459'), -- Helarjar Champion , 42459 - Dual Wield
(@CGUID+79, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+80, 0, 0, 0, 1, 3, 0, 0, 0, '199867 203605 67236'), -- Night Watch Mariner , 199867 - Helmet, 203605 - Fencing, 67236 - Invisibility and Stealth Detection
(@CGUID+81, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+82, 0, 0, 0, 1, 3, 0, 0, 0, '198395'), -- Skeletal Warrior , 198395 - Rage
(@CGUID+83, 0, 0, 0, 1, 3, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade , 195219 - Eye Patch, 42459 - Dual Wield
(@CGUID+84, 0, 0, 0, 1, 3, 0, 0, 0, '145953'), -- Shroud Hound , 145953 - Cosmetic - Sleep Zzz
(@CGUID+85, 0, 0, 0, 1, 3, 0, 0, 0, '42459'), -- Helarjar Champion , 42459 - Dual Wield
(@CGUID+86, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+87, 0, 0, 50331648, 1, 3, 0, 0, 0, ''), -- Captured Val'kyr
(@CGUID+88, 0, 0, 50331648, 1, 3, 0, 0, 0, '191835'), -- Cursed Falke , 191835 - Helheim
(@CGUID+89, 0, 0, 0, 1, 3, 0, 0, 0, '195219'), -- Seacursed Swiftblade - 195219 - Eye Patch
(@CGUID+90, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Mistcaller 
(@CGUID+91, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Champion 
(@CGUID+92, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Skjal
(@CGUID+93, 0, 0, 0, 1, 3, 0, 0, 0, '42459'), -- Helarjar Champion - 42459 - Dual Wield
(@CGUID+94, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Mistmender 
(@CGUID+95, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Mistcaller 
(@CGUID+96, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper 
(@CGUID+97, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Champion 
(@CGUID+98, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Mistmender 
(@CGUID+99, 0, 0, 0, 1, 3, 0, 0, 0, '195219'), -- Seacursed Swiftblade , 195219 - Eye Patch
(@CGUID+100, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Seacursed Soulkeeper 
(@CGUID+101, 0, 0, 0, 1, 3, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade , 195219 - Eye Patch, 42459 - Dual Wield
(@CGUID+102, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Mistcaller
(@CGUID+103, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Mistcaller
(@CGUID+104, 0, 0, 0, 1, 3, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade , 195219 - Eye Patch, 42459 - Dual Wield
(@CGUID+105, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helya - 194603 - Soulless Scream
(@CGUID+106, 0, 0, 33554432, 1, 3, 0, 0, 0, ''), -- -Unknown-
(@CGUID+107, 0, 0, 0, 1, 3, 0, 0, 0, ''), -- Helarjar Berserker
(@CGUID+108, 0, 0, 0, 1, 3, 0, 0, 0, ''); -- Kelp Scuttler