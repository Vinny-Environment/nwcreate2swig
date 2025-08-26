/* NwcreateApi.i - SWIG interface file for NwcreateApi classes */

%module nwcreate

%{
#include "NwcreateApi.hpp"
#include "Headers.hpp"
%}

%include <windows.i>
%include <std_string.i>
%include <std_wstring.i>
%include <stdint.i>
%include <exception.i>

// Handle the CLASS_DECLSPEC macro
//#define CLASS_DECLSPEC

// Forward declarations
class LcNwcData;
class LtNwcAttribute;
class LcNwcAttribute;
class LtNwcPropertyAttribute;
class LcNwcPropertyAttribute;
class LtNwcGeometry;

// Ignore the private implementation details
%ignore LcNwcDataWrapper::mData;
%ignore LcNwcAttributeWrapper::mAttribute;
%ignore LcNwcPropertyAttributeWrapper::mPropertyAttribute;

// Include the main header
%include "NwcreateApi.hpp"

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

// Handle the LcNwcDataWrapper parameter in AddProperty
%typemap(in) LcNwcDataWrapper (LcNwcDataWrapper temp) {
    // Convert from target language object to LcNwcDataWrapper
    void* argp = 0;
    int res = SWIG_ConvertPtr($input, &argp, SWIGTYPE_p_LcNwcDataWrapper, 0);
    if (!SWIG_IsOK(res)) {
        SWIG_exception_fail(SWIG_ArgError(res), "expected LcNwcDataWrapper object");
    }
    temp = *reinterpret_cast<LcNwcDataWrapper*>(argp);
    $1 = temp;
}

// Handle LtNwcAttribute parameter
%typemap(in) LtNwcAttribute {
    // You may need to adjust this based on the actual type definition
    $1 = (LtNwcAttribute)SWIG_AsVal_long($input);
}

// Exception handling
%exception {
    try {
        $action
    } catch (const std::exception& e) {
        SWIG_exception(SWIG_RuntimeError, e.what());
    }
}

// Additional directives for specific classes

// For LcNwcAttributeWrapper - make protected constructors accessible
%extend LcNwcAttributeWrapper {
    // Create factory methods for protected constructors if needed
    // These would need to be implemented in your C++ code
}

// For LcNwcPropertyAttributeWrapper - handle inheritance
%feature("director") LcNwcPropertyAttributeWrapper;
