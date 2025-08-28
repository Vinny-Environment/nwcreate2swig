#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSurfaceWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcSurfaceWrapper::LcNwcSurfaceWrapper(const LcNwcSurfaceWrapper& other)
{
	this->mSurface = new LcNwcSurface(*other.mSurface);
}

LcNwcSurfaceWrapper::LcNwcSurfaceWrapper(LtNwcSurface handle)
{
	this->mSurface = new LcNwcSurface(handle);
}

LcNwcSurfaceWrapper LcNwcSurfaceWrapper::Copy()
{
	return LcNwcSurfaceWrapper(this->mSurface->Copy());
}

void LcNwcSurfaceWrapper::SetUserData(int data)
{
	this->mSurface->SetUserData(data);
}

void LcNwcSurfaceWrapper::Evaluate(double u, double v, double pnt[3])
{
	this->mSurface->Evaluate(u, v, pnt);
}

void LcNwcSurfaceWrapper::Transform(const LcNwcTransformWrapper& transform)
{
	this->mSurface->Transform(*transform.mTransform);
}

void LcNwcSurfaceWrapper::Translate(double x, double y, double z)
{
	this->mSurface->Translate(x, y, z);
}

void LcNwcSurfaceWrapper::Translate(double v[3])
{
	this->mSurface->Translate(v[0], v[1], v[2]);
}

LcNwcSurfaceWrapper::~LcNwcSurfaceWrapper()
{
	LiNwcSurfaceDestroy(*this->mSurface);
}