#include "nwcreateApi.hpp"

#define LI_NWC_NO_PROGRESS_CALLBACKS NULL
#define LI_NWC_NO_USER_DATA NULL

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSceneWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcSceneWrapper::LcNwcSceneWrapper()
{
	LiNwcApiInitialise();
	this->mScene = new LcNwcScene();
}

void LcNwcSceneWrapper::AddNode(const LcNwcNodeWrapper& node)
{
	this->mScene->AddNode(*node.mNode);
}

void LcNwcSceneWrapper::WriteCache(const std::wstring& orig_filename, const std::wstring& filename)
{
	this->mScene->WriteCache(orig_filename.c_str(), filename.c_str(), LI_NWC_NO_PROGRESS_CALLBACKS, LI_NWC_NO_USER_DATA);
}

LcNwcSceneWrapper::~LcNwcSceneWrapper() 
{
	LiNwcSceneDestroy(*this->mScene);
}