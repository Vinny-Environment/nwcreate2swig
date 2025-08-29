#ifndef NWCREATE_API_I
#define NWCREATE_API_I

%module nwcreateWrapperLib

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

class LcNwcGeometryWrapper;
class LcNwcExternalGeometryWrapper;
class LcNwcTextStyleWrapper;
class LcNwcGeometryStreamWrapper;
class LcNwcCurveWrapper;
class LcNwcBezierCurveWrapper;
class LcNwcBSplineCurveWrapper;
class LcNwcCircleWrapper;
class LcNwcEllipseWrapper;
class LcNwcHyperbolaWrapper;
class LcNwcLineWrapper;
class LcNwcParabolaWrapper;
class LcNwcTrimmedCurveWrapper;

class LcNwcSurfaceWrapper;

class LcNwcBRepEntityWrapper;
class LcNwcLoopWrapper;
class LcNwcFaceWrapper;
class LcNwcShellWrapper;

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

%rename(LcNwcGuidWrapper) LcNwcGuidWrapper;
class LcNwcGuidWrapper {
public:
	LcNwcGuidWrapper(const std::wstring& guid);
	~LcNwcGuidWrapper();
};

// Attributes 

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

%rename(LcNwcTransformWrapper) LcNwcTransformWrapper;
class LcNwcTransformWrapper : public LcNwcAttributeWrapper {
public:
    LcNwcTransformWrapper(double x, double y, double z);
	LcNwcTransformWrapper(double rX, double rY, double rZ, double rA, double tX, double tY, double tZ);
	LcNwcTransformWrapper(double matrix[16], bool reverses);
    ~LcNwcTransformWrapper();
protected:
	LcNwcTransformWrapper(LtNwcTransform handle);
};

%rename(LcNwcMaterialWrapper) LcNwcMaterialWrapper;
class LcNwcMaterialWrapper : public LcNwcAttributeWrapper {
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
	LcNwcMaterialWrapper(LtNwcMaterial handle);
};

%rename(LcNwcSemanticPriorityWrapper) LcNwcSemanticPriorityWrapper;
class LcNwcSemanticPriorityWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcSemanticPriorityWrapper();
	void SetPriority(double priority);
	~LcNwcSemanticPriorityWrapper();
protected:
	LcNwcSemanticPriorityWrapper(LtNwcSemanticPriority handle);
};

%rename(LcNwcTextAttributeWrapper) LcNwcTextAttributeWrapper;
class LcNwcTextAttributeWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcTextAttributeWrapper();
	void SetText(const std::wstring& text);
	~LcNwcTextAttributeWrapper();
protected:
	LcNwcTextAttributeWrapper(LtNwcTextAttribute handle);
};

%rename(LcNwcNameAttributeWrapper) LcNwcNameAttributeWrapper;
class LcNwcNameAttributeWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcNameAttributeWrapper();
	void SetStableId(bool b);
	~LcNwcNameAttributeWrapper();
protected:
	LcNwcNameAttributeWrapper(LtNwcNameAttribute handle);
};

enum LtNwcNat64AttributeFormatWrapper {
	LI_NWC_NAT64_FORMAT_DECIMAL_Wrap,
	LI_NWC_NAT64_FORMAT_HEXADECIMAL_Wrap,
};

%rename(LcNwcNat64AttributeWrapper) LcNwcNat64AttributeWrapper;
class LcNwcNat64AttributeWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcNat64AttributeWrapper();
	void SetStableId(bool b);
	void SetValue(unsigned long long value);
	void SetDisplayFormat(LtNwcNat64AttributeFormatWrapper format);
	~LcNwcNat64AttributeWrapper();
protected:
	LcNwcNat64AttributeWrapper(LtNwcNat64Attribute handle);
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

%rename(LcNwcURLAttributeWrapper) LcNwcURLAttributeWrapper;
class LcNwcURLAttributeWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcURLAttributeWrapper();
	void AddURL(const std::wstring& name, const std::wstring& url);
	void AddURLEx(const std::wstring& name, const std::wstring& url, const std::wstring& category_user_name, const std::string& category_internal_name);
	void AddAttachmentPoint(double x, double y, double z);
	~LcNwcURLAttributeWrapper();
protected:
	LcNwcURLAttributeWrapper(LtNwcURLAttribute handle);
};

%rename(LcNwcBinaryAttributeWrapper) LcNwcBinaryAttributeWrapper;
class LcNwcBinaryAttributeWrapper : public LcNwcAttributeWrapper {
public:
	LcNwcBinaryAttributeWrapper();
	void SetValue(const unsigned char*& data, int length);
	~LcNwcBinaryAttributeWrapper();
protected:
	LcNwcBinaryAttributeWrapper(LtNwcBinaryAttribute handle);
};

// LcNwcNode, LcNwcGroup, LcNwcGeometry, LcNwcGeometryStream

%rename(LcNwcNodeWrapper) LcNwcNodeWrapper;
class LcNwcNodeWrapper {
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


%rename(LcNwcExternalGeometryWrapper) LcNwcExternalGeometryWrapper;
class LcNwcExternalGeometryWrapper {
public:
	LcNwcExternalGeometryWrapper();
	void SetFileLoader(const std::string& file_loader);
	void SetLinkName(const std::string& link_name);
	void SetUri(const std::wstring& uri);
	void SetUserData(void* user_data);
	void SetVertexProperties(unsigned int vertex_properties);
	void SetBoundingBox(double min_point[3], double max_point[3]);
	void SetNumPrimitives(unsigned int num_primitives);
	void SetPrimitiveTypes(unsigned int primitive_types);
	~LcNwcExternalGeometryWrapper();
protected:
	LcNwcExternalGeometryWrapper(LtNwcExternalGeometry handle);
};

%rename(LcNwcCurveWrapper) LcNwcCurveWrapper;
class LcNwcCurveWrapper {
public:
	LcNwcCurveWrapper Copy();
	void SetUserData(int data);
	void Evaluate(double t, double pnt[3]);
	void Reverse();
	void Transform(LcNwcTransformWrapper transform);
	void Translate(double x, double y, double z);
	void Translate(double v[3]);
	double GetFirstParameter(bool* is_infinite = NULL);
	double GetLastParameter(bool* is_infinite = NULL);
	~LcNwcCurveWrapper();
protected:
	LcNwcCurveWrapper(const LcNwcCurve& other);
	LcNwcCurveWrapper(LtNwcCurve handle);
};

%rename(LcNwcBezierCurveWrapper) LcNwcBezierCurveWrapper;
class LcNwcBezierCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcBezierCurveWrapper(int num_poles, double poles[][3]);
	LcNwcBezierCurveWrapper(int num_poles, double poles[][3], double weights[]);
	~LcNwcBezierCurveWrapper();
protected:
	LcNwcBezierCurveWrapper(LtNwcBezierCurve handle);
};

%rename(LcNwcBSplineCurveWrapper) LcNwcBSplineCurveWrapper;
class LcNwcBSplineCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], int num_knots, double knots[], int mults[], int degree, bool periodic = false);
	LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], double weights[], int num_knots, double knots[], int mults[], bool periodic = false);
	~LcNwcBSplineCurveWrapper();
protected:
	LcNwcBSplineCurveWrapper(LtNwcBSplineCurve handle);
};

%rename(LcNwcCircleWrapper) LcNwcCircleWrapper;
class LcNwcCircleWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcCircleWrapper(double pnt[3], double xaxis[3], double yaxis[3], double radius);
	~LcNwcCircleWrapper();
protected:
	LcNwcCircleWrapper(LtNwcCircle handle);
};

%rename(LcNwcEllipseWrapper) LcNwcEllipseWrapper;
class LcNwcEllipseWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcEllipseWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius);
	~LcNwcEllipseWrapper();
protected:
	LcNwcEllipseWrapper(LtNwcEllipse handle);
};

%rename(LcNwcHyperbolaWrapper) LcNwcHyperbolaWrapper;
class LcNwcHyperbolaWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcHyperbolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius);
	~LcNwcHyperbolaWrapper();
protected:
	LcNwcHyperbolaWrapper(LtNwcHyperbola handle);
};

%rename(LcNwcLineWrapper) LcNwcLineWrapper;
class LcNwcLineWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcLineWrapper(double pnt[3], double dir[3]);
	~LcNwcLineWrapper();
protected:
	LcNwcLineWrapper(LtNwcLine handle);
};

%rename(LcNwcParabolaWrapper) LcNwcParabolaWrapper;
class LcNwcParabolaWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcParabolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double focal_length);
	~LcNwcParabolaWrapper();
protected:
	LcNwcParabolaWrapper(LtNwcParabola handle);
};


%rename(LcNwcTrimmedCurveWrapper) LcNwcTrimmedCurveWrapper;
class LcNwcTrimmedCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double param0, double param1, bool sense = true);
	LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double pnt0[3], double pnt1[3], bool sense = true);
	~LcNwcTrimmedCurveWrapper();
protected:
	LcNwcTrimmedCurveWrapper(LtNwcTrimmedCurve handle);
};

// Surfaces
%rename(LcNwcSurfaceWrapper) LcNwcSurfaceWrapper;
class LcNwcSurfaceWrapper 
{
public:
	LcNwcSurfaceWrapper(const LcNwcSurfaceWrapper& other);
	LcNwcSurfaceWrapper Copy();
	void SetUserData(int data);
	void Evaluate(double u, double v, double pnt[3]);
	void Transform(const LcNwcTransformWrapper& transform);
	void Translate(double x, double y, double z);
	void Translate(double v[3]);
	~LcNwcSurfaceWrapper();
protected:
	LcNwcSurfaceWrapper(LtNwcSurface handle);
};

// BRep

enum LtNwcLoopTypeWrapper {
	LI_NWC_LOOP_AUTO_Wrap,
	LI_NWC_LOOP_BOUNDARY_Wrap,
	LI_NWC_LOOP_HOLE_Wrap,
};

enum LtNwcBRepEntityTypeWrapper {
	LI_NWC_BREP_UNKNOWN_Wrap,
	LI_NWC_BREP_COMPOUND_Wrap,
	LI_NWC_BREP_COMPSOLID_Wrap,
	LI_NWC_BREP_BODY_Wrap,
	LI_NWC_BREP_SOLID_Wrap,
	LI_NWC_BREP_SHELL_Wrap,
	LI_NWC_BREP_FACE_Wrap,
	LI_NWC_BREP_LOOP_Wrap,
	LI_NWC_BREP_COEDGE_Wrap,
	LI_NWC_BREP_EDGE_Wrap,
	LI_NWC_BREP_VERTEX_Wrap
};

%rename(LcNwcBRepEntityWrapper) LcNwcBRepEntityWrapper;
class LcNwcBRepEntityWrapper 
{
public:
	LcNwcBRepEntityWrapper(const LcNwcBRepEntityWrapper& other);
	LtNwcBRepEntityTypeWrapper GetBRepEntityType() const;
	void SetUserData(int data);
	LcNwcBRepEntityWrapper Copy();
	void Transform(const LcNwcTransformWrapper& transform);
	void Translate(double x, double y, double z);
	void Translate(double v[3]);
	~LcNwcBRepEntityWrapper();
protected:
	LcNwcBRepEntityWrapper(LtNwcBRepEntity handle);
};

%rename(LcNwcLoopWrapper) LcNwcLoopWrapper;
class LcNwcLoopWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcLoopWrapper();
	//LcNwcLoopWrapper(LcNwcBRepProfileBuilder& builder);
	//void AddCoedge(LtNwcCoedge coedge);
	void SetType(LtNwcLoopTypeWrapper type);
	~LcNwcLoopWrapper();
protected:
	LcNwcLoopWrapper(LtNwcLoop handle);
};

enum LtNwcSenseWrapper
{
	LI_NWC_SENSE_NEGATIVE_Wrap = -1,
	LI_NWC_SENSE_POSITIVE_Wrap = +1,
};

%rename(LcNwcFaceWrapper) LcNwcFaceWrapper;
class LcNwcFaceWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcFaceWrapper(const LcNwcSurfaceWrapper& surface, LtNwcSenseWrapper sense);
	void AddLoop(const LcNwcLoopWrapper& loop);
	~LcNwcFaceWrapper();
protected:
	LcNwcFaceWrapper(LtNwcFace handle);
};

%rename(LcNwcShellWrapper) LcNwcShellWrapper;
class LcNwcShellWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcShellWrapper();
	~LcNwcShellWrapper();
	void AddFace(const LcNwcFaceWrapper& face);
protected:
	LcNwcShellWrapper(LtNwcShell handle);
};

enum LtNwcTextRenderStyleWrapper {
	LI_NWC_TEXT_RENDER_FILLED_Wrap,  
	LI_NWC_TEXT_RENDER_OUTLINE_Wrap, 
};

%rename(LcNwcTextStyleWrapper) LcNwcTextStyleWrapper;
class LcNwcTextStyleWrapper
{
public:
	LcNwcTextStyleWrapper(const std::wstring& typeface);
	LcNwcTextStyleWrapper(const LcNwcTextStyleWrapper& other);
	void SetTypeface(const std::wstring& typeface);
	void SetFontHeight(double height);
	void SetPointSize(int point_size);
	void SetRenderStyle(LtNwcTextRenderStyleWrapper render_style);
	void SetFontStyle(int font_style);
	void SetFontWeight(int font_weight);
	~LcNwcTextStyleWrapper();
protected:
	friend class LcNwcGeometryStreamWrapper;
	LcNwcTextStyleWrapper(LtNwcTextStyle handle);
};

enum LtNwcShapeFlagsWrapper
{
	eTWO_SIDED_Wrap = 0x02,
	eNORMALIZE_Wrap = 0x04, 
	eREVERSED_Wrap = 0x10, 
};

%rename(LcNwcGeometryStreamWrapper) LcNwcGeometryStreamWrapper;
class LcNwcGeometryStreamWrapper
{
public:
	void CreaseAngle(double angle);
	void MakeSolidsSingleSided(bool enable);
	void PriorityScale(double scale);
	void ShapeFlags(LtNwcShapeFlagsWrapper flags);
	void SplitThreshold(int t);
	void SpatialSplitThreshold(int t);
	void MergeThreshold(int t);
	void RecenterThreshold(double dist);
	void FacetingFactor(double factor);
	void MaxFacetDeviation(double tol);
	void ExteriorFaceting(bool b);
	void CorrectGenNormalOrientation(bool enable);
	void CorrectVertexNormalOrientation(bool enable);
	void IndexedVertexAliases(bool enable);
	void PushTransform();
	void SetTransformIdentity();
	void SetTransformTranslation(double x, double y, double z);
	void SetTransformTranslation(const double v[3]);
	void SetTransform(double matrix[16]);
	void MultTransformTranslation(double x, double y, double z);
	void MultTransformTranslation(const double v[3]);
	void MultTransform(double matrix[16]);
	void PopTransform();
	void ExternalGeometry(const LcNwcExternalGeometryWrapper& geometry);
	void Begin(unsigned int vertex_properties);
	void Color(double r, double g, double b, double a);
	void Normal(double x, double y, double z);
	void Normal(const double v[3]);
	void TexCoord(double x, double y);
	int IndexedVertex(double x, double y, double z);
	int IndexedVertex(const double p[3]);
	void TriangleVertex(double x, double y, double z);
	void TriangleVertex(const double p[3]);
	void TriangleIndex(int index);
	void TriStripVertex(double x, double y, double z);
	void TriStripVertex(const double p[3]);
	void TriStripIndex(int index);
	void TriFanVertex(double x, double y, double z);
	void TriFanVertex(const double p[3]);
	void TriFanIndex(int index);
	void ConvexPolyVertex(double x, double y, double z);
	void ConvexPolyVertex(const double p[3]);
	void ConvexPolyIndex(int index);
	void SeqEnd();
	void BeginPolygon();
	void BeginPolygonContour();
	void PolygonVertex(double x, double y, double z);
	void PolygonVertex(const double p[3]);
	void PolygonIndex(int index);
	void PolygonEllipse(double center[3], double major[3], double minor[3], double start_ang = 0, double end_ang = 0);
	void EndPolygonContour();
	void EndPolygon();
	void FacetRadius(double radius);
	int GetNumCirclePts(double radius);
	void Circle(double center[3], double normal[3], double radius);
	void Circle3Point(double pt1[3], double pt2[3], double pt3[3]);
	void Ellipse(double center[3], double major[3], double minor[3], double start_ang = 0, double end_ang = 0);
	void EllipseCurve(double center[3], double major[3], double minor[3], double start_ang = 0, double end_ang = 0);
	void Cylinder(double pt1[3], double pt2[3], double radius);
	void Conic(double pt1[3], double major1[3], double minor1[3], double pt2[3], double major2[3], double minor2[3], double start_ang = 0, double end_ang = 0);
	void Cuboid(double pt1[3], double pt2[3]);
	void Sphere(double pt[3], double radius);
	void EllipsoidSection(double center[3], double x_axis[3], double y_axis[3], double z_axis[3], double latitude_min, double latitude_max, double longitude_min, double longitude_max);
	void Ellipsoid(double center[3], double x_axis[3], double y_axis[3], double z_axis[3]);
	void TorusSection(double center[3], double x_axis[3], double y_axis[3], double major_radius, double minor_radius, double phi_min, double phi_max, double longitude_min, double longitude_max);
	void Torus(double center[3], double x_axis[3], double y_axis[3], double major_radius, double minor_radius);
	LtInt32 IndexedLineVertex(double x, double y, double z);
	LtInt32 IndexedLineVertex(const double p[3]);
	void LineVertex(double x, double y, double z);
	void LineVertex(const double p[3]);
	void LineIndex(int index);
	void LineStripVertex(double x, double y, double z);
	void LineStripVertex(const double p[3]);
	void LineStripIndex(int index);
	void Point(double x, double y, double z);
	void Point(const double p[3]);
	void SnapPoint(double x, double y, double z);
	void SnapPoint(const double p[3]);
	void Curve(const LcNwcCurveWrapper& curve);
	void CurveSegment(const LcNwcCurveWrapper& curve, double start, double end);
	void FacetEnd();
	void End();
	void CoordTolerance(double tolerance);
	void GenerateParametrics(bool enable);
	int BRepShell(const LcNwcShellWrapper& shell); 
	int BRepEntity(const LcNwcBRepEntityWrapper& entity);
	std::string BRepFaceterName() const;
	int BRepNumFailedFaces();
	void BeginText(const LcNwcTextStyleWrapper& style);
	void AddText(const std::wstring& text);
	void EndText();
	~LcNwcGeometryStreamWrapper();
protected:
	LcNwcGeometryStreamWrapper(LtNwcGeometryStream stream);
};

%rename(LcNwcGeometryWrapper) LcNwcGeometryWrapper;
class LcNwcGeometryWrapper : public LcNwcNodeWrapper
{
public:
	LcNwcGeometryWrapper();
	LcNwcGeometryStreamWrapper OpenStream();
	void CloseStream(const LcNwcGeometryStreamWrapper& stream);
	~LcNwcGeometryWrapper();
protected:
	LcNwcGeometryWrapper(LtNwcGeometry handle);
};


// LcNwcScene
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
%ignore LcNwcDataWrapper::mDataWrapper;
%ignore LcNwcGuidWrapper::mGuidWrapper;

%ignore LcNwcAttributeWrapper::mAttributeWrapper;
%ignore LcNwcTransformWrapper::mTransformWrapper;
%ignore LcNwcMaterialWrapper::mMaterialWrapper;
%ignore LcNwcSemanticPriorityWrapper::mSemanticPriorityWrapper;
%ignore LcNwcTextAttributeWrapper::mTextAttributeWrapper;
%ignore LcNwcNameAttributeWrapper::mNameAttributeWrapper;
%ignore LcNwcNat64AttributeWrapper::mNat64AttributeWrapper;
%ignore LcNwcPropertyAttributeWrapper::mPropertyAttributeWrapper;
%ignore LcNwcURLAttributeWrapper::mURLAttributeWrapper;
%ignore LcNwcBinaryAttributeWrapper::mBinaryAttributeWrapper;

%ignore LcNwcGeometryWrapper::mGeometryWrapper;
%ignore LcNwcExternalGeometryWrapper::mExternalGeometryWrapper;
%ignore LcNwcTextStyleWrapper::mTextStyleWrapper;
%ignore LcNwcGeometryStreamWrapper::mGeometryStreamWrapper;
%ignore LcNwcCurveWrapper::mCurveWrapper;
%ignore LcNwcBezierCurveWrapper::mBezierCurveWrapper;
%ignore LcNwcBSplineCurveWrapper::mBSplineCurveWrapper;
%ignore LcNwcCircleWrapper::mCircleWrapper;
%ignore LcNwcEllipseWrapper::mEllipseWrapper;
%ignore LcNwcHyperbolaWrapper::mHyperbolaWrapper;
%ignore LcNwcLineWrapper::mLineWrapper;
%ignore LcNwcParabolaWrapper::mParabolaWrapper;
%ignore LcNwcTrimmedCurveWrapper::mTrimmedCurveWrapper;

%ignore LcNwcSurfaceWrapper::mSurfaceWrapper;

%ignore LcNwcBRepEntityWrapper::mBRepEntityWrapper;
%ignore LcNwcLoopWrapper::mLoopWrapper;
%ignore LcNwcFaceWrapper::mFaceWrapper;
%ignore LcNwcShellWrapper::mShellWrapper;

%ignore LcNwcNodeWrapper::mNodeWrapper;
%ignore LcNwcGroupWrapper::mGroupWrapper;

%ignore LcNwcSceneWrapper::mSceneWrapper;

#endif // NWCREATE_API_I
