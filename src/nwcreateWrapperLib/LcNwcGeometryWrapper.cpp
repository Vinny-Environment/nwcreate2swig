#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcGeometryWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGeometryWrapper::LcNwcGeometryWrapper() : LcNwcNodeWrapper(*(this->mGeometry = new LcNwcGeometry()))
{

}

LcNwcGeometryWrapper::LcNwcGeometryWrapper(LtNwcGeometry handle) : LcNwcNodeWrapper(*(this->mGeometry = new LcNwcGeometry(handle)))
{

}

LcNwcGeometryStreamWrapper LcNwcGeometryWrapper::OpenStream()
{
	return LcNwcGeometryStreamWrapper(this->mGeometry->OpenStream());
}

void LcNwcGeometryWrapper::CloseStream(const LcNwcGeometryStreamWrapper& stream)
{
	this->mGeometry->CloseStream(*stream.mGeometryStream);
}

LcNwcGeometryWrapper::~LcNwcGeometryWrapper()
{
	LiNwcGeometryDestroy(*this->mGeometry);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcExternalGeometryWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcExternalGeometryWrapper::LcNwcExternalGeometryWrapper()
{
	this->mExternalGeometry = new LcNwcExternalGeometry();
}

LcNwcExternalGeometryWrapper::LcNwcExternalGeometryWrapper(LtNwcExternalGeometry handle)
{
	this->mExternalGeometry = new LcNwcExternalGeometry(handle);
}

void LcNwcExternalGeometryWrapper::SetFileLoader(const std::string& file_loader)
{
	this->mExternalGeometry->SetFileLoader(file_loader.c_str());
}

void LcNwcExternalGeometryWrapper::SetLinkName(const std::string& link_name)
{
	this->mExternalGeometry->SetLinkName(link_name.c_str());
}

void LcNwcExternalGeometryWrapper::SetUri(const std::wstring& uri)
{
	this->mExternalGeometry->SetUri(uri.c_str());
}

void LcNwcExternalGeometryWrapper::SetUserData(void* user_data)
{
	this->mExternalGeometry->SetUserData(user_data);
}

void LcNwcExternalGeometryWrapper::SetVertexProperties(unsigned int vertex_properties)
{
	this->mExternalGeometry->SetVertexProperties(vertex_properties);
}

void LcNwcExternalGeometryWrapper::SetBoundingBox(double min_point[3], double max_point[3])
{
	this->mExternalGeometry->SetBoundingBox(min_point, max_point);
}

void LcNwcExternalGeometryWrapper::SetNumPrimitives(unsigned int num_primitives)
{
	this->mExternalGeometry->SetNumPrimitives(num_primitives);
}

void LcNwcExternalGeometryWrapper::SetPrimitiveTypes(unsigned int primitive_types)
{
	this->mExternalGeometry->SetPrimitiveTypes(primitive_types);
}

LcNwcExternalGeometryWrapper::~LcNwcExternalGeometryWrapper()
{
	LiNwcExternalGeometryDestroy(*this->mExternalGeometry);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcTextStyleWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcTextStyleWrapper::LcNwcTextStyleWrapper(const std::wstring& typeface)
{
	this->mTextStyle = new LcNwcTextStyle(typeface.c_str());
}

LcNwcTextStyleWrapper::LcNwcTextStyleWrapper(const LcNwcTextStyleWrapper& other)
{
	this->mTextStyle = new LcNwcTextStyle(*other.mTextStyle);
}

LcNwcTextStyleWrapper::LcNwcTextStyleWrapper(LtNwcTextStyle handle)
{
	this->mTextStyle = new LcNwcTextStyle(handle);
}

void LcNwcTextStyleWrapper::SetTypeface(const std::wstring& typeface)
{
	this->mTextStyle->SetTypeface(typeface.c_str());
}

void LcNwcTextStyleWrapper::SetFontHeight(double height)
{
	this->mTextStyle->SetFontHeight(height);
}

void LcNwcTextStyleWrapper::SetPointSize(int point_size)
{
	this->mTextStyle->SetPointSize(point_size);
}

void LcNwcTextStyleWrapper::SetRenderStyle(LtNwcTextRenderStyleWrapper render_style)
{
	this->mTextStyle->SetRenderStyle((LtNwcTextRenderStyle)render_style);
}

void LcNwcTextStyleWrapper::SetFontStyle(int font_style)
{
	this->mTextStyle->SetFontStyle(font_style);
}

void LcNwcTextStyleWrapper::SetFontWeight(int font_weight)
{
	this->mTextStyle->SetFontWeight(font_weight);
}

LcNwcTextStyleWrapper::~LcNwcTextStyleWrapper()
{
	LiNwcTextStyleDestroy(*this->mTextStyle);
}
//-----------------------------------------------------------------------------------------------------------------------
// LcNwcGeometryStreamWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGeometryStreamWrapper::LcNwcGeometryStreamWrapper(LtNwcGeometryStream stream)
{
	this->mGeometryStream = new LcNwcGeometryStream(stream);
}

void LcNwcGeometryStreamWrapper::CreaseAngle(double angle)
{
	this->mGeometryStream->CreaseAngle(angle);
}

void LcNwcGeometryStreamWrapper::MakeSolidsSingleSided(bool enable)
{
	this->mGeometryStream->MakeSolidsSingleSided(enable);
}

void LcNwcGeometryStreamWrapper::PriorityScale(double scale)
{
	this->mGeometryStream->PriorityScale(scale);
}

void LcNwcGeometryStreamWrapper::ShapeFlags(LtNwcShapeFlagsWrapper flags)
{
	this->mGeometryStream->ShapeFlags((LtNwcShapeFlags)flags);
}

void LcNwcGeometryStreamWrapper::SplitThreshold(int t)
{
	this->mGeometryStream->SplitThreshold(t);
}

void LcNwcGeometryStreamWrapper::SpatialSplitThreshold(int t)
{
	this->mGeometryStream->SpatialSplitThreshold(t);
}

void LcNwcGeometryStreamWrapper::MergeThreshold(int t)
{
	this->mGeometryStream->MergeThreshold(t);
}

void LcNwcGeometryStreamWrapper::RecenterThreshold(double dist)
{
	this->mGeometryStream->RecenterThreshold(dist);
}

void LcNwcGeometryStreamWrapper::FacetingFactor(double factor)
{
	this->mGeometryStream->FacetingFactor(factor);
}

void LcNwcGeometryStreamWrapper::MaxFacetDeviation(double tol)
{
	this->mGeometryStream->MaxFacetDeviation(tol);
}

void LcNwcGeometryStreamWrapper::ExteriorFaceting(bool b)
{
	this->mGeometryStream->ExteriorFaceting(b);
}

void LcNwcGeometryStreamWrapper::CorrectGenNormalOrientation(bool enable)
{
	this->mGeometryStream->CorrectGenNormalOrientation(enable);
}

void LcNwcGeometryStreamWrapper::CorrectVertexNormalOrientation(bool enable)
{
	this->mGeometryStream->CorrectVertexNormalOrientation(enable);
}

void LcNwcGeometryStreamWrapper::IndexedVertexAliases(bool enable)
{
	this->mGeometryStream->IndexedVertexAliases(enable);
}

void LcNwcGeometryStreamWrapper::PushTransform()
{
	this->mGeometryStream->PushTransform();
}

void LcNwcGeometryStreamWrapper::SetTransformIdentity()
{
	this->mGeometryStream->SetTransformIdentity();
}

void LcNwcGeometryStreamWrapper::SetTransformTranslation(double x, double y, double z)
{
	this->mGeometryStream->SetTransformTranslation(x, y, z);
}

void LcNwcGeometryStreamWrapper::SetTransformTranslation(const double v[3])
{
	this->mGeometryStream->SetTransformTranslation(v[0], v[1], v[2]);
}

void LcNwcGeometryStreamWrapper::SetTransform(double matrix[16])
{
	this->mGeometryStream->SetTransform(matrix);
}

void LcNwcGeometryStreamWrapper::MultTransformTranslation(double x, double y, double z)
{
	this->mGeometryStream->MultTransformTranslation(x, y, z);
}

void LcNwcGeometryStreamWrapper::MultTransformTranslation(const double v[3])
{
	this->mGeometryStream->MultTransformTranslation(v[0], v[1], v[2]);
}

void LcNwcGeometryStreamWrapper::MultTransform(double matrix[16])
{
	this->mGeometryStream->MultTransform(matrix);
}

void LcNwcGeometryStreamWrapper::PopTransform()
{
	this->mGeometryStream->PopTransform();
}

void LcNwcGeometryStreamWrapper::ExternalGeometry(const LcNwcExternalGeometryWrapper& geometry)
{
	this->mGeometryStream->ExternalGeometry(*geometry.mExternalGeometry);
}

void LcNwcGeometryStreamWrapper::Begin(unsigned int vertex_properties)
{
	this->mGeometryStream->Begin(vertex_properties);
}

void LcNwcGeometryStreamWrapper::Color(double r, double g, double b, double a)
{
	this->mGeometryStream->Color(r, g, b, a);
}

void LcNwcGeometryStreamWrapper::Normal(double x, double y, double z)
{
	this->mGeometryStream->Normal(x, y, z);
}

void LcNwcGeometryStreamWrapper::Normal(const double v[3])
{
	this->mGeometryStream->Normal(v[0], v[1], v[2]);
}

void LcNwcGeometryStreamWrapper::TexCoord(double x, double y)
{
	this->mGeometryStream->TexCoord(x, y);
}

int LcNwcGeometryStreamWrapper::IndexedVertex(double x, double y, double z)
{
	return this->mGeometryStream->IndexedVertex(x, y, z);
}

int LcNwcGeometryStreamWrapper::IndexedVertex(const double p[3])
{
	return this->mGeometryStream->IndexedVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::TriangleVertex(double x, double y, double z)
{
	this->mGeometryStream->TriangleVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::TriangleVertex(const double p[3])
{
	this->mGeometryStream->TriangleVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::TriangleIndex(int index)
{
	this->mGeometryStream->TriangleIndex(index);
}

void LcNwcGeometryStreamWrapper::TriStripVertex(double x, double y, double z)
{
	this->mGeometryStream->TriStripVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::TriStripVertex(const double p[3])
{
	this->mGeometryStream->TriStripVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::TriStripIndex(int index)
{
	this->mGeometryStream->TriStripIndex(index);
}

void LcNwcGeometryStreamWrapper::TriFanVertex(double x, double y, double z)
{
	this->mGeometryStream->TriFanVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::TriFanVertex(const double p[3])
{
	this->mGeometryStream->TriFanVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::TriFanIndex(int index)
{
	this->mGeometryStream->TriFanIndex(index);
}

void LcNwcGeometryStreamWrapper::ConvexPolyVertex(double x, double y, double z)
{
	this->mGeometryStream->ConvexPolyVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::ConvexPolyVertex(const double p[3])
{
	this->mGeometryStream->ConvexPolyVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::ConvexPolyIndex(int index)
{
	this->mGeometryStream->ConvexPolyIndex(index);
}

void LcNwcGeometryStreamWrapper::SeqEnd()
{
	this->mGeometryStream->SeqEnd();
}

void LcNwcGeometryStreamWrapper::BeginPolygon()
{
	this->mGeometryStream->BeginPolygon();
}

void LcNwcGeometryStreamWrapper::BeginPolygonContour()
{
	this->mGeometryStream->BeginPolygonContour();
}

void LcNwcGeometryStreamWrapper::PolygonVertex(double x, double y, double z)
{
	this->mGeometryStream->PolygonVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::PolygonVertex(const double p[3])
{
	this->mGeometryStream->PolygonVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::PolygonIndex(int index)
{
	this->mGeometryStream->PolygonIndex(index);
}

void LcNwcGeometryStreamWrapper::PolygonEllipse(double center[3], double major[3], double minor[3], double start_ang, double end_ang)
{
	this->mGeometryStream->PolygonEllipse(center, major, minor, start_ang, end_ang);
}

void LcNwcGeometryStreamWrapper::EndPolygonContour()
{
	this->mGeometryStream->EndPolygonContour();
}

void LcNwcGeometryStreamWrapper::EndPolygon()
{
	this->mGeometryStream->EndPolygon();
}

void LcNwcGeometryStreamWrapper::FacetRadius(double radius)
{
	this->mGeometryStream->FacetRadius(radius);
}

int LcNwcGeometryStreamWrapper::GetNumCirclePts(double radius)
{
	return this->mGeometryStream->GetNumCirclePts(radius);
}

void LcNwcGeometryStreamWrapper::Circle(double center[3], double normal[3], double radius)
{
	this->mGeometryStream->Circle(center, normal, radius);
}

void LcNwcGeometryStreamWrapper::Circle3Point(double pt1[3], double pt2[3], double pt3[3])
{
	this->mGeometryStream->Circle3Point(pt1, pt2, pt3);
}

void LcNwcGeometryStreamWrapper::Ellipse(double center[3], double major[3], double minor[3], double start_ang, double end_ang)
{
	this->mGeometryStream->Ellipse(center, major, minor, start_ang, end_ang);
}

void LcNwcGeometryStreamWrapper::EllipseCurve(double center[3], double major[3], double minor[3], double start_ang, double end_ang)
{
	this->mGeometryStream->EllipseCurve(center, major, minor, start_ang, end_ang);
}

void LcNwcGeometryStreamWrapper::Cylinder(double pt1[3], double pt2[3], double radius)
{
	this->mGeometryStream->Cylinder(pt1, pt2, radius);
}

void LcNwcGeometryStreamWrapper::Conic(double pt1[3], double major1[3], double minor1[3], double pt2[3], double major2[3], double minor2[3], double start_ang, double end_ang)
{
	this->mGeometryStream->Conic(pt1, major1, minor1, pt2, major2, minor2, start_ang, end_ang);
}

void LcNwcGeometryStreamWrapper::Cuboid(double pt1[3], double pt2[3])
{
	this->mGeometryStream->Cuboid(pt1, pt2);
}

void LcNwcGeometryStreamWrapper::Sphere(double pt[3], double radius)
{
	this->mGeometryStream->Sphere(pt, radius);
}

void LcNwcGeometryStreamWrapper::EllipsoidSection(double center[3], double x_axis[3], double y_axis[3], double z_axis[3], double latitude_min, double latitude_max, double longitude_min, double longitude_max)
{
	this->mGeometryStream->EllipsoidSection(center, x_axis, y_axis, z_axis, latitude_min, latitude_max, longitude_min, longitude_max);
}

void LcNwcGeometryStreamWrapper::Ellipsoid(double center[3], double x_axis[3], double y_axis[3], double z_axis[3])
{
	this->mGeometryStream->Ellipsoid(center, x_axis, y_axis, z_axis);
}

void LcNwcGeometryStreamWrapper::TorusSection(double center[3], double x_axis[3], double y_axis[3], double major_radius, double minor_radius, double phi_min, double phi_max, double longitude_min, double longitude_max)
{
	this->mGeometryStream->TorusSection(center, x_axis, y_axis, major_radius, minor_radius, phi_min, phi_max, longitude_min, longitude_max);
}

void LcNwcGeometryStreamWrapper::Torus(double center[3], double x_axis[3], double y_axis[3], double major_radius, double minor_radius)
{
	this->mGeometryStream->Torus(center, x_axis, y_axis, major_radius, minor_radius);
}

LtInt32 LcNwcGeometryStreamWrapper::IndexedLineVertex(double x, double y, double z)
{
	return this->mGeometryStream->IndexedLineVertex(x, y, z);
}

LtInt32 LcNwcGeometryStreamWrapper::IndexedLineVertex(const double p[3])
{
	return this->mGeometryStream->IndexedLineVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::LineVertex(double x, double y, double z)
{
	this->mGeometryStream->LineVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::LineVertex(const double p[3])
{
	this->mGeometryStream->LineVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::LineIndex(int index)
{
	this->mGeometryStream->LineIndex(index);
}

void LcNwcGeometryStreamWrapper::LineStripVertex(double x, double y, double z)
{
	this->mGeometryStream->LineStripVertex(x, y, z);
}

void LcNwcGeometryStreamWrapper::LineStripVertex(const double p[3])
{
	this->mGeometryStream->LineStripVertex(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::LineStripIndex(int index)
{
	this->mGeometryStream->LineStripIndex(index);
}

void LcNwcGeometryStreamWrapper::Point(double x, double y, double z)
{
	this->mGeometryStream->Point(x, y, z);
}

void LcNwcGeometryStreamWrapper::Point(const double p[3])
{
	this->mGeometryStream->Point(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::SnapPoint(double x, double y, double z)
{
	this->mGeometryStream->SnapPoint(x, y, z);
}

void LcNwcGeometryStreamWrapper::SnapPoint(const double p[3])
{
	this->mGeometryStream->SnapPoint(p[0], p[1], p[2]);
}

void LcNwcGeometryStreamWrapper::Curve(const LcNwcCurveWrapper& curve)
{
	this->mGeometryStream->Curve(*curve.mCurve);
}

void LcNwcGeometryStreamWrapper::CurveSegment(const LcNwcCurveWrapper& curve, double start, double end)
{
	this->mGeometryStream->CurveSegment(*curve.mCurve, start, end);
}

void LcNwcGeometryStreamWrapper::FacetEnd()
{
	this->mGeometryStream-> FacetEnd();
}

void LcNwcGeometryStreamWrapper::End()
{
	this->mGeometryStream->End();
}

void LcNwcGeometryStreamWrapper::CoordTolerance(double tolerance)
{
	this->mGeometryStream->CoordTolerance(tolerance);
}

void LcNwcGeometryStreamWrapper::GenerateParametrics(bool enable)
{
	this->mGeometryStream->GenerateParametrics(enable);
}

int LcNwcGeometryStreamWrapper::BRepShell(const LcNwcShellWrapper& shell)
{
	return this->mGeometryStream->BRepShell(*shell.mShell);
}

int LcNwcGeometryStreamWrapper::BRepEntity(const LcNwcBRepEntityWrapper& entity)
{
	return this->mGeometryStream->BRepEntity(*entity.mBRepEntity);
}

std::string LcNwcGeometryStreamWrapper::BRepFaceterName() const
{
	return std::string(this->mGeometryStream->BRepFaceterName());
}

int LcNwcGeometryStreamWrapper::BRepNumFailedFaces()
{
	return this->mGeometryStream->BRepNumFailedFaces();
}

void LcNwcGeometryStreamWrapper::BeginText(const LcNwcTextStyleWrapper& style)
{
	this->mGeometryStream->BeginText(*style.mTextStyle);
}

void LcNwcGeometryStreamWrapper::AddText(const std::wstring& text)
{
	this->mGeometryStream->AddText(text.c_str());
}

void LcNwcGeometryStreamWrapper::EndText()
{
	this->mGeometryStream->EndText();
}


LcNwcGeometryStreamWrapper::~LcNwcGeometryStreamWrapper()
{
	//destroy method exists??
}

//LcNwcCurveWrapper and all other inherits
//-----------------------------------------------------------------------------------------------------------------------
// LcNwcCurveWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcCurveWrapper::LcNwcCurveWrapper(const LcNwcCurve& other)
{
	this->mCurve = new LcNwcCurve(other);
}

LcNwcCurveWrapper::LcNwcCurveWrapper(LtNwcCurve handle)
{
	this->mCurve = new LcNwcCurve(handle);
}

LcNwcCurveWrapper LcNwcCurveWrapper::Copy()
{
	return LcNwcCurveWrapper(this->mCurve->Copy());
}

void LcNwcCurveWrapper::SetUserData(int data)
{
	this->mCurve->SetUserData(data);
}

void LcNwcCurveWrapper::Evaluate(double t, double pnt[3])
{
	this->mCurve->Evaluate(t, pnt);
}

void LcNwcCurveWrapper::Reverse()
{
	this->mCurve->Reverse();
}

void LcNwcCurveWrapper::Transform(const LcNwcTransformWrapper& transform)
{
	this->mCurve->Transform(*transform.mTransform);
}

void LcNwcCurveWrapper::Translate(double x, double y, double z)
{
	this->mCurve->Translate(x, y, z);
}

void LcNwcCurveWrapper::Translate(double v[3])
{
	this->mCurve->Translate(v[0], v[1], v[2]);
}

double LcNwcCurveWrapper::GetFirstParameter(bool* is_infinite)
{
	return this->mCurve->GetFirstParameter(is_infinite);
}

double LcNwcCurveWrapper::GetLastParameter(bool* is_infinite)
{
	return this->mCurve->GetLastParameter(is_infinite);
}

LcNwcCurveWrapper::~LcNwcCurveWrapper()
{
	LiNwcCurveDestroy(*this->mCurve);
}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcBezierCurveWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcBezierCurveWrapper::LcNwcBezierCurveWrapper(int num_poles, double poles[][3]) : LcNwcCurveWrapper(*(mBezierCurve = new LcNwcBezierCurve(num_poles, poles)))
{

}

LcNwcBezierCurveWrapper::LcNwcBezierCurveWrapper(int num_poles, double poles[][3], double weights[]) : LcNwcCurveWrapper(*(mBezierCurve = new LcNwcBezierCurve(num_poles, poles, weights)))
{

}

LcNwcBezierCurveWrapper::LcNwcBezierCurveWrapper(LtNwcBezierCurve handle) : LcNwcCurveWrapper(*(mBezierCurve = new LcNwcBezierCurve(handle)))
{

}

LcNwcBezierCurveWrapper::~LcNwcBezierCurveWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcBSplineCurveWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcBSplineCurveWrapper::LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], int num_knots, double knots[], int mults[], int degree, bool periodic) : LcNwcCurveWrapper(*(mBSplineCurve = new LcNwcBSplineCurve(num_poles, poles, num_knots, knots, mults, degree, periodic)))
{

}

LcNwcBSplineCurveWrapper::LcNwcBSplineCurveWrapper(int num_poles, double poles[][3], double weights[], int num_knots, double knots[], int mults[], bool periodic) : LcNwcCurveWrapper(*(mBSplineCurve = new LcNwcBSplineCurve(num_poles, poles, weights, num_knots, knots, mults, periodic)))
{

}

LcNwcBSplineCurveWrapper::LcNwcBSplineCurveWrapper(LtNwcBSplineCurve handle) : LcNwcCurveWrapper(*(mBSplineCurve = new LcNwcBSplineCurve(handle)))
{

}

LcNwcBSplineCurveWrapper::~LcNwcBSplineCurveWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcCircleWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcCircleWrapper::LcNwcCircleWrapper(double pnt[3], double xaxis[3], double yaxis[3], double radius) : LcNwcCurveWrapper(*(this->mCircle = new LcNwcCircle(pnt, xaxis, yaxis, radius)))
{

}

LcNwcCircleWrapper::LcNwcCircleWrapper(LtNwcCircle handle) : LcNwcCurveWrapper(*(this->mCircle = new LcNwcCircle(handle)))
{

}

LcNwcCircleWrapper::~LcNwcCircleWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcEllipseWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcEllipseWrapper::LcNwcEllipseWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius) : LcNwcCurveWrapper(*(this->mEllipse = new LcNwcEllipse(pnt, xaxis, yaxis, major_radius, minor_radius)))
{

}

LcNwcEllipseWrapper::LcNwcEllipseWrapper(LtNwcEllipse handle) : LcNwcCurveWrapper(*(this->mEllipse = new LcNwcEllipse(handle)))
{

}

LcNwcEllipseWrapper::~LcNwcEllipseWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcHyperbolaWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcHyperbolaWrapper::LcNwcHyperbolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double major_radius, double minor_radius) : LcNwcCurveWrapper(*(this->mHyperbola = new LcNwcHyperbola(pnt, xaxis, yaxis, major_radius, minor_radius)))
{

}

LcNwcHyperbolaWrapper::LcNwcHyperbolaWrapper(LtNwcHyperbola handle) : LcNwcCurveWrapper(*(this->mHyperbola = new LcNwcHyperbola(handle)))
{

}

LcNwcHyperbolaWrapper::~LcNwcHyperbolaWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcLineWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcLineWrapper::LcNwcLineWrapper(double pnt[3], double dir[3]) : LcNwcCurveWrapper(*(this->mLine = new LcNwcLine(pnt, dir)))
{

}

LcNwcLineWrapper::LcNwcLineWrapper(LtNwcLine handle) : LcNwcCurveWrapper(*(this->mLine = new LcNwcLine(handle)))
{

}

LcNwcLineWrapper::~LcNwcLineWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcParabolaWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcParabolaWrapper::LcNwcParabolaWrapper(double pnt[3], double xaxis[3], double yaxis[3], double focal_length) : LcNwcCurveWrapper(*(this->mParabola = new LcNwcParabola(pnt, xaxis, yaxis, focal_length)))
{

}

LcNwcParabolaWrapper::LcNwcParabolaWrapper(LtNwcParabola handle) : LcNwcCurveWrapper(*(this->mParabola = new LcNwcParabola(handle)))
{

}

LcNwcParabolaWrapper::~LcNwcParabolaWrapper()
{

}

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcTrimmedCurveWrapper 
//-----------------------------------------------------------------------------------------------------------------------
LcNwcTrimmedCurveWrapper::LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double param0, double param1, bool sense) : LcNwcCurveWrapper(*(mTrimmedCurve = new LcNwcTrimmedCurve(*basis_curve.mCurve, param0, param1, sense)))
{

}

LcNwcTrimmedCurveWrapper::LcNwcTrimmedCurveWrapper(LcNwcCurveWrapper basis_curve, double pnt0[3], double pnt1[3], bool sense) : LcNwcCurveWrapper(*(mTrimmedCurve = new LcNwcTrimmedCurve(*basis_curve.mCurve, pnt0, pnt1, sense)))
{

}

LcNwcTrimmedCurveWrapper::LcNwcTrimmedCurveWrapper(LtNwcTrimmedCurve handle) : LcNwcCurveWrapper(*(mTrimmedCurve = new LcNwcTrimmedCurve(handle)))
{

}

LcNwcTrimmedCurveWrapper::~LcNwcTrimmedCurveWrapper()
{
	
}

