#pragma once
#pragma once

#include "TransformationsLibPrivate.h"

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class HartmanTran : public IFunction<BaseType> {

		public:

			HartmanTran() {
				mType = FT_LORENTZ;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			// mParams[0] ... 
			// mParams[1] ... 
			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
			}

		protected:

			const double *mParams;

		};

	}
}