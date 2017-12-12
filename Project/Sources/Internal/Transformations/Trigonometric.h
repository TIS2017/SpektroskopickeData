#pragma once

#include "TransformationsLibPrivate.h"

namespace DataAnalysis { namespace Transformations {
	
	/*
		Trignonometric function which looks like this:
			Out = a * trigF( 2PI *b * In + c ),
			where tigF is sin or cos
	*/
	template <class BaseType> class TrigonometricFunction : public IFunction<BaseType> {
	public:
		void Initialize( __in const BaseType a, __in const BaseType b, __in const BaseType c ) {
			mA = a;
			mB = b;
			mC = c;
			mInitialized = true;
		}

		void Initialize( __in_ecount( 3 ) const BaseType *pParams ) {
			mA = *pParams;
			mB = *( pParams + 1 );
			mC = *( pParams + 2 );
			mInitialized = true;
		}

		void Initialize( __in const Buffer<BaseType> &params ) {
			if ( params.Length() >= 3 ) {
				Initialize( params.Ptr() );
			}
		}

		void Initialize( __in const vector<BaseType> &params ) {
			if ( params.size() >= 3 ) {
				Initialize( params.data() );
			}
		}

	protected:
		BaseType mA, mB, mC;
	};

	// Out = a * sin( In * 2PI*b + c )
	template <class BaseType = double > class SinFunction : public TrigonometricFunction<BaseType> {
	public:
		SinFunction() { mType = FT_TRIG_SIN; };

		virtual inline void Apply( __in const BaseType &in, __out BaseType &out  ) const {
			out = mA * sin( 2 * M_PI*mB*in + mC );
		};
	};

	// Out = a * cos( In * 2PI*b + c )
	template <class BaseType = double > class CosFunction : public TrigonometricFunction<BaseType> {
	public:
		CosFunction() { mType = FT_TRIG_COS; };

		virtual inline void Apply( __in const BaseType &in, __out BaseType &out ) const {
			out = mA * cos( 2 * M_PI*mB*in + mC );
		};
	};

} }