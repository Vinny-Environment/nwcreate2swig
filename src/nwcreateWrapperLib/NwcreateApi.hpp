#pragma once

//#define NWCREATE_SWIG_API __declspec(dllexport)

class LcNwcDataWrapper;
class LcNwcGuidWrapper;

class LcNwcAttributeWrapper;
class LcNwcTransformWrapper;
class LcNwcMaterialWrapper;
class LcNwcSemanticPriorityWrapper;
class LcNwcTextAttributeWrapper;
class LcNwcNameAttributeWrapper;
class LcNwcNat64AttributeWrapper;
class LcNwcPropertyAttributeWrapper;
class LcNwcURLAttributeWrapper;
class LcNwcBinaryAttributeWrapper;


class LcNwcNodeWrapper;
class LcNwcGroupWrapper;
class LcNwcSceneWrapper;



#include "Headers.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// Data types
//-----------------------------------------------------------------------------------------------------------------------

/**@brief A wrapper class around LcNwcData API
*/
class NWCREATE_SWIG_API LcNwcDataWrapper {
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

/**@brief A paretially wrapper class around LcNwcGuid API
*/
class NWCREATE_SWIG_API LcNwcGuidWrapper {
public:
	LcNwcGuidWrapper(const std::wstring& guid);
	~LcNwcGuidWrapper();
protected:
	friend class LcNwcNodeWrapper;
private:
	LcNwcGuid* mGuid;
};

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcAttribute and inherits
// 
// LiNwcTransform+
// 
// LiNwcMaterial+
// 
// LiNwcSemanticPriority+
// 
// LiNwcTextAttribute+
// LiNwcNameAttribute+
// LiNwcNat64Attribute+
// LiNwcPropertyAttribute+
// LiNwcURLAttribute+
// LiNwcBinaryAttribute
// 
//-----------------------------------------------------------------------------------------------------------------------

/**@brief A wrapper class around LcNwcAttribute API
*/
class NWCREATE_SWIG_API LcNwcAttributeWrapper {
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

/**@brief A wrapper class around LcNwcTransform API
*/
class NWCREATE_SWIG_API LcNwcTransformWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcTransformWrapper(double x, double y, double z);
	LcNwcTransformWrapper(double rX, double rY, double rZ, double rA, double tX, double tY, double tZ);
	LcNwcTransformWrapper(double matrix[16], bool reverses);
	~LcNwcTransformWrapper();
protected:
	LcNwcTransformWrapper(const LtNwcTransform& handle);
	
private:
	LcNwcTransform* mTransform;
};

/**@brief A partially wrapper class around LcNwcMaterial API
*/
class NWCREATE_SWIG_API LcNwcMaterialWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcMaterialWrapper();
	void SetDiffuseColor(double r, double g, double b);
	void SetAmbientColor(double r, double g, double b);
	void SetSpecularColor(double r, double g, double b);
	void SetEmissiveColor(double r, double g, double b);
	void SetShininess(double t);
	void SetTransparency(double t);
	~LcNwcMaterialWrapper();
protected:
	LcNwcMaterialWrapper(const LtNwcMaterial& handle);
private:
	LcNwcMaterial* mMaterial;
};

/**@brief A wrapper class around LcNwcSemanticPriority API
*/
class NWCREATE_SWIG_API LcNwcSemanticPriorityWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcSemanticPriorityWrapper();
	void SetPriority(double priority);
	~LcNwcSemanticPriorityWrapper();
protected:
	LcNwcSemanticPriorityWrapper(const LtNwcSemanticPriority& handle);
private:
	LcNwcSemanticPriority* mSemanticPriority;
};

/**@brief A wrapper class around LcNwcTextAttribute API
*/
class NWCREATE_SWIG_API LcNwcTextAttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcTextAttributeWrapper();
	void SetText(const std::wstring& text);
	~LcNwcTextAttributeWrapper();
protected:
	LcNwcTextAttributeWrapper(const LtNwcTextAttribute& handle);
private:
	LcNwcTextAttribute* mTextAttribute;
};

/**@brief A wrapper class around LcNwcNameAttribute API
*/
class NWCREATE_SWIG_API LcNwcNameAttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcNameAttributeWrapper();
	void SetStableId(bool b);
	~LcNwcNameAttributeWrapper();
protected:
	LcNwcNameAttributeWrapper(const LtNwcNameAttribute& handle);
private:
	LcNwcNameAttribute* mNameAttribute;
};

/**@brief A wrapper class around LcNwcNat64Attribute API
*/
class NWCREATE_SWIG_API LcNwcNat64AttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcNat64AttributeWrapper();
	void SetStableId(bool b);
	void SetValue(double value);
	void DisplayValueAsDecimal();
	void DisplayValueAsHexaDecimal();
	~LcNwcNat64AttributeWrapper();
protected:
	LcNwcNat64AttributeWrapper(const LtNwcNat64Attribute& handle);
private:
	LcNwcNat64Attribute* mNat64Attribute;
};

/**@brief A wrapper class around LcNwcPropertyAttribute API
*/
class NWCREATE_SWIG_API LcNwcPropertyAttributeWrapper : public LcNwcAttributeWrapper
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

/**@brief A wrapper class around LcNwcURLAttribute API
*/
class NWCREATE_SWIG_API LcNwcURLAttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcURLAttributeWrapper();
	void AddURL(const std::wstring& name, const std::wstring& url);
	void AddURLEx(const std::wstring& name, const std::wstring& url, const std::wstring& category_user_name, const std::string& category_internal_name);
	void AddAttachmentPoint(double x, double y, double z);
	~LcNwcURLAttributeWrapper();
protected:
	LcNwcURLAttributeWrapper(const LtNwcURLAttribute& handle);
private:
	LcNwcURLAttribute* mURLAttribute;
};

/**@brief A wrapper class around LcNwcBinaryAttribute API
*/
class NWCREATE_SWIG_API LcNwcBinaryAttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcBinaryAttributeWrapper();
	void SetValue(const unsigned char*& data, int length);
	~LcNwcBinaryAttributeWrapper();
protected:
	LcNwcBinaryAttributeWrapper(const LtNwcBinaryAttribute& handle);
private:
	LcNwcBinaryAttribute* mBinaryAttribute;
};



//-----------------------------------------------------------------------------------------------------------------------
// LcNwcNode, LcNwcGroup, LcNwcGeometry
//-----------------------------------------------------------------------------------------------------------------------

/**@brief A wrapper class around LcNwcNode API
*/
class NWCREATE_SWIG_API LcNwcNodeWrapper
{
protected:
	friend class LcNwcGroupWrapper;
	friend class LcNwcSceneWrapper;
	LcNwcNodeWrapper(LtNwcNode handle);
	LcNwcNodeWrapper(const LcNwcNode& other);
public:
	void SetName(const std::wstring& name);
	void SetGuid(const LcNwcGuidWrapper& guid);
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
class NWCREATE_SWIG_API LcNwcGroupWrapper : public LcNwcNodeWrapper
{	
public:
	LcNwcGroupWrapper();
	void SetInsert(bool b);
	void SetLayer(bool b);
	void SetComposite(bool b);
	void SetCollection(bool b);
	void AddNode(const LcNwcNodeWrapper& node);
	~LcNwcGroupWrapper();
protected:
	LcNwcGroupWrapper(const LtNwcGroup& handle);
private:
	LcNwcGroup* mGroup;
};

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSceneWrapper
//-----------------------------------------------------------------------------------------------------------------------

/**@brief A wrapper class around LcNwcScene API
*/
class NWCREATE_SWIG_API LcNwcSceneWrapper
{
public:
	LcNwcSceneWrapper();
	void AddNode(const LcNwcNodeWrapper& node);
	void WriteCache(const std::wstring& orig_filename, const std::wstring& filename);
	~LcNwcSceneWrapper();
private:
	LcNwcScene* mScene;
};
