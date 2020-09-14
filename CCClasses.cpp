#include "cClasses.h"
#include "cMath.h"

void I3DEngine::SetPostEffectParam(const char* pParam, float fValue, bool bForceValue)
{
	CallFunction<void(__thiscall*)(PVOID, const char*, float, bool)>(this, RE_I3DEngine_SetPostEffectParam)(this, pParam, fValue, bForceValue);
}

IRenderer* SSystemGlobalEnvironment::GetIRenderer()
{
	return (IRenderer*)*(DWORD64*)((DWORD64)this + LIRenderer);
}

I3DEngine* SSystemGlobalEnvironment::Get3DEngine()
{
	return (I3DEngine*)*(DWORD64*)((DWORD64)this + LI3DEngine);
}

IPhysicalWorld* SSystemGlobalEnvironment::GetIPhysicalWorld()
{
	return (IPhysicalWorld*)*(DWORD64*)((DWORD64)this + LIPhysicalWorld);
}

IEntitySystem* SSystemGlobalEnvironment::GetIEntitySystem()
{
	return (IEntitySystem*)*(DWORD64*)((DWORD64)this + LIEntitySystem);
}

IGame* SSystemGlobalEnvironment::GetIGame()
{
	return (IGame*)*(DWORD64*)((DWORD64)this + BB_IGame);
}

ISystem* SSystemGlobalEnvironment::GetSystem()
{
	return (ISystem*)*(DWORD64*)((DWORD64)this + LISystem);
}

SSystemGlobalEnvironment* SSystemGlobalEnvironment::Singleton()
{
	return *(SSystemGlobalEnvironment**)BB_SystemGL;
}

void* IPhysicalEntity::GetForeignData(int itype)
{
	return CallFunction<void* (__thiscall*)(PVOID, int)>(this, RE_IPhysicalEntity_GetForeignData)(this, itype);
}

int IPhysicalWorld::GetEntitiesAround(const Vec3& ptmin, const Vec3& ptmax, IPhysicalEntity**& pList, int objtypes, IPhysicalEntity* pPetitioner, int szListPrealloc, int iCaller)
{
	return ((char(__thiscall*)(IPhysicalWorld*, const Vec3&, const Vec3&, IPhysicalEntity**&, int, IPhysicalEntity*, int, int))0x140AEA740)(this, ptmin, ptmax, pList, objtypes, pPetitioner, szListPrealloc, iCaller);
}

int IPhysicalWorld::RayWorldIntersection(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts, int nSkipEnts, void* pForeignData, int iForeignData, const char* pNameTag, ray_hit_cached* phitLast, int iCaller)
{
	using oRayWorldIntersection = int(__fastcall*)(PVOID, const Vec3&, const Vec3&, int, unsigned int, ray_hit*, int, IPhysicalEntity**, int, void*, int, const char*, ray_hit_cached*, int);
	return CallFunction<oRayWorldIntersection>(this, RE_IPhysicalWorld_RayWorldIntersection)(this, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
}

int IPhysicalWorld::RayWorldIntersectionParams(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts, int nSkipEnts, void* pForeignData, int iForeignData, const char* pNameTag, ray_hit_cached* phitLast, int iCaller)
{
	using oRayWorldIntersection = int(__fastcall*)(PVOID, const Vec3&, const Vec3&, int, unsigned int, ray_hit*, int, IPhysicalEntity**, int, void*, int, const char*, ray_hit_cached*, int);
	return CallFunction<oRayWorldIntersection>(this, RE_IPhysicalWorld_RayWorldIntersectionParams)(this, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
}

Vec3 IPhysicalWorld::GetMPos(Vec3 BoneID, Vec3 CamPos, FLOAT Correct)
{
	Vec3 vOut = BoneID - CamPos;
	FLOAT sqr = (FLOAT)sqrt(vOut.x * vOut.x + vOut.y * vOut.y + vOut.z * vOut.z);
	vOut /= sqr;
	vOut *= sqr - Correct;
	return vOut;
}

BOOL IPhysicalWorld::IsVisible(Vec3 BoneID, FLOAT Correct)
{
	ray_hit tmpHit;
	Vec3 CamPos = IRenderer::Singleton()->GetViewCamera();
	Vec3 vOut(GetMPos(BoneID, CamPos, Correct));
	return !this->RayWorldIntersectionParams(CamPos, vOut, 0x100 | 1, 0xA | 0x400, &tmpHit, 1);
}

INT IPhysicalWorld::IsVisible(Vec3 p_BoneID, Vec3 m_BoneID)
{
	ray_hit tmpHit;
	return !this->RayWorldIntersectionParams(m_BoneID, p_BoneID - m_BoneID, 779, (10 & 0x0F), &tmpHit, 1);
}

float ITimer::GetCurrTime(ETimer which)
{
	return CallFunction<float(__thiscall*)(PVOID, ETimer)>(this, RE_ITimer_GetCurrTime)(this, which);
}

float ITimer::GetAsyncCurTime()
{
	return CallFunction<float(__thiscall*)(PVOID)>(this, RE_ITimer_GetAsyncCurTime)(this);
}

const char* ISurfaceType::GetName()
{
	return CallFunction<const char* (__thiscall*)(PVOID)>(this, RE_ISurfaceType_GetName)(this);
}

int IGameRules::GetTeam(EntityId entityId)
{
	return CallFunction<int(__thiscall*)(PVOID, EntityId)>(this, RE_IGameRules_GetTeam)(this, entityId);
}

void IGameRules::SetTeam(int teamId, EntityId entityId)
{
	CallFunction<void(__thiscall*)(PVOID, int, EntityId)>(this, RE_IGameRules_SetTeam)(this, teamId, entityId);
}

void IGameRules::SendCommunicationEvent(UINT eventType, EntityId sender)
{
	CallFunction<void(__thiscall*)(PVOID, UINT, EntityId, UINT)>(this, RE_IGameRules_SendCommunicationEvent)(this, eventType, sender, 0);
}

int IGameRules::GetHitTypeId(const char* type)
{
	return CallFunction<int(__thiscall*)(PVOID, const char*)>(this, RE_IGameRules_GetHitTypeId)(this, type);
}

void IGameRules::RequestHit(HitInfo* pHitInfo)
{
	CallFunction<void(__thiscall*)(PVOID, HitInfo*)>(this, RE_IGameRules_RequestHit)(this, pHitInfo);
}

ISurfaceType* IGameRules::GetHitMaterial(int materialId)
{
	return CallFunction<ISurfaceType* (__thiscall*)(PVOID, int)>(this, RE_IGameRules_GetHitMaterial)(this, materialId);
}

int IGameRules::GetHitMaterialId(const char* materialName)
{
	return CallFunction<int(__thiscall*)(PVOID, const char*)>(this, RE_IGameRules_GetHitMaterialId)(this, materialName);
}

IGame* IGame::Singleton()
{
	return *(IGame**)BB_IGame;
}

void IGame::SetPlayer(int GameFunction, float Value)
{
	switch (GameFunction)
	{
	case ClimbExtraHeight:
		if (DWORD64 v0 = *(DWORD64*)(*(DWORD64*)(*(DWORD64*)((DWORD64)this + 0x288) + 0x8) + 0x8))
		{
			*(float*)(v0 + 0x1C) = 2.25f + Value;
		}
		break;
	case SlideMultDistance:
		if (DWORD64 v0 = *(DWORD64*)(*(DWORD64*)(*(DWORD64*)((DWORD64)this + 0x288) + 0x8) + 0x10))
		{
			*(float*)(v0 + 0x54) = Value;
		}
		break;
	case AntiAfk:
		if (DWORD64 v0 = *(DWORD64*)(*(DWORD64*)((DWORD64)this + 0x320) + 0x10))
		{
			*(float*)(v0) = Value;
		}
		break;
	}
}

CWeaponSystem* IGame::GetWeaponSystem()
{
	return CallFunction<CWeaponSystem* (__thiscall*)(PVOID)>(this, RE_IGame_GetWeaponSystem)(this);
}

IGameFramework* IGameFramework::Singleton()
{
	return *(IGameFramework**)BB_IGameFramework;
}

BOOL IGameFramework::get_cli_actor(IActor** pActor)
{
	using GetClientActorP = BOOL(__fastcall*)(PVOID64, IActor**);
	return CallFunction<GetClientActorP >(this, RE_IGameFramework_GetClientActor)(this, pActor);
}

IActor* IGameFramework::get_cli_actor()
{
	IActor* pLocalActor = NULL;
	bool bGetActorResult = CallFunction<bool(__thiscall*)(PVOID, IActor**)>(this, RE_IGameFramework_GetClientActor)(this, &pLocalActor);
	if (!bGetActorResult) pLocalActor = NULL;
	return pLocalActor;
}

IEntitySystem* IGameFramework::GetIEntitySystem()
{
	return (IEntitySystem*)*(DWORD64*)((DWORD64)this + RE_IGameFramework_GetIEntitySystem);
}

IActorSystem* IGameFramework::GetActorSystem()
{
	return CallFunction<IActorSystem* (__thiscall*)(PVOID)>(this, RE_IGameFramework_GetActorSystem)(this);
}

IItemSystem* IGameFramework::GetIItemSystem()
{
	return CallFunction<IItemSystem* (__thiscall*)(PVOID)>(this, RE_IGameFramework_GetIItemSystem)(this);
}

IGameRules* IGameFramework::get_GAME_RULES()
{
	return CallFunction<IGameRules* (__thiscall*)(PVOID)>(this, RE_IGameFramework_GetGameRules)(this);
}

IActor* IGameFramework::GetActor(EntityId actorId)
{
	IActor* pActor = this->GetActorSystem()->GetActor(actorId);
	if (!pActor)
		return NULL;

	return static_cast<IActor*>(pActor);
}

bool IGameFramework::IsMyTeam(IActor* mActor, IActor* pActor) {
	auto mTeam = this->get_GAME_RULES()->GetTeam(mActor->GetEntity()->GetEntityId());
	auto pTeam = this->get_GAME_RULES()->GetTeam(pActor->GetEntity()->GetEntityId());
	return !(mTeam != pTeam || pTeam == 0);
}

uint32 IEntityRenderProxy::GetFlags()
{
	return *(uint32*)((DWORD64)this + 0x9C);
}

void IEntityRenderProxy::SetRndFlags(INT flag)
{
	*(DWORD64*)((DWORD64)this + 0x24) = flag;
}

VOID IEntityRenderProxy::SetHUDSilhouettesParams(float a, float r, float g, float b)
{
	CallFunction<void(__fastcall*)(PVOID64, float, float, float, float)>(this, 352)(this, a, r, g, b);
	this->SetRndFlags(eAllMap);
}

QuatT& ISkeletonPose::GetAbsJointByID(int nJointID)
{
	return CallFunction<QuatT& (__thiscall*)(PVOID, int)>(this, RE_ISkeletonPose_GetAbsJointByID)(this, nJointID);
}

void ISkeletonPose::SetAbsJointByID(int nJointID, const QuatT& pose)
{
	CallFunction<void(__thiscall*)(PVOID, int, const QuatT&)>(this, (RE_ISkeletonPose_GetAbsJointByID + 1))(this, nJointID, pose);
}

int16 ISkeletonPose::GetJointIdByName(const char* sz_joint_name)
{
	return CallFunction<int16(__fastcall*)(PVOID64, const char*)>(this, RE_ISkeletonPose_GetJointIDByName)(this, sz_joint_name);
}

EBone ISkeletonPose::GetJointIDByNameParams(const char* boneName)
{
	return CallFunction<EBone(__thiscall*)(PVOID, const char*)>(this, RE_ISkeletonPose_GetJointIDByName)(this, boneName);
}

IPhysicalEntity* ISkeletonPose::GetCharacterPhysics()
{
	return CallFunction<IPhysicalEntity* (__thiscall*)(PVOID)>(this, RE_ISkeletonPhysics_GetCharacterPhysics)(this);
}

ISkeletonPose* ICharacterInstance::GetISkeletonPose()
{
	return CallFunction<ISkeletonPose* (__thiscall*)(PVOID)>(this, RE_ICharacterInstance_GetISkeletonPose)(this);
}

int IEntity::GetFlags()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IEntity_GetFlags)(this);
}

const char* IEntity::GetName()
{
	return CallFunction<const char* (__thiscall*)(PVOID)>(this, RE_IEntity_GetName)(this);
}

bool IEntity::IsHidden()
{
	return CallFunction<bool(__fastcall*)(PVOID64)>(this, RE_IEntity_IsHidden)(this);
}

void IEntity::SetPos(const Vec3& vPos, int nWhyFlags)
{
	CallFunction<void(__thiscall*)(PVOID, const Vec3&, int)>(this, RE_IEntity_SetPos)(this, vPos, nWhyFlags);
}

Matrix34& IEntity::GetWorldTM()
{
	return CallFunction<Matrix34& (__thiscall*)(PVOID)>(this, RE_IEntity_GetWorldTM)(this);
}

void IEntity::GetWorldBounds(AABB& bbox)
{
	CallFunction<void(__thiscall*)(PVOID, AABB&)>(this, RE_IEntity_GetWorldBounds)(this, bbox);
}

void IEntity::SetLocalPos(const Vec3& vPos, int nWhyFlags)
{
	CallFunction<void(__thiscall*)(PVOID, const Vec3&, int)>(this, RE_IEntity_SetLocalPos)(this, vPos, nWhyFlags);
}

void IEntity::SetLocPos(Vec3 vPos)
{
	Matrix34 Matrix = *(Matrix34*)((DWORD64)this + 0x40);
	Matrix.m03 = vPos.x;
	Matrix.m13 = vPos.y;
	Matrix.m23 = vPos.z;
	*(Matrix34*)((DWORD64)this + 0x40) = Matrix;
}

void IEntity::SetRotation(const Vec3& vAngles, int nWhyFlags)
{
	CallFunction<void(__thiscall*)(PVOID, const Vec3&, int)>(this, RE_IEntity_SetRotation)(this, vAngles, nWhyFlags);
}

void IEntity::SetRotationTM(const Quat& rotation, int nWhyFlag)
{
	return CallFunction<void(__fastcall*)(PVOID, const Quat&, int)>(this, RE_IEntity_SetRotation)(this, rotation, nWhyFlag);
}

void IEntity::SetPosRotScale(const Vec3& vPos, const Quat& qRotation, const Vec3& vScale, int nWhyFlags)
{
	CallFunction<void(__fastcall*)(PVOID, const Vec3&, const Quat&, const Vec3&, int)>(this, 33)(this, vPos, qRotation, vScale, nWhyFlags);
}

void IEntity::InvalidateTM(int nWhyFlags)
{
	CallFunction<void(__thiscall*)(PVOID, int)>(this, RE_IEntity_InvalidateTM)(this, nWhyFlags);
}

const Vec3& IEntity::GetRotation()
{
	return CallFunction<const Vec3& (__thiscall*)(PVOID)>(this, RE_IEntity_GetRotation)(this);
}

Quat& IEntity::GetRotationTM()
{
	return CallFunction<Quat& (__fastcall*)(PVOID)>(this, RE_IEntity_GetRotation)(this);
}

void IEntity::SetSlotLocalTM(int nSlot, const Matrix34& localTM, int nWhyFlags)
{
	CallFunction<void(__thiscall*)(PVOID, int, const Matrix34&, int)>(this, RE_IEntity_SetSlotLocalTM)(this, nSlot, localTM, nWhyFlags);
}

int IEntity::GetSlotCount()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IEntity_GetSlotCount)(this);
}

const Matrix34& IEntity::GetSlotLocalTM(int nSlot, bool bRelativeToParent)
{
	return CallFunction<const Matrix34& (__thiscall*)(PVOID, int, bool)>(this, RE_IEntity_GetSlotLocalTM)(this, nSlot, bRelativeToParent);
}

int IEntity::LoadCharacter(int nSlot, const char* sFilename, int nLoadFlags)
{
	return CallFunction<int(__thiscall*)(PVOID, int, const char*, int)>(this, RE_IEntity_LoadCharacter)(this, nSlot, sFilename, nLoadFlags);
}

int IEntity::LoadGeometry(int nSlot, const char* sFilename, const char* sGeomName, int nLoadFlags)
{
	return CallFunction<int(__thiscall*)(PVOID, int, const char*, const char*, int)>(this, RE_IEntity_LoadGeometry)(this, nSlot, sFilename, sGeomName, nLoadFlags);
}

EntityId IEntity::GetEntityId()
{
	return CallFunction<EntityId(__thiscall*)(PVOID)>(this, RE_IEntity_GetID)(this);
}

IEntityClass* IEntity::GetEntityClass()
{
	return CallFunction<IEntityClass* (__fastcall*)(PVOID64)>(this, RE_IEntity_GetEntityClass)(this);
}

ICharacterInstance* IEntity::GetCharacter(int nSlot)
{
	return CallFunction<ICharacterInstance* (__thiscall*)(PVOID, int)>(this, RE_IEntity_GetCharacter)(this, nSlot);
}

IEntityRenderProxy* IEntity::GetProxy(EEntityProxy proxy)
{
	return CallFunction<IEntityRenderProxy* (__thiscall*)(PVOID, int)>(this, RE_IEntity_GetProxy)(this, proxy);
}

void IEntity::SetHUDSilhouettesParams(f32 a, f32 r, f32 g, f32 b)
{
	if (IEntityRenderProxy* pRenderProxy = this->GetProxy())
	{
		DWORD64 v34 = (*(DWORD64(__thiscall**)(IEntityRenderProxy*))(*(DWORD64*)pRenderProxy + 0x20))(pRenderProxy);
		pRenderProxy->SetHUDSilhouettesParams(a, r, g, b);
		*(DWORD*)(v34 + 0x10) |= eAllMap;
	}
}

Vec3 IEntity::GetWorldPos() {
	Matrix34 m = this->GetWorldTM();
	return m.GetTranslation();
}

Vec3 IEntity::GetBonePos(EBone eBone)
{
	ICharacterInstance* pLocalCharacter = GetCharacter(0);
	if (!pLocalCharacter) return Vec3();
	ISkeletonPose* pLocalSkeleton = pLocalCharacter->GetISkeletonPose();
	if (!pLocalSkeleton) return Vec3();

	Matrix34 World = GetWorldTM();
	Matrix34 SkeletonAbs = Matrix34(pLocalSkeleton->GetAbsJointByID(eBone));
	Matrix34 matWorld = World;

	float m03, m13, m23;
	m03 = (World.m00 * SkeletonAbs.m03) + (World.m01 * SkeletonAbs.m13) + (World.m02 * SkeletonAbs.m23) + World.m03;
	matWorld.m03 = m03;
	m13 = (World.m10 * SkeletonAbs.m03) + (World.m11 * SkeletonAbs.m13) + (World.m12 * SkeletonAbs.m23) + World.m13;
	matWorld.m13 = m13;
	m23 = (World.m20 * SkeletonAbs.m03) + (World.m21 * SkeletonAbs.m13) + (World.m22 * SkeletonAbs.m23) + World.m23;
	matWorld.m23 = m23;

	return matWorld.GetTranslation();
}

void IEntity::SetLocation(const Vec3& vPos, int nWhyFlags)
{
	m_vPos = vPos;
	InvalidateTM(nWhyFlags | ENTITY_XFORM_POS);
}

void IEntity::SetRotationQuat(const Quat& qRotation, int nWhyFlags)
{
	m_qRotation = qRotation;
	InvalidateTM(nWhyFlags | ENTITY_XFORM_ROT);
}

void IEntity::RotateToVector(Vec3 vDir)
{
	vDir /= vDir.GetLength();
	SetRotationQuat(Quat::CreateRotationVDir(vDir));
}

void IEntity::SetScale(const Vec3& vScale, int nWhyFlags)
{
	m_vScale = vScale;
	InvalidateTM(nWhyFlags | ENTITY_XFORM_SCL);
}

const char* IEntityArchetype::GetName()
{
	return CallFunction<const char* (__thiscall*)(PVOID)>(this, RE_IEntityArchetype_GetName)(this);
}

IEntity* IEntityIt::Next()
{
	return CallFunction<IEntity* (__thiscall*)(PVOID)>(this, RE_IEntityIt_Next)(this);
}

IEntityClass* IEntityClassRegistry::FindClass(const char* sClassName)
{
	return CallFunction<IEntityClass* (__thiscall*)(PVOID, const char*)>(this, RE_IEntityClassRegistry_FindClass)(this, sClassName);
}

IEntityClass* IEntityClassRegistry::RegisterStdClass(const IEntitySpawnParams& entityClassDesc)
{
	return CallFunction<IEntityClass* (__thiscall*)(PVOID, const IEntitySpawnParams&)>(this, RE_IEntityClassRegistry_RegisterStdClass)(this, entityClassDesc);
}

IEntity* IEntitySystem::GetEntity(uint64 id)
{
	return CallFunction<IEntity* (__fastcall*)(PVOID64, uint64)>(this, 0x58)(this, id);
}

IEntity* IEntitySystem::FindEntityByName(const char* sEntityName)
{
	return CallFunction<IEntity* (__thiscall*)(PVOID, const char*)>(this, RE_IEntitySystem_FindEntityByName)(this, sEntityName);
}

IEntityIt* IEntitySystem::GetEntityIterator()
{
	return CallFunction<IEntityIt* (__thiscall*)(PVOID)>(this, RE_IEntitySystem_GetEntityIterator)(this);
}

IEntityClassRegistry* IEntitySystem::GetClassRegistry()
{
	return CallFunction<IEntityClassRegistry* (__thiscall*)(PVOID)>(this, RE_IEntitySystem_GetClassRegistry)(this);
}

void IEntitySystem::RemoveEntity(EntityId entity, bool bForceRemoveNow)
{
	CallFunction<void(__thiscall*)(PVOID, EntityId, bool)>(this, RE_IEntitySystem_RemoveEntity)(this, entity, bForceRemoveNow);
}

IEntity* IEntitySystem::SpawnEntity(IEntitySpawnParams& params, bool bAutoInit)
{
	return CallFunction<IEntity* (__thiscall*)(PVOID, IEntitySpawnParams&, bool)>(this, RE_IEntitySystem_SpawnEntity)(this, params, bAutoInit);
}

IEntity* IEntitySystem::SpawnObject(const char* entityName, const char* entityClass, Vec3 vPos)
{
	if (IEntityClass* pClass = GetClassRegistry()->FindClass(entityClass))
	{
		IEntitySpawnParams spawnParams;
		memset(&spawnParams, 0, sizeof(IEntitySpawnParams));
		spawnParams.vPosition = vPos;
		spawnParams.sName = entityName;
		spawnParams.pClass = pClass;
		spawnParams.qRotation.w = 1.f;
		spawnParams.vScale = Vec3(1.f, 1.f, 1.f);
		return SpawnEntity(spawnParams);
	}
	return NULL;
}

IEntity* IEntitySystem::SpawnObjectParams(const char* entityName, const char* entityClass, const char* entityArchetype, Vec3 vPos)
{
	if (IEntityClass* pClass = GetClassRegistry()->FindClass(entityClass))
	{
		IEntitySpawnParams spawnParams;
		memset(&spawnParams, 0, sizeof(IEntitySpawnParams));
		spawnParams.vPosition = vPos;
		spawnParams.sName = entityName;
		spawnParams.pClass = pClass;
		if (m_pEntityArchetypeManager && entityArchetype)
		{
			spawnParams.pArchetype = m_pEntityArchetypeManager->FindArchetype(entityArchetype);
		}
		spawnParams.qRotation.w = 1.f;
		spawnParams.vScale = Vec3(1.f, 1.f, 1.f);
		return SpawnEntity(spawnParams);
	}
	return NULL;
}

const char* IEntityClass::GetIClassName()
{
	return CallFunction<const char* (__fastcall*)(PVOID64)>(this, RE_IEntityClass_GetIClassName)(this);
}

bool IGameObject::BindToNetwork()
{
	return CallFunction<bool(__thiscall*)(PVOID)>(this, RE_IGameObject_BindToNetwork)(this);
}

void IGameObject::DoInvokeRMI(PVOID body, ERMInvocation where, int channel)
{
	CallFunction<void(__thiscall*)(PVOID, PVOID, ERMInvocation, int)>(this, FUNC_IGameObject_DoInvokeRMI)(this, body, where, channel);
}

void CProjectile::Launch(const Vec3& vPos, const Vec3& vDir, const Vec3& vVelocity, float fSpeedScale)
{
	CallFunction<void(__thiscall*)(PVOID, const Vec3&, const Vec3&, const Vec3&, float)>(this, RE_CProjectile_Launch)(this, vPos, vDir, vVelocity, fSpeedScale);
}

bool IRenderer::ProjectToScreen(w2s_info* info)
{
	return CallFunction<bool(__fastcall*)(PVOID64, w2s_info*)>(this, LCD3D9Renderer_ProjectToScreen)(this, info);
}

Vec3 IRenderer::GetViewCamera()
{
	return *(Vec3*)((DWORD64)this + LCD3D9Renderer_GetViewCamera);
}

IDirect3DDevice9* IRenderer::Get3DDevice()
{
	return (IDirect3DDevice9*)*(DWORD64*)((DWORD64)this + LD3D9Renderer_IDirect3DDevice);
}

IRenderer* IRenderer::Singleton()
{
	return *(IRenderer**)BB_CD3D9Renderer;
}

int IFireMode::SetAmmoCount(int count)
{
	return CallFunction<int(__thiscall*)(PVOID, int)>(this, RE_IFireMode_SetAmmoCount)(this, count);
}

int IWeaponParamsThree::GetAmmoCount()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_GetAmmoCount)(this);
}

void IWeaponParamsThree::SetAmmoCount(int IValue)
{
	CallFunction<void(__thiscall*)(PVOID, int)>(this, RE_SetAmmoCount)(this, IValue);
}

int IFireMode::GetAmmoCount()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IFireMode_GetAmmoCount)(this);
}

int IFireMode::GetClipSize()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IFireMode_GetClipSize)(this);
}

float IFireMode::GetRecoil()
{
	return CallFunction<float(__thiscall*)(PVOID)>(this, RE_IFireMode_GetRecoil)(this);
}

float IFireMode::GetSpread()
{
	return CallFunction<float(__thiscall*)(PVOID)>(this, RE_IFireMode_GetSpread)(this);
}

const char* IAnimationGraphState::GetCurrentStateName() {
	return CallFunction<const char* (__thiscall*)(PVOID)>(this, RE_IAnimation_GetCurrentStateName)(this);
}

int IActor::GetHealth()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetHealth)(this);
}

bool IActor::IsDead()
{
	return GetHealth() <= 0;
}

void IActor::SetHealth(int iHealth)
{
	CallFunction<void(__thiscall*)(PVOID, int)>(this, RE_IActor_SetHealth)(this, iHealth);
}

void IActor::SetMaxHealth(float fMaxHealth)
{
	CallFunction<void(__thiscall*)(PVOID, float)>(this, RE_IActor_SetMaxHealth)(this, fMaxHealth);
}

int IActor::GetMaxHealth()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetMaxHealth)(this);
}

int IActor::GetArmor()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetArmor)(this);
}

int IActor::GetMaxArmor()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetMaxArmor)(this);
}

EntityId IActor::GetGrabbedEntityId()
{
	return CallFunction<EntityId(__thiscall*)(PVOID)>(this, RE_IActor_GetGrabbedEntityId)(this);
}

void IActor::SetCurrentItem(EntityId itemId)
{
	CallFunction<void(__thiscall*)(PVOID, EntityId)>(this, RE_IActor_SetCurrentItem)(this, itemId);
}

void IActor::SetViewRotation(const Quat& pRotation)
{
	CallFunction<void(__thiscall*)(PVOID, const Quat&)>(this, RE_IActor_SetViewRotation)(this, pRotation);
}

Quat IActor::GetViewRotation()
{
	return CallFunction<Quat(__thiscall*)(PVOID)>(this, RE_IActor_GetViewRotation)(this);
}

IItem* IActor::get_cureentrs_items(bool bIncludeVehicle)
{
	return CallFunction<IItem* (__thiscall*)(PVOID, bool)>(this, RE_IActor_GetCurrentItem)(this, bIncludeVehicle);
}

IInventory* IActor::GetInventory()
{
	return CallFunction<IInventory* (__thiscall*)(PVOID)>(this, RE_IActor_GetInventory)(this);
}

IMovementController* IActor::GetMovementController()
{
	return CallFunction<IMovementController* (__thiscall*)(PVOID)>(this, RE_IActor_GetMovementController)(this);
}

IEntity* IActor::LinkToVehicle(EntityId vehicleId)
{
	return CallFunction<IEntity* (__thiscall*)(PVOID, EntityId)>(this, RE_IActor_LinkToVehicle)(this, vehicleId);
}

IEntity* IActor::GetLinkedEntity()
{
	return CallFunction<IEntity* (__thiscall*)(PVOID)>(this, RE_IActor_GetLinkedEntity)(this);
}

IAnimationGraphState* IActor::GetAnimationGraphState()
{
	return CallFunction<IAnimationGraphState* (__fastcall*)(PVOID)>(this, RE_IActor_GetAnimationGraphState)(this);
}

int IActor::GetSpectatorMode()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetSpectatorMode)(this);
}

void IActor::SetSleepTimer(float fTimer)
{
	CallFunction<void(__thiscall*)(PVOID, float)>(this, RE_IActor_SetSleepTimer)(this, fTimer);
}

PVOID IActor::GetReplacementMaterial()
{
	return CallFunction<PVOID(__thiscall*)(PVOID)>(this, RE_IActor_GetReplacementMaterial)(this);
}

bool IActor::IsThirdPerson()
{
	return CallFunction<bool(__thiscall*)(PVOID)>(this, RE_IActor_IsThirdPerson)(this);
}

void IActor::ToggleThirdPerson()
{
	CallFunction<void(__thiscall*)(PVOID)>(this, RE_IActor_ToggleThirdPerson)(this);
}

bool IActor::IsPlayer()
{
	return CallFunction<bool(__thiscall*)(PVOID)>(this, RE_IActor_IsPlayer)(this);
}

bool IActor::IsClient()
{
	return CallFunction<bool(__thiscall*)(PVOID)>(this, RE_IActor_IsClient)(this);
}

char* IActor::GetActorClassName()
{
	return CallFunction<char* (__thiscall*)(PVOID)>(this, RE_IActor_GetActorClassName)(this);
}

const char* IActor::GetEntityClassName()
{
	return CallFunction<const char* (__thiscall*)(PVOID)>(this, RE_IActor_GetEntityClassName)(this);
}

void IActor::SetCurrentClass(int iClassId)
{
	CallFunction<void(__thiscall*)(PVOID, int)>(this, RE_IActor_SetCurrentClass)(this, iClassId);
}

int IActor::GetCurrentClass()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActor_GetCurrentClass)(this);
}

IEntity* IActor::GetEntity()
{
	return (IEntity*)*(DWORD64*)((DWORD64)this + RE_IActor_GetEntity);
}

DWORD64 IActor::EntityID()
{
	return (DWORD64) * (DWORD64*)((DWORD64)this + RE_IActor_EntityID);
}

CPlayer* IActor::GetPlayer()
{
	return *(CPlayer**)((DWORD64)this + LCPlayer);
}

BOOL IWeaponParamsTwo::GetStat(uint32_t id, FLOAT* value)
{
	if (uint32_t* stat = FindStat(id))
	{
		*(uint32_t*)value = stat[0] ^ stat[1];
		return TRUE;
	}
	return FALSE;
}

BOOL IWeaponParamsTwo::SetStat(uint32_t id, FLOAT value)
{
	if (uint32_t* stat = FindStat(id))
	{
		stat[0] = *(uint32_t*)&value ^ stat[1];
		return TRUE;
	}
	return FALSE;
}

void IWeaponPTR::GetShutter(int8 Value)
{
	*(int8*)((DWORD64)this + 0xD2) = Value;
}


IWeaponPTR* IWeapon::pWeaponPTR()
{
	return (IWeaponPTR*)*(DWORD64*)((DWORD64)this + 0x8);
}

void IWeapon::StartFire()
{
	CallFunction<void(__thiscall*)(PVOID)>(this, RE_IWeapon_StartFire)(this);
}

void IWeapon::StopFire()
{
	CallFunction<void(__thiscall*)(PVOID)>(this, RE_IWeapon_StopFire)(this);
}

VOID IWeapon::ClampFire(__int8 Delay)
{
	Sleep(Delay); StartFire(); StopFire();
}

void IWeapon::Reload(bool force)
{
	CallFunction<void(__thiscall*)(PVOID, bool)>(this, RE_IWeapon_Reload)(this, force);
}

bool IWeapon::GetCrosshairVisibility()
{
	return CallFunction<bool(__thiscall*)(PVOID)>(this, RE_IWeapon_GetCrosshairVisibility)(this);
}

float IWeapon::GetCrosshairOpacity()
{
	return CallFunction<float(__thiscall*)(PVOID)>(this, RE_IWeapon_GetCrosshairOpacity)(this);
}

int IWeapon::GetNumOfFireModes()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IWeapon_GetNumOfFireModes)(this);
}

IFireMode* IWeapon::GetFireMode(int idx)
{
	return CallFunction<IFireMode* (__thiscall*)(PVOID, int)>(this, RE_IWeapon_GetFireMode)(this, idx);
}

int IWeapon::GetCurrentFireMode()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IWeapon_GetCurrentFireMode)(this);
}

void IWeapon::SetCurrentFireMode(int idx)
{
	CallFunction<void(__thiscall*)(PVOID, int)>(this, RE_IWeapon_SetCurrentFireMode)(this, idx);
}

void IWeapon::SetFiringPos(Vec3 vPos)
{
	if (DWORD64 v0 = *(DWORD64*)((DWORD64)this + 0x18))*(Vec3*)(v0 + 0x1C) = vPos;
}

IEntity* IItem::GetIWeaponEntity()
{
	return m_pEntity;
}

IGameObject* IItem::GetGameObject()
{
	return m_pGameObject;
}

EntityId IItem::GetEntityId()
{
	return m_entityId;
}

DWORD IItem::GetItemId()
{
	return m_dwItemId;
}

IWeapon* IItem::GetIWeapon()
{
	return CallFunction<IWeapon* (__thiscall*)(PVOID)>(this, RE_IItem_GetIWeapon)(this);
}

void IItem::PickUp(EntityId picker, bool sound, bool select, bool keepHistory, const char* setup)
{
	return CallFunction<void(__thiscall*)(PVOID, EntityId, bool, bool, bool, const char*)>(this, RE_IItem_PickUp)(this, picker, sound, select, keepHistory, setup);
}

IItem* IItemSystem::GetItem(EntityId itemId)
{
	return CallFunction<IItem* (__thiscall*)(PVOID, EntityId)>(this, RE_IItemSystem_GetItem)(this, itemId);
}

EntityId IItemSystem::GiveItem(IActor* pActor, const char* item, bool sound, bool select, bool keepHistory, const char* setup, EEntityFlags entityFlags)
{
	return CallFunction<EntityId(__thiscall*)(PVOID, IActor*, const char*, bool, bool, bool, const char*)>(this, RE_IItemSystem_GiveItem)(this, pActor, item, sound, select, keepHistory, setup);
}

int IInventory::GetCount()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IInventory_GetCount)(this);
}

EntityId IInventory::GetItem(int slotId)
{
	return CallFunction<EntityId(__thiscall*)(PVOID, int)>(this, RE_IInventory_GetItem)(this, slotId);
}

EntityId IInventory::GetCurrentItemId()
{
	return CallFunction<EntityId(__thiscall*)(PVOID)>(this, RE_IInventory_GetCurrentItemId)(this);
}

IActor* IActorIterator::Next()
{
	typedef IActor* (__fastcall* aNext)(PVOID64);
	return CallFunction<aNext>(this, RE_IActorIterator_Next)(this);
}

int IActorSystem::GetCount()
{
	return CallFunction<int(__thiscall*)(PVOID)>(this, RE_IActorSystem_GetCount)(this);
}

IActor* IActorSystem::GetActorByChannelId(int ChannelId)
{
	return CallFunction<IActor* (__thiscall*)(PVOID, int)>(this, RE_IActorSystem_GetActorByChannelId)(this, ChannelId);
}

IActor* IActorSystem::GetActor(int entityId)
{
	return CallFunction<IActor* (__thiscall*)(PVOID, int)>(this, RE_IActorSystem_GetActor)(this, entityId);
}

void IActorSystem::CreateActorIterator(IActorIterator** ActorIterator)
{
	using CreateActorIterator = VOID(__fastcall*)(PVOID64, IActorIterator**);
	return CallFunction<CreateActorIterator>(this, 144)(this, ActorIterator);
}

VOID SCVars::i_soundeffects(INT32 Value) {
	*(INT32*)((DWORD64)this + 0xE0) = Value;
}

VOID SCVars::i_pelletsDisp(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x128) = Value;
}

VOID SCVars::i_unlimitedammo(INT32 Value) {
	*(INT32*)((DWORD64)this + 0x130) = Value;
}

VOID SCVars::i_lighteffects(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0xEC) = Value;
}

VOID SCVars::i_particleeffects(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0xF0) = Value;
}

VOID SCVars::i_rejecteffects(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0xF4) = Value;
}

VOID SCVars::g_parametric_recoil_random_enabled(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x24C) = Value;
}

VOID SCVars::g_parametric_spread_attack_enabled(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x250) = Value;
}

VOID SCVars::g_kickvote_pve_max_checkpoints(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x49C) = Value;
}

VOID SCVars::g_crosshair_spread_tuning_enable(INT32 Value) {
	*(INT32*)((DWORD64)this + 0x5CC) = Value;
}

VOID SCVars::g_gameroom_afk_timeout(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x794) = Value;
}

VOID SCVars::g_ingame_afk_timeout(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0x798) = Value;
}

VOID SCVars::g_anti_cheat_memscan_thread_delay(FLOAT Value) {
	*(FLOAT*)((DWORD64)this + 0xB8C) = Value;
}

VOID SCVars::g_anti_cheat_memscan_log(INT32 Value) {
	*(INT32*)((DWORD64)this + 0xB90) = Value;
}

VOID SCVars::g_anti_cheat_memscan_dump_patterns(INT32 Value) {
	*(INT32*)((DWORD64)this + 0xB94) = Value;
}

bool SCVars::IsInRoom(INT Room, INT RoomTwo)
{
	return this->g_victoryCondition() == Room || this->g_victoryCondition() == RoomTwo;
}

INT32 SCVars::g_victoryCondition() {
	return (INT32) * (DWORD64*)((DWORD64)this + 0x600);
}

SCVars* SCVars::Singleton() {
	return *(SCVars**)BB_SCVars;
}
