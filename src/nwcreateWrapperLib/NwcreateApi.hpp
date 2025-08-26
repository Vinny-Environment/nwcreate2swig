#pragma once

#define CLASS_DECLSPEC __declspec(dllexport)

#include "string"
#include "nwcreate/LiNwcAll.h"
//class LcNwcData;

/**@brief A wrapper class around LcNwcData API
*/
class CLASS_DECLSPEC LcNwcDataWrapper {
public:
	LcNwcDataWrapper();
	void SetFloat(double value);
	void SetLinearFloat(double value);
	void SetAreaFloat(double value);
	void SetVolumeFloat(double value);
	void SetAngularFloat(double value);
	void SetBoolean(bool value);
	void SetInt32(int value);
	void SetInt64(long long value);
	void SetWideString(const std::wstring& value);
	void SetTime(long long value);
	void SetName(const std::wstring& user_name, const std::string& internal_name);
	void SetNameEnum(const std::wstring& user_name, const std::string& internal_name, int value);
	void SetPoint3D(double x, double y, double z);

	~LcNwcDataWrapper();
private:
	LcNwcData mData;
};

/*
class NwcPropertyAttribute {
public:
	friend class NwcGroupWrapper;

	NwcPropertyAttribute();
	void SetName(const std::wstring& name);
	void SetClassName(const std::wstring& userName, const std::wstring& internalName);
	void SetInternal(bool value);
	void AddProperty(const std::wstring& user_name, const std::wstring& internal_name, LtNwcData property)
private:
	LcNwcPropertyAttribute mPropertyAttribute;
};

class NwcGroupWrapper {
public:
	NwcGroupWrapper();
	void SetName(const std::wstring& name);
	
	void AddAttribute(const NwcPropertyAttribute& attribute);

	void SetInsert(bool b);
	void SetLayer(bool b);
	void SetComposite(bool b);
	void SetCollection(bool b);
	void AddNode();
private:
	LcNwcGroup mGroup;
};
class NwcreateApi
{
public:
	NwcreateApi();

	void SaveProject(const std::wstring& savePath);

private:
	LcNwcScene mScene;
};

*/

// endif