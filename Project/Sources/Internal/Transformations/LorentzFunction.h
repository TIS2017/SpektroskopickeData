#pragma once

#include "TransformationsLibPrivate.h"

namespace DataAnalysis { namespace Transformations {

	template <class BaseType = double> class LorentzFunction : public IFunction<BaseType> {
	public:

		ConstantFunction() {
			mType = FT_LORENTZ;
		}

		void Initialize( __in const BaseType params ) {
			mParams = params;
			mInitialized = true;
		}

		virtual void Apply( __in const BaseType &in, __out BaseType &out ) const {
			UNREFERENCED_PARAMETER( in );
			double lineCenter2 = fcnCarre(x);
			double gamma2 = fcnCarre(*(mParams+1));
			double intensity = *(mParams)*(*(mParams+1))*fcnInverse(gamma2+lineCenter2);
			out = intensity;
		}

	protected:

		BaseType mParams;

	};

} }