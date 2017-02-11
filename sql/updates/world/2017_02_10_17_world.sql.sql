DELETE FROM `gameobject_template` WHERE `entry`=246779;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(246779, 49, 11554, 'Font of Power', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23222); -- Font of Power

UPDATE `gameobject_template` SET `VerifiedBuild`=23222 WHERE `entry` IN (246947, 246838, 246987, 246843, 246919, 245067, 245063, 245064, 245065, 246948, 245609, 246834, 246988, 246125, 245062, 246435, 246842, 245066, 246888, 246836, 246989, 243403, 247041, 243842, 265476, 246839, 246985, 246840, 251963, 253001, 246890, 246835, 251960, 246889, 246837, 246844, 246841, 265477, 246763, 246986, 224697);

UPDATE `gameobject_template` SET `VerifiedBuild`=23222 WHERE `entry`=252680; -- Challenger's Cache
UPDATE `gameobject_template` SET `VerifiedBuild`=23222 WHERE `entry`=239323; -- Challenge Mode - Start Door (Line 2.35)
UPDATE `gameobject_template` SET `VerifiedBuild`=23222 WHERE `entry`=249462; -- Crate of Dragur Dust
UPDATE `gameobject_template` SET `VerifiedBuild`=23222 WHERE `entry`=252681; -- Superior Challenger's Cache
DELETE FROM `gameobject_template` WHERE `entry` IN (267034 /*Portal to Stormheim*/, 252682 /*Peerless Challenger's Cache*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(267034, 22, 15196, 'Portal to Stormheim', '', '', '', 0.5, 233512, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23222), -- Portal to Stormheim
(252682, 3, 33268, 'Peerless Challenger''s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 1824, 0, 1, 0, 0, 68449, 0, 5, 110, 23222); -- Peerless Challenger's Cache

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (252680 /*Challenger's Cache*/, 252681 /*Superior Challenger's Cache*/, 252682 /*Peerless Challenger's Cache*/, 249462 /*Crate of Dragur Dust*/, 239323 /*Challenge Mode - Start Door (Line 2.35)*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(252680, 94, 16416), -- Challenger's Cache
(252681, 94, 16416), -- Superior Challenger's Cache
(252682, 94, 16416), -- Peerless Challenger's Cache
(249462, 0, 4), -- Crate of Dragur Dust
(239323, 1375, 0); -- Challenge Mode - Start Door (Line 2.35)

UPDATE gameobject_template SET ScriptName = 'legion_instance_teleporter' WHERE entry = 252145;