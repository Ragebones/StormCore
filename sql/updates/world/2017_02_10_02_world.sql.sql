UPDATE `gameobject_template` SET `Data0`=130702, `Data5`=0 WHERE `entry`=215457;
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=215457;

DELETE FROM `spell_target_position` WHERE `ID`=130702;
INSERT INTO `spell_target_position` VALUES
(130702,0,870,-298.999,-1172.299,61.593,23360);