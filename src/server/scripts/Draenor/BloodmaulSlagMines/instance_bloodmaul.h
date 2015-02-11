////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2015 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INSTANCE_BLOODMAUL_H
# define INSTANCE_BLOODMAUL_H

# include "ScriptUtils.h"

namespace MS
{
    namespace Instances
    {
        namespace Bloodmaul
        {
            enum BossIds
            {
                BossSlaveWatcherCrushto,
                BossForgemasterGogduh,
                BossRoltall,
                BossGugrokk
            };

            enum MobEntries
            {
                MinesBat                = 75374,
                BloodmaulEnforcer       = 84978,
                BloodmaulOverseer       = 75426,
                BloodmaulSlaver         = 75191,
                BloodmaulOverseer2      = 75193,
                BloodmaulGeomancer      = 75198,
                BloodmaulEnforcer2      = 84978,
                BloodmaulWarder         = 75210,
                BloodmaulOgreMage       = 75272,
                EarthCrushStalker       = 83650,
                CapturedMiner1          = 74355,
                CapturedMiner2          = 74356,
                CapturedMiner3          = 74357,
                HordeMinerSpawn         = 75585,
                NeutralMinerSpawn       = 75586,
                AllianceMinerSpawn      = 75584,
                SlaveWatcherCrushto     = 74787,

                OgreWheelStalker        = 75499,
                Slagna                  = 75406,
                MoltenEarthElemental    = 75209,
                FirePillar              = 75327,
                SearingEmber            = 75360,
                LavaExplosionStalker    = 75846,
                MagmaLord               = 75211,

                /// Roltall
                Roltall                 = 75786,
                FieryBoulder1           = 75853,
                FieryBoulder2           = 75854,
                FieryBoulder3           = 75828,

                /// Gug'rokk
                Gugrokk                 = 74790,
                SLGGenricMoPLargeAoI    = 68553,
                UnstableSlag            = 74927
            };

            enum GameObjects
            {
                RoltallEntranceWall = 224643,
                RoltallExitWall     = 225693,
                RoltallBridge       = 224487
            };

            enum Data
            {
                RaiseTheMiners,
                RaiseTheMinersChangeTarget,
                SpawnSlagna
            };

            enum Talks
            {
                WarderAttack            = 0,
                CapturedMinerReleased   = 0
            };

            enum eAchievements
            {
                IsDraenorOnFire = 9008
            };

            namespace SlaverWatcherCrushto
            {
                enum Texts
                {
                    TalkIntro
                };
            }
        }
    }
}

#endif /* !INSTANCE_BLOODMAUL_H */