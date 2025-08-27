#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcNodeWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcNodeWrapper::LcNwcNodeWrapper(LtNwcNode handle)
{
	this->mNode = new LcNwcNode(handle);
}

LcNwcNodeWrapper::LcNwcNodeWrapper(const LcNwcNode& other)
{
	this->mNode = new LcNwcNode(other);
}

void LcNwcNodeWrapper::SetName(const std::wstring& name)
{
	this->mNode->SetName(name.c_str());
}

void LcNwcNodeWrapper::SetClassName(const std::wstring& user_name, const std::string& internal_name)
{
	this->mNode->SetClassName(user_name.c_str(), internal_name.c_str());
}

void LcNwcNodeWrapper::SetHidden(bool b)
{
	this->mNode->SetHidden(b);
}

void LcNwcNodeWrapper::SetRequired(bool b)
{
	this->mNode->SetRequired(b);
}

void LcNwcNodeWrapper::SetTwoSided(bool b)
{
	this->mNode->SetTwoSided(b);
}

void LcNwcNodeWrapper::AddAttribute(const LcNwcAttributeWrapper& attrib)
{
	this->mNode->AddAttribute(*attrib.mAttribute);
}

void LcNwcNodeWrapper::SetEnableAutoMerge(bool b)
{
	this->mNode->SetEnableAutoMerge(b);
}

LcNwcNodeWrapper::~LcNwcNodeWrapper()
{
	LiNwcNodeDestroy(*mNode);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcGroupWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGroupWrapper::LcNwcGroupWrapper() : LcNwcNodeWrapper(*this->mGroup)
{
	this->mGroup = new LcNwcGroup();
}

LcNwcGroupWrapper::LcNwcGroupWrapper(LtNwcGroup handle) : LcNwcNodeWrapper(*this->mGroup)
{
	this->mGroup = new LcNwcGroup(handle);
}

void LcNwcGroupWrapper::SetInsert(bool b)
{
	this->mGroup->SetInsert(b);
}

void LcNwcGroupWrapper::SetLayer(bool b)
{
	this->mGroup->SetLayer(b);
}

void LcNwcGroupWrapper::SetComposite(bool b)
{
	this->mGroup->SetComposite(b);
}

void LcNwcGroupWrapper::SetCollection(bool b)
{
	this->mGroup->SetCollection(b);
}

void LcNwcGroupWrapper::AddNode(const LcNwcNodeWrapper& node)
{
	this->mGroup->AddNode(*node.mNode);
}

LcNwcGroupWrapper::~LcNwcGroupWrapper()
{
	LiNwcGroupDestroy(*this->mGroup);
}