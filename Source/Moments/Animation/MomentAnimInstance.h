#pragma once

#include "Animation/AnimInstance.h"
#include "MomentAnimInstance.generated.h"

class UAnimMontage; // Forward declaration

UCLASS()
class MOMENTS_API UMomentAnimInstance : public UAnimInstance
{
	GENERATED_UCLASS_BODY()

	//> UObject Interface
	virtual void PostLoad() override;

	virtual void BeginDestroy() override;

	virtual void NativeBeginPlay() override;

	//> AnimInstance Interface
	virtual void NativeInitializeAnimation() override;
	//virtual void NativeUninitializeAnimation() override;

	virtual void PreUpdateAnimation(float DeltaSeconds) override;
	//virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	bool IsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	bool IsAccelerating;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	bool FullBody;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float Pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float Roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float Yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float YawDelta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	float StopDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MomentAnimInstance, meta = (AllowPrivateAccess = "true"))
	FRotator RotationLastTick;
};