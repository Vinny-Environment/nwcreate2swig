#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------

LcNwcAttributeWrapper::LcNwcAttributeWrapper(LtNwcAttribute handle)
{
	mAttribute = new LcNwcAttribute(handle);
}

LcNwcAttributeWrapper::LcNwcAttributeWrapper(const LcNwcAttribute& other)
{
	mAttribute = new LcNwcAttribute(other);
}

void LcNwcAttributeWrapper::SetName(const std::wstring& name)
{
	mAttribute->SetName(name.c_str());
}

void LcNwcAttributeWrapper::SetClassName(const std::wstring& user_name, const std::string& internal_name)
{
	mAttribute->SetClassName(user_name.c_str(), internal_name.c_str());
}

void LcNwcAttributeWrapper::SetInternal(bool value)
{
	mAttribute->SetInternal(value);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcPropertyAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcPropertyAttributeWrapper::LcNwcPropertyAttributeWrapper() : LcNwcAttributeWrapper(LiNwcPropertyAttributeCreate())
{
	mPropertyAttribute = new LcNwcPropertyAttribute();
}

LcNwcPropertyAttributeWrapper::LcNwcPropertyAttributeWrapper(LtNwcPropertyAttribute handle) : LcNwcAttributeWrapper(handle)
{
	mPropertyAttribute = new LcNwcPropertyAttribute(handle);
}

void LcNwcPropertyAttributeWrapper::AddProperty(const std::wstring& user_name, const std::string& internal_name, LcNwcDataWrapper propertyInfo)
{
	mPropertyAttribute->AddProperty(user_name.c_str(), internal_name.c_str(), propertyInfo.mData);
}

int LcNwcPropertyAttributeWrapper::Size() const
{
	return mPropertyAttribute->Size();
}