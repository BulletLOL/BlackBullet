#pragma once
#include "Classes.h"
#include <cstddef>
#include "Function.h"
#include "cMath.h"
#include "cClasses.h"
D3DVIEWPORT9 Viewport;

bool GetTeamss(IActors* myActor, IActors* enemyActor)
{
	if (SSystemGlobalEnvironments::Singleton())
	{
		int myTeam = SSystemGlobalEnvironments::Singleton()->pGame->GetIGameFramework()->GetIGameRules()->GetTeam(myActor->GetLinkedEntity()->GetId());
		int enemyTeam = SSystemGlobalEnvironments::Singleton()->pGame->GetIGameFramework()->GetIGameRules()->GetTeam(enemyActor->GetLinkedEntity()->GetId());

		if (myTeam != enemyTeam
			|| myTeam == NULL)
			return true;
		else
			return false;
	}
}

Vec3 GetBonePositionById(IEntitys* pIEntity, int iBoneId, Vec3 vOffset = { ZERO })
{
	if (ICharacterInstances* pICharacterInstance = pIEntity->GetCharacter(0))
	{
		if (ISkeletonPoses* pISkeletonPose = pICharacterInstance->GetISkeletonPose())
		{
			Matrix34 pMatrix34 = pIEntity->GetWorldTM() * Matrix34(pISkeletonPose->GetAbsJointByID(iBoneId));

			Vec3 vOutput = pMatrix34.GetTranslation() + vOffset;

			return vOutput;
		}
		else return ZERO;
	}
	else return ZERO;
}

void ClientHitByEnemy(IActors* shooterId, IActors* targetId, Vec3 vPos, unsigned long projectileId, int partId)
{
	IItems* pIItem = nullptr;
	IGameFrameworks* pIGameFramework = nullptr;
	IMovementController* pIMovementController = nullptr;

	if (pIGameFramework = SSystemGlobalEnvironments::Singleton()->pGame->GetIGameFramework())
	{
		if (shooterId && targetId
			&& !shooterId->IsDead()
			&& !targetId->IsDead())
		{
			pIItem = shooterId->GetCurrentItem();
			if (pIItem)
			{
				pIMovementController = shooterId->GetMovementController();
				if (pIMovementController)
				{
					SMovementState pSMovementState;
					pIMovementController->GetMovementState(pSMovementState);

					SGameClientHitInfo pSGameClientHitInfo;

					pSGameClientHitInfo.shooterId = shooterId->GetLinkedEntity()->GetId();
					pSGameClientHitInfo.targetId = targetId->GetLinkedEntity()->GetId();

					pSGameClientHitInfo.material = pIGameFramework->GetIGameRules()->GetHitMaterialId("mat_head");

					pSGameClientHitInfo.type = pIGameFramework->GetIGameRules()->GetHitTypeId("melee");



					pSGameClientHitInfo.partId = partId;

					pSGameClientHitInfo.pos = vPos;
					pSGameClientHitInfo.dir = pSGameClientHitInfo.pos - pSMovementState.weaponPosition;
					pSGameClientHitInfo.shootPos = pSMovementState.weaponPosition;

					pSGameClientHitInfo.itemId = shooterId->GetCurrentItem()->GetCurrentItemId();
					pSGameClientHitInfo.projectileId = projectileId;
					pSGameClientHitInfo.itemType = 65535;

					pSGameClientHitInfo.normal = pSGameClientHitInfo.dir * -1.f;

					pSGameClientHitInfo.distanceToHit = 1.f;
					pSGameClientHitInfo.penetrationCount = 0;

					pIGameFramework->GetIGameRules()->ClientHit(&pSGameClientHitInfo);
				}
			}
		}
	}
}


bool CheckBoneFromActor(IEntitys* pIEntity, Vec3& vPos, int& partId)
{
	partId = 13;

	vPos = GetBonePositionById(pIEntity, partId);

	return true;
}

Vec3 GetBonePositionByID(IEntity* Entity, INT BoneID)
{
	ICharacterInstance* CharacterInstance = Entity->GetCharacter(0);

	if (!CharacterInstance)
	{
		return Vec3{ 0,0,0 };
	}

	ISkeletonPose* SkeletonPose = CharacterInstance->GetISkeletonPose();

	if (!SkeletonPose)
	{
		return Vec3{ 0,0,0 };
	}

	Matrix34 MatrixWorld = Entity->GetWorldTM() * Matrix34(SkeletonPose->GetAbsJointByID(BoneID));

	return MatrixWorld.GetTranslation();
}

float Distance(Vec3 VecA, Vec3 VecB)
{
	return sqrt(((VecA.x - VecB.x) * (VecA.x - VecB.x)) + ((VecA.y - VecB.y) * (VecA.y - VecB.y)) + ((VecA.z - VecB.z) * (VecA.z - VecB.z)));
}

Vec3 TargetPos = ZERO;

int GetTeam(IActor* Actor)
{
	IGameFramework* pFrameWork = IGameFramework::Singleton();
	if (Actor)
		return pFrameWork->get_GAME_RULES()->GetTeam(Actor->GetEntity()->GetEntityId());//pEnt->GetID()
}

bool MyTeam(IActor* MyPlayer, IActor* EnemyPlayer)
{
	int mTeam = GetTeam(MyPlayer);
	int pTeam = GetTeam(EnemyPlayer);

	if ((mTeam != pTeam || pTeam == 0))
		return true;
	else
		return false;
}

bool GetDeadPlayer(IActor* Player)
{
	if (Player->IsDead()) return true;
	else return false;
}

bool WorldToScreen(Vec3 vEntPos, Vec3* sPos)
{

	IRenderer::w2s_info info;
	info.Posx = vEntPos.x;
	info.Posy = vEntPos.y;
	info.Posz = vEntPos.z;

	info.Scrnx = &sPos->x;
	info.Scrny = &sPos->y;
	info.Scrnz = &sPos->z;

	SSystemGlobalEnvironment::Singleton()->GetIRenderer()->ProjectToScreen(&info);

	if (sPos->z < 0.0f || sPos->z > 1.0f) {
		return 0;
	}

	sPos->x *= (Viewport.Width / 100.0f);
	sPos->y *= (Viewport.Height / 100.0f);
	return TRUE;
}

Vec3 GetPlayerPos(IEntity* pEntit)
{
	Vec3 vOffset = Vec3();
	Matrix34 pWorld = pEntit->GetWorldTM();
	vOffset = pWorld.GetTranslation();
	return vOffset;
}

void Aim(IActor* MyActor, Vec3 EnemyBone)
{
	Vec3 vDiffer;
	vDiffer = EnemyBone - GetBonePositionByID(MyActor->GetEntity(), 13);//13 is head pvp
	Quat FinalHeadPos = Quat::CreateRotationVDir(vDiffer.normalize());//FinalHeadPos = CalculatedRotation, vDiffer = BulletLine
	MyActor->GetPlayer()->SetViewRotation(FinalHeadPos);
}

VOID AimType2(IActor* MyActor, Vec3 MyPosition, Vec3 TargetPos)
{
	Vec3 BulletLine = { 0, 0, 0 };

	BulletLine.x = TargetPos.x - MyPosition.x;
	BulletLine.y = TargetPos.y - MyPosition.y;
	BulletLine.z = TargetPos.z - MyPosition.z;

	float Sqrt = sqrtf(BulletLine.x * BulletLine.x + BulletLine.y * BulletLine.y + BulletLine.z * BulletLine.z);
	BulletLine.x = BulletLine.x / Sqrt;
	BulletLine.y = BulletLine.y / Sqrt;
	BulletLine.z = (BulletLine.z) / Sqrt;
	Quat CalculatedRotation = Quat::CreateRotationVDir(BulletLine.GetNormalized());
	MyActor->GetPlayer()->SetViewRotation(CalculatedRotation);

}

float GetHypotenuse(Vec3 vPos) {

	Vec3 vScreen = { 0,0,0 };
	if (WorldToScreen(vPos, &vScreen)) {
		FLOAT PositionX = 0.f;
		FLOAT PositionY = 0.f;
		FLOAT ScreenCenterX = (Viewport.Width * 0.5f);
		FLOAT ScreenCenterY = (Viewport.Height * 0.5f);
		PositionX = vScreen.x > ScreenCenterX ? vScreen.x - ScreenCenterX : ScreenCenterX - vScreen.x;
		PositionY = vScreen.y > ScreenCenterY ? vScreen.y - ScreenCenterY : ScreenCenterY - vScreen.y;
		return sqrt(PositionX * PositionX + PositionY * PositionY);
	}
}

// try now
IActor* GetNearest()
{
	float TempDistance = 99999999.9f;

	IActor* LocalActor = nullptr;
	IActor* NearestActor = nullptr;
	IActorSystem* ActorSystem = nullptr;
	IActorIterator* ActorIterator = nullptr;
	auto Pframe = IGameFramework::Singleton();
	auto pEntIt = SSystemGlobalEnvironment::Singleton()->GetIEntitySystem()->GetEntityIterator();
	Vec3 ScreenPos = { 0,0,0 };
	if (Pframe->get_cli_actor(&LocalActor)) {
		if (LocalActor && pEntIt)
			for (; IEntity * pEnt = pEntIt->Next(); )
			{
				if (IActor* LocPlayer = Pframe->GetActorSystem()->GetActor(pEnt->GetEntityId()))
				{
					if (LocalActor != LocPlayer) {
						if (IGameFramework::Singleton()->IsMyTeam(LocalActor, LocPlayer) && (!GetDeadPlayer(LocPlayer))) {
							Vec3 LocalPos = GetBonePositionByID(LocalActor->GetEntity(), 13);
							Vec3 Bone = GetBonePositionByID(pEnt, 13);
							auto Distances = Distance(LocalPos, Bone);

							if (Distances < TempDistance)
							{
								NearestActor = LocPlayer;
								TempDistance = Distances;
							}
						}
					}
				}
			}
	}
	return NearestActor;
}

IPhysicalWorld* GGetPhysicalWorld = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld();
