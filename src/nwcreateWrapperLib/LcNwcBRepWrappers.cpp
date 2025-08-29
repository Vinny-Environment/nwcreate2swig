#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcBRepEntityWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcBRepEntityWrapper::LcNwcBRepEntityWrapper(const LcNwcBRepEntityWrapper& other)
{
	this->mBRepEntity = new LcNwcBRepEntity(*other.mBRepEntity);
}

LcNwcBRepEntityWrapper::LcNwcBRepEntityWrapper(LtNwcBRepEntity handle)
{
	this->mBRepEntity = new LcNwcBRepEntity(handle);
}

LtNwcBRepEntityTypeWrapper LcNwcBRepEntityWrapper::GetBRepEntityType() const
{
	return (LtNwcBRepEntityTypeWrapper)this->mBRepEntity->GetType();
}

void LcNwcBRepEntityWrapper::SetUserData(int data)
{
	this->mBRepEntity->SetUserData(data);
}

LcNwcBRepEntityWrapper LcNwcBRepEntityWrapper::Copy()
{
	return LcNwcBRepEntityWrapper(this->mBRepEntity->Copy());
}

void LcNwcBRepEntityWrapper::Transform(const LcNwcTransformWrapper& transform)
{
	this->mBRepEntity->Transform(*transform.mTransform);
}

void LcNwcBRepEntityWrapper::Translate(double x, double y, double z)
{
	this->mBRepEntity->Translate(x, y, z);
}

void LcNwcBRepEntityWrapper::Translate(double v[3])
{
	this->mBRepEntity->Translate(v[0], v[1], v[2]);
}

LcNwcBRepEntityWrapper::~LcNwcBRepEntityWrapper()
{
	LiNwcBRepEntityDestroy(*this->mBRepEntity);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcLoopWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcLoopWrapper::LcNwcLoopWrapper() : LcNwcBRepEntityWrapper(*(this->mLoop = new LcNwcLoop()))
{

}

LcNwcLoopWrapper::LcNwcLoopWrapper(LtNwcLoop handle) : LcNwcBRepEntityWrapper(*(this->mLoop = new LcNwcLoop(handle)))
{

}

void LcNwcLoopWrapper::SetType(LtNwcLoopTypeWrapper type)
{
	this->mLoop->SetType((LtNwcLoopType)type);
}

LcNwcLoopWrapper::~LcNwcLoopWrapper()
{
	LiNwcLoopDestroy(*this->mLoop);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcFaceWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcFaceWrapper::LcNwcFaceWrapper(const LcNwcSurfaceWrapper& surface, LtNwcSenseWrapper sense) : LcNwcBRepEntityWrapper(*(this->mFace = new LcNwcFace(*surface.mSurface, (LtNwcSense)sense)))
{

}

LcNwcFaceWrapper::LcNwcFaceWrapper(LtNwcFace handle) : LcNwcBRepEntityWrapper(*(this->mFace = new LcNwcFace(handle)))
{

}

void LcNwcFaceWrapper::AddLoop(const LcNwcLoopWrapper& loop)
{
	this->mFace->AddLoop(*loop.mLoop);
}

LcNwcFaceWrapper::~LcNwcFaceWrapper()
{
	LiNwcFaceDestroy(*this->mFace);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcShellWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcShellWrapper::LcNwcShellWrapper() : LcNwcBRepEntityWrapper(*(this->mShell = new LcNwcShell()))
{

}

LcNwcShellWrapper::LcNwcShellWrapper(LtNwcShell handle) : LcNwcBRepEntityWrapper(*(this->mShell = new LcNwcShell(handle)))
{

}

void LcNwcShellWrapper::AddFace(const LcNwcFaceWrapper& face)
{
	this->mShell->AddFace(*face.mFace);
}

LcNwcShellWrapper::~LcNwcShellWrapper()
{
	LiNwcShellDestroy(*this->mShell);
}
