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

enum LtNwcNat64AttributeFormatWrapper {
	LI_NWC_NAT64_FORMAT_DECIMAL_Wrap,
	LI_NWC_NAT64_FORMAT_HEXADECIMAL_Wrap,
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
	LcNwcGroupWrapper(const LtNwcGroup& handle);
private:
	LcNwcGroup* mGroup;
};

enum LtNwcShapeFlagsWrapper
{
	eTWO_SIDED_Wrap = 0x02,
	eNORMALIZE_Wrap = 0x04,
	eREVERSED_Wrap = 0x10,
};

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
	void ExternalGeometry(LtNwcExternalGeometry geometry); //TODO Wrapper
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
	//void Curve(LtNwcCurve curve); //TODO Make Wrapper
	//void CurveSegment(LtNwcCurve curve, double start, double end); //TODO Make Wrapper
	void FacetEnd();
	void End();
	void CoordTolerance(double tolerance);
	void GenerateParametrics(bool enable);
	//int BRepShell(LtNwcShell shell); //TODO Make Wrapper
	//int BRepEntity(LtNwcBRepEntity entity); //TODO Make Wrapper
	std::string BRepFaceterName() const;
	int BRepNumFailedFaces();
	//void BeginText(LtNwcTextStyle style); //TODO Make Wrapper
	void AddText(const std::wstring& text);
	void EndText();
	~LcNwcGeometryStreamWrapper();
protected:
	friend class LcNwcGeometryWrapper;
	LcNwcGeometryStreamWrapper(const LtNwcGeometryStream& stream);
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
	LcNwcGeometryWrapper(const LtNwcGeometry& handle);
private:
	LcNwcGeometry* mGeometry;
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
