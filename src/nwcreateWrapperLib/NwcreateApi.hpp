#pragma once

//#define CLASS_DECLSPEC __declspec(dllexport)

class LcNwcDataWrapper;
class LcNwcAttributeWrapper;
class LcNwcPropertyAttributeWrapper;
class LcNwcNodeWrapper;
class LcNwcGroupWrapper;
class LcNwcSceneWrapper;

#include "Headers.hpp"
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
protected:
	friend class LcNwcPropertyAttributeWrapper;
private:
	LcNwcData* mData;
};

/**@brief A wrapper class around LcNwcAttribute API
*/
class CLASS_DECLSPEC LcNwcAttributeWrapper {
public:
	void SetName(const std::wstring& name);
	void SetClassName(const std::wstring& user_name, const std::string& internal_name);
	void SetInternal(bool value);
	~LcNwcAttributeWrapper();
protected:
	friend class LcNwcNodeWrapper;
	friend class LcNwcPropertyAttributeWrapper;
	LcNwcAttributeWrapper(const LtNwcAttribute& handle);
	LcNwcAttributeWrapper(const LcNwcAttribute& other);
private:
	LcNwcAttribute* mAttribute;
};

/**@brief A wrapper class around LcNwcPropertyAttribute API
*/
class CLASS_DECLSPEC LcNwcPropertyAttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcPropertyAttributeWrapper();
	void AddProperty(const std::wstring& user_name, const std::string& internal_name, const LcNwcDataWrapper& propertyInfo);
	int Size() const;
	~LcNwcPropertyAttributeWrapper();
protected:
	LcNwcPropertyAttributeWrapper(const LtNwcPropertyAttribute& handle);
private:
	LcNwcPropertyAttribute* mPropertyAttribute;
};


/**@brief A wrapper class around LcNwcNode API
*/
class CLASS_DECLSPEC LcNwcNodeWrapper
{
protected:
	friend class LcNwcGroupWrapper;
	friend class LcNwcSceneWrapper;
	LcNwcNodeWrapper(LtNwcNode handle);
	LcNwcNodeWrapper(const LcNwcNode& other);
public:
	void SetName(const std::wstring& name);
	//void SetGuid(LtNwcGuidWrapper guid);
	void SetClassName(const std::wstring& user_name, const std::string& internal_name);
	void SetHidden(bool b);
	void SetRequired(bool b);
	void SetTwoSided(bool b);
	void AddAttribute(const LcNwcAttributeWrapper& attrib);
	void SetEnableAutoMerge(bool b);
	~LcNwcNodeWrapper();
private:
	LcNwcNode* mNode;
};

/**@brief A wrapper class around LcNwcGroup API
*/
class CLASS_DECLSPEC LcNwcGroupWrapper : public LcNwcNodeWrapper
{	
public:
	LcNwcGroupWrapper();
	void SetInsert(bool b);
	void SetLayer(bool b);
	void SetComposite(bool b);
	void SetCollection(bool b);
	void AddNode(const LcNwcNodeWrapper& node);
	~LcNwcGroupWrapper();
//protected:
//	LcNwcGroupWrapper(const LtNwcGroup& handle);
private:
	LcNwcGroup* mGroup;
};

/**@brief A wrapper class around LcNwcScene API
*/
class CLASS_DECLSPEC LcNwcSceneWrapper
{
public:
	LcNwcSceneWrapper();
	void AddNode(const LcNwcNodeWrapper& node);
	void WriteCache(const std::wstring& orig_filename, const std::wstring& filename);
	~LcNwcSceneWrapper();
private:
	LcNwcScene* mScene;
};
