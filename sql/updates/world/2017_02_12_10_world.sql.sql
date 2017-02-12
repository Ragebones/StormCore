DELETE FROM `spell_script_names` WHERE `spell_id`=108416;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (108416, 'spell_warl_dark_pact');

DELETE FROM `spell_script_names` WHERE `spell_id`=198590;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (198590, 'spell_warl_drain_soul');

DELETE FROM `gameobject_template` WHERE `entry`= 181621;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES ('181621', '22', '7359', 'Soulwell', '', '', '', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'go_soulwell', '22566');

DELETE FROM `spell_script_names` WHERE `spell_id`=6262;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (198590, 'spell_warl_healthstone');

DELETE FROM `spell_script_names` WHERE `spell_id`=172;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (108416, 'spell_warl_corruption');

DELETE FROM `spell_script_names` WHERE `spell_id`=205179;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (205179, 205246);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (205179, 'spell_warl_phantom_singularity');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (205246, 'spell_warl_phantom_singularity_dot');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (348, 193541);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (348, 'spell_warl_immolate');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (193541, 'spell_warl_immolate');