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
				//out += Voigt(in);
				double v = in;
				static const std::complex<double> i(0.0, 1.0);
				double w0 = mParams[6];
				double td = w0 / 2;
				double v0 = mParams[3];
				double delta0 = mParams[8];


				//counting z
				std::complex<double> z = log(2) * (w0 + i*(v0 + delta0 - v)) / td;

				//counting first multiplier
				double first = 1 / abs(td);

				//counting second multiplier
				double second = sqrt(log(2) / M_PI);

				//counting third multiplier
				std::complex<double> third = pow(M_E, -pow(z, 2)) * erfc(-z.real());

				//return first * second * third;
				out += first * second * third.real();
			}

		protected:

			const double *mParams;

		private:

		};

	}
}
