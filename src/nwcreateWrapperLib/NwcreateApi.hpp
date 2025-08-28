#pragma once
#include "Headers.hpp"

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
// Attributes
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
	LcNwcAttributeWrapper(LtNwcAttribute handle);
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
	friend class LcNwcCurveWrapper;
	friend class LcNwcSurfaceWrapper;
	friend class LcNwcBRepEntityWrapper;
	LcNwcTransformWrapper(LtNwcTransform handle);
	
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
	LcNwcMaterialWrapper(LtNwcMaterial handle);
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
	LcNwcSemanticPriorityWrapper(LtNwcSemanticPriority handle);
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
	LcNwcTextAttributeWrapper(LtNwcTextAttribute handle);
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
	LcNwcNameAttributeWrapper(LtNwcNameAttribute handle);
private:
	LcNwcNameAttribute* mNameAttribute;
};

enum LtNwcNat64AttributeFormatWrapper {
	LI_NWC_NAT64_FORMAT_DECIMAL_Wrap,
	LI_NWC_NAT64_FORMAT_HEXADECIMAL_Wrap
};

/**@brief A wrapper class around LcNwcNat64Attribute API
*/
class NWCREATE_SWIG_API LcNwcNat64AttributeWrapper : public LcNwcAttributeWrapper
{
public:
	LcNwcNat64AttributeWrapper();
	void SetStableId(bool b);
	void SetValue(double value);
	void SetDisplayFormat(LtNwcNat64AttributeFormatWrapper format);
	~LcNwcNat64AttributeWrapper();
protected:
	LcNwcNat64AttributeWrapper(LtNwcNat64Attribute handle);
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
	LcNwcPropertyAttributeWrapper(LtNwcPropertyAttribute handle);
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
	LcNwcURLAttributeWrapper(LtNwcURLAttribute handle);
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
	LcNwcBinaryAttributeWrapper(LtNwcBinaryAttribute handle);
private:
	LcNwcBinaryAttribute* mBinaryAttribute;
};

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcNode, LcNwcGroup, LcNwcGeometry, LcNwcGeometryStream
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
	LcNwcGroupWrapper(LtNwcGroup handle);
private:
	LcNwcGroup* mGroup;
};

/**@brief A wrapper class around LcNwcGroup API
*/
class NWCREATE_SWIG_API LcNwcExternalGeometryWrapper 
{
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
	friend class LcNwcGeometryStreamWrapper;
	LcNwcExternalGeometryWrapper(LtNwcExternalGeometry handle);
private:
	LcNwcExternalGeometry* mExternalGeometry;
};

/**@brief A wrapper class around LcNwcCurve API
*/
class NWCREATE_SWIG_API LcNwcCurveWrapper
{
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
	friend class LcNwcTrimmedCurveWrapper;
	friend class LcNwcGeometryStreamWrapper;
	LcNwcCurveWrapper(const LcNwcCurve& other);
	LcNwcCurveWrapper(LtNwcCurve handle);
private:
	LcNwcCurve* mCurve;
};

/**@brief A wrapper class around LcNwcBezierCurve API
*/
class NWCREATE_SWIG_API LcNwcBezierCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcBezierCurveWrapper(int num_poles, double poles[][3]);
	LcNwcBezierCurveWrapper(int num_poles, double poles[][3], double weights[]);
	~LcNwcBezierCurveWrapper();
protected:
	LcNwcBezierCurveWrapper(LtNwcBezierCurve handle);
private:
	LcNwcBezierCurve* mBezierCurve;
};

/**@brief A wrapper class around LcNwcBSplineCurve API
*/
class NWCREATE_SWIG_API LcNwcBSplineCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], int num_knots, double knots[], int mults[], int degree, bool periodic = false);
	LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], double weights[], int num_knots, double knots[], int mults[], bool periodic = false);
	~LcNwcBSplineCurveWrapper();
protected:
	LcNwcBSplineCurveWrapper(LtNwcBSplineCurve handle);
private:
	LcNwcBSplineCurve* mBSplineCurve;
};

/**@brief A wrapper class around LcNwcCircle API
*/
class NWCREATE_SWIG_API LcNwcCircleWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcCircleWrapper(double pnt[3], double xaxis[3], double yaxis[3], double radius);
	~LcNwcCircleWrapper();
protected:
	LcNwcCircleWrapper(LtNwcCircle handle);
private:
	LcNwcCircle* mCircle;
};

/**@brief A wrapper class around LcNwcEllipse API
*/
class NWCREATE_SWIG_API LcNwcEllipseWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcEllipseWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius);
	~LcNwcEllipseWrapper();
protected:
	LcNwcEllipseWrapper(LtNwcEllipse handle);
private:
	LcNwcEllipse* mEllipse;
};

/**@brief A wrapper class around LcNwcHyperbola API
*/
class NWCREATE_SWIG_API LcNwcHyperbolaWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcHyperbolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius);
	~LcNwcHyperbolaWrapper();
protected:
	LcNwcHyperbolaWrapper(LtNwcHyperbola handle);
private:
	LcNwcHyperbola* mHyperbola;
};

/**@brief A wrapper class around LcNwcLine API
*/
class NWCREATE_SWIG_API LcNwcLineWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcLineWrapper(double pnt[3], double dir[3]);
	~LcNwcLineWrapper();
protected:
	LcNwcLineWrapper(LtNwcLine handle);
private:
	LcNwcLine* mLine;
};

/**@brief A wrapper class around LcNwcParabola API
*/
class NWCREATE_SWIG_API LcNwcParabolaWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcParabolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double focal_length);
	~LcNwcParabolaWrapper();
protected:
	LcNwcParabolaWrapper(LtNwcParabola handle);
private:
	LcNwcParabola* mParabola;
};

/**@brief A wrapper class around LcNwcTrimmedCurve API
*/
class NWCREATE_SWIG_API LcNwcTrimmedCurveWrapper : public LcNwcCurveWrapper
{
public:
	LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double param0, double param1, bool sense = true);
	LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double pnt0[3], double pnt1[3], bool sense = true);
	~LcNwcTrimmedCurveWrapper();
protected:
	LcNwcTrimmedCurveWrapper(LtNwcTrimmedCurve handle);
private:
	LcNwcTrimmedCurve* mTrimmedCurve;
};

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSurface and it's inherits
//-----------------------------------------------------------------------------------------------------------------------

/**@brief A wrapper class around LcNwcSurfaceWrapper API
*/
class NWCREATE_SWIG_API LcNwcSurfaceWrapper
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
	friend class LcNwcFaceWrapper;
	LcNwcSurfaceWrapper(LtNwcSurface handle);
private:
	LcNwcSurface* mSurface;
};

//TODO: LcNwcBezierSurface, LcNwcBSplineSurface, LcNwcConicalSurface, LcNwcCylindricalSurface, LcNwcExtrudedSurface, LcNwcOffsetSurface, LcNwcPlane, LcNwcRectangularTrimmedSurface, LcNwcRevolvedSurface, LcNwcSphericalSurface, LcNwcToroidalSurface 

//-----------------------------------------------------------------------------------------------------------------------
// BRep and it's inherits
//----------------------------------------------------------------------------------------------------------------------- 

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

/**@brief A wrapper class around LcNwcBRepEntity  API
*/
class NWCREATE_SWIG_API LcNwcBRepEntityWrapper
{
public:
	LcNwcBRepEntityWrapper(const LcNwcBRepEntityWrapper& other);
	LtNwcBRepEntityTypeWrapper GetType() const;
	void SetUserData(int data);
	LcNwcBRepEntityWrapper Copy();
	void Transform(const LcNwcTransformWrapper& transform);
	void Translate(double x, double y, double z);
	void Translate(double v[3]);
	~LcNwcBRepEntityWrapper();
protected:
	friend class LcNwcGeometryStreamWrapper;
	LcNwcBRepEntityWrapper(LtNwcBRepEntity handle);
private:
	LcNwcBRepEntity* mBRepEntity;
};

//TODO: LcNwcBody, LcNwcBRepBox, LcNwcBRepCylinder, LcNwcBRepDifference, LcNwcBRepHalfSpace, LcNwcBRepIntersection, LcNwcBRepPrism, LcNwcBRepRevolve, LcNwcBRepUnion, LcNwcCoedge, LcNwcCompound, LcNwcEdge, LcNwcFace (+), LcNwcLoop (+/-), LcNwcShell (+/-), LcNwcSolid, LcNwcVertex 

/**@brief A wrapper class around LcNwcLoop API
*/
class NWCREATE_SWIG_API LcNwcLoopWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcLoopWrapper();
	//LcNwcLoopWrapper(LcNwcBRepProfileBuilder& builder);
	//void AddCoedge(LtNwcCoedge coedge);
	void SetType(LtNwcLoopTypeWrapper type);
	~LcNwcLoopWrapper();
protected:
	friend class LcNwcFaceWrapper;
	LcNwcLoopWrapper(LtNwcLoop handle);
private:
	LcNwcLoop* mLoop;
};

enum LtNwcSenseWrapper
{
	LI_NWC_SENSE_NEGATIVE_Wrap = -1,
	LI_NWC_SENSE_POSITIVE_Wrap = +1,
};


/**@brief A wrapper class around LcNwcFace API
*/
class NWCREATE_SWIG_API LcNwcFaceWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcFaceWrapper(const LcNwcSurfaceWrapper& surface, LtNwcSenseWrapper sense);
	void AddLoop(const LcNwcLoopWrapper& loop);
	~LcNwcFaceWrapper();
protected:
	friend class LcNwcShellWrapper;
	LcNwcFaceWrapper(LtNwcFace handle);
private:
	LcNwcFace* mFace;
};

/**@brief A wrapper class around LcNwcShell API
*/
class NWCREATE_SWIG_API LcNwcShellWrapper : public LcNwcBRepEntityWrapper
{
public:
	LcNwcShellWrapper();
	~LcNwcShellWrapper();
	void AddFace(const LcNwcFaceWrapper& face);
protected:
	friend class LcNwcGeometryStreamWrapper;
	LcNwcShellWrapper(LtNwcShell handle);
private:
	LcNwcShell* mShell;
};

enum LtNwcTextRenderStyleWrapper {
	LI_NWC_TEXT_RENDER_FILLED_Wrap,  
	LI_NWC_TEXT_RENDER_OUTLINE_Wrap, 
};

/**@brief A wrapper class around LcNwcTextStyle API
*/
class NWCREATE_SWIG_API LcNwcTextStyleWrapper
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
private:
	LcNwcTextStyle* mTextStyle;
};

enum LtNwcShapeFlagsWrapper
{
	eTWO_SIDED_Wrap = 0x02,
	eNORMALIZE_Wrap = 0x04,
	eREVERSED_Wrap = 0x10,
};

/**@brief A wrapper class around LcNwcGeometryStream API
*/
class NWCREATE_SWIG_API LcNwcGeometryStreamWrapper
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
	friend class LcNwcGeometryWrapper;
	LcNwcGeometryStreamWrapper(LtNwcGeometryStream stream);
private:
	LcNwcGeometryStream* mGeometryStream;
};

/**@brief A wrapper class around LcNwcGeometry API
*/
class NWCREATE_SWIG_API LcNwcGeometryWrapper : public LcNwcNodeWrapper
{
public:
	LcNwcGeometryWrapper();
	LcNwcGeometryStreamWrapper OpenStream();
	void CloseStream(const LcNwcGeometryStreamWrapper& stream);
	~LcNwcGeometryWrapper();
protected:
	LcNwcGeometryWrapper(LtNwcGeometry handle);
private:
	LcNwcGeometry* mGeometry;
};

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcSceneWrapper, Viewes and etc
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
