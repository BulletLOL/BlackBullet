#pragma once
#include "cClasses.h"
#include "Classes.h"
#include "cMath.h"
#include "Functions.h"
#include "XorStr.h"
#include "Includes.h"
#include "MenuClasses.h"

bool pNear(Vec3 vEntityPos)
{
    if (!IRenderer::Singleton()) return false;
    Vec3 vCameraPos = IRenderer::Singleton()->GetViewCamera();
    bool bProximityZ = abs(vCameraPos.z - vEntityPos.z) <= 1.5f;
    vCameraPos.z = vEntityPos.z = 0.f;
    bool bProximityXY = (vCameraPos - vEntityPos).GetLength() <= 1.25f;
    return bProximityXY && bProximityZ;
}
bool EnevyDead(IActor* mPactor, IActor* pIActor) {
    return (pIActor == mPactor || pIActor->IsDead());
}
float climbextra = 20.0f;
std::list<IEntity*> spawnedEntites;

void ESP()
{
    DWORD Visibility;
    Vec3 max_pos = ZERO;
    IActor* Me_Actor = IGameFramework::Singleton()->get_cli_actor();
    if (!Me_Actor) return;
    IMovementController* pMovind = Me_Actor->GetMovementController();
    if (!pMovind) return;
    IEntitySystem* pEnti_Sustem = SSystemGlobalEnvironment::Singleton()->GetIEntitySystem();
    if (!pEnti_Sustem) return;
    IEntityIt* p_enbti_it = pEnti_Sustem->GetEntityIterator();
    if (!p_enbti_it) return;
    IEntity* pLocalEntity = Me_Actor->m_pEntity;
    if (!pLocalEntity) return;

    if (!IGame::Singleton()) return;

    IItem* m_Item = Me_Actor->get_cureentrs_items();

    if (m_Item && m_Item->GetIWeaponEntity())
    {
        IWeapon* pWeapon = m_Item->GetIWeapon();
        if (!pWeapon) return;
        while (IEntity* p_entit_cl = p_enbti_it->Next())
        {
            IEntityClass* pEntityClass = p_entit_cl->GetEntityClass();
            IEntityRenderProxy* pRenderProxy = p_entit_cl->GetProxy();
            if (!pRenderProxy || !pEntityClass) continue;
            uint32 RenderFlags = pRenderProxy->GetFlags();
            const char* ClassName = pEntityClass->GetIClassName();
            const char* Name = p_entit_cl->GetName();
            IPhysicalWorld* getphysicalworld = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld();
            if (IActor* pActor = IGameFramework::Singleton()->GetActor(p_entit_cl->GetEntityId()))
            {
                if (EnevyDead(Me_Actor, pActor)) continue;
                if (IGameFramework::Singleton()->IsMyTeam(Me_Actor, pActor)) continue;
                Vec3 vBonePos = ZERO;
                int nBoneId = 0;

                if (MV.Bouton.Silhouettes)
                {
                    pRenderProxy->SetHUDSilhouettesParams(255, 255, 000, 000); break;//Red
                }
            }
        }
    }
}