/*=========================================================================

  Program:   itkUNC
  Module:    $RCSfile: sovTubeGlRenderMethodSlicer.h,v $
  Language:  C++
  Date:      $Date: 2005-01-27 23:31:57 $
  Version:   $Revision: 1.1.1.1 $
  Author:    Julien Jomier

  Copyright (c) 2002 CADDLab @ UNC. All rights reserved.
  See itkUNCCopyright.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef sov_TubeGlRenderMethodSlicer_h
#define sov_TubeGlRenderMethodSlicer_h

#include "sovGlRenderMethodSlicer.h"
#include "itkTubeSpatialObject.h"
#include "sovOpenGLWin32Header.h"

namespace sov
{

  
class SOVOpenGLRenderMethod_EXPORT TubeGlRenderMethodSlicer
: public GlRenderMethodSlicer
{

public:


  typedef TubeGlRenderMethodSlicer        Self;
  typedef GlRenderMethodSlicer            Superclass;
  typedef SmartPointer< Self >        Pointer;
  typedef SmartPointer< const Self >  ConstPointer;
  typedef Superclass::ObjectType      ObjectType;
  typedef Superclass::ObjectListType  ObjectListType;

  typedef itk::TubeSpatialObject<3>           TubeType;
  typedef TubeType::Pointer                   TubePointer;
  typedef TubeType::ChildrenListType   TubeListType;
  typedef TubeType::TubePointType             TubePointType;
  typedef TubePointType*                      TubePointPointer;
  typedef TubeType::PointListType             TubePointListType;
  typedef TubePointListType *                 TubePointListPointer;
  typedef TubePointType::PointType            PointType;
  typedef PointType *                         PointPointer;


  itkNewMacro( TubeGlRenderMethodSlicer );

  itkTypeMacro( TubeGlRenderMethodSlicer, GlRenderMethod3D );

  virtual void draw( void );

protected:

  TubeGlRenderMethodSlicer( void );
  ~TubeGlRenderMethodSlicer( void );

  void PrintSelf (std::ostream &os, Indent indent) const;

  virtual void Update(); 
  
};

}

#endif //_TubeGlRenderMethodSlicer_h
