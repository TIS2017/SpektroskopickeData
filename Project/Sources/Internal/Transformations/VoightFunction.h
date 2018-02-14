#pragma once
#include "TransformationsLibPrivate.h"

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class VoightFunction : public IFunction<BaseType> {
		public:

			VoightFunction() {
				mType = FT_VOIGHT;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}
			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
				double rx = (sqrt(log(2)) * (xi - (x0 + mParams[8])) / mParams[7]);
				double ry = ((mParams[6] / mParams[7]) * sqrt(log(2)));
				double vr, vi, vr0;
				cwerf(0.0, ry, &vr0, &vi);
				cwerf(rx, ry, &vr, &vi);
				return a * vr / vr0;
			}

		protected:
			const double *mParams;
		};
	}
}