#pragma once
#include "cClasses.h"
struct ISystems;
struct IGameRuless;
struct IActors;
struct IGames;
struct IItems;
struct IEntitys;
struct IActorSystems;
struct IActorIterators;
struct IGameFrameworks;
struct SSystemGlobalEnvironments;

struct ISkeletonPoses;
struct ICharacterInstances;

struct IMovementController;
#define Virtual virtualfunction

template <typename T>
T Virtual(void* base, int index)
{
	return (*(T**)base)[index];

}
struct SSystemGlobalEnvironments
{
public:
	char pad_0x0000[0xC8]; //0x0000
	IGames* pGame; //0x00C8 
	char pad_0x00CC[0x1C]; //0x00CC
	ISystems* pSystem; //0x00E8 

	static SSystemGlobalEnvironments* Singleton()
	{
		return *(SSystemGlobalEnvironments**)0x141D132D0;
	}
};

struct SGameClientHitInfo
{
public:
	EntityId shooterId; //0x0000 
	EntityId targetId; //0x0004 
	float unknown0; //0x0008 
	float unknown1; //0x000C 
	int material; //0x0010 
	int type; //0x0014 
	int bulletType; //0x0018 
	int partId; //0x001C 
	Vec3 pos; //0x0020 
	Vec3 dir; //0x002C 
	Vec3 shootPos; //0x0038 
	bool meleeArmorAbsorb; //0x0044 
	unsigned long itemId; //0x0048 
	EntityId projectileId; //0x004C 
	unsigned short itemType; //0x0050 
	float unknown2; //0x0054 
	Vec3 normal; //0x0058 
	float unknown3; //0x0064 
	unsigned long long unknown4; //0x0068 
	float unknown5; //0x006C 
	bool unknown6; //0x0070 
	float unknown7; //0x0074 
	float distanceToHit; //0x0078 
	unsigned long unknown8; //0x007C 
	float timeStamp; //0x0080 
	unsigned short penetrationCount; //0x0084 
};

struct IGameFrameworks
{
public:
	IActorSystems* GetIActorSystem()
	{
		return Virtual<IActorSystems* (__fastcall*)(void*)>(this, 25)(this);
	}

	bool GetClientActor(IActors** pActor)
	{
		return Virtual<bool(__thiscall*)(void*, IActors**)>(this, 142)(this, pActor);
	}

	IGameRuless* GetIGameRules()
	{
		return Virtual<IGameRuless* (__thiscall*)(void*)>(this, 137)(this);
	}
};

struct IGameRuless
{
public:
	int GetHitTypeId(const char* type)
	{
		return Virtual<int(__thiscall*)(void*, const char*)>(this, 40)(this, type);
	}

	int GetTeam(EntityId entityId)
	{
		return Virtual<int(__thiscall*)(void*, EntityId)>(this, 108)(this, entityId);
	}

	int GetHitMaterialId(const char* materialName)
	{
		return Virtual<int(__thiscall*)(void*, const char*)>(this, 113)(this, materialName);
	}

	void ClientHit(SGameClientHitInfo* hitInfo)
	{
		Virtual<void(__thiscall*)(void*, SGameClientHitInfo*)>(this, 155)(this, hitInfo);
	}
};

struct IActors
{
public:
	bool IsDead()
	{
		return IActors::GetHealth() <= 0;
	}

	int GetHealth()
	{
		return Virtual<int(__fastcall*)(void*)>(this, 27)(this);
	}

	IItems* GetCurrentItem(bool includeVehicle = false)
	{
		return Virtual<IItems* (__fastcall*)(void*, bool)>(this, 57)(this, includeVehicle);
	}

	IMovementController* GetMovementController()
	{
		return Virtual<IMovementController* (__fastcall*)(void*)>(this, 61)(this);
	}

	IEntitys* GetLinkedEntity()
	{
		return pEntity;
	}

	void RecoilAnimation(int playAnim)
	{
		Virtual<void(__thiscall*)(PVOID, int)>(this, 91)(this, playAnim); // 0 - Ignore Recoil
	}

private:
	char pad_0x0000[0x10];
	IEntitys* pEntity;
};

struct IGames
{
public:
	IGameFrameworks* GetIGameFramework()
	{
		return Virtual<IGameFrameworks* (__thiscall*)(void*)>(this, 14)(this);
	}
};

struct IItems
{
public:
	unsigned long GetCurrentItemId()
	{
		return m_pItemId;
	}

private:
	char pad_0x0000[0x4C]; //0x0000
	unsigned long m_pItemId; //0x004C
};

struct IEntitys
{
public:
	EntityId GetId()
	{
		return Virtual<EntityId(__thiscall*)(void*)>(this, 1)(this);
	}

	const Matrix34& GetWorldTM()
	{
		return Virtual<const Matrix34& (__thiscall*)(void*)>(this, 23)(this);
	}

	ICharacterInstances* GetCharacter(int nSlot)
	{
		return Virtual<ICharacterInstances* (__thiscall*)(void*, int)>(this, 82)(this, nSlot);
	}

	EntityId GetEntityIds()
	{
		return CallFunction<EntityId(__thiscall*)(PVOID)>(this, RE_IEntity_GetID)(this);
	}
};

struct IActorSystems
{
public:
	IActors* GetActor(EntityId entityId)
	{
		return Virtual<IActors* (__fastcall*)(void*, EntityId)>(this, 15)(this, entityId);
	}

	void CreateActorIterator(IActorIterators** pActorIterator)
	{
		return Virtual<void(__thiscall*)(void*, IActorIterators**)>(this, 18)(this, pActorIterator);
	}
};

struct IActorIterators
{
public:
	IActors* Next()
	{
		return Virtual<IActors* (__fastcall*)(void*)>(this, 1)(this);
	}
};


struct ISkeletonPoses
{
public:
	int GetJointIDByName(const char* name)
	{
		return Virtual<int(__thiscall*)(PVOID, const char*)>(this, 3)(this, name);
	}

	const char* GetJointNameByID(int nJointID)
	{
		return Virtual<const char* (__thiscall*)(PVOID, int)>(this, 3)(this, nJointID);
	}

	QuatT& GetAbsJointByID(int nJointID)
	{
		return Virtual<QuatT& (__thiscall*)(PVOID, int)>(this, 7)(this, nJointID);
	}
};

struct ICharacterInstances
{
public:
	ISkeletonPoses* GetISkeletonPose()
	{
		return Virtual<ISkeletonPoses* (__thiscall*)(PVOID)>(this, 5)(this);
	}
};
/*

class CMovementComponent
{
	struct SFlightController
	{
		bool	bForward, bBackward,
			bRight, bLeft,
			bUp, bDown;

		bool	bShift;
		bool	bSlow;

		SFlightController() { memset(this, 0, sizeof(SFlightController)); }
	};

public:
	CMovementComponent(IActor* pActor, bool bIsLocal) : m_pActor(pActor), m_bIsLocal(bIsLocal) {};
	void Update();
	void UpdatePlayerScale();

	IActor* m_pActor = NULL;

	float m_teleportStep = 2.f;
	Vec3 m_teleportPos = Vec3(0.f, 0.f, 0.f);

	SFlightController m_flightControl;

	bool m_bRuntimeSync = false;
	bool m_bNoclip = false;
	bool m_bCasper = false;
	bool m_bTeleport = false;

private:
	float m_hasteExtraSpeed = 4.f;
	float m_slideExtraSpeed = 50.f;
	float m_jumpExtraHeight = 20.f;

	float m_flySpeed = 2.f;
	float m_flySpeedFast = 5.f;
	float m_flySpeedSlow = 1.f;

	bool m_bIsLocal = false;

	DWORD64 m_dwLastTime = 0;
	DWORD64 m_dwCasperUpdateLastTime = 0;
	Vec3 m_vLastPos;
	bool m_bNeedsReset = false;

	bool IsEnabled();
};

class CMovementManager
{
public:
	void Update();
	std::list<CMovementComponent*> GetAllComponents();
	CMovementComponent* FindComponent(IActor* pActor);
	void OnKeyDown(WPARAM wKey);
	void OnKeyUp(WPARAM wKey);

	CMovementComponent* m_pClient = NULL;
	std::list<CMovementComponent*> m_players = {};
};

CMovementManager g_syncMovement;

void CMovementManager::Update()
{
	IActor* pClientActor = IGameFramework::Singleton()->get_cli_actor();
	if (!pClientActor)
	{
		if (m_pClient)
		{
			delete m_pClient;
			m_pClient = NULL;
		}
	}
	else
	{
		if (m_pClient)
		{
			if (m_pClient->m_pActor != pClientActor)
			{
				m_pClient->m_pActor = pClientActor;
			}
		}
		else
		{
			m_pClient = new CMovementComponent(pClientActor, true);
		}
	}

	IEntitySystem* pEntitySystem = SSystemGlobalEnvironment::Singleton()->GetIEntitySystem();
	if (!pEntitySystem) return;
	IEntityIt* pEntIterator = pEntitySystem->GetEntityIterator();
	if (!pEntIterator) return;
	IActorSystem* pActorSystem = IGameFramework::Singleton()->GetActorSystem();
	if (!pActorSystem) return;

	// components who point on nonexistent actors
	std::list<CMovementComponent*> m_playersUnused = m_players;

	// creating new components
	while (IEntity* pEnt = pEntIterator->Next())
	{
		IActor* pActor = pActorSystem->GetActor(pEnt->GetEntityId());
		if (!pActor || !pActor->IsPlayer()) continue;

		CMovementComponent* pComp = FindComponent(pActor);
		if (pComp)
		{
			m_playersUnused.remove(pComp);
		}
		else
		{
			m_players.push_back(new CMovementComponent(pActor, false));
		}
	}

	// removing unused components
	if (m_playersUnused.size())
	{
		for (std::list<CMovementComponent*>::iterator it = m_playersUnused.begin(); it != m_playersUnused.end(); ++it)
		{
			CMovementComponent* pComp = *it;
			m_players.remove(pComp);
			delete pComp;
		}
		m_playersUnused.clear();
	}

	// updating components
	std::list<CMovementComponent*> components = GetAllComponents();
	for (std::list<CMovementComponent*>::iterator it = components.begin(); it != components.end(); ++it)
	{
		(*it)->Update();
	}
}*/