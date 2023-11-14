--- src/Mod/Part/App/Geometry2d.cpp.orig	2023-11-14 12:23:41 UTC
+++ src/Mod/Part/App/Geometry2d.cpp
@@ -180,7 +180,7 @@ void Geom2dPoint::Save(Base::Writer &writer) const
         << "<Geom2dPoint "
         << "X=\"" << Point.x << "\" "
         << "Y=\"" << Point.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dPoint::Restore(Base::XMLReader &reader)
@@ -872,7 +872,7 @@ void Geom2dCircle::Save(Base::Writer& writer) const
     SaveAxis(writer, axis);
     writer.Stream()
         << "Radius=\"" << c.Radius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dCircle::Restore(Base::XMLReader& reader)
@@ -1033,7 +1033,7 @@ void Geom2dArcOfCircle::Save(Base::Writer &writer) con
     SaveAxis(writer, axis, u, v);
     writer.Stream()
         << "Radius=\"" << c.Radius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfCircle::Restore(Base::XMLReader &reader)
@@ -1195,7 +1195,7 @@ void Geom2dEllipse::Save(Base::Writer& writer) const
     writer.Stream()
         << "MajorRadius=\"" << e.MajorRadius() << "\" "
         << "MinorRadius=\"" << e.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dEllipse::Restore(Base::XMLReader& reader)
@@ -1372,7 +1372,7 @@ void Geom2dArcOfEllipse::Save(Base::Writer &writer) co
     writer.Stream()
         << "MajorRadius=\"" << e.MajorRadius() << "\" "
         << "MinorRadius=\"" << e.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfEllipse::Restore(Base::XMLReader &reader)
@@ -1501,7 +1501,7 @@ void Geom2dHyperbola::Save(Base::Writer& writer) const
     writer.Stream()
         << "MajorRadius=\"" <<  h.MajorRadius() << "\" "
         << "MinorRadius=\"" <<  h.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dHyperbola::Restore(Base::XMLReader& reader)
@@ -1634,7 +1634,7 @@ void Geom2dArcOfHyperbola::Save(Base::Writer &writer) 
     writer.Stream()
         << "MajorRadius=\"" <<  h.MajorRadius() << "\" "
         << "MinorRadius=\"" <<  h.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfHyperbola::Restore(Base::XMLReader &reader)
@@ -1745,7 +1745,7 @@ void Geom2dParabola::Save(Base::Writer& writer) const
     SaveAxis(writer, axis);
     writer.Stream()
         << "Focal=\"" << focal << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dParabola::Restore(Base::XMLReader& reader)
@@ -1858,7 +1858,7 @@ void Geom2dArcOfParabola::Save(Base::Writer &writer) c
     SaveAxis(writer, axis, u, v);
     writer.Stream()
         << "Focal=\"" << focal << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfParabola::Restore(Base::XMLReader &reader)
@@ -1973,7 +1973,7 @@ void Geom2dLine::Save(Base::Writer &writer) const
         << "PosY=\"" << Pos.y << "\" "
         << "DirX=\"" << Dir.x << "\" "
         << "DirY=\"" << Dir.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dLine::Restore(Base::XMLReader &reader)
@@ -2107,7 +2107,7 @@ void Geom2dLineSegment::Save(Base::Writer &writer) con
         << "StartY=\"" << Start.y << "\" "
         << "EndX=\"" << End.x << "\" "
         << "EndY=\"" << End.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dLineSegment::Restore(Base::XMLReader &reader)
