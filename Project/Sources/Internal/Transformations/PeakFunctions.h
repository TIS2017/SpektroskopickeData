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
				out = in;
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
				double v = in;
				double v0 = mParams[3];
				double delta0 = mParams[8];
				double t0 = mParams[7] / 2;

				//calculate part in bracket
				double zatvorka = -log(2) * ((v - pow((v0 + delta0), 2)) / pow(t0, 2));

				//calculate first multiplier
				double prvy = 1 / t0;

				//calculate second multiplier
				double druhy = log(2) / M_PI;

				//return prvy * druhy * exp(zatvorka);
				out += prvy * druhy * exp(zatvorka);
			}

		private:
			const double *mParams;

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