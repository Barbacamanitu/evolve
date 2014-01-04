#pragma once
class SkeletalComponent;
class CCDWorldBone
{
public:
	CCDWorldBone(void);
	~CCDWorldBone(void);
	void SetSkeletalComponent(SkeletalComponent* sComp)
	{
		mSkeletalComponent = sComp;
	};

	SkeletalComponent* GetSkeletalComponent()
	{
		return mSkeletalComponent;
	};


private:
	SkeletalComponent* mSkeletalComponent;
};

