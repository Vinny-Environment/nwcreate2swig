#include "nwcreateApi.hpp"

//-----------------------------------------------------------------------------------------------------------------------
// LcNwcGeometryWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGeometryWrapper::LcNwcGeometryWrapper() : LcNwcNodeWrapper(*(this->mGeometry = new LcNwcGeometry()))
{

}

LcNwcGeometryWrapper::LcNwcGeometryWrapper(const LtNwcGeometry& handle) : LcNwcNodeWrapper(*(this->mGeometry = new LcNwcGeometry(handle)))
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
// LcNwcGeometryStreamWrapper
//-----------------------------------------------------------------------------------------------------------------------
LcNwcGeometryStreamWrapper::LcNwcGeometryStreamWrapper(const LtNwcGeometryStream& stream)
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

void LcNwcGeometryStreamWrapper::ExternalGeometry(LtNwcExternalGeometry geometry) //TODO Wrapper
{
	this->mGeometryStream->ExternalGeometry(geometry);
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
/*
void LcNwcGeometryStreamWrapper::Curve(LtNwcCurve curve)
{
	this->mGeometryStream->Curve(curve);
}

void LcNwcGeometryStreamWrapper::CurveSegment(LtNwcCurve curve, double start, double end)
{
	this->mGeometryStream->CurveSegment(curve, start, end);
}
*/
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
/*
int LcNwcGeometryStreamWrapper::BRepShell(LtNwcShell shell)
{
	return this->mGeometryStream->BRepShell(shell);
}

int LcNwcGeometryStreamWrapper::BRepEntity(LtNwcBRepEntity entity)
{
	return this->mGeometryStream->BRepEntity(entity);
}
*/
std::string LcNwcGeometryStreamWrapper::BRepFaceterName() const
{
	return std::string(this->mGeometryStream->BRepFaceterName());
}

int LcNwcGeometryStreamWrapper::BRepNumFailedFaces()
{
	return this->mGeometryStream->BRepNumFailedFaces();
}

/*
void LcNwcGeometryStreamWrapper::BeginText(LtNwcTextStyle style)
{
	this->mGeometryStream->BeginText(style);
}
*/
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