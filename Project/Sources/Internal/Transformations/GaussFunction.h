#pragma once

#include "TransformationsLibPrivate.h"

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class GaussFunction : public IFunction<BaseType> {

		public:

			GaussFunction() {
				mType = FT_LORENTZ;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
			}

		protected:

			const double *mParams;

		};

	}
}