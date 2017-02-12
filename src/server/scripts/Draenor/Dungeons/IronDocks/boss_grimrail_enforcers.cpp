/*
 * Copyright (C) 2014-2017 StormCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "iron_docks.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"

enum Spells
{
};

enum Texts
{
    SAY_INTRO = 0,
};

enum Events
{
    EVENT_MOVE_HOME = 1,
    EVENT_TALK_INTRO,
};

enum Phases
{
    PHASE_INTRO = 1,
    PHASE_COMBAT,
};

enum MovePoints
{
    POINT_ESCAPE_TRAIN = 1,
    POINT_HOME_POSITION,
};

Position const AhriokJumpPos = { 6518.6f,  -1174.51f, 12.4305f };
Position const MakoggJumpPos = { 6508.75f, -1175.21f, 12.4305f };
Position const NeesaJumpPos  = { 6499.82f, -1175.17f, 12.4305f };

Position const AhriokHomePos = { 6514.702f, -1134.09f,  4.958493f };
Position const MakoggHomePos = { 6508.09f,  -1128.319f, 4.958493f };
Position const NeesaHomePos  = { 6502.828f, -1133.913f, 4.958484f };


class boss_ahriok_dugru : public CreatureScript
{
public:
    boss_ahriok_dugru() : CreatureScript("boss_ahriok_dugru") { }

    struct boss_ahriok_dugruAI : public BossAI
    {
        boss_ahriok_dugruAI(Creature* creature) : BossAI(creature, DATA_AHRIOK)
        {
            _grimrailEscaped = false;
        }

        bool _grimrailEscaped;

        void Reset() override
        {
            _Reset();
            if (_grimrailEscaped)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_RELEASE_ENFORCERS:
                    me->ExitVehicle();
                    me->SendSetPlayHoverAnim(true);
                    me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(),
                        me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation()); // temphack until vehicle exit locations are calculated properly
                    me->GetMotionMaster()->MoveJump(AhriokJumpPos, 12.95f * 2, 1.0f, POINT_ESCAPE_TRAIN);
                    events.SetPhase(PHASE_INTRO);
                    _grimrailEscaped = true;
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
                case POINT_ESCAPE_TRAIN:
                    events.ScheduleEvent(EVENT_MOVE_HOME, 1);
                    break;
                case POINT_HOME_POSITION:
                    events.ScheduleEvent(EVENT_TALK_INTRO, 6000);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !(events.IsInPhase(PHASE_INTRO)))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_HOME:
                        me->SendSetPlayHoverAnim(false);
                        me->SetHomePosition(AhriokHomePos);
                        me->GetMotionMaster()->MovePoint(POINT_HOME_POSITION, me->GetHomePosition(), true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        break;
                    case EVENT_TALK_INTRO:
                        Talk(SAY_INTRO);
                        events.SetPhase(PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_ahriok_dugruAI>(creature);
    }
};

class boss_makogg_emberblade : public CreatureScript
{
public:
    boss_makogg_emberblade() : CreatureScript("boss_makogg_emberblade") { }

    struct boss_makogg_emberbladeAI : public BossAI
    {
        boss_makogg_emberbladeAI(Creature* creature) : BossAI(creature, DATA_MAKOGG)
        {
            _grimrailEscaped = false;
        }

        bool _grimrailEscaped;

        void Reset() override
        {
            _Reset();
            if (_grimrailEscaped)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_RELEASE_ENFORCERS:
                    me->ExitVehicle();
                    me->SendSetPlayHoverAnim(true);
                    me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(),
                        me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation()); // temphack until vehicle exit locations are calculated properly
                    me->GetMotionMaster()->MoveJump(MakoggJumpPos, 12.95f * 2, 1.0f, POINT_ESCAPE_TRAIN);
                    events.SetPhase(PHASE_INTRO);
                    _grimrailEscaped = true;
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
                case POINT_ESCAPE_TRAIN:
                    events.ScheduleEvent(EVENT_MOVE_HOME, 1);
                    break;
                case POINT_HOME_POSITION:
                    events.ScheduleEvent(EVENT_TALK_INTRO, 10000);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !(events.IsInPhase(PHASE_INTRO)))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_HOME:
                        me->SendSetPlayHoverAnim(false);
                        me->SetHomePosition(MakoggHomePos);
                        me->GetMotionMaster()->MovePoint(POINT_HOME_POSITION, me->GetHomePosition(), true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        break;
                    case EVENT_TALK_INTRO:
                        Talk(SAY_INTRO);
                        events.SetPhase(PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_makogg_emberbladeAI>(creature);
    }
};

class boss_neesa_nox : public CreatureScript
{
public:
    boss_neesa_nox() : CreatureScript("boss_neesa_nox") { }

    struct boss_neesa_noxAI : public BossAI
    {
        boss_neesa_noxAI(Creature* creature) : BossAI(creature, DATA_NEESA)
        {
            _grimrailEscaped = false;
        }

        bool _grimrailEscaped;

        void Reset() override
        {
            _Reset();
            if (_grimrailEscaped)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_RELEASE_ENFORCERS:
                    me->ExitVehicle();
                    me->SendSetPlayHoverAnim(true);
                    me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(),
                        me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation()); // temphack until vehicle exit locations are calculated properly
                    me->GetMotionMaster()->MoveJump(NeesaJumpPos, 12.95f * 2, 1.0f, POINT_ESCAPE_TRAIN);
                    events.SetPhase(PHASE_INTRO);
                    _grimrailEscaped = true;
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
                case POINT_ESCAPE_TRAIN:
                    events.ScheduleEvent(EVENT_MOVE_HOME, 1);
                    break;
                case POINT_HOME_POSITION:
                    events.ScheduleEvent(EVENT_TALK_INTRO, 10000);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !(events.IsInPhase(PHASE_INTRO)))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_HOME:
                        me->SendSetPlayHoverAnim(false);
                        me->SetHomePosition(NeesaHomePos);
                        me->GetMotionMaster()->MovePoint(POINT_HOME_POSITION, me->GetHomePosition(), true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        break;
                    case EVENT_TALK_INTRO:
                        Talk(SAY_INTRO);
                        events.SetPhase(PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_neesa_noxAI>(creature);
    }
};

// This AI-Script is a placeholder for the ability sequencer for future implementations

class npc_ability_sequencer : public CreatureScript
{
public:
    npc_ability_sequencer() : CreatureScript("npc_ability_sequencer") { }

    struct npc_ability_sequencerAI : public BossAI
    {
        npc_ability_sequencerAI(Creature* creature) : BossAI(creature, DATA_GRIMRAIL_ENFORCER)
        {
        }

        void Reset() override
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            /*
            switch (action)
            {
                case 0:
                    break;
                default:
                    break;
            }
            */
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 0:
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<npc_ability_sequencerAI>(creature);
    }
};

void AddSC_boss_grimrail_enforcers()
{
    new boss_ahriok_dugru();
    new boss_makogg_emberblade();
    new boss_neesa_nox();
    new npc_ability_sequencer();
}
