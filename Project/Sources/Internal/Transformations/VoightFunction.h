#pragma once
#include "TransformationsLibPrivate.h"

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class VoightFunction : public IFunction<BaseType> {
		public:

			VoightFunction() {
				mType = FT_VOIGHT;
			}

			void Initialize(__in const BaseType params) {
				mParams = params;
				mInitialized = true;
			}

			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
			}

		protected:
			BaseType mParams;
		};
	}
}