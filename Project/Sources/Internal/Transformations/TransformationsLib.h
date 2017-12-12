#pragma once

#include "TransformationsLibPrivate.h"
#include "ConstantFunction.h"
#include "PolynomialTransform.h"
#include "Spline.h"
#include "Trigonometric.h"
#include "CompositeFunctions.h"
#include "DataTransformations.h"
#include "InputTransformation.h"

namespace DataAnalysis { namespace Transformations {

	/* 
		Function for converting internal function type enum values to input/output function types
		does not support converting "FT_MODEL_..." types ( mainly because they are not represented by any number in LabView structs :) )
		IMPORTANT!
			As this function is not needed anywhere, it is not developed further and may not work properly!
	*/
	inline int GetInputFunctionType( __in const FUNCTION_TYPE type ) {
		int resType = static_cast<int>(type);
		while ( resType >= 0x1000 ) {
			resType -= 0x1000;
		}
		return resType;
	}

	/* 
		Function for retrieving internal function type based on information from labview input data
		Input:	functName: string indetifying sub-function
				typeId:	int indetifying concrete sub-function type
		Mapping:
			Polynomial functions: XScl, YOff, YPol, BPol
				Types:	0 -> basic polynomial
						1 -> Legendre polynomial
						2 -> Chebyshev polynomial
				XScl apparently does not come with typeId -> Static mapping
			Trigonometric functions: YTrg, BTrg
				Types:	0 -> Sin
						1 -> Cos
			Spline functions: YSpl, BSpl
				Types: None
				Mapped statically
			Summary operation: YTyp
				Types:	1 -> Multiplication
						2 -> Division
			Constant Offset function: XOff
				Mapped statically
			Transformations: XT/YT/BL/PK
				Mapped statically
	*/
	inline FUNCTION_TYPE GetInternalFunctionType( __in const string &functName, __in int typeId = 0 ) {
		if ( functName.compare( "XScl" ) == 0 ) {
			typeId = FT_POLY_BASIC;
		}
		else if ( functName.compare( "YOff" ) == 0 || functName.compare( "YPol" ) == 0 || functName.compare( "BPol" ) == 0 ) {
			typeId += 0x1000;
		}
		else if ( functName.compare( "YTrg" ) == 0 || functName.compare( "BTrg" ) == 0 ) {
			typeId += 0x2000;
		}
		else if ( functName.compare( "YSpl" ) == 0 || functName.compare( "BSpl" ) == 0 ) {
			typeId = FT_SPLINE_CUBIC_HERMITE;
		}
		else if ( functName.compare( "YTyp" ) == 0 ) {
			typeId += 0x4000;
		} 
		else if( functName.compare( "XOff" ) == 0 ) {
			typeId = FT_CONSTANT;
		}
		else if ( functName.compare( "XT" ) == 0 ) {
			typeId = FT_TRANSFORM_X;
		}
		else if ( functName.compare( "YT" ) == 0 ) {
			typeId = FT_TRANSFORM_Y;
		}
		else if ( functName.compare( "BL" ) == 0 ) {
			typeId = FT_MODEL_BASELINE;
		}
		else if ( functName.compare( "PK" ) == 0 ) {
			typeId = FT_MODEL_PEAKS;
		}
		else {
			return FT_UNKNOWN;
		}

		return static_cast<FUNCTION_TYPE>( typeId );
	}

} }