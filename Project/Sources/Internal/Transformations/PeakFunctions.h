#pragma once

#include "TransformationsLibPrivate.h"
#include <math.h>
#include <complex>

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class LorentzFunction : public IFunction<BaseType> {

		public:

			LorentzFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual inline void Apply(__in const BaseType &in, __out BaseType &out) const {
				//out += Lorentz(in);
				double v = in;
				double t0 = mParams[6] / 2;
				double v0 = mParams[3];
				double delta0 = mParams[8];

				//calculate divisor
				double divisor = v - pow((v0 + delta0), 2) + pow(t0, 2);

				//calculate first multiplier
				double multiplier = 1 / M_PI;

				//return multiplier *	(abs(t0) / divisor);
				out += multiplier *	(abs(t0) / divisor);
			}

		protected:

			const double *mParams;

		private:

		};

		template <class BaseType = double> class GaussFunction : public IFunction<BaseType> {

		public:

			GaussFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual inline void Apply(__in const BaseType &in, __out BaseType &out) const {
				out = in;
			}

		protected:

			const double *mParams;

		private:

		
		};

		template <class BaseType = double> class VoigtFunction : public IFunction<BaseType> {

		public:

			VoigtFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
				out = in;
			}

		protected:

			const double *mParams;

		private:

		};

	}
}