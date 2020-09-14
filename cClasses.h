#pragma once
#include "cMath.h"
class SSystemGlobalEnvironment;
class CCryAction;
struct CD3D9Renderer;
class ISystem;
struct IGameFramework;
class IGame;
struct ITimer;
class CNetCVars;
struct SCVars;
class IPhysicalWorld;
struct IEntitySystem;
struct IActorSystem;
struct IItemSystem;
struct IInventory;
struct IWeaponObject;
struct IWeaponShootParams;

class IRenderer;
struct IGameObject;
struct IEntity;
struct IItem;
class IEntityClass;
struct CProjectile;
class IActor;
class CPlayer;
enum I_OFFSETS_FUNK_EU : int
{
	F_GET_CLIENTACTOR = 0x470,
	F_GET_CLIENTACTOR_EU = 0x470,//+
};

template <typename t>
static bool is_valid_ptr(t* ptr)
{
	return (ptr) ? true : false;
}

typedef std::map<const char*, IEntityClass*>	ClassNameMap;
typedef std::map<int, const char*>				THitTypeMap;

#define gInputSymbols ((SInputSymbol**)0x141ED31A8)

////////////////////////////////////////////////////////////	STATICS  ////////////////////////////////////////////////////////////

#define BB_SystemGL								0x141D4BAA0		// scandir_all	+
#define	BB_IGameFramework						0x142055558     // CryENGINE last xraph first DWORD upper
#define BB_IGame								0x1420548C0     // Libs/UI/HUDHitIndicatorCenter.tif
#define BB_CD3D9Renderer						0x1420502F0     // RainDropsGen 
#define BB_SCVars								0x1420548B8   	// IsSameTeam //ICVar
#define BB_ITimer								0x1420189F8     // CD3D9Renderer::RT_EndFrame 

#define STATIC_CNetCVars							0x141ED3D78 		// Zombie kicked; remote machine was backing off for %.1f seconds
#define _pTimer									(*(ITimer**)					STATIC_ITimer)
#define _pNetCVars									(*(CNetCVars**)					STATIC_CNetCVars)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////    PARAMS    ////////////////////////////////////////////////////////////

#define LISystem							0xE8				// GetUserName
#define LI3DEngine							0xF8				// Dof_FocusDistance
#define LIPhysicalWorld						0x70				// RayWorldIntersection(Game)
#define LIEntitySystem						0xD8				// "GetEntityByName"
#define	LIRenderer							0x48				// Draw2DLine
#define LSSGE_IGame							0xC8				// entity in parameter 2 is not an item/weapon

#define LD3D9Renderer_IDirect3DDevice			0xA6D0				// RainDropsGen
#define LCD3D9Renderer_ProjectToScreen			0x320
#define LCD3D9Renderer_GetViewCamera			0x1700

#define LEntityId						0x20				// proximityRadius

#define LCPlayer						0xD10				// Can't entry output sj to demux more than limit. ???

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////    FUNCTIONS    //////////////////////////////////////////////////////////
#define RE_GetAmmoCount								0x10
#define RE_SetAmmoCount								0x10 
#define RE_IGame_GetWeaponSystem					0x128		// 

#define RE_CCryAction_GetClientChannel				0x238		// User left the game

#define RE_IGameFramework_GetIEntitySystem			0x30
#define RE_IGameFramework_GetActorSystem			0xC8		// proximityRadius
#define RE_IGameFramework_GetClientActor			0x470		// sp_difficulty, first SUB
#define RE_IGameFramework_GetIItemSystem			0xD0		// entity in parameter 2 is not an item/weapon
#define RE_IGameFramework_GetGameRules				0x448		// IsSameTeam

#define RE_ISurfaceType_GetName						0x18

#define RE_IGameRules_GetTeam						0x448		// IsSameTeam
#define RE_IGameRules_SetTeam						0x358		// SetTeam
#define RE_IGameRules_SendCommunicationEvent		0x2D0		// SendCommunicationEvent
#define RE_IGameRules_RequestHit					0x4E0		// 
#define RE_IGameRules_GetHitTypeId					0x140		// "bullet", first sub
#define RE_IGameRules_GetHitMaterial				0x398
#define RE_IGameRules_GetHitMaterialId				0x390

#define RE_IPhysicalEntity_GetForeignData			0x68

#define RE_I3DEngine_SetPostEffectParam				0x478		// "Dof_FocusDistance"

#define RE_ISystem_Update							0x20		// 

#define RE_IPhysicalWorld_RayWorldIntersection				0x118		// RayWorldIntersection(Game)
#define RE_IPhysicalWorld_RayWorldIntersectionParams		0x308

#define RE_ITimer_GetCurrTime						0x18		// "PostEffectsGame" (*(void (__stdcall **)(_DWORD64))(**(_DWORD64 **)(SSystemGlobalEnvironment + 0x68) + 0xC))(0);
#define RE_ITimer_GetAsyncCurTime					0x30		// "FarTreeSprites" (*(void (**)(void))(v8 + 24))();

#define RE_ICharacterInstance_GetISkeletonPose		0x28		// Bip01, 5th SUB, 2nd offset

#define RE_ISkeletonPose_GetJointIDByName			0x18		// Bip01, 5th SUB, 1st offset
#define RE_ISkeletonPose_GetAbsJointByID			0x38		// RgtArm01 (v7 = (*(int (__thiscall **)(int, DWORD64))(*(DWORD64 *)v6 + 0x1C))(v6, 0);)											

#define RE_ISkeletonPhysics_GetCharacterPhysics		0x110		// SerializableRopes or CharRope or PhysicsProxy

#define RE_IGameObject_BindToNetwork				0xE8		// 
#define FUNC_IGameObject_DoInvokeRMI				0x1C0		// 

#define RE_CProjectile_Launch						0xF0		// 
#define FRE_CProjectile_SetParams					0xD8		// 

#define RE_IEntity_GetCharacter					  0x290		// Bip01, 6th SUB, 1st offset
#define RE_IEntity_GetProxy						  0x1D8		// CreateRenderProxy
#define RE_IEntity_IsHidden						  0x178		// 
#define RE_IEntity_GetFlags                       0x30
#define RE_IEntity_GetName                        0x60
#define RE_IEntity_SetPos                         0xA8
#define RE_IEntity_GetWorldTM                     0xB8
#define RE_IEntity_GetWorldBounds                 0xC8
#define RE_IEntity_SetLocalPos                    0xD8
#define RE_IEntity_SetRotation                    0xE8
#define RE_IEntity_GetRotation                    0xF0
#define RE_IEntity_GetSlotLocalTM                 0x238
#define RE_IEntity_GetSlotCount                   0x240
#define RE_IEntity_SetSlotLocalTM                 0x258
#define RE_IEntity_InvalidateTM					  0x2F8
#define RE_IEntity_LoadCharacter                  0x1B8
#define RE_IEntity_LoadGeometry                   0x2C0
#define RE_IEntity_GetID                          0x8 
#define RE_IEntity_GetEntityClass				  0x18

#define	RE_IERP_SetHUDSilhouettesParams				0x160		// HudSilhouettes_Type, second SUB -> last SUB in pseudocode -> finding offset (COERCE_FLOAT in params)

#define RE_IEntitySystem_GetEntity					0x58
#define RE_IEntitySystem_FindEntityByName			0x60		// 
#define RE_IEntitySystem_GetEntityIterator			0xA8		// 
#define RE_IEntitySystem_GetClassRegistry			0x40		// EntityClass
#define RE_IEntitySystem_SpawnEntity				0x48
#define RE_IEntitySystem_RemoveEntity				0x80

#define RE_IEntityClass_GetIClassName				0x10
#define RE_IEntityArchetype_GetName					0x10

#define RE_IEntityClassRegistry_FindClass			0x18
#define RE_IEntityClassRegistry_RegisterStdClass	0x30

#define RE_IEntityIt_Next							0x30		// 

#define RE_IFireMode_SetAmmoCount					0x58		// 
#define RE_IFireMode_GetAmmoCount					0x60		// 
#define RE_IFireMode_GetClipSize					0x68		// 
#define RE_IFireMode_GetRecoil						0xB8		// 
#define RE_IFireMode_GetSpread						0xC0		// 

#define RE_IWeapon_StartFire						0x58		// CScriptBind_Weapon::AutoShoot (first)
#define RE_IWeapon_StopFire							0x60		// CScriptBind_Weapon::AutoShoot (second)
#define RE_IWeapon_Reload							0x98		// Reload
#define RE_IWeapon_GetCrosshairVisibility			0xC8		// 
#define RE_IWeapon_GetCrosshairOpacity				0xD0		// 
#define RE_IWeapon_GetNumOfFireModes				0xD8		// 
#define RE_IWeapon_GetFireMode						0xE0		// 
#define RE_IWeapon_GetCurrentFireMode				0xF8		// 
#define RE_IWeapon_SetCurrentFireMode				0x100		// 

#define RE_IItem_GetIWeapon							0x278		// OffHand (offset in return of last 'if' is GetIWeapon)
#define RE_IItem_PickUp								0x150		// OnUpdateItems (first sub)

#define RE_IActor_SyncPos							0x70		// Game object extension with base %p for entity %s for RMI %s not found
#define RE_IActor_IsDead							0xC0	    // active_player...
#define RE_IActor_GetHealth							0xD8		// GetHealth
#define RE_IActor_SetHealth							0xE0		// 
#define RE_IActor_SetMaxHealth						0xF0		// SetMaxHealth
#define RE_IActor_GetMaxHealth						0xF8		// 
#define RE_IActor_GetArmor							0x100		// 
#define RE_IActor_GetMaxArmor						0x108		// 
#define RE_IActor_GetGrabbedEntityId				0x168		// 
#define RE_IActor_SetCurrentItem					0x180		// 
#define RE_IActor_SetViewRotation					0x198		// 
#define RE_IActor_GetViewRotation					0x1A0		// 

#define RE_IActor_GetCurrentItem					0x1C8		// CurrentItemName
#define RE_IActor_GetInventory						0x1D8		// OnActorStandUp
#define RE_IActor_GetMovementController				0x1E8		// Angle to actor %d is %f deg
#define RE_IActor_GetAnimationGraphState			0x120	

#define RE_IActor_LinkToVehicle						0x1E8		// 	OUTDATED
#define RE_IActor_GetLinkedEntity					0x1F0		// 	OUTDATED

#define RE_IActor_GetEntity							0x10
#define RE_IActor_EntityID							0x20

#define RE_IActor_GetSpectatorMode					0x1F8		// 	OUTDATED
#define RE_IActor_SetSleepTimer						0x200		// 	OUTDATED
#define RE_IActor_GetReplacementMaterial			0x208		// 	OUTDATED
#define RE_IActor_IsThirdPerson						0x210		// 	OUTDATED
#define RE_IActor_ToggleThirdPerson					0x218		// 	OUTDATED

#define RE_IActor_IsPlayer							0x230		// OnActorSitDown
#define RE_IActor_IsClient							0x238		// 

#define RE_IActor_GetActorClassName				    0x248		// 	OUTDATED
#define RE_IActor_GetEntityClassName			    0x258		// 	OUTDATED
#define RE_IActor_SetCurrentClass				    0x370		// 	OUTDATED
#define RE_IActor_GetCurrentClass				    0x378		// 	OUTDATED

#define RE_IAnimation_GetCurrentStateName			0x100

#define RE_IInventory_GetCount						0x100		// GetCount
#define RE_IInventory_GetItem                     0x120		// GetItem
#define RE_IInventory_GetCurrentItemId            0x170		// GetCurrentItemId

#define RE_IItemSystem_GetItem                    0xB0		// OnUpdateItems
#define RE_IItemSystem_GiveItem                   0x118		// giveable

#define RE_IActorSystem_GetCount                  0x68
#define RE_IActorSystem_GetActorByChannelId       0x70
#define RE_IActorSystem_GetActor                  0x78		// proximityRadius

#define RE_IActorIterator_Next					0x8


#define TARGET_METHOD_INDEX_DAMAGE		155
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ISystem
{
public:
	char _0x0000[0x10D0];
	Vec3 CamPos; //0x0710 
};

class I3DEngine
{
public:
	void SetPostEffectParam(const char* pParam, float fValue, bool bForceValue = false);
};

class SSystemGlobalEnvironment
{
public:
	IRenderer* GetIRenderer();
	I3DEngine* Get3DEngine();
	IPhysicalWorld* GetIPhysicalWorld();
	IEntitySystem* GetIEntitySystem();
	IGame* GetIGame();
	ISystem* GetSystem();
	static SSystemGlobalEnvironment* Singleton();
};

class IPhysicalEntity
{
public:
	void* GetForeignData(int itype = 0);
};

struct ray_hit
{
	float dist;
	IPhysicalEntity* pCollider;
	int ipart;
	int partid;
	short surface_idx;
	short idmatOrg;			// original material index, not mapped with material mapping
	int foreignIdx;
	int iNode;				// BV tree node that had the intersection; can be used for "warm start" next time
	Vec3 pt;
	Vec3 n;					// surface normal
	int bTerrain;			// global terrain hit
	int iPrim;				// hit triangle index
	ray_hit* next;			// reserved for internal use, do not change
};

struct ray_hit_cached		// used in conjunction with rwi_reuse_last_hit
{
	IPhysicalEntity* pCollider;
	int ipart;
	int iNode;

	ray_hit_cached() { pCollider = 0; ipart = 0; }
	ray_hit_cached(const ray_hit& hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; }
	ray_hit_cached& operator=(const ray_hit& hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; return *this; }
};

struct SPlayerInfo
{
	int v0;
	__int64 v1[2];
	__int64 v2;
	int v3;
	__int64 v4;
	int v5;
};

struct SClimbMessage
{
	__int64 v0;
	char v1;
	int v2;
	char v3;
	SPlayerInfo v4;
	char v5;
};

struct EventPhysRWIResult;

class SRWIParams
{
public:
	void* pForeignData = 0;
	__int64 iForeignData = 0;
	int (*OnEvent)(const EventPhysRWIResult*);
	Vec3 org;
	Vec3 dir;
	__int32 objTypes;
	unsigned int flags;
	ray_hit* hits;
	__int32 nMaxHits;
	ray_hit_cached* phitLast = 0;
	__int32 nSkipEnts = 0;
	IPhysicalEntity** pSkipEnts = 0;
};

class IPhysicalWorld
{
public:
	int GetEntitiesAround(const Vec3& ptmin, const Vec3& ptmax, IPhysicalEntity**& pList, int objtypes, IPhysicalEntity* pPetitioner = NULL, int szListPrealloc = 0, int iCaller = 4);
	int RayWorldIntersection(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = "RayWorldIntersection(Game)", ray_hit_cached* phitLast = 0, int iCaller = 4);
	int RayWorldIntersectionParams(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = "RayWorldIntersection(Game)", ray_hit_cached* phitLast = 0, int iCaller = 4);
	Vec3 GetMPos(Vec3 BoneID, Vec3 CamPos, FLOAT Correct);
	BOOL IsVisible(Vec3 BoneID, FLOAT Correct);
	INT IsVisible(Vec3 p_BoneID, Vec3 m_BoneID);
};

class CWeaponSystem
{
public:
	CProjectile* DoSpawnAmmo(IEntityClass* pAmmoType, bool bRemote = 0);
};

struct ITimer
{
	float GetCurrTime(ETimer which = ETIMER_GAME);
	float GetAsyncCurTime();
};

struct ISurfaceType
{
	const char* GetName();
};

//enum
//{
//	huh = sizeof(I)
//	huh = sizeof(DWORD),
//	huiata0 = sizeof(float),
//	huiata1 = sizeof(Vec2),
//	huiata2 = sizeof(Vec3),
//	huiata3 = sizeof(void*)
//}
struct HitInfo
{
public:
	EntityId shooterId; //0x0000 
	EntityId targetId; //0x0004 
	char pad_0008[8]; //0x0008 
	int material = -1; //0x0010 
	int type; //0x0014 
	int bulletType = -1; //0x0018 
	int partId; //0x001C 
	Vec3 pos; //0x0020 
	Vec3 dir; //0x002C 
	Vec3 shootPos; //0x0038 
	bool meleeArmorAbsorb; //0x0044 
	char pad_0045[3]; //0x0045 
	DWORD itemId = 0; //0x0048 
	DWORD projectileId = 0; //0x004C 
	WORD itemType = -1; // 0x0050 
	char pad_0052[6]; //0x0052 
	Vec3 normal; //0x0058 
	char pad_0064[4]; //0x0064 
	DWORD64 dw_0x68 = (unsigned int)(signed int)0.0f; //0x0068 
	bool b_0x70; //0x0070 
	char pad_0071[7]; //0x0071 
	float distance; //0x0078 
	DWORD dw_0x7C; //0x0078 
	float timeStamp; //0x0080 
	WORD w_0x84 = 256; //0x0084 
};


class IGameRules
{
public:
	char pad_0x0000[0x10];			//0x0000
	IEntity* m_pEntity;				//0x0010
	IGameObject* m_pGameObject;		//0x0018
	EntityId m_entityId;			//0x0020
	char pad_0x0024[0x174];			//0x0024
	THitTypeMap m_hitTypes;			//0x0198

	int GetTeam(EntityId entityId);
	void SetTeam(int teamId, EntityId entityId);
	void SendCommunicationEvent(UINT eventType, EntityId sender);
	int GetHitTypeId(const char* type);
	void RequestHit(HitInfo* pHitInfo);
	ISurfaceType* GetHitMaterial(int materialId);
	int GetHitMaterialId(const char* materialName);
};
enum STATS_TYPE : DWORD64
{
	STATS_ACTOR_CLIMB = 0x8,
	STATS_ACTOR_SLIDE = 0x10,
};

enum SLIDE_TYPE : INT
{
	SLIDE_STAMINA = 24,
	SLIDE_STAMINA_MIN = 28,
	SLIDE_DELAY = 32,
	SLIDE_TO_SLIDE = 36,
	SLIDE_MODE = 40,
	SLIDE_ROTATE = 52,
	SLIDE_DISTANCE_ONE = 84
};
class CScriptBind_Actor
{
public:
	template <typename T>
	void SetStats(int iIndex, T tValue, DWORD64 dwType)
	{
		DWORD64 dwBase = *(DWORD64*)(*(DWORD64*)((DWORD64)this + 0x8) + dwType);

		if (dwBase)
			*(T*)(dwBase + iIndex) = tValue;
	}
};
class IGame
{
public:
	static IGame* Singleton();
	void SetPlayer(int GameFunction, float Value);
	CWeaponSystem* GetWeaponSystem();

	CScriptBind_Actor* GetActorScriptBind()
	{
		return m_pScriptBindActor;
	}

private:
	char pad_0x0000[0x288]; //0x0000
	CScriptBind_Actor* m_pScriptBindActor; //0x0288 
};

struct IGameFramework
{
	static IGameFramework* Singleton();
	BOOL get_cli_actor(IActor** pActor);
	IActor* get_cli_actor();
	IActor* GetActor(EntityId actorId);
	IEntitySystem* GetIEntitySystem();
	IActorSystem* GetActorSystem();
	IItemSystem* GetIItemSystem();
	IGameRules* get_GAME_RULES();
	bool IsMyTeam(IActor* mActor, IActor* pActor);

	bool sGetClientActor(IActor** pAct, bool IsNaClient = true) { return CallFunction<bool(__fastcall*)(PVOID, IActor**)>(this, IsNaClient ? F_GET_CLIENTACTOR : F_GET_CLIENTACTOR_EU)(this, pAct) && *pAct != NULL; }


	DWORD64 GetCurrTimeMillis(DWORD64 dwResult = 0)
	{
		CallFunction<void(__thiscall*)(PVOID, DWORD64*)>(this, 0x248)(this, &dwResult);
		return dwResult;
	}
};

class IEntityRenderProxy
{
public:
	uint32 GetFlags();
	void SetRndFlags(INT flag);
	VOID SetHUDSilhouettesParams(float a, float r, float g, float b);
};

struct ISkeletonPose
{
	QuatT& GetAbsJointByID(int nJointID);
	void SetAbsJointByID(int nJointID, const QuatT& pose);
	int16 GetJointIdByName(const char* sz_joint_name);
	EBone GetJointIDByNameParams(const char* boneName);
	IPhysicalEntity* GetCharacterPhysics();
};

struct ICharacterInstance
{
	ISkeletonPose* GetISkeletonPose();
};

struct IEntityArchetype
{
	const char* GetName();
};

struct IEntity
{
	int GetFlags();
	const char* GetName();
	bool IsHidden();
	void SetPos(const Vec3& vPos, int nWhyFlags = 0);
	Matrix34& GetWorldTM();
	void GetWorldBounds(AABB& bbox);
	void SetLocalPos(const Vec3& vPos, int nWhyFlags = 0);
	void SetLocPos(Vec3 vPos);
	void SetRotation(const Vec3& vAngles, int nWhyFlags = 0);
	void SetRotationTM(const Quat& rotation, int nWhyFlag = 10);
	void SetPosRotScale(const Vec3& vPos, const Quat& qRotation, const Vec3& vScale, int nWhyFlags = 0);
	void InvalidateTM(int nWhyFlags);
	const Vec3& GetRotation();
	Quat& GetRotationTM();
	void SetSlotLocalTM(int nSlot, const Matrix34& localTM, int nWhyFlags = 0);
	int GetSlotCount();
	const Matrix34& GetSlotLocalTM(int nSlot, bool bRelativeToParent);
	int LoadCharacter(int nSlot, const char* sFilename, int nLoadFlags = 0);
	int LoadGeometry(int nSlot, const char* sFilename, const char* sGeomName, int nLoadFlags);
	EntityId GetEntityId();

	IEntityClass* GetEntityClass();
	ICharacterInstance* GetCharacter(int nSlot);
	IEntityRenderProxy* GetProxy(EEntityProxy proxy = ENTITY_PROXY_RENDER);

	void SetHUDSilhouettesParams(f32 a, f32 r, f32 g, f32 b);

	Vec3 GetWorldPos();
	Vec3 GetBonePos(EBone eBone);

	void SetLocation(const Vec3& vPos, int nWhyFlags = 0);
	void SetRotationQuat(const Quat& qRotation, int nWhyFlags = 0);
	void RotateToVector(Vec3 vDir);
	void SetScale(const Vec3& vScale, int nWhyFlags = 0);

	char pad_0000[48]; //0x0000
	IEntityClass* m_pClass; //0x0030
	IEntityArchetype* m_pArchetype; //0x0038
	Matrix34 EntityWorldTM; //0x0040
	Vec3 m_vPos; //0x0070
	Vec3 m_vScale; //0x007C
	Quat m_qRotation; //0x0088
};

struct IEntityIt
{
	IEntity* Next();
};

class IEntitySpawnParams
{
public:
	EntityId Id; //0x0000 
	char pad_0x0004[0x14]; //0x0004 
	IEntityClass* pClass; //0x0018 
	IEntityArchetype* pArchetype;
	char pad_0x0020[0x8]; //0x0020 
	const char* sName; //0x0030 
	char pad_0x0038[0x8]; //0x0038 
	DWORD nFlags; //0x0040 
	char pad_0x0044[0x3]; //0x0044 
	Vec3 vPosition; //0x0047 
	Quat qRotation; //0x0053 
	Vec3 vScale; //0x0063 
	char pad_0x00060[0x90];
}; //Size=0x0068

struct IEntityClassRegistry
{
	char pad_0x00[0x8];
	ClassNameMap m_mapClassName;
	IEntityClass* m_pDefaultClass;

	IEntityClass* FindClass(const char* sClassName);
	IEntityClass* RegisterStdClass(const IEntitySpawnParams& entityClassDesc);
};

class CEntityArchetypeManager
{
public:
	typedef std::map<const char*, IEntityArchetype*, stl::less_stricmp<const char*>> ArchetypesNameMap;
	ArchetypesNameMap m_nameToArchetypeMap;

	IEntityArchetype* FindArchetype(const char* sArchetype)
	{
		IEntityArchetype* pArchetype = stl::find_in_map(m_nameToArchetypeMap, sArchetype, NULL);
		return pArchetype;
	}
};

struct IEntitySystem
{
	char pad_0x0000[0x404E8];
	CEntityArchetypeManager* m_pEntityArchetypeManager;

	IEntity* GetEntity(uint64 id);
	IEntity* FindEntityByName(const char* sEntityName);
	IEntityIt* GetEntityIterator();
	IEntityClassRegistry* GetClassRegistry();
	void RemoveEntity(EntityId entity, bool bForceRemoveNow = false);
	IEntity* SpawnEntity(IEntitySpawnParams& params, bool bAutoInit = true);
	IEntity* SpawnObject(const char* entityName, const char* entityClass, Vec3 vPos);
	IEntity* SpawnObjectParams(const char* entityName, const char* entityClass, const char* entityArchetype, Vec3 vPos);
};

class IEntityClass
{
public:
	const char* GetIClassName();
};

struct IGameObject
{
	char pad_0x0000[0xB4];
	int m_predictionHandle;

	bool BindToNetwork();
	void DoInvokeRMI(PVOID body, ERMInvocation where, int channel);
};

struct CProjectile
{
	char pad_0x0000[0x10];			//0x0000
	IEntity* m_pEntity;				//0x0010
	IGameObject* m_pGameObject;		//0x0018
	EntityId m_entityId;			//0x0020

	void Launch(const Vec3& vPos, const Vec3& vDir, const Vec3& vVelocity, float fSpeedScale = 1.f);
};

class ClientDevice
{
public:
	DWORD* pDevice;
};

class IRenderer
{
public:

	struct w2s_info
	{
		float Posx;
		float Posy;
		float Posz;
		float* Scrnx;
		float* Scrny;
		float* Scrnz;
	};

	class VecToScreen
	{
	public:
		FLOAT InputX;
		FLOAT InputY;
		FLOAT InputZ;
		FLOAT* OutputX;
		FLOAT* OutputY;
		FLOAT* OutputZ;
	};


	bool ProjectToScreen(w2s_info* info);
	Vec3 GetViewCamera();
	IDirect3DDevice9* Get3DDevice();
	static IRenderer* Singleton();
	DWORD64* GetDirectDevice()
	{
		return (DWORD64*)*(DWORD64*)((DWORD64)this + 0xA6D0);
	}
};

struct SInputSymbol
{
	enum EType { Button, Toggle, RawAxis, Axis, Trigger, };
	__inline bool IsState(int State) { return (state & State) == State; }
	__inline void AddState(int State) { state = state | State; }
	const EKeyId keyId;
	const char* name;
	const __int32 devSpecId;
	int state;
	const EType type;
	float value;
	__int32 user;
	__int8 deviceIndex;
};

struct SStanceState
{
	Vec3 pos;//0-8
	Vec3 entityDirection;//c-14
	Vec3 animationBodyDirection;//18-20
	Vec3 upDirection;//24-2C
	Vec3 weaponPosition;//30-38
	Vec3 aimDirection;//3C-44
	Vec3 fireDirection;//48-50
	Vec3 eyePosition;//54-5C
	Vec3 eyeDirection;//60-68
	float lean;//6C
	float peekOver;//70
	AABB m_StanceSize;//74-88
	AABB m_ColliderSize;//8C-94,98-A0
};

struct SMovementState : public SStanceState
{
	DWORD64 Unk;
	EStance stance;
	Vec3 animationEyeDirection;
	Vec3 movementDirection, lastMovementDirection;
	float desiredSpeed;
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAlive;
	bool isAiming;
	bool isFiring;
	bool isVisible;
	bool isMoving;
};

class CMovementRequest {};

class IMovementController
{
public:
	virtual ~IMovementController() {};
	virtual bool RequestMovement(CMovementRequest& request) = 0;
	virtual void GetMovementState(SMovementState& state) = 0;
	virtual bool GetStanceState() = 0;
};

class IFireMode
{
public:
	int SetAmmoCount(int count);
	int GetAmmoCount();
	int GetClipSize();
	float GetRecoil();
	float GetSpread();
};

class IAnimationGraphState
{
public:
	const char* GetCurrentStateName();
};



class CPlayer
{
public:
	Matrix44 m[2]; //0x0000 
	Quat m_viewQuat; //0x0080 
	Quat m_viewQuatFinal; //0x0090 
	Quat m_baseQuat; //0x00A0 
	Quat GetViewRotation()
	{
		return m_viewQuatFinal;
	}
	void SetViewRotation(Quat& rotation)
	{
		m_baseQuat = rotation;
		m_viewQuat = rotation;
		m_viewQuatFinal = rotation;
	}
};



class IActor
{
public:
	char pad_0000[16]; //0x0000
	IEntity* m_pEntity; //0x0010
	IGameObject* m_pGameObject; //0x0018
	EntityId m_entityId; //0x0020		
	char pad_0024[3704]; //0x0024
	float claymore_detector_radius; //0x0E9C
	float claymore_activation_delay_mul; //0x0EA0

	void RecoilAnimation(int playAnim)
	{
		Function<void(__thiscall*)(PVOID, int)>(this, 91)(this, playAnim); // 0 - Ignore Recoil
	}

	int GetWeaponType()
	{
		return *(int*)((__int64)this + 0xED4);//0xED4
	}

	int GetHealth();
	bool IsDead();
	void SetHealth(int iHealth);
	void SetMaxHealth(float fMaxHealth);
	int GetMaxHealth();
	int GetArmor();
	int GetMaxArmor();
	EntityId GetGrabbedEntityId();
	void SetCurrentItem(EntityId itemId);
	void SetViewRotation(const Quat& pRotation);
	Quat GetViewRotation();
	IItem* get_cureentrs_items(bool bIncludeVehicle = false);
	IInventory* GetInventory();
	IMovementController* GetMovementController();
	IEntity* LinkToVehicle(EntityId vehicleId);
	IEntity* GetLinkedEntity();
	IAnimationGraphState* GetAnimationGraphState();
	int GetSpectatorMode();
	void SetSleepTimer(float fTimer);
	PVOID GetReplacementMaterial();
	bool IsThirdPerson();
	void ToggleThirdPerson();
	bool IsPlayer();
	bool IsClient();
	char* GetActorClassName();
	const char* GetEntityClassName();
	void SetCurrentClass(int iClassId);
	int GetCurrentClass();

	IEntity* GetEntity();
	DWORD64 EntityID();

	CPlayer* GetPlayer();


	bool GetDeadPlayer(IActor* Player)
	{
		if (Player->IsDead())return true;
		else return false;
	}

	template <class T>
	inline VOID Set(DWORD64 offset, T value)
	{
		*(T*)((DWORD64)this + offset) = value;
	}

};

class IWeaponParamsOne
{
public:
	char _0x00[0x10];
	__int32 m_iPellets;				// 0x10
	IEntityClass* m_pAmmoType;		// 0x18

	void SetBulletsNumber(int iValue)
	{
		*(int*)((__int64)this + 0x10) = iValue;
	}
};

class IWeaponParamsTwo//IWeaponCrypt
{
	typedef std::map<uint32_t, uint32_t[2]> TWeaponMap;
public:
	char pad_0x00[0x68];
	TWeaponMap m_stats;	// 0x68	"needIcon"
	BOOL GetStat(uint32_t id, FLOAT* value);
	BOOL SetStat(uint32_t id, FLOAT value);

private:
	uint32_t* FindStat(uint32_t id)
	{
		TWeaponMap::iterator it = m_stats.find(id);
		if (it != m_stats.end())
		{
			return it->second;
		}
		return 0;
	}
};

class IWeaponParamsThree
{
public:

	int GetAmmoCount();
	void SetAmmoCount(int value);

	char pad_0000[8]; //0x0000
	bool m_bUnlimitedAmmo; //0x0008
	char pad_0009[3]; //0x0009
	uint32_t m_iAmmo; //0x000C
};
typedef unsigned __int64 qword;
class IWeaponPTR
{
public:
	char pad_0000[56]; //0x0000
	IItem* m_pItem; //0x0038
	char pad_0040[8]; //0x0040
	IWeaponParamsOne* GetIWeaponParamOne; //0x0048
	char pad_0050[16]; //0x0050
	IWeaponParamsTwo* GetWeaponParamsTwo; //0x0060
	IWeaponParamsThree* GetIWeaponParamThree; //0x0068
	void GetShutter(int8 Value);
	void SpawnAmmo();
	void RequestShoot(DWORD64 dwPellets = 0);
	void RequestMultiShoot(int a1, Vec3 vPos, Vec3 vDir, INT64 a4, int a5, std::vector<EntityId> projectiles, DWORD64 dwPellets, PDWORD64 pdwTimeStamp);
	void SvRequestMultiShoot(CProjectile* pProjectile, Vec3& vPos, Vec3& vDir, Vec3& Vell, EntityId* projectiles, int a5);

	void unlimpar(bool status) {
		*(qword*)((qword)this + 0xB8) = status == true;
	}

	bool is_fireng()
	{
		qword a1 = *(qword*)((qword)this + 0xB8);
		return (a1 == 3 || a1 == 6 || a1 == 12 || a1 == 13 || a1 == 14 || a1 == 15 || a1 == 16 || a1 == 48 || a1 == 49);
	}
	void fire_animation(bool status)
	{
		if (is_fireng())
		{
			unlimpar(status);
		}
	}

};

class IWeapon
{
public:
	IWeaponPTR* pWeaponPTR();
	void StartFire();
	void StopFire();
	VOID ClampFire(__int8 Delay = 0);
	void Reload(bool force = false);
	bool GetCrosshairVisibility();
	float GetCrosshairOpacity();
	int GetNumOfFireModes();
	IFireMode* GetFireMode(int idx);
	int GetCurrentFireMode();
	void SetCurrentFireMode(int idx);
	void SetFiringPos(Vec3 vPos);

	VOID AUTO()
	{
		StartFire();
		StopFire();
	}
};

struct IItem
{
public:
	IEntity* GetIWeaponEntity();
	IGameObject* GetGameObject();
	EntityId GetEntityId();
	DWORD GetItemId();
	IWeapon* GetIWeapon();
	void PickUp(EntityId picker, bool sound = true, bool select = true, bool keepHistory = true, const char* setup = NULL);

private:
	char pad_0x0000[0x10];			//0x0000
	IEntity* m_pEntity;				//0x0010
	IGameObject* m_pGameObject;		//0x0018
	EntityId m_entityId;			//0x0020
	char pad_0x0024[0x28];			//0x0024
	DWORD m_dwItemId;				//0x004C
};

struct IItemSystem
{
	IItem* GetItem(EntityId itemId);
	EntityId GiveItem(IActor* pActor, const char* item, bool sound, bool select = true, bool keepHistory = true, const char* setup = NULL, EEntityFlags entityFlags = (EEntityFlags)0);
};

struct IInventory
{
	int GetCount();
	EntityId GetItem(int slotId);
	EntityId GetCurrentItemId();
};

class IWeaponCrypt {
	char pad_0x0000[0x68];
	TWeaponMap m_mWeaponMap;

private:
	inline int* EncryptDataEntry(int Id) {
		TWeaponMap::iterator It = m_mWeaponMap.find(Id);
		if (It != m_mWeaponMap.end()) { return It->second; }
		return false;
	}

public:
	inline bool EncryptFloat(int Id, float fValue) {
		auto EncDataProtection = EncryptDataEntry(Id);
		if (EncDataProtection != NULL) {
			EncDataProtection[0] = *(int*)&fValue ^ EncDataProtection[1];
			return true;
		}
		return false;
	}

	inline bool DecryptFloat(int Id, float* fValue) {
		auto DecDataProtection = EncryptDataEntry(Id);
		if (DecDataProtection != NULL) {
			*(int*)&fValue = DecDataProtection[0] ^ DecDataProtection[1];
			return true;
		}
		return false;
	}
};

class IActorIterator
{
public:
	IActor* Next();
};

struct IActorSystem
{
	int GetCount();
	IActor* GetActorByChannelId(int ChannelId);
	IActor* GetActor(int entityId);
	void CreateActorIterator(IActorIterator** ActorIterator);
};

struct SCVars
{
	VOID i_soundeffects(INT32 Value);
	VOID i_pelletsDisp(FLOAT Value);
	VOID i_lighteffects(FLOAT Value);
	VOID i_particleeffects(FLOAT Value);
	VOID i_rejecteffects(FLOAT Value);
	VOID i_unlimitedammo(INT32 Value);
	void g_parametric_recoil_random_enabled(FLOAT Value);
	void g_parametric_spread_attack_enabled(FLOAT Value);
	void g_kickvote_pve_max_checkpoints(FLOAT Value);
	void g_crosshair_spread_tuning_enable(INT32 Value);
	void g_gameroom_afk_timeout(FLOAT Value);
	void g_ingame_afk_timeout(FLOAT Value);
	void g_anti_cheat_memscan_thread_delay(FLOAT Value);
	void g_anti_cheat_memscan_log(INT32 Value);
	void g_anti_cheat_memscan_dump_patterns(INT32 Value);
	bool IsInRoom(INT Room, INT RoomTwo);
	INT32 g_victoryCondition();
	static SCVars* Singleton();
};
