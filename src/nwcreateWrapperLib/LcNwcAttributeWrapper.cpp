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
// LcNwcTransformWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcTransformWrapper::LcNwcTransformWrapper(double x, double y, double z) : LcNwcAttributeWrapper(*(this->mTransform = new LcNwcTransform(x , y, z)))
{

}

LcNwcTransformWrapper::LcNwcTransformWrapper(double rX, double rY, double rZ, double rA, double tX, double tY, double tZ) : LcNwcAttributeWrapper(*(this->mTransform = new LcNwcTransform(rX, rY, rZ, rA, tX, tY, tZ)))
{

}

LcNwcTransformWrapper::LcNwcTransformWrapper(double matrix[16], bool reverses) : LcNwcAttributeWrapper(*(this->mTransform = new LcNwcTransform(matrix, reverses)))
{

}

LcNwcTransformWrapper::LcNwcTransformWrapper(const LtNwcTransform& handle) : LcNwcAttributeWrapper(*(this->mTransform = new LcNwcTransform(handle)))
{

}

LcNwcTransformWrapper::~LcNwcTransformWrapper()
{
	LiNwcTransformDestroy(*this->mTransform);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcMaterialWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcMaterialWrapper::LcNwcMaterialWrapper() : LcNwcAttributeWrapper(*(this->mMaterial = new LcNwcMaterial()))
{

}

LcNwcMaterialWrapper::LcNwcMaterialWrapper(const LtNwcMaterial& handle) : LcNwcAttributeWrapper(*(this->mMaterial = new LcNwcMaterial(handle)))
{

}

void LcNwcMaterialWrapper::SetDiffuseColor(double r, double g, double b)
{
	this->mMaterial->SetDiffuseColor(r, g, b);
}

void LcNwcMaterialWrapper::SetAmbientColor(double r, double g, double b)
{
	this->mMaterial->SetAmbientColor(r, g, b);
}

void LcNwcMaterialWrapper::SetSpecularColor(double r, double g, double b)
{
	this->mMaterial->SetSpecularColor(r, g, b);
}

void LcNwcMaterialWrapper::SetEmissiveColor(double r, double g, double b)
{
	this->mMaterial->SetEmissiveColor(r, g, b);
}

void LcNwcMaterialWrapper::SetShininess(double t)
{
	this->mMaterial->SetShininess(t);
}

void LcNwcMaterialWrapper::SetTransparency(double t)
{
	this->mMaterial->SetTransparency(t);
}

LcNwcMaterialWrapper::~LcNwcMaterialWrapper()
{
	LiNwcMaterialDestroy(*this->mMaterial);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSemanticPriorityWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcSemanticPriorityWrapper::LcNwcSemanticPriorityWrapper() : LcNwcAttributeWrapper(*(this->mSemanticPriority = new LcNwcSemanticPriority()))
{

}

LcNwcSemanticPriorityWrapper::LcNwcSemanticPriorityWrapper(const LtNwcSemanticPriority& handle) : LcNwcAttributeWrapper(*(this->mSemanticPriority = new LcNwcSemanticPriority(handle)))
{

}

void LcNwcSemanticPriorityWrapper::SetPriority(double priority)
{
	this->mSemanticPriority->SetPriority(priority);
}

LcNwcSemanticPriorityWrapper::~LcNwcSemanticPriorityWrapper()
{
	LiNwcSemanticPriorityDestroy(*this->mSemanticPriority);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcTextAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcTextAttributeWrapper::LcNwcTextAttributeWrapper() : LcNwcAttributeWrapper(*(this->mTextAttribute = new LcNwcTextAttribute()))
{

}

LcNwcTextAttributeWrapper::LcNwcTextAttributeWrapper(const LtNwcTextAttribute& handle) : LcNwcAttributeWrapper(*(this->mTextAttribute = new LcNwcTextAttribute(handle)))
{

}

void LcNwcTextAttributeWrapper::SetText(const std::wstring& text)
{
	this->mTextAttribute->SetText(text.c_str());
}

LcNwcTextAttributeWrapper::~LcNwcTextAttributeWrapper()
{
	LiNwcTextAttributeDestroy(*this->mTextAttribute);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcNameAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcNameAttributeWrapper::LcNwcNameAttributeWrapper() : LcNwcAttributeWrapper(*(this->mNameAttribute = new LcNwcNameAttribute()))
{

}

LcNwcNameAttributeWrapper::LcNwcNameAttributeWrapper(const LtNwcNameAttribute& handle) : LcNwcAttributeWrapper(*(this->mNameAttribute = new LcNwcNameAttribute(handle)))
{

}

void LcNwcNameAttributeWrapper::SetStableId(bool b)
{
	this->mNameAttribute->SetStableId(b);
}

LcNwcNameAttributeWrapper::~LcNwcNameAttributeWrapper()
{
	LiNwcNameAttributeDestroy(*this->mNameAttribute);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcNat64AttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcNat64AttributeWrapper::LcNwcNat64AttributeWrapper() : LcNwcAttributeWrapper(*(this->mNat64Attribute = new LcNwcNat64Attribute()))
{

}

LcNwcNat64AttributeWrapper::LcNwcNat64AttributeWrapper(const LtNwcNat64Attribute& handle) : LcNwcAttributeWrapper(*(this->mNat64Attribute = new LcNwcNat64Attribute(handle)))
{

}

void LcNwcNat64AttributeWrapper::SetStableId(bool b)
{
	this->mNat64Attribute->SetStableId(b);
}

void LcNwcNat64AttributeWrapper::SetValue(double value)
{
	this->mNat64Attribute->SetValue(value);
}

void LcNwcNat64AttributeWrapper::DisplayValueAsDecimal()
{
	this->mNat64Attribute->SetDisplayFormat(LtNwcNat64AttributeFormat::LI_NWC_NAT64_FORMAT_DECIMAL);
}

void LcNwcNat64AttributeWrapper::DisplayValueAsHexaDecimal()
{
	this->mNat64Attribute->SetDisplayFormat(LtNwcNat64AttributeFormat::LI_NWC_NAT64_FORMAT_HEXADECIMAL);
}

LcNwcNat64AttributeWrapper::~LcNwcNat64AttributeWrapper()
{
	LiNwcNat64AttributeDestroy(*this->mNat64Attribute);
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

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcURLAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcURLAttributeWrapper::LcNwcURLAttributeWrapper() : LcNwcAttributeWrapper(*(this->mURLAttribute = new LcNwcURLAttribute()))
{

}

LcNwcURLAttributeWrapper::LcNwcURLAttributeWrapper(const LtNwcURLAttribute& handle) : LcNwcAttributeWrapper(*(this->mURLAttribute = new LcNwcURLAttribute(handle)))
{

}

void LcNwcURLAttributeWrapper::AddURL(const std::wstring& name, const std::wstring& url)
{
	this->mURLAttribute->AddURL(name.c_str(), url.c_str());
}

void LcNwcURLAttributeWrapper::AddURLEx(const std::wstring& name, const std::wstring& url, const std::wstring& category_user_name, const std::string& category_internal_name)
{
	this->mURLAttribute->AddURLEx(name.c_str(), url.c_str(), category_user_name.c_str(), category_internal_name.c_str());
}

void LcNwcURLAttributeWrapper::AddAttachmentPoint(double x, double y, double z)
{
	this->mURLAttribute->AddAttachmentPoint(x, y, z);
}

LcNwcURLAttributeWrapper::~LcNwcURLAttributeWrapper()
{
	LiNwcURLAttributeDestroy(*this->mURLAttribute);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcBinaryAttributeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcBinaryAttributeWrapper::LcNwcBinaryAttributeWrapper() : LcNwcAttributeWrapper(*(this->mBinaryAttribute = new LcNwcBinaryAttribute()))
{

}

LcNwcBinaryAttributeWrapper::LcNwcBinaryAttributeWrapper(const LtNwcBinaryAttribute& handle) : LcNwcAttributeWrapper(*(this->mBinaryAttribute = new LcNwcBinaryAttribute(handle)))
{

}

void LcNwcBinaryAttributeWrapper::SetValue(const unsigned char*& data, int length)
{
	this->mBinaryAttribute->SetValue(data, length);
}

LcNwcBinaryAttributeWrapper::~LcNwcBinaryAttributeWrapper()
{
	LiNwcBinaryAttributeDestroy(*this->mBinaryAttribute);
}

