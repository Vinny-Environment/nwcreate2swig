#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------

LcNwcAttributeWrapper::LcNwcAttributeWrapper(const LtNwcAttribute& handle)
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

LcNwcAttributeWrapper::~LcNwcAttributeWrapper() 
{
	LiNwcAttributeDestroy(*mAttribute);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcPropertyAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcPropertyAttributeWrapper::LcNwcPropertyAttributeWrapper() : LcNwcAttributeWrapper(*(this->mPropertyAttribute = new LcNwcPropertyAttribute()))
{

}

LcNwcPropertyAttributeWrapper::LcNwcPropertyAttributeWrapper(const LtNwcPropertyAttribute& handle) : LcNwcAttributeWrapper(*(this->mPropertyAttribute = new LcNwcPropertyAttribute(handle)))
{

}

void LcNwcPropertyAttributeWrapper::AddProperty(const std::wstring& user_name, const std::string& internal_name, const LcNwcDataWrapper& propertyInfo)
{
	mPropertyAttribute->AddProperty(user_name.c_str(), internal_name.c_str(), *propertyInfo.mData);
}

int LcNwcPropertyAttributeWrapper::Size() const
{
	return mPropertyAttribute->Size();
}

LcNwcPropertyAttributeWrapper::~LcNwcPropertyAttributeWrapper()
{
	LiNwcPropertyAttributeDestroy(*mPropertyAttribute);
}