#include "MomentAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../MomentsCharacter.h"

UMomentAnimInstance::UMomentAnimInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMomentAnimInstance::PostLoad()
{
	Super::PostLoad();
}

void UMomentAnimInstance::BeginDestroy()
{
	Super::BeginDestroy();
}

void UMomentAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UMomentAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UMomentAnimInstance::PreUpdateAnimation(float DeltaSeconds)
{
	Super::PreUpdateAnimation(DeltaSeconds);

	if( !TryGetPawnOwner()->IsValidLowLevel() )
		return;

	AMomentsCharacter* _Character = Cast<AMomentsCharacter>(TryGetPawnOwner());
	if (!_Character)
		return;

	IsInAir = TryGetPawnOwner()->GetMovementComponent()->IsFalling();
	Speed = TryGetPawnOwner()->GetVelocity().Length();
	FRotator _Rotator = UKismetMathLibrary::NormalizedDeltaRotator(TryGetPawnOwner()->GetBaseAimRotation(), TryGetPawnOwner()->GetActorRotation());
	Roll = _Rotator.Roll;
	Pitch = _Rotator.Pitch;
	Yaw = _Rotator.Yaw;

	_Rotator = UKismetMathLibrary::NormalizedDeltaRotator(TryGetPawnOwner()->GetActorRotation(), RotationLastTick);
	YawDelta = UKismetMathLibrary::FInterpTo(YawDelta, (_Rotator.Yaw / DeltaSeconds) / 15.f, DeltaSeconds, 10.f);
	RotationLastTick = TryGetPawnOwner()->GetActorRotation();

	IsAccelerating = (_Character->GetCharacterMovement()->GetCurrentAcceleration().Length() > 0);

	float _Temp = 0.f;
	GetCurveValue("FullBody", _Temp);
	FullBody = (_Temp > 0);

	FRotator _FromX = UKismetMathLibrary::MakeRotFromX(TryGetPawnOwner()->GetVelocity());
	_Rotator = UKismetMathLibrary::NormalizedDeltaRotator(TryGetPawnOwner()->GetActorRotation(), _FromX);
	Direction = _Rotator.Yaw * -1.f;

	if(IsAccelerating)
		StopDirection = Direction;
}


