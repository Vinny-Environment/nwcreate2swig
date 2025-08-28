#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcDataWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcDataWrapper::LcNwcDataWrapper() 
{
	this->mData = new LcNwcData();
}

void LcNwcDataWrapper::SetFloat(double value)
{
	mData->SetFloat(value);
}

void LcNwcDataWrapper::SetLinearFloat(double value)
{
	mData->SetLinearFloat(value);
}

void LcNwcDataWrapper::SetAreaFloat(double value)
{
	mData->SetAreaFloat(value);
}

void LcNwcDataWrapper::SetVolumeFloat(double value)
{
	mData->SetVolumeFloat(value);
}

void LcNwcDataWrapper::SetAngularFloat(double value)
{
	mData->SetAngularFloat(value);
}

void LcNwcDataWrapper::SetBoolean(bool value)
{
	mData->SetBoolean(value);
}

void LcNwcDataWrapper::SetInt32(int value)
{
	mData->SetInt32(value);
}

void LcNwcDataWrapper::SetInt64(long long value)
{
	mData->SetInt64(value);
}

void LcNwcDataWrapper::SetWideString(const std::wstring& value)
{
	mData->SetWideString(value.c_str());
}

void LcNwcDataWrapper::SetTime(long long value)
{
	mData->SetTime(value);
}

void LcNwcDataWrapper::SetName(const std::wstring& user_name, const std::string& internal_name)
{
	mData->SetName(user_name.c_str(), internal_name.c_str());
}

void LcNwcDataWrapper::SetNameEnum(const std::wstring& user_name, const std::string& internal_name, int value)
{
	mData->SetNameEnum(user_name.c_str(), internal_name.c_str(), value);
}

void LcNwcDataWrapper::SetPoint3D(double x, double y, double z)
{
	mData->SetPoint3D(x, y, z);
}

LcNwcDataWrapper::~LcNwcDataWrapper()
{
	LiNwcDataDestroy(*this->mData);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcDataWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGuidWrapper::LcNwcGuidWrapper(const std::wstring& guid)
{
	this->mGuid = new LcNwcGuid(LiNwcGuidCreateFromGuidString(guid.c_str()));
}

LcNwcGuidWrapper::~LcNwcGuidWrapper()
{
	LiNwcGuidDestroy(*this->mGuid);
}