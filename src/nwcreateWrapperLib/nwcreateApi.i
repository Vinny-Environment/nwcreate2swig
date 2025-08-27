%module nwcreateNET

%{
#include "NwcreateApi.hpp"
%}

%include <std_string.i>
%include <std_wstring.i>
%include <windows.i>
%include <exception.i>

// Enable wide string support
%include "std_wstring.i"

// Handle the CLASS_DECLSPEC macro
//#define CLASS_DECLSPEC

// Forward declarations
class LcNwcDataWrapper;
class LcNwcAttributeWrapper;
class LcNwcPropertyAttributeWrapper;
class LcNwcNodeWrapper;
class LcNwcGroupWrapper;
class LcNwcSceneWrapper;

%rename(LcNwcDataWrapper) LcNwcDataWrapper;
class LcNwcDataWrapper {
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
};

%rename(LcNwcAttributeWrapper) LcNwcAttributeWrapper;
class LcNwcAttributeWrapper {
public:
    void SetName(const std::wstring& name);
    void SetClassName(const std::wstring& user_name, const std::string& internal_name);
    void SetInternal(bool value);
    ~LcNwcAttributeWrapper();
protected:
    LcNwcAttributeWrapper(LtNwcAttribute handle);
	LcNwcAttributeWrapper(const LcNwcAttribute& other);
};

%rename(LcNwcPropertyAttributeWrapper) LcNwcPropertyAttributeWrapper;
class LcNwcPropertyAttributeWrapper : public LcNwcAttributeWrapper {
public:
    LcNwcPropertyAttributeWrapper();
    void AddProperty(const std::wstring& user_name, const std::string& internal_name, LcNwcDataWrapper propertyInfo);
    int Size() const;
    ~LcNwcPropertyAttributeWrapper();
protected:
	LcNwcPropertyAttributeWrapper(LtNwcPropertyAttribute handle);
};

%rename(LcNwcNodeWrapper) LcNwcNodeWrapper;
class LcNwcNodeWrapper {
public:
    void SetName(const std::wstring& name);
    void SetClassName(const std::wstring& user_name, const std::string& internal_name);
    void SetHidden(bool b);
    void SetRequired(bool b);
    void SetTwoSided(bool b);
    void AddAttribute(const LcNwcAttributeWrapper& attrib);
    void SetEnableAutoMerge(bool b);
    ~LcNwcNodeWrapper();
protected:
	LcNwcNodeWrapper(LtNwcNode handle);
	LcNwcNodeWrapper(const LcNwcNode& other);
};

%rename(LcNwcGroupWrapper) LcNwcGroupWrapper;
class LcNwcGroupWrapper : public LcNwcNodeWrapper {
public:
    LcNwcGroupWrapper();
    void SetInsert(bool b);
    void SetLayer(bool b);
    void SetComposite(bool b);
    void SetCollection(bool b);
    void AddNode(const LcNwcNodeWrapper& node);
    ~LcNwcGroupWrapper();
protected:
	LcNwcGroupWrapper(LtNwcGroup handle);
};

%rename(LcNwcSceneWrapper) LcNwcSceneWrapper;
class LcNwcSceneWrapper {
public:
    LcNwcSceneWrapper();
    void AddNode(const LcNwcNodeWrapper& node);
    void WriteCache(const std::wstring& orig_filename, const std::wstring& filename);
    ~LcNwcSceneWrapper();
};

// Additional typemaps for better language integration
%typemap(out) std::wstring {
    // Convert std::wstring to target language string
    $result = SWIG_FromWChar($1.c_str());
}

%typemap(in) const std::wstring& (std::wstring temp) {
    // Convert target language string to std::wstring
    wchar_t* ptr = NULL;
    int res = SWIG_AsWCharPtrAndSize($input, &ptr, NULL, 0);
    if (!SWIG_IsOK(res)) {
        SWIG_exception_fail(SWIG_TypeError, "expected wide string");
    }
    temp = ptr;
    $1 = &temp;
}

%typemap(in) long long {
    // Handle 64-bit integers
    $1 = (long long)SWIG_AsVal_long_long($input);
}

%typemap(out) long long {
    // Return 64-bit integers
    $result = SWIG_From_long_long($1);
}

// Exception handling
%exception {
    try {
        $action
    } catch (const std::exception& e) {
        SWIG_exception(SWIG_RuntimeError, e.what());
    }
}

// Handle the friend relationships by making protected members accessible
%ignore LcNwcDataWrapper::mData;
%ignore LcNwcAttributeWrapper::mAttribute;
%ignore LcNwcPropertyAttributeWrapper::mPropertyAttribute;
%ignore LcNwcNodeWrapper::mNode;
%ignore LcNwcGroupWrapper::mGroup;
%ignore LcNwcSceneWrapper::mScene;