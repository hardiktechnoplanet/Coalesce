
// STEP Read Methods
#include "STEPControl_Reader.hxx"
#include <TopoDS_Shape.hxx>
// STL Read & Write Methods
#include <StlAPI_Writer.hxx>
#include <BRepMesh_IncrementalMesh.hxx>

int step2stl(char *in, char *out) {
  // Read from STEP
	//Creat a reader
  STEPControl_Reader reader;
  //Read the input STEP file using the created reader
  IFSelect_ReturnStatus stat = reader.ReadFile(in);
  Standard_Integer NbRoots = reader.NbRootsForTransfer();
  Standard_Integer NbTrans = reader.TransferRoots();
  TopoDS_Shape Original_Solid = reader.OneShape();
 
  // Before writing to STL we need to form a mesh
  StlAPI_Writer stlWriter = StlAPI_Writer();
  // Convert the TopoDS_Shape Object to Triangular Mesh
  BRepMesh_IncrementalMesh Mesh(Original_Solid, 0.0001);
  Mesh.Perform();

  //Write to STL
  stlWriter.Write( Original_Solid, out);
  //cout << "last check " << endl;
  return 1;
}


Standard_Integer main (int argc, char *argv[]) {
  step2stl(argv[1], argv[2]);
  return 0;
}


